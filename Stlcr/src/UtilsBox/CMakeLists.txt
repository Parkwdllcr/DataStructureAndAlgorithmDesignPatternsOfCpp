# main编译
project(UtilsBox VERSION 0.1.0)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# 当前目录所有资源文件添加到SRCS
aux_source_directory(src SRCS)
# 生成mian函数
add_library(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} ThreadUtils)
