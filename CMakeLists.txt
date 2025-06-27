cmake_minimum_required(VERSION 3.30)

project(Wallpaper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files for main app
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

# Enable testing
enable_testing()
add_subdirectory(Vendor/googletest)

# Collect test sources only from tests directory
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS Tests/*.cpp)

# Create test executable
add_executable(Tests ${TEST_SOURCES})
target_link_libraries(Tests PRIVATE gtest gtest_main)

# Your main application
add_executable(Wallpaper ${SOURCES})

# Compiler warnings and flags
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
