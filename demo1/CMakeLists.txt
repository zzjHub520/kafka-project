cmake_minimum_required(VERSION 3.16)
project(demo1)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER /usr/local/gcc-9.3.0/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/local/gcc-9.3.0/bin/g++)

INCLUDE_DIRECTORIES(/usr/local/include/librdkafka)
LINK_DIRECTORIES(/usr/local/lib)

add_executable(demo1 main.cpp)
TARGET_LINK_LIBRARIES(demo1 librdkafka++.so)