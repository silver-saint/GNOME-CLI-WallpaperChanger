cmake_minimum_required(VERSION 3.20)

project(Wallpaper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    App/*.cpp
    Wallpaper/*.cpp
    FileManager/*.cpp
    Settings/*.cpp
    SaveDirectory/*.cpp
)

add_executable(Wallpaper ${SOURCES})
