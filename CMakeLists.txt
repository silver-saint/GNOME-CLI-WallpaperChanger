cmake_minimum_required(VERSION 3.30)

project(Wallpaper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)


enable_testing()
add_subdirectory(Vendor/googletest)


file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS Tests/*.cpp)

add_executable(Tests ${TEST_SOURCES})
target_link_libraries(Tests PRIVATE gtest gtest_main)

add_executable(Wallpaper ${SOURCES})

target_compile_options(Wallpaper PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:
        -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow
        -Wnull-dereference -Wold-style-cast -Wnon-virtual-dtor
        -Woverloaded-virtual -Wno-unused-parameter -Werror
    >
    $<$<CXX_COMPILER_ID:Clang>:
        -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow
        -Wnull-dereference -Wold-style-cast -Wnon-virtual-dtor
        -Woverloaded-virtual -Wno-unused-parameter -Werror
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /W4 /permissive- /w44265 /w44062 /WX
    >
)
