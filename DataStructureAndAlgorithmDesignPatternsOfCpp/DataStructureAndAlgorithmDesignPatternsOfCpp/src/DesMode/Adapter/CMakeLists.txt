cmake_minimum_required(VERSION 3.0)

project(Adapter)
message("this is adapterCmake")
aux_source_directory(. SRCS)

add_library(${PROJECT_NAME} SHARED ${SRCS})
