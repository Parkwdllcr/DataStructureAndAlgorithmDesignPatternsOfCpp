//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    utilsbox_utils.h
///  \brief   define common utility
///
///  \version 1.0
///  \date    Aug. 20, 2014
//////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdint.h>
#include "thread_os_define.h"

namespace Util
{
#define THREAD_OK 1
#define THREAD_FAILED 0

	typedef struct
	{
		uint16_t usYear;     // absolute year
		uint16_t usMonth;    // absolute month
		uint16_t usDayOfWeek;// week, 0 - sunday, 1 - monday, etc..
		uint16_t usDay;      // day
		uint16_t usHour;     // hour ( 0 - 23 )
		uint16_t usMinute;   // minute ( 0 - 59 )
		uint16_t usSecond;   // second ( 0 - 59 )
		uint16_t usMilliseconds; // millisecond ( 0 - 999 )
	}SYSTEM_TIME;

	/// \class CUtils utilsbox_utils.h
	/// \brief Implement CUtils


	class CUtils
	{

	public:
		CUtils();
		~CUtils();

		static unsigned long GetCurrentTimes();
		static void GetCurrentTimes(unsigned long& ulSec, unsigned long& ulUSec);
		static int32_t GetSystemTime(SYSTEM_TIME* const pSystemtime);
		static int32_t GetSystemUTCTime(SYSTEM_TIME* const pSystemtime);

		static void MSleep(unsigned long mseconds);

		static int32_t GetInputParameter(const unsigned short pno, const char* psstr, char* pdstr, const unsigned short dstrmaxlen);
		static int32_t GetTokenString(char** ppcSipMsgBuf, uint32_t* puiDataLen, const char chSeparator, char** ppcTokenString, uint32_t* puiStringLen);

		static int CheckCPUEndian();

		static int32_t IsDigitString(const char* psstr);
		static int32_t IsHexString(const char* psstr);
		static int32_t IsFloatString(const char* psstr);

		static uint32_t GetCurrentThreadId();

		//static int32_t MkDir(const char *pathname, int32_t mode);
		static int32_t Chmod(const char* pathname, int32_t mode);

		static int32_t StrNCaseCmp(const char* s1, const char* s2, uint32_t n);
		//static int32_t StrCaseCmp(const char *s1, const char *s2);

		static int32_t ExecuteSystemCommand(const char* strSystemCommand);

		// static long GetFileLength(const char* strFilePathName);
		 //static int32_t GetFileContent(const char* strFilePathName, const uint32_t uiStartPos, unsigned char* pBufferData, const uint32_t uiBufferDataLen, uint32_t& uiDataLen);

		static int32_t CheckTimeValid(const uint32_t uiTime);

		static unsigned short CheckSumCalculate(const unsigned char* pucData, unsigned int uiDataLen);

		static int32_t BufHexToString(const unsigned char* const pucHexBuf, const uint32_t uiHexBufLength, unsigned char* pucStringBuf, const uint32_t uiStringBufLength);
		static int32_t BufStringToHex(const unsigned char* const pucStringBuf, const uint32_t uiStringBufLength, unsigned char* pucHexBuf, const uint32_t uiHexBufLength);

	};

	// get rid of left space
#define THREAD_StrTrimLeftSpace(Macro_Input_Str,  Macro_Input_Len) \
{   \
    const char* pcMacroInnerTmpStr = (Macro_Input_Str); \
    if ( 0!=(Macro_Input_Len) ) \
    { \
        while ( Macro_Input_Len ) \
        { \
            if ( ' '==*pcMacroInnerTmpStr++ ) \
            { \
                (Macro_Input_Str)++; \
                (Macro_Input_Len)--; \
            } \
            else \
            { \
                break; \
            } \
        } \
    } \
}

// get rid of left and right space
#define THREAD_StrTrimSpace(Macro_Input_Str,  Macro_Input_Len) \
{   \
    const char* pcMacroInnerTmpStr = (Macro_Input_Str); \
    if ( 0!=(Macro_Input_Len) ) \
    { \
        while ( Macro_Input_Len ) \
        { \
            if ( ' '==*pcMacroInnerTmpStr++ ) \
            { \
                (Macro_Input_Str)++; \
                (Macro_Input_Len)--; \
            } \
            else \
            { \
                break; \
            } \
        } \
        if ( 0!=(Macro_Input_Len) ) \
        { \
            pcMacroInnerTmpStr = (Macro_Input_Str)+(Macro_Input_Len-1); \
            while ( Macro_Input_Len ) \
            { \
                if ( ' '==*pcMacroInnerTmpStr-- ) \
                { \
                    (Macro_Input_Len)--; \
                } \
                else \
                { \
                    break; \
                } \
            } \
        } \
    } \
}

// define threa trap, if time up, will log a message in order to indicate itself running normally
#define UTILSBOX_THREAD_TRAP
#ifdef UTILSBOX_THREAD_TRAP
#define UTILSBOX_THREAD_TRAP_INTERVAL 120000     // milliseconds

#define UTILSBOX_THREAD_TRAP_PREPARE(PRINTF, strActorName) \
\
    PRINTF("Thread Actor '%s_%u' Begin Normally!", strActorName, utilsbox::CUtils::GetCurrentThreadId()); \
	unsigned long ulCurTime = utilsbox::CUtils::GetCurrentTimes();\
	unsigned long ulLastTime = ulCurTime;

#define UTILSBOX_THREAD_TRAP_RUN(PRINTF, strActorName, ulInterval) \
\
    ulCurTime = utilsbox::CUtils::GetCurrentTimes(); \
    if ( ulLastTime<=ulCurTime ) \
    { \
        if ( ulInterval<=(ulCurTime-ulLastTime) ) \
        { \
            PRINTF("Thread Actor '%s_%u' Running Normally!", strActorName, utilsbox::CUtils::GetCurrentThreadId()); \
            ulLastTime = ulCurTime; \
        } \
    } \
    else \
    { \
        ulLastTime = ulCurTime; \
    }
#define UTILSBOX_THREAD_TRAP_FINISH(PRINTF, strActorName) \
    \
    PRINTF("Thread Actor '%s_%u' Exit Normally!", strActorName, utilsbox::CUtils::GetCurrentThreadId());
#else
#define UTILSBOX_THREAD_TRAP_PREPARE()
#define UTILSBOX_THREAD_TRAP_RUN()
#define UTILSBOX_THREAD_TRAP_FINISH()
#endif

// define threa trap
#define UTILSBOX_TIME_ESCAPE
#ifdef UTILSBOX_TIME_ESCAPE
#define UTILSBOX_MAX_TIME_ESCAPE_LEN 1000

#define UTILSBOX_TIME_ESCAPE_BEGIN() \
\
	unsigned long ulCurTime = utilsbox::CUtils::GetCurrentTimes();

#define UTILSBOX_TIME_ESCAPE_END(PRINTF, ulInterval) \
\
    unsigned long ulLastTime = utilsbox::CUtils::GetCurrentTimes(); \
    if ( ulCurTime<=ulLastTime ) \
    { \
        unsigned long ulTimeLen = ulLastTime - ulCurTime; \
        if ( ulInterval<=ulTimeLen ) \
        { \
            PRINTF("TimeEscape Overflow ---->  %lu ms.", ulTimeLen); \
        } \
    }
#else
#define UTILSBOX_TIME_ESCAPE_BEGIN()
#define UTILSBOX_TIME_ESCAPE_END()
#endif

// define host/network bytes convertion
#define UTILSBOX_BigLittleSwap16(x) static_cast<unsigned short>((((x)>>8) & 0xff) | (((x) & 0xff)<<8))
#define UTILSBOX_BigLittleSwap32(x) ((((x) & 0xff) << 24) | (((x) >> 24) & 0xff) | (((x) & 0xff0000) >> 8) | (((x) & 0xff00) << 8))

#define UTILSBOX_htons(x) (utilsbox::CUtils::CheckCPUEndian()?(x):UTILSBOX_BigLittleSwap16(x))
#define UTILSBOX_ntohs(x) UTILSBOX_htons(x)
#define UTILSBOX_htonl(x) (utilsbox::CUtils::CheckCPUEndian()?(x):UTILSBOX_BigLittleSwap32(x))
#define UTILSBOX_ntohl(x) UTILSBOX_htonl(x)
}







