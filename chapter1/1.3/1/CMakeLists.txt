# 设置CMake所需的最低版本，低于该版本将报错
cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)
# 声明项目名称recipe-01，编程语言CXX表示C++
project(recipe-01 LANGUAGES CXX)

# 创建静态库
add_library(message
  STATIC
  Message.hpp
  Message.cpp
  )

# 编译和链接源文件hello-world.cpp，生成可执行文件hello-world
add_executable(hello-world hello-world.cpp)

# 将静态库链接到可执行目标
target_link_libraries(hello-world message)



