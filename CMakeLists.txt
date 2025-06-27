cmake_minimum_required(VERSION 3.30)

project(Wallpaper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)
enable_testing()
add_subdirectory(Vendor/googletest)
# Recursively get all test .cpp files
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "*.cpp")

# Create test target
add_executable(Tests ${TEST_SOURCES})

# Link GoogleTest
target_link_libraries(Tests gtest gtest_main)

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
