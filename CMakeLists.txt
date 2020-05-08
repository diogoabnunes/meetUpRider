cmake_minimum_required(VERSION 3.15)
project(meetUpRider)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)

include_directories(lib)

add_executable(meetUpRider main.cpp lib/graphviewer.cpp lib/connection.cpp)