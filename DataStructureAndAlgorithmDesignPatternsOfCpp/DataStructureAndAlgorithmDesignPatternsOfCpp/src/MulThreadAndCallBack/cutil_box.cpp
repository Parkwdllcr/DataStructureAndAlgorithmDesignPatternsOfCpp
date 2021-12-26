//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    THREAD_utils.cpp
///  \brief   implement CUtils
///
///  \version 1.0
///  \date    August. 20 2014
//////////////////////////////////////////////////////////////////////////

#include <string.h>
#include "MulThreadAndCallBack/cutil_box.h"

#ifndef _THREAD_OS_LINUX_ // for windows impletement
#include <windows.h>
#include <direct.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/syscall.h>

#endif

// namespace
namespace thread {

CUtils::CUtils()
{
}

CUtils::~CUtils()
{
}

unsigned long CUtils::GetCurrentTimes()
{
#ifdef _THREAD_OS_WIN_ // for windows impletement
    return static_cast<unsigned long>(::GetTickCount());
#elif defined(_THREAD_OS_LINUX_)
    struct timeval tv;

    if ( (::gettimeofday(&tv, NULL)!=0) || (tv.tv_usec>1000000) )
    {
        return (unsigned long)(-1);
    }
    return (unsigned long)(tv.tv_sec*1000 + tv.tv_usec/1000);
#else
#error "Unsupported OS!"
#endif
}

void CUtils::GetCurrentTimes(unsigned long &ulSec, unsigned long &ulUSec)
{
#ifdef _THREAD_OS_LINUX_
    struct timeval tv;

    if( (::gettimeofday(&tv, NULL)!=0) || (tv.tv_usec>1000000) )
    {
        ulSec = 0;
        ulUSec = 0;
        return ;
    }

    ulSec = tv.tv_sec;
    ulUSec = tv.tv_usec;
#else

#endif
}

void CUtils::MSleep(unsigned long mseconds)
{
#ifdef _THREAD_OS_WIN_ // for windows impletement
    ::_sleep( mseconds );
#elif defined(_THREAD_OS_LINUX_)
    ::usleep( mseconds*1000 );
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::GetInputParameter(const unsigned short pno, const char* psstr, char* pdstr, const unsigned short dstrmaxlen)
{
    char* pstart,*pend;
    unsigned int loop = 0;
    unsigned int len = 0;

    if ( !psstr || !pdstr || !dstrmaxlen )
    {
        return THREAD_FAILED;
    }

    pstart = const_cast<char*>(psstr);
    pend = pstart;
    while ( 1 )
    {
        if ( ('\0'!=*pend)&&(' '!=*pend) )
        {
            pend++;
            continue;
        }
        if ( (' '==*pend)&&(pstart==pend) )
        {
            pend++;
            pstart = pend;
            continue;
        }

        if ( loop==pno )
        {
            if ( pstart>=pend )
            {
                return THREAD_FAILED;
            }
            len = static_cast<unsigned int>(pend - pstart);
            if ( dstrmaxlen<=len )
            {
                return THREAD_FAILED;
            }
            memcpy(pdstr, pstart, len);
            *(pdstr+len) = '\0';
            return THREAD_OK;
        }
        if ( '\0'==*pend )
        {
            break;
        }

        loop++;
        pend++;
        pstart = pend;
    }
    return THREAD_FAILED;
}

int32_t CUtils::GetTokenString(char** ppcSipMsgBuf, uint32_t* puiDataLen, const char chSeparator,
                                    char** ppcTokenString, uint32_t* puiStringLen)
{
    if ( (NULL==ppcSipMsgBuf)||
         (NULL==*ppcSipMsgBuf)||
         (NULL==puiDataLen)||
         (NULL==ppcTokenString)||
         (NULL==puiStringLen) )
    {
        return THREAD_FAILED;
    }

    if ( 0==*puiDataLen )
    {
        return THREAD_FAILED;
    }

    *ppcTokenString = NULL;
    *puiStringLen = 0;

    // -1, all the left bytes are the token
    if ( 0>=chSeparator )
    {
        *puiStringLen = *puiDataLen;
        *ppcTokenString = *ppcSipMsgBuf;
        *ppcSipMsgBuf = NULL;
        *puiDataLen = 0;
        return THREAD_OK;
    }

    char* const pSBegin = *ppcSipMsgBuf;
    const char* pSEnd = pSBegin;
    for ( uint32_t uiLoop=*puiDataLen;uiLoop>0;uiLoop-- )
    {
        if ( *pSEnd==chSeparator )
        {
            if ( '\r'==chSeparator )
            {
                // '\r' must follow by '\n'
                if ( '\n'!=*(pSEnd+1) )
                {
                    *puiStringLen = static_cast<unsigned short>(pSEnd-pSBegin);
                    *ppcTokenString = pSBegin;
                    *ppcSipMsgBuf += static_cast<uint32_t>(*puiStringLen+1);//skin '\r','\n'
                    *puiDataLen -= static_cast<uint32_t>(*puiStringLen+1);
                }
                else
                {
                    *puiStringLen = static_cast<unsigned short>(pSEnd-pSBegin);
                    *ppcTokenString = pSBegin;
                    *ppcSipMsgBuf += static_cast<uint32_t>(*puiStringLen+2);//skin '\r','\n'
                    *puiDataLen -= static_cast<uint32_t>(*puiStringLen+2);
                }
            }
            else if ( '\n'==chSeparator )
            {
                if ( (pSBegin==pSEnd)||('\r'!=*(pSEnd-1)) )
                {
                    *puiStringLen = static_cast<unsigned short>(pSEnd-pSBegin);
                    *ppcTokenString = pSBegin;
                    *ppcSipMsgBuf += static_cast<uint32_t>(*puiStringLen+1);// skin chSeparator
                    *puiDataLen -= static_cast<uint32_t>(*puiStringLen+1);
                }
                else
                {
                    *puiStringLen = static_cast<unsigned short>((pSEnd-pSBegin)-1);
                    *ppcTokenString = pSBegin;
                    *ppcSipMsgBuf += static_cast<uint32_t>(*puiStringLen+2);// skin '\r','\n'
                    *puiDataLen -= static_cast<uint32_t>(*puiStringLen+2);
                }
            }
            else
            {
                *puiStringLen = static_cast<unsigned short>(pSEnd-pSBegin);
                *ppcTokenString = pSBegin;
                *ppcSipMsgBuf += static_cast<uint32_t>(*puiStringLen+1);// skin chSeparator
                *puiDataLen -= static_cast<uint32_t>(*puiStringLen+1);
            }

            //skin space
            THREAD_StrTrimSpace(*ppcTokenString, *puiStringLen);
            THREAD_StrTrimLeftSpace(*ppcSipMsgBuf, *puiDataLen);
            return THREAD_OK;
        }
        else
        {
            pSEnd++;
        }
    }

    return THREAD_FAILED;
}

int CUtils::CheckCPUEndian()
{
    union
    {
        unsigned long int i;
        unsigned char s[4];
    }c = {0x09876543};
    return (0x09 == c.s[0]);
}

int32_t CUtils::IsDigitString(const char* psstr)
{
    if ( (!psstr)||('\0'==*psstr) )
    {
        return THREAD_FAILED;
    }

    while ( '\0'!=*psstr )
    {
        if ( (0x30>(*psstr))||
             (0x39<(*psstr))  )
        {
            return THREAD_FAILED;
        }
        psstr++;
    }
    return THREAD_OK;
}

int32_t CUtils::IsHexString(const char* psstr)
{
    if ( (!psstr)||('\0'==*psstr) )
    {
        return THREAD_FAILED;
    }

    if ( 2>strlen(psstr) )
    {
        return THREAD_FAILED;
    }

    // skin "0x"
    if ( (2<=strlen(psstr))&&(('x'==*(psstr+1))||('X'==*(psstr+1))) )
    {
        if ( '0'!=*psstr )
        {
            return THREAD_FAILED;
        }
        psstr += 2;
    }

    if ( '\0'==*psstr )
    {
        return THREAD_FAILED;
    }

    while ( '\0'!=*psstr )
    {
        if ( ((0x30<=(*psstr))&&
              (0x39>=(*psstr)))||
             ((0x41<=(*psstr))&&
              (0x46>=(*psstr)))||
             ((0x61<=(*psstr))&&
              (0x66>=(*psstr))) )
        {
            psstr++;
        }
        else
        {
            return THREAD_FAILED;
        }
    }
    return THREAD_OK;
}

int32_t CUtils::IsFloatString(const char* psstr)
{
    if ( (!psstr)||('\0'==*psstr) )
    {
        return THREAD_FAILED;
    }

    char* p = const_cast<char*>(strchr(psstr, '.'));
    if ( (!p)||(psstr==p) )
    {
        return THREAD_FAILED;
    }

    // first part
    while ( p!=psstr )
    {
        if ( (0x30>(*psstr))||
             (0x39<(*psstr))  )
        {
            return THREAD_FAILED;
        }
        psstr++;
    }

    // skin '.'
    psstr++;

    if ( '\0'==*psstr )
    {
        return THREAD_FAILED;
    }

    // second part
    while ( '\0'!=*psstr )
    {
        if ( (0x30>(*psstr))||
             (0x39<(*psstr))  )
        {
            return THREAD_FAILED;
        }
        psstr++;
    }
    return THREAD_OK;
}

uint32_t CUtils::GetCurrentThreadId()
{
#ifdef _THREAD_OS_WIN_ // for windows impletement
    return static_cast<uint32_t>(::GetCurrentThreadId());
#elif defined(_THREAD_OS_LINUX_)
    return static_cast<uint32_t>(syscall(__NR_gettid));
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::MkDir(const char *pathname, int32_t mode)
{
#ifdef _THREAD_OS_WIN_ // for windows impletement
    mode = 0;
    if ( 0!=mkdir(pathname) )
    {
        return THREAD_FAILED;
    }
    return THREAD_OK;
#elif defined(_THREAD_OS_LINUX_)
    if ( 0!=mkdir(pathname, mode) )
    {
        return THREAD_FAILED;
    }
    return THREAD_OK;
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::Chmod(const char *pathname, int32_t mode)
{
#ifdef _THREAD_OS_WIN_ // for windows impletement
    // do nothing
    mode = 0;
    return THREAD_OK;
#elif defined(_THREAD_OS_LINUX_)
    if ( 0!=chmod(pathname, mode) )
    {
        return THREAD_FAILED;
    }
    return THREAD_OK;
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::GetSystemTime(SYSTEM_TIME* const pSystemtime)
{
    if ( !pSystemtime )
    {
        return THREAD_FAILED;
    }
    memset(pSystemtime, 0, sizeof(SYSTEM_TIME));

#if defined(_THREAD_OS_WIN_)
        // get local time
        SYSTEMTIME timenow;
        ::GetLocalTime(&timenow);

        // fill in
        pSystemtime->usYear = timenow.wYear;
        pSystemtime->usMonth = timenow.wMonth;
        pSystemtime->usDayOfWeek = timenow.wDayOfWeek;
        pSystemtime->usDay = timenow.wDay;
        pSystemtime->usHour = timenow.wHour;
        pSystemtime->usMinute = timenow.wMinute;
        pSystemtime->usSecond = timenow.wSecond;
        pSystemtime->usMilliseconds = timenow.wMilliseconds;
        return THREAD_OK;
#elif defined(_THREAD_OS_LINUX_)
        // get local time
        struct timeval tv;
        struct tm *timenow;

        gettimeofday(&tv, NULL);
        timenow = localtime((time_t*)&tv.tv_sec);
        if ( NULL==timenow )
        {
            return THREAD_FAILED;
        }

        // fill in
        pSystemtime->usYear = timenow->tm_year + 1900;
        pSystemtime->usMonth = timenow->tm_mon + 1;
        pSystemtime->usDayOfWeek = timenow->tm_wday;
        pSystemtime->usDay = timenow->tm_mday;
        pSystemtime->usHour = timenow->tm_hour;
        pSystemtime->usMinute = timenow->tm_min;
        pSystemtime->usSecond = timenow->tm_sec;
        pSystemtime->usMilliseconds = tv.tv_usec/1000;
        return THREAD_OK;
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::GetSystemUTCTime(SYSTEM_TIME* const pSystemtime)
{
    if ( !pSystemtime )
    {
        return THREAD_FAILED;
    }
    memset(pSystemtime, 0, sizeof(SYSTEM_TIME));

#if defined(_THREAD_OS_WIN_)
        // get UTC time
        SYSTEMTIME timenow;
        ::GetSystemTime(&timenow);

        // fill in
        pSystemtime->usYear = timenow.wYear;
        pSystemtime->usMonth = timenow.wMonth;
        pSystemtime->usDayOfWeek = timenow.wDayOfWeek;
        pSystemtime->usDay = timenow.wDay;
        pSystemtime->usHour = timenow.wHour;
        pSystemtime->usMinute = timenow.wMinute;
        pSystemtime->usSecond = timenow.wSecond;
        pSystemtime->usMilliseconds = timenow.wMilliseconds;
        return THREAD_OK;
#elif defined(_THREAD_OS_LINUX_)
        // get UTC time
        struct timeval tv;
        struct tm *timenow;

        gettimeofday(&tv, NULL);
        timenow = gmtime((time_t*)&tv.tv_sec);
        if ( NULL==timenow )
        {
            return THREAD_FAILED;
        }

        // fill in
        pSystemtime->usYear = timenow->tm_year + 1900;
        pSystemtime->usMonth = timenow->tm_mon + 1;
        pSystemtime->usDayOfWeek = timenow->tm_wday;
        pSystemtime->usDay = timenow->tm_mday;
        pSystemtime->usHour = timenow->tm_hour;
        pSystemtime->usMinute = timenow->tm_min;
        pSystemtime->usSecond = timenow->tm_sec;
        pSystemtime->usMilliseconds = tv.tv_usec/1000;
        return THREAD_OK;
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::StrNCaseCmp(const char* s1, const char* s2, uint32_t n)
{
#ifdef _THREAD_OS_WIN_ // for windows impletement
    return strnicmp(s1, s2, n);
#elif defined(_THREAD_OS_LINUX_)
    return strncasecmp(s1, s2, n);
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::StrCaseCmp(const char* s1, const char* s2)
{
#ifdef _THREAD_OS_WIN_ // for windows impletement
    return stricmp(s1, s2);
#elif defined(_THREAD_OS_LINUX_)
    return strcasecmp(s1, s2);
#else
#error "Unsupported OS!"
#endif
}

int32_t CUtils::ExecuteSystemCommand(const char* strSystemCommand)
{
    if ( !strSystemCommand )
    {
        return THREAD_FAILED;
    }

    uint32_t uiDataLen = static_cast<uint32_t>(strlen(strSystemCommand));
    if ( 0==uiDataLen )
    {
        return THREAD_FAILED;
    }

#ifdef _THREAD_OS_WIN_ // for windows impletement
    //system(strSystemCommand);
    return THREAD_OK;
#elif defined(_THREAD_OS_LINUX_)
    char* pcDataBuffer = static_cast<char*>(malloc(sizeof(char)*uiDataLen));
    if ( !pcDataBuffer )
    {
        return THREAD_FAILED;
    }
    memset(pcDataBuffer, 0, uiDataLen);
    memcpy(pcDataBuffer, strSystemCommand, uiDataLen);

    char* pcTokenString = NULL;
    uint32_t uiStringLen = 0;
    const int32_t MAX_PARAM_NUM = 16;
    int32_t iParamNum = 0;
    char *argv_list[MAX_PARAM_NUM+1] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    // parse the parameters
    while( 0<uiDataLen )
    {
        if ( MAX_PARAM_NUM<=iParamNum )
        {
            return THREAD_FAILED;
        }

        // get section
        if( THREAD_OK!=CUtils::GetTokenString(&pcDataBuffer, &uiDataLen,' ', &pcTokenString, &uiStringLen) )
        {
            // last parameter
            *(pcDataBuffer+uiDataLen) = '\0';
            argv_list[iParamNum] = pcDataBuffer;
            iParamNum++;
            break;
        }

        // if NULL
        if ( 0==uiStringLen )
        {
            continue;
        }

        // parameter
        *(pcTokenString+uiStringLen) = '\0';
        argv_list[iParamNum] = pcTokenString;
        iParamNum++;
    }

    // execute
    pid_t child_pid;
    int child_status;

    child_pid = fork ();
    if (child_pid != 0)
    {
        waitpid(child_pid, &child_status, 0);
        return THREAD_OK;
    }
    else
    {
        execvp (argv_list[0], argv_list);
        abort ();
    }

#else
#error "Unsupported OS!"
#endif
}

long CUtils::GetFileLength(const char* strFilePathName)
{
    if ( !strFilePathName )
    {
        return -1;
    }

    FILE* fp;
    fp = fopen(strFilePathName,"rb");
    if ( NULL==fp )
    {
        return -1;
    }
    fseek(fp,0,SEEK_END);
    long longBytes = ftell(fp);
    if ( 0>longBytes )
    {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return static_cast<uint32_t>(longBytes);
}

int32_t CUtils::GetFileContent(const char* strFilePathName, const uint32_t uiStartPos, unsigned char* pBufferData, const uint32_t uiBufferDataLen, uint32_t& uiDataLen)
{
    if ( (!strFilePathName)||(!pBufferData) )
    {
        return THREAD_FAILED;
    }

    long lFileLen = CUtils::GetFileLength(strFilePathName);
    if ( 0>=lFileLen )
    {
        return THREAD_FAILED;
    }
    uint32_t uiFileLen = static_cast<uint32_t>(lFileLen);
    if ( uiFileLen<=uiStartPos )
    {
        return THREAD_FAILED;
    }
    uiDataLen = uiFileLen-uiStartPos;
    if ( uiBufferDataLen<uiDataLen )
    {
        uiDataLen = uiBufferDataLen;
    }

    FILE* fp;
    fp = fopen(strFilePathName,"rb");
    if ( NULL==fp )
    {
        return THREAD_FAILED;
    }

    fseek(fp, uiStartPos, SEEK_SET);
    if ( uiDataLen!=fread(pBufferData , 1, uiDataLen, fp) )
    {
#ifdef _THREAD_OS_WIN_ // for windows impletement
#elif defined(_THREAD_OS_LINUX_)
#else
#error "Unsupported OS!"
#endif
        fclose(fp);
        return THREAD_FAILED;
    }
    fclose(fp);
    return THREAD_OK;
}

int32_t CUtils::CheckTimeValid(const uint32_t uiTime)
{
    uint16_t usTmp = static_cast<uint16_t>(((uiTime)>>16)&0xFFFF);
    if ( (2010>usTmp)||(usTmp>9999) )
    {
        return THREAD_FAILED;
    }
    usTmp = static_cast<uint8_t>(((uiTime)>>8)&0xFF);
    if ( (1>usTmp)||(usTmp>12) )
    {
        return THREAD_FAILED;
    }
    usTmp = static_cast<uint8_t>(uiTime&0xFF);
    if ( (1>usTmp)||(usTmp>31) )
    {
        return THREAD_FAILED;
    }
    return THREAD_OK;
}

unsigned short CUtils::CheckSumCalculate(const unsigned char* pucData, unsigned int uiDataLen)
{
    unsigned long ulSum;

    if((NULL == pucData) || (0 == uiDataLen))
    {
        return 0xffff;
    }

    ulSum = 0;
    while( uiDataLen > 1 )
    {
        // This is the inner loop
        ulSum += ((*pucData << 8) | (*(pucData + 1)));
        pucData += 2;
        uiDataLen -= 2;
    }
    //  Add left-over byte, if any
    if( uiDataLen > 0 )
    {
        ulSum += ((* pucData) << 8);
    }
    //  Fold 32-bit sum to 16 bits
    while ( (ulSum >> 16) > 0 )
    {
        ulSum = (ulSum & 0xffff) + (ulSum >> 16);
    }

    return static_cast<unsigned short>(~(ulSum&0xffff));
}

int32_t CUtils::BufHexToString(const unsigned char * const pucHexBuf,const uint32_t uiHexBufLength,unsigned char * pucStringBuf,const uint32_t uiStringBufLength)
{
    if ( (!pucHexBuf) || (!pucStringBuf) || (0 >= uiHexBufLength) || (255 <= uiHexBufLength)|| ( 2*uiHexBufLength > uiStringBufLength) )
    {
        return  THREAD_FAILED;
    }

    for (uint32_t uiLoop = 0; uiLoop<uiHexBufLength; uiLoop++)
    {
        unsigned char uiHigh = ((*(pucHexBuf+uiLoop))&0x0F);
        unsigned char uiLow = (((*(pucHexBuf+uiLoop))>>4)&0x0F);
        // low
        if (( 0 <= uiLow ) && ( 9 >= uiLow ))
        {
            *(pucStringBuf+2*uiLoop) = uiLow + 48;// '0' = 48
        }
        else if (( 10 <= uiLow ) && ( 15 >= uiLow ))
        {
            *(pucStringBuf+2*uiLoop) = uiLow + 55;// 'A' =65
        }
        else
        {
            return  THREAD_FAILED;
        }

        // high
        if (( 0 <= uiHigh ) && ( 9 >= uiHigh ))
        {
            *(pucStringBuf+2*uiLoop+1) = uiHigh + 48;
        }
        else if (( 10 <= uiHigh ) && ( 15 >= uiHigh ))
        {
            *(pucStringBuf+2*uiLoop+1) = uiHigh + 55;// 'A' =65
        }
        else
        {
            return  THREAD_FAILED;
        }
    }

    return THREAD_OK;
}

int32_t CUtils::BufStringToHex(const unsigned char * const pucStringBuf,const uint32_t uiStringBufLength,unsigned char * pucHexBuf,const uint32_t uiHexBufLength)
{
    if ( (!pucHexBuf) || (!pucStringBuf) || (uiStringBufLength > 2*uiHexBufLength) )
    {
        return  THREAD_FAILED;
    }

    if ( uiStringBufLength%2 )
    {
        return  THREAD_FAILED;
    }

    unsigned char uiTemp = 0;
    for (uint32_t uiLoop = 0; uiLoop < (uiStringBufLength>>1);uiLoop++)
    {
        unsigned char uiHigh = *(pucStringBuf+2*uiLoop);
        unsigned char uiLow = *(pucStringBuf+2*uiLoop+1);
        if ( (48<=uiLow) && (57>=uiLow))
        {
            uiLow -= 48;// '0'~'9'

        }
        else if ( (65<=uiLow) && (70>=uiLow))
        {
            uiLow -= 55;// 'A'~'F'
        }
        else
        {
            return  THREAD_FAILED;
        }

        if ( (48<=uiHigh) && (57>=uiHigh))
        {
            uiHigh -= 48;// '0'~'9'

        }
        else if ( (65<=uiHigh) && (70>=uiHigh))
        {
            uiHigh -= 55;// 'A'~'F'
        }
        else
        {
            return  THREAD_FAILED;
        }
        uiTemp = (uiLow&0x0F) + ((uiHigh&0x0F)<<4);
        *(pucHexBuf+uiLoop) = uiTemp;
    }

    return THREAD_OK;
}

}  // namespace
