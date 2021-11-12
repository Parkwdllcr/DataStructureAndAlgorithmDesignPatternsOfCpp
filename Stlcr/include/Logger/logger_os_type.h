//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    logger_os_type.h
///  \brief   recognize the OS
///
///  \version 1.0
///  \date    Jan. 01, 2017
//////////////////////////////////////////////////////////////////////////

#ifndef __LOGGER_OS_TYPE_H__
#define __LOGGER_OS_TYPE_H__

// recognize the OS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined( WIN64 )
#if !defined(_LOGGER_OS_WIN_)
#define _LOGGER_OS_WIN_
#endif

#elif defined(__linux__) || defined(__linux) || defined(_LOGGER_OS_LINUX_)
#if !defined(_LOGGER_OS_UNIX_)
#define _LOGGER_OS_UNIX_
#endif
#if !defined(_LOGGER_OS_LINUX_)
#define _LOGGER_OS_LINUX_
#endif

#else
#error "Unsupported OS!"
#endif

// Dll Export
#if defined(__lint)
#define LOGGER_EXPORT      __export(LOGGERFoundation)
#elif defined(_LOGGER_OS_WIN_)
#define  LOGGER_EXPORT    __declspec(dllexport)
#elif __GNUC__ >= 4
#define LOGGER_EXPORT      __attribute__ ((visibility("default")))
#else
#define LOGGER_EXPORT
#endif

#endif // __LOGGER_OS_TYPE_H__

