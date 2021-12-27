cmake_minimum_required(VERSION 3.0)

project(MulThreadAndCallBack)
message("this is MulThreadAndCallBack")

aux_source_directory(. SRCS)

add_library(${PROJECT_NAME} SHARED ${SRCS})