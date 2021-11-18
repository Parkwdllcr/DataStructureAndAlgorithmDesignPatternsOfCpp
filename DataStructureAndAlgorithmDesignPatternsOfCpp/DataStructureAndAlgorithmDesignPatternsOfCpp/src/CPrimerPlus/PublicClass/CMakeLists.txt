cmake_minimum_required(VERSION 3.0)

project(PublicClass)
message("this is PublicClass")
aux_source_directory(. SRCS)
add_library(${PROJECT_NAME} SHARED ${SRCS})