cmake_minimum_required(VERSION 3.31)
project(compressor)

set(CMAKE_CXX_STANDARD 20)

add_executable(compressor src/main.cpp
        src/escritor.cpp
        include/escritor.h
        src/rlc.cpp
        include/rlc.h
        src/nodoArbol.cpp
        include/nodoArbol.h
        src/huffman.cpp
        include/huffman.h)
