//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    threadutils_os_type.h
///  \brief   recognize the OS
///
///  \version 1.0
///  \date    August. 15, 2014
//////////////////////////////////////////////////////////////////////////

#ifndef __THREADUTILS_OS_TYPE_H__
#define __THREADUTILS_OS_TYPE_H__

// recognize the OS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined( WIN64 )
#if !defined(_THREADUTILS_OS_WIN_)
#define _THREADUTILS_OS_WIN_
#endif

#elif defined(__linux__) || defined(__linux) || defined(_THREADUTILS_OS_LINUX_)
#if !defined(_THREADUTILS_OS_UNIX_)
#define _THREADUTILS_OS_UNIX_
#endif
#if !defined(_THREADUTILS_OS_LINUX_)
#define _THREADUTILS_OS_LINUX_
#endif

#else
#error "Unsupported OS!"
#endif

// Dll Export
#if defined(__lint)
#define THREADUTILS_EXPORT      __export(THREADUTILSFoundation)
#elif defined(_THREADUTILS_OS_WIN_)
#define  THREADUTILS_EXPORT    __declspec(dllexport)
#elif __GNUC__ >= 4
#define THREADUTILS_EXPORT      __attribute__ ((visibility("default")))
#else
#define THREADUTILS_EXPORT
#endif

#endif // __THREADUTILS_OS_TYPE_H__

