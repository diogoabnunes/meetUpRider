cmake_minimum_required(VERSION 3.14)
project(meetUpRider)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)

include_directories(lib)

add_executable(meetUpRider main.cpp lib/graphviewer.cpp lib/connection.cpp src/utils.cpp
        src/Automovel.cpp src/Pessoa.cpp src/Time.cpp src/Condutor.cpp src/ReadFiles.cpp
        src/Local.cpp src/Menu.cpp src/Dados.h src/Dados.cpp)