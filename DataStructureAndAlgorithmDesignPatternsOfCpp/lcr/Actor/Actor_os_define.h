#pragma once

// recognize the OS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined( WIN64 )
#if !defined(_ACTOR_OS_WIN_)
#define _ACTOR_OS_WIN_
#endif

#elif defined(__linux__) || defined(__linux) || defined(_ACTOR_OS_LINUX_)
#if !defined(_ACTOR_OS_UNIX_)
#define _ACTOR_OS_UNIX_
#endif
#if !defined(_ACTOR_OS_LINUX_)
#define _ACTOR_OS_LINUX_
#endif

#else
#error "Unsupported OS!"
#endif

// Dll Export
#if defined(__lint)
#define ACTOR_EXPORT      __export(ACTORFoundation)
#elif defined(_ACTOR_OS_WIN_)
#define  ACTOR_EXPORT    __declspec(dllexport)
#elif __GNUC__ >= 4
#define ACTOR_EXPORT      __attribute__ ((visibility("default")))
#else
#define ACTOR_EXPORT
#endif

