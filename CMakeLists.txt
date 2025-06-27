cmake_minimum_required(VERSION 3.30)

project(Wallpaper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(Wallpaper ${SOURCES})
target_compile_options(Wallpaper PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wshadow
        -Wnull-dereference
        -Wold-style-cast
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wno-unused-parameter
        -Werror
    >
    $<$<CXX_COMPILER_ID:Clang>:
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wshadow
        -Wnull-dereference
        -Wold-style-cast
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wno-unused-parameter
        -Werror
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /permissive-
        /w44265   # uninitialized variables
        /w44062   # possible null dereference
        /WX       # treat warnings as errors
    >
)
#target_include_directories(Wallpaper PRIVATE include)
