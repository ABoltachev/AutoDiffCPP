#ifndef LIBAUTODIFF_COMMON_H
#define LIBAUTODIFF_COMMON_H

#ifdef _WIN32
    #ifdef LIBAUTODIFF_EXPORTS
        #define LIBAUTODIFF_API __declspec(dllexport)
    #else
        #define LIBAUTODIFF_API __declspec(dllimport)
    #endif
#else
    #define LIBAUTODIFF_API
#endif

#endif // LIBAUTODIFF_COMMON_H
