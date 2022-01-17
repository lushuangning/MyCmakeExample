# 设置CMake所需的最低版本，低于该版本将报错
cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)
# 声明项目名称recipe-04，编程语言CXX表示C++
project(recipe-05 LANGUAGES CXX)
option(USE_LIBRARY "Compile sources into a library" OFF)
# 打印变量的值
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")
# BUILD_SHARED_LIBS是CMake的全局变量
set(BUILD_SHARED_LIBS OFF)

# 引入一个变量_source，包括Message.hpp和Message.cpp
list(APPEND _sources Message.hpp Message.cpp)

# 引入一个基于USE_LIBRARY的if-else语句，如果逻辑为真，则Message.hpp和Message.cpp将打包成一个库
if(USE_LIBRARY)
  add_library(message ${_sources})
  add_executable(hello-world hello-world.cpp)
  target_link_libraries(hello-world message)
else()
  add_executable(hello-world hello-world.cpp ${_sources})
endif()
