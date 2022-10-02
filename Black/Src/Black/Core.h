#pragma once

#ifdef BLACK_PLATFORM_WINDOWS
    #ifdef BLACK_BUILD_DLL
        #define BLACKAPI __declspec(dllexport)
    #else
        #define BLACKAPI __declspec(dllimport)
    #endif
#else
    #error ONLY WINDOWS SUPPORTED!
#endif

#if BLACK_ENABLE_ASSERT
#define BLACK_ASSERT(x,...){if(!(x)){BLACK_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
#define BLACK_CORE_ASSERT(x,...){if(!(x)){BLACK_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
#else
#define BLACK_ASSERT
#define BLACK_CORE_ASSERT
#endif

#define BIT(x) (1<<x)