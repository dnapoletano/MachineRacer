cmake_minimum_required(VERSION 3.18)

project(MachineRacer LANGUAGES CXX)
set(CMAKE_MAKE_PROGRAM "Makefile")

message("------------ Machine Racer Config --------------")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SDL_Include "/usr/local/include")
set(SDL_Library_Path "/usr/local/lib")

# set our include directories
set (LOCAL_INCLUDE_DIRS
   ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(src)

message("------------ End -------------------------------")