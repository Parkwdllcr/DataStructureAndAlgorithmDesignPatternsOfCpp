cmake_minimum_required(VERSION 3.0)

project(LinkList)
message("this is LinkList")

aux_source_directory(. SRCS)

add_library(${PROJECT_NAME} SHARED ${SRCS})