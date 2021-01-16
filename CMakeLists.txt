cmake_minimum_required(VERSION 3.1)
project(async)


add_definitions(-std=gnu++17 -U__STRICT_ANSI__)

SET(CMAKE_CXX_FLAGS -pthread)

set(LINKER_FLAGS1 -lcygwin)
set(LINKER_FLAGS2 -lSDL2main)
set(LINKER_FLAGS3 -lSDL2)
set(LINKER_FLAGS4 -mwindows)


include_directories(src) # необходимо для того, чтобы писать в директиве просто lib.h

set(SOURCE_FILES src/lib.cpp)

add_executable(async main.cpp ${SOURCE_FILES})
