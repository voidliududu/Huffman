cmake_minimum_required(VERSION 3.8)
project(huffman)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS_DEBUG $ENV{CXXFLAGS} -fpermissive)
set(SOURCE_FILES main.cpp FileManager.cpp FileManager.h Counter.cpp Counter.h Hufman.cpp Hufman.h Compress.cpp Compress.h Cli.cpp Cli.h)
#set(SOURCE_FILES main.cpp Counter.cpp Counter.h Hufman.cpp Hufman.h Compress.cpp Compress.h)
#set(SOURCE_FILES main.cpp FileManager.cpp FileManager.h)
#set(SOURCE_FILES main.cpp)

add_executable(huffman ${SOURCE_FILES})