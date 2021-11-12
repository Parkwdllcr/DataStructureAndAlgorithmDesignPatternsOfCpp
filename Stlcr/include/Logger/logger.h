//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    logger_logger.h
///  \brief   define the logger
///
///  \version 1.0
///  \date    Jan. 01, 2017
//////////////////////////////////////////////////////////////////////////

#ifndef __LOGGER_LOGGER_H__
#define __LOGGER_LOGGER_H__

#ifndef LOGGER_LOG
#define LOGGER_LOG
#endif

#ifdef LOGGER_LOG

#include <stdio.h>

#include "Logger/logger_os_type.h"

// close some warning
#ifdef _LOGGER_OS_WIN_ // for windows impletement
#pragma warning(disable:4251)
#pragma warning(disable:4996)
#pragma warning(disable:4127)
#endif

// logger macro
#define LOGGER_OUTPUT_FILE
//#define LOGGER_OUTPUT_TERM

// namespace
namespace logger {

// define log level
enum LOG_LEVEL
{
    LOG_LEVEL_TRACE  = 0,
    LOG_LEVEL_DEBUG  = 1,
    LOG_LEVEL_DEV_WARN   = 2,
    LOG_LEVEL_DEV_ERROR  = 3,
    LOG_LEVEL_TRACE_INFO   = 4,
    LOG_LEVEL_DEV_INFO   = 5,

    LOG_LEVEL_NUM
};

}  // namespace

#if defined(LOGGER_OUTPUT_FILE)||defined(LOGGER_OUTPUT_TERM)
#include "UtilsBox/utilsbox_mutex.h"

// namespace
namespace logger {

/// \class CLogger CLogger.h
/// \brief define the logger
class LOGGER_EXPORT CLogger
{

public:
    virtual ~CLogger();
    static CLogger* GetInstance();
    int32_t Initialize(const char* const pstrMyName);
    void SetLogSwitch(const int iLevel, const int iLogSwitch);
    void ShowLogSwitchState();
    void LogTerm(const int iLevel, const char* const pFileName, const int iLineNum, const char * pcFormat,...);
    void LogFile(const int iLevel, const char* const pFileName, const int iLineNum, const char * pcFormat,...);

protected:
    CLogger();

private:
    void CreateLogDir();
    int32_t GetLogFileName();
    void WriteFile(const char* const pcLogInfo, const int iLogInfoLen);
    const char* GetLogLevelName(const int iLevel)  const;
    int CanLog(const int iLevel);

private:
    static CLogger* m_pInstance;
    utilsbox::CMutex m_MutexLoggerSwitch;
    utilsbox::CMutex m_MutexLoggerFile;
    bool m_bCreateLogDir;
    char m_strMyName[64];
    char m_acLogFilePathName[256];
    char m_acLogDirPathName[256];
    int m_aiLogSwitch[LOG_LEVEL_NUM];

};

}  // namespace

#endif


#if defined(LOGGER_OUTPUT_FILE)&&defined(LOGGER_OUTPUT_TERM)
#define LOGGER_LOG_INITIAL(strLoggerName, strConfigFileName)    \
            {  \
            logger::CLogger::GetInstance()->Initialize(strLoggerName); \
          }

#define LOGGER_TRACE(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_TRACE), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_TRACE), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_DEBUG(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEBUG), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEBUG), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_WARN(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_ERROR(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_INFO(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }
#define LOGGER_DEV_INFO(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_MUNUAL(log_source, log_level, log_file_name, log_line, log_function_name, fmt, ...)

#elif defined(LOGGER_OUTPUT_FILE)
#define LOGGER_LOG_INITIAL(strLoggerName, strConfigFileName)    \
            {  \
            logger::CLogger::GetInstance()->Initialize(strLoggerName); \
          }

#define LOGGER_TRACE(fmt, ...)   logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_TRACE), __FILE__, __LINE__, fmt, ## __VA_ARGS__);
#define LOGGER_DEBUG(fmt, ...)   logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEBUG), __FILE__, __LINE__, fmt, ## __VA_ARGS__);
#define LOGGER_WARN(fmt, ...)    logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), __FILE__, __LINE__, fmt, ## __VA_ARGS__);
#define LOGGER_ERROR(fmt, ...)   logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), __FILE__, __LINE__, fmt, ## __VA_ARGS__);
#define LOGGER_INFO(fmt, ...)    logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__);
#define LOGGER_DEV_INFO(fmt, ...)    logger::CLogger::GetInstance()->LogFile(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__);
#define LOGGER_MUNUAL(log_source, log_level, log_file_name, log_line, log_function_name, fmt, ...)

#elif defined(LOGGER_OUTPUT_TERM)
#define LOGGER_LOG_INITIAL(strLoggerName, strConfigFileName)

#define LOGGER_TRACE(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_TRACE), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_DEBUG(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEBUG), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_WARN(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_ERROR(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_INFO(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }
#define LOGGER_DEV_INFO(fmt, ...)   \
            {  \
            logger::CLogger::GetInstance()->LogTerm(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), __FILE__, __LINE__, fmt, ## __VA_ARGS__); \
          }

#define LOGGER_MUNUAL(log_source, log_level, log_file_name, log_line, log_function_name, fmt, ...)


#else // output nothing
#define LOGGER_LOG_INITIAL(strLoggerName, strConfigFileName)

#define LOGGER_TRACE(fmt, ...)
#define LOGGER_DEBUG(fmt, ...)
#define LOGGER_WARN(fmt, ...)
#define LOGGER_ERROR(fmt, ...)
#define LOGGER_INFO(fmt, ...)
#define LOGGER_DEV_INFO(fmt, ...)
#define LOGGER_MUNUAL(log_source, log_level, log_file_name, log_line, log_function_name, fmt, ...)

#endif

// set log switch
#if defined(LOGGER_OUTPUT_CONTAINER_LOGGER)&&defined(LOGGER_OUTPUT_FILE)&&defined(LOGGER_OUTPUT_TERM)
#define LOGGER_SHOW_LOG_STATE()   \
            {  \
            logger::CLogger::GetInstance()->ShowLogSwitchState(); \
            logger::CContainerLogger::GetInstance()->ShowLogSwitchState(); \
          }

#define LOGGER_TRACE_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch); \
          }

#define LOGGER_DEBUG_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG), fLogSwitch); \
          }

#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch); \
          }

#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch); \
          }

#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch); \
          }
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch); \
          }

#elif defined(LOGGER_OUTPUT_CONTAINER_LOGGER)&&defined(LOGGER_OUTPUT_FILE)
#define LOGGER_SHOW_LOG_STATE()   \
            {  \
            logger::CLogger::GetInstance()->ShowLogSwitchState(); \
            logger::CContainerLogger::GetInstance()->ShowLogSwitchState(); \
          }

#define LOGGER_TRACE_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch); \
          }

#define LOGGER_DEBUG_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG), fLogSwitch); \
          }

#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch); \
          }

#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch); \
          }

#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch); \
          }
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch); \
          }

#elif defined(LOGGER_OUTPUT_CONTAINER_LOGGER)&&defined(LOGGER_OUTPUT_TERM)
#define LOGGER_SHOW_LOG_STATE()   \
            {  \
            logger::CLogger::GetInstance()->ShowLogSwitchState(); \
            logger::CContainerLogger::GetInstance()->ShowLogSwitchState(); \
          }

#define LOGGER_TRACE_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch); \
          }

#define LOGGER_DEBUG_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG), fLogSwitch); \
          }

#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch); \
          }

#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch); \
          }

#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch); \
          }
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)   \
            {  \
            logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch); \
            logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch); \
          }

#elif defined(LOGGER_OUTPUT_FILE)&&defined(LOGGER_OUTPUT_TERM)
#define LOGGER_SHOW_LOG_STATE()         logger::CLogger::GetInstance()->ShowLogSwitchState();
#define LOGGER_TRACE_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch);
#define LOGGER_DEBUG_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG),  fLogSwitch);
#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch);
#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch);
#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch);
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch);

#elif defined(LOGGER_OUTPUT_CONTAINER_LOGGER)
#define LOGGER_SHOW_LOG_STATE()         logger::CContainerLogger::GetInstance()->ShowLogSwitchState();
#define LOGGER_TRACE_SWITCH(fLogSwitch) logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch);
#define LOGGER_DEBUG_SWITCH(fLogSwitch) logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG),  fLogSwitch);
#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)  logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch);
#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch) logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch);
#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)  logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch);
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)  logger::CContainerLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch);

#elif defined(LOGGER_OUTPUT_FILE)
#define LOGGER_SHOW_LOG_STATE()         logger::CLogger::GetInstance()->ShowLogSwitchState();
#define LOGGER_TRACE_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch);
#define LOGGER_DEBUG_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG),  fLogSwitch);
#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch);
#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch);
#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch);
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch);

#elif defined(LOGGER_OUTPUT_TERM)
#define LOGGER_SHOW_LOG_STATE()         logger::CLogger::GetInstance()->ShowLogSwitchState();
#define LOGGER_TRACE_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE), fLogSwitch);
#define LOGGER_DEBUG_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEBUG),  fLogSwitch);
#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_WARN), fLogSwitch);
#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch) logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_ERROR), fLogSwitch);
#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_TRACE_INFO), fLogSwitch);
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)  logger::CLogger::GetInstance()->SetLogSwitch(static_cast<int>(logger::LOG_LEVEL_DEV_INFO), fLogSwitch);

#else // output nothing
#define LOGGER_SHOW_LOG_STATE()
#define LOGGER_TRACE_SWITCH(fLogSwitch)
#define LOGGER_DEBUG_SWITCH(fLogSwitch)
#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)
#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch)
#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)
#define LOGGER_DEV_INFO_SWITCH(fLogSwitch)
#endif

#define LOGGER_PRINTF(fmt, ...) printf(fmt, ## __VA_ARGS__)
#define LOGGER_PRINTFBUF(XBUF,XLEN) \
        { \
          for ( unsigned int i=0;i<XLEN;i++ ) { \
            if ( 0==i%16 ) \
            { \
                LOGGER_PRINTF("\r\n"); \
            } \
            LOGGER_PRINTF("%.2x ", XBUF[i]); \
          } \
          LOGGER_PRINTF("\r\n"); \
      }
#define LOGGER_PRINTFSTRING(XSTR,XLEN) \
        { \
          for ( unsigned int i=0;i<XLEN;i++ ) { \
            LOGGER_PRINTF("%c", XSTR[i]); \
          } \
          LOGGER_PRINTF("\r\n"); \
      }


#else
#define LOGGER_LOG_INITIAL(strLoggerName, strConfigFileName)

#define LOGGER_TRACE(fmt, ...)
#define LOGGER_DEBUG(fmt, ...)
#define LOGGER_WARN(fmt, ...)
#define LOGGER_ERROR(fmt, ...)
#define LOGGER_INFO(fmt, ...)
#define LOGGER_DEV_INFO(fmt, ...)

#define LOGGER_SHOW_LOG_STATE()
#define LOGGER_TRACE_SWITCH(fLogSwitch)
#define LOGGER_DEBUG_SWITCH(fLogSwitch)
#define LOGGER_DEV_WARN_SWITCH(fLogSwitch)
#define LOGGER_DEV_ERROR_SWITCH(fLogSwitch)
#define LOGGER_TRACE_INFO_SWITCH(fLogSwitch)

#define LOGGER_PRINTF(fmt, ...)
#define LOGGER_PRINTFBUF(XBUF,XLEN)
#define LOGGER_PRINTFSTRING(XSTR,XLEN)

#endif

#endif // __MR_DSS_LOGGER_H__


