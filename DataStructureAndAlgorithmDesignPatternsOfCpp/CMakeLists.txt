cmake_minimum_required(VERSION 3.0)

project(StudyDesMode)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
message("this is stdudyCMake")

add_subdirectory(src)