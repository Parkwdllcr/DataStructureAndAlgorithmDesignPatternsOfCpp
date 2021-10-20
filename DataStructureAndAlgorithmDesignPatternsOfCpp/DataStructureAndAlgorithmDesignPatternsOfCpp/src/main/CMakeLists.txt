cmake_minimum_required(VERSION 3.0)
message("this is main CMake")
project(DesMode)

aux_source_directory(. SRCS)
add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} AbstractFactory Adapter FactoryMode Iterator Observer SimpleFactory Singleton State 3thDataProcessing)


