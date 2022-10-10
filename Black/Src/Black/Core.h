#pragma once

#ifdef BLACK_PLATFORM_WINDOWS
    #ifdef BLACK_DYNAMIC_LINK
        #ifdef BLACK_BUILD_DLL

            #define BLACKAPI __declspec(dllexport)
        #else
            #define BLACKAPI __declspec(dllimport)
        #endif
    #else
        #define BLACKAPI
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


#define BLACK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)