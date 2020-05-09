cmake_minimum_required(VERSION 3.14)
project(meetUpRider)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)

include_directories(lib)

add_executable(meetUpRider main.cpp lib/graphviewer.cpp lib/connection.cpp src/Automovel.cpp src/Pessoa.cpp src/Pessoa.h src/Time.cpp src/Time.h src/Condutor.cpp src/Condutor.h src/ReadFiles.cpp src/ReadFiles.h src/utils.cpp src/utils.h src/Passageiro.cpp src/Passageiro.h)