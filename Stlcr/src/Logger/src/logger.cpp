//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    dss_logger.cpp
///  \brief   implement logger
///
///  \version 1.0
///  \date    Jan. 01, 2017
//////////////////////////////////////////////////////////////////////////

#include <stdarg.h>
#include <string.h>

#include "Logger/logger_return_code.h"
#include "UtilsBox/utilsbox_utils.h"
#include "Logger/logger.h"

#ifdef LOGGER_LOG

#if defined(LOGGER_OUTPUT_FILE)||defined(LOGGER_OUTPUT_TERM)

// namespace
namespace logger {

CLogger* CLogger::m_pInstance = NULL;

CLogger* CLogger::GetInstance()
{
    if( NULL == m_pInstance )
    {
        m_pInstance = ( new CLogger() );
    }
    return m_pInstance;
}

CLogger::CLogger() : m_MutexLoggerSwitch(), m_MutexLoggerFile(), m_bCreateLogDir(false)
{
    memset(m_strMyName, 0, sizeof(m_strMyName));
    sprintf(m_strMyName, "Default");
    memset(m_acLogFilePathName, 0, sizeof(m_acLogFilePathName));
    memset(m_acLogDirPathName, 0, sizeof(m_acLogDirPathName));
    for (int i=0;i<static_cast<int>(LOG_LEVEL_NUM);i++)
    {
        m_aiLogSwitch[i] = LOGGER_FAILED;
    }

    // error switch must open
    m_aiLogSwitch[LOG_LEVEL_DEV_ERROR] = LOGGER_OK;
}

CLogger::~CLogger()
{
    m_pInstance = NULL;
}

int32_t CLogger::Initialize(const char* const pstrMyName)
{
    // set name
    if ( pstrMyName )
    {
        snprintf(m_strMyName, sizeof(m_strMyName), pstrMyName);
    }
    sprintf(m_acLogDirPathName, "./log");
    return LOGGER_OK;
}

void CLogger::CreateLogDir()
{
    if ( !m_bCreateLogDir )
    {
        if ( LOGGER_OK!=utilsbox::CUtils::MkDir(m_acLogDirPathName, 0755) )
        {
            //LOGGER_PRINTF("ERROR: [%s:%d] Create Dir(%s) Failed!\r\n", __FILE__, __LINE__, m_acLogDirPathName);
        }
        else
        {
            //LOGGER_PRINTF("ERROR: [%s:%d] Create Dir(%s) Successfully!\r\n", __FILE__, __LINE__, m_acLogDirPathName);
        }
        m_bCreateLogDir = true;
    }
}

int32_t CLogger::GetLogFileName()
{
    FILE   *fp = NULL;
    unsigned char ucNeedCreate;
    long lFileLen;

    ucNeedCreate = 0;
    if ( '\0'==m_acLogFilePathName[0] )
    {
        ucNeedCreate = 1;
    }
    else
    {
        fp = fopen(m_acLogFilePathName , "rb");
        if ( NULL==fp )
        {
            ucNeedCreate = 1;
        }
        else
        {
            fseek(fp,0,SEEK_END);
            lFileLen = ftell(fp);
            fclose(fp);
            if ( 0>lFileLen )
            {
                ucNeedCreate = 1;
            }
            else
            {
                if ( (10485760)<lFileLen )//  10M×Ö½Ú
                {
                    ucNeedCreate = 1;
                }
            }
        }
    }

    if ( 1==ucNeedCreate )
    {
        // get local time
        utilsbox::SYSTEM_TIME systemtime;
        if ( LOGGER_OK!=utilsbox::CUtils::GetSystemTime(&systemtime) )
        {
            LOGGER_PRINTF("ERROR: [%s:%d] GetSystemTime Failed!\r\n", __FILE__, __LINE__);
            return LOGGER_FAILED;
        }

        sprintf(m_acLogFilePathName , "%s/log_%s_%.4d%.2d%.2d_%.2d%.2d%.2d_%.3u.txt",
                     m_acLogDirPathName, m_strMyName, systemtime.usYear, systemtime.usMonth, systemtime.usDay,
                     systemtime.usHour, systemtime.usMinute, systemtime.usSecond, systemtime.usMilliseconds);

        // create file
        FILE* fp = fopen(m_acLogFilePathName , "a");
        if ( NULL==fp )
        {
            LOGGER_PRINTF("ERROR: [%s:%d] Create File(%s) Failed!\r\n", __FILE__, __LINE__, m_acLogFilePathName);
            return LOGGER_FAILED;
        }
        fclose(fp);

        // change mode
        if ( LOGGER_OK!=utilsbox::CUtils::Chmod(m_acLogFilePathName,0755) )
        {
            LOGGER_PRINTF("ERROR: [%s:%d] Chmod File(%s) Failed!\r\n", __FILE__, __LINE__, m_acLogFilePathName);
            return LOGGER_FAILED;
        }
    }
    return LOGGER_OK;
}

void CLogger::WriteFile(const char* const pcLogInfo, int iLogInfoLen)
{
    if ( (!pcLogInfo)||(0==iLogInfoLen) )
    {
        LOGGER_PRINTF("ERROR: [%s:%d] LogFile Failed!\r\n", __FILE__, __LINE__);
        return;
    }

    // lock
    m_MutexLoggerFile.Lock();

    // try to create dir
    CreateLogDir();

    // get file name
    if ( LOGGER_OK!=GetLogFileName() )
    {
        // unlock
        m_MutexLoggerFile.UnLock();
        return ;
    }

    FILE* fp = fopen(m_acLogFilePathName , "a");
    if ( NULL==fp )
    {
        // unlock
        m_MutexLoggerFile.UnLock();
        return ;
    }

    fwrite(pcLogInfo , static_cast<uint32_t>(iLogInfoLen) , 1 , fp);
    fclose(fp);

    // unlock
    m_MutexLoggerFile.UnLock();
    return;
}

const char* CLogger::GetLogLevelName(const int iLevel) const
{
    switch (static_cast<LOG_LEVEL>(iLevel))
    {
        case LOG_LEVEL_TRACE:
            return "TRACE";
        case LOG_LEVEL_DEBUG:
            return "DEBUG";
        case LOG_LEVEL_DEV_WARN:
            return "WARN";
        case LOG_LEVEL_DEV_ERROR:
            return "ERROR";
        case LOG_LEVEL_TRACE_INFO:
        case LOG_LEVEL_DEV_INFO:
            return "INFO";
        default:
            return "UNKNOWN";
    }
}

int CLogger::CanLog(const int iLevel)
{
    if ( LOG_LEVEL_NUM<=static_cast<LOG_LEVEL>(iLevel) )
    {
        return LOGGER_FAILED;
    }

    // lock
    m_MutexLoggerSwitch.Lock();

    const int iLogSwitch = m_aiLogSwitch[iLevel];

    // unlock
    m_MutexLoggerSwitch.UnLock();
    return iLogSwitch;
}

void CLogger::SetLogSwitch(const int iLevel, const int iLogSwitch)
{
    if ( LOG_LEVEL_NUM<=static_cast<LOG_LEVEL>(iLevel) )
    {
        return ;
    }

    // lock
    m_MutexLoggerSwitch.Lock();

    m_aiLogSwitch[iLevel] = iLogSwitch;

    // unlock
    m_MutexLoggerSwitch.UnLock();
    LOGGER_PRINTF("Log %s %s.\r\n", GetLogLevelName(iLevel), LOGGER_OK==iLogSwitch?"Open":"Close");
}

void CLogger::ShowLogSwitchState()
{
    // lock
    m_MutexLoggerSwitch.Lock();

    for (int i=0;i<static_cast<int>(LOG_LEVEL_NUM);i++)
    {
        LOGGER_PRINTF("Log %s %s.\r\n", GetLogLevelName(i), LOGGER_OK==m_aiLogSwitch[i]?"Open":"Close");
    }

    // unlock
    m_MutexLoggerSwitch.UnLock();
}

void CLogger::LogTerm(const int iLevel, const char* const pFileName, const int iLineNum, const char * pcFormat,...)
{
   char acLogInfoBuf[2048+1];
    va_list arg;

    if ( !pFileName )
    {
        LOGGER_PRINTF("ERROR: [%s:%d] LogTerm Failed!\r\n", __FILE__, __LINE__);
        return ;
    }

    // can log
    if ( LOGGER_OK!=CanLog(iLevel) )
    {
        return ;
    }

    memset(acLogInfoBuf, 0, sizeof(acLogInfoBuf));
    int iLogInfoLen = 0;

    // get local time
    utilsbox::SYSTEM_TIME systemtime;
    if ( LOGGER_OK!=utilsbox::CUtils::GetSystemTime(&systemtime) )
    {
        LOGGER_PRINTF("ERROR: [%s:%d] GetSystemTime Failed!\r\n", __FILE__, __LINE__);
        return ;
    }

    iLogInfoLen = sprintf(acLogInfoBuf , "%s: [%.4d.%.2d.%.2d %.2d:%.2d:%.2d.%.3u] [%s:%d] ",
                            GetLogLevelName(iLevel), systemtime.usYear, systemtime.usMonth, systemtime.usDay,
                            systemtime.usHour, systemtime.usMinute, systemtime.usSecond, systemtime.usMilliseconds,
                            pFileName, iLineNum);

    // check
    if ( (0>=iLogInfoLen)||
         ((sizeof(acLogInfoBuf)-3)<=static_cast<uint32_t>(iLogInfoLen)) )
    {
        LOGGER_PRINTF("ERROR: [%s:%d] LogTerm Failed!\r\n", __FILE__, __LINE__);
        return ;
    }

    va_start(arg, pcFormat);
    iLogInfoLen += vsnprintf(acLogInfoBuf+iLogInfoLen, (sizeof(acLogInfoBuf)-iLogInfoLen)-3, pcFormat, arg);
    va_end(arg);

    acLogInfoBuf[iLogInfoLen] = '\r';
    acLogInfoBuf[iLogInfoLen+1] = '\n';
    acLogInfoBuf[iLogInfoLen+2] = '\0';

    // log
    LOGGER_PRINTF(acLogInfoBuf);
    return;
}

void CLogger::LogFile(const int iLevel, const char* const pFileName, const int iLineNum, const char * pcFormat,...)
{
    char acLogInfoBuf[2048+1];
    va_list arg;

    if ( !pFileName )
    {
        LOGGER_PRINTF("ERROR: [%s:%d] LogFile Failed!\r\n", __FILE__, __LINE__);
        return ;
    }

    // can log
    if ( LOGGER_OK!=CanLog(iLevel) )
    {
        return ;
    }

    memset(acLogInfoBuf, 0, sizeof(acLogInfoBuf));
    int iLogInfoLen = 0;

    // get local time
    utilsbox::SYSTEM_TIME systemtime;
    if ( LOGGER_OK!=utilsbox::CUtils::GetSystemTime(&systemtime) )
    {
        LOGGER_PRINTF("ERROR: [%s:%d] GetSystemTime Failed!\r\n", __FILE__, __LINE__);
        return ;
    }

    iLogInfoLen = sprintf(acLogInfoBuf , "%s: [%.4d.%.2d.%.2d %.2d:%.2d:%.2d.%.3u] [%s:%d] ",
                            GetLogLevelName(iLevel), systemtime.usYear, systemtime.usMonth, systemtime.usDay,
                            systemtime.usHour, systemtime.usMinute, systemtime.usSecond, systemtime.usMilliseconds,
                            pFileName, iLineNum);

    // check
    if ( (0>=iLogInfoLen)||
         ((sizeof(acLogInfoBuf)-3)<=static_cast<uint32_t>(iLogInfoLen)) )
    {
        LOGGER_PRINTF("ERROR: [%s:%d] LogTerm Failed!\r\n", __FILE__, __LINE__);
        return ;
    }

    va_start(arg, pcFormat);
    iLogInfoLen += vsnprintf(acLogInfoBuf+iLogInfoLen, (sizeof(acLogInfoBuf)-iLogInfoLen)-3, pcFormat, arg);
    va_end(arg);

    acLogInfoBuf[iLogInfoLen] = '\r';
    acLogInfoBuf[iLogInfoLen+1] = '\n';
    acLogInfoBuf[iLogInfoLen+2] = '\0';
    iLogInfoLen += 2;

    // log file
    WriteFile(acLogInfoBuf, iLogInfoLen);
    return;
}

}  // namespace

#endif

#endif

