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


#define BIT(x) (1<<x)