# main编译
project(main VERSION 0.1.0)

# 添加头文件搜索目录
include_directories(include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# 当前目录所有资源文件添加到SRCS
aux_source_directory(. SRCS)
# 生成mian函数
add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} Logger UtilsBox ThreadUtils)
