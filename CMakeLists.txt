cmake_minimum_required(VERSION 3.30)

project(Wallpaper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.hpp)

enable_testing()

add_subdirectory(Vendor/googletest)

add_library(wallpaper_lib STATIC ${SOURCES})

target_include_directories(wallpaper_lib PUBLIC src)

add_executable(Wallpaper src/main.cpp) 

target_link_libraries(Wallpaper PRIVATE wallpaper_lib)


file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS Tests/*.cpp)

add_executable(Tests ${TEST_SOURCES})

target_link_libraries(Tests PRIVATE wallpaper_lib gtest gtest_main)

add_test(NAME UnitTests COMMAND Tests)

target_compile_options(wallpaper_lib PRIVATE
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