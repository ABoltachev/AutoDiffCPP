if(DEFINED CLANG_CXX14_CMAKE_)
    return()
else()
    set(CLANG_CXX14_CMAKE_ 1)
endif()

find_program(CMAKE_C_COMPILER clang)
find_program(CMAKE_CXX_COMPILER clang++)

if(NOT CMAKE_C_COMPILER)
    message(FATAL_ERROR "clang not found")
endif()

if(NOT CMAKE_CXX_COMPILER)
    message(FATAL_ERROR "clang++ not found")
endif()

set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_STANDARD 14)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstandalone-debug")
endif()
