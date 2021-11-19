#pragma once

// recognize the OS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined( WIN64 )
#if !defined(_MRDSS_OS_WIN_)
#define _MRDSS_OS_WIN_
#endif

#elif defined(__linux__) || defined(__linux) || defined(LINUX)
#if !defined(_MRDSS_OS_UNIX_)
#define OS_UNIX_
#endif
#if !defined(_MRDSS_OS_LINUX_)
#define OS_LINUX_
#endif

#else
#error "Unsupported OS!"
#endif

// Dll Export
#if defined(__lint)
#define MRDSS_EXPORT      __export(MRDSSFoundation)
#elif defined(_MRDSS_OS_WIN_)
#define  MRDSS_EXPORT    __declspec(dllexport)
#elif __GNUC__ >= 4
#define EXPORT      __attribute__ ((visibility("default")))
#else
#define MRDSS_EXPORT
#endif

// define realtime
#define REAL_TIME_


