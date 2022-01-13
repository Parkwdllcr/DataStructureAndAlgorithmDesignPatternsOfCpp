#pragma once

// recognize the OS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined( WIN64 )
#if !defined(_THREAD_OS_WIN_)
#define _THREAD_OS_WIN_
#endif

#elif defined(__linux__) || defined(__linux) || defined(_THREAD_OS_LINUX_)
#if !defined(_THREAD_OS_UNIX_)
#define _THREAD_OS_UNIX_
#endif
#if !defined(_THREAD_OS_LINUX_)
#define _THREAD_OS_LINUX_
#endif

#else
#error "Unsupported OS!"
#endif

// Dll Export
#if defined(__lint)
#define THREAD_EXPORT      __export(THREADFoundation)
#elif defined(_UTILSBOX_OS_WIN_)
#define THREAD_EXPORT    __declspec(dllexport)
#elif __GNUC__ >= 4
#define THREAD_EXPORT      __attribute__ ((visibility("default")))
#else
#define THREAD_EXPORT
#endif

