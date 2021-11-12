//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    dss_realtime_logger.h
///  \brief   define the realtime logger
///
///  \version 1.0
///  \date    Jan. 01, 2017
//////////////////////////////////////////////////////////////////////////

#ifndef _LOGGER_REALTIME_LOGGER_H__
#define _LOGGER_REALTIME_LOGGER_H__

#ifndef LOGGER_REALTIME_LOG
#define LOGGER_REALTIME_LOG
#endif

#ifdef LOGGER_REALTIME_LOG

#include "Logger/logger_os_type.h"
#include "UtilsBox/utilsbox_utils.h"

//#define RT_LOGGER_OUTPUT_REALTIME
#define RT_LOGGER_OUTPUT_TERM

#ifdef RT_LOGGER_OUTPUT_REALTIME
#define LOGGER_REALTIME_TRACE    RT_TRACE_INFO
#define LOGGER_REALTIME_DEBUG    RT_TRACE_DEBUG
#define LOGGER_REALTIME_WARN     RT_TRACE_WARN
#define LOGGER_REALTIME_ERROR    RT_TRACE_ERROR
#define LOGGER_REALTIME_INFO     RT_TRACE_INFO

#elif defined(RT_LOGGER_OUTPUT_TERM)
#include <stdio.h>

#define LOGGER_REALTIME_TRACE(fmt, ...) do{ printf("TRACE: [%lu][%s:%d] ", utilsbox::CUtils::GetCurrentTimes(), __FILE__, __LINE__); printf(fmt, ##__VA_ARGS__); printf("\r\n"); }while(0)
#define LOGGER_REALTIME_DEBUG(fmt, ...) do{ printf("DEBUG: [%lu][%s:%d] ", utilsbox::CUtils::GetCurrentTimes(), __FILE__, __LINE__); printf(fmt, ##__VA_ARGS__); printf("\r\n"); }while(0)
#define LOGGER_REALTIME_WARN(fmt, ...)  do{ printf("WARN : [%lu][%s:%d] ", utilsbox::CUtils::GetCurrentTimes(), __FILE__, __LINE__); printf(fmt, ##__VA_ARGS__); printf("\r\n"); }while(0)
#define LOGGER_REALTIME_ERROR(fmt, ...) do{ printf("ERROR: [%lu][%s:%d] ", utilsbox::CUtils::GetCurrentTimes(), __FILE__, __LINE__); printf(fmt, ##__VA_ARGS__); printf("\r\n"); }while(0)
#define LOGGER_REALTIME_INFO(fmt, ...)  do{ printf("INFO : [%lu][%s:%d] ", utilsbox::CUtils::GetCurrentTimes(), __FILE__, __LINE__); printf(fmt, ##__VA_ARGS__); printf("\r\n"); }while(0)

#else
#define LOGGER_REALTIME_TRACE(fmt, ...)
#define LOGGER_REALTIME_DEBUG(fmt, ...)
#define LOGGER_REALTIME_WARN(fmt, ...)
#define LOGGER_REALTIME_ERROR(fmt, ...)
#define LOGGER_REALTIME_INFO(fmt, ...)
#endif

#endif

#endif // __MR_DSS_REALTIME_LOGGER_H__


