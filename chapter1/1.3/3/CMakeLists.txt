# 设置CMake所需的最低版本，低于该版本将报错
cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)
# 声明项目名称recipe-01，编程语言CXX表示C++
project(recipe-01 LANGUAGES CXX)

add_library(message-objs
  OBJECT
  Message.hpp
  Message.cpp
  )
  
# 保证编译的目标文件与生成位置无关
set_target_properties(message-objs
  PROPERTIES
  POSITION_INDEPENDENT_CODE 1
  )
  
add_library(message-shared
  SHARED
  $<TARGET_OBJECTS:message-objs>
  )

set_target_properties(message-shared
  PROPERTIES
  OUTPUT_NAME "message"
  )

add_library(message-static
  STATIC
  $<TARGET_OBJECTS:message-objs>
  )

set_target_properties(message-static
  PROPERTIES
  OUTPUT_NAME "message"
  )

# 编译和链接源文件hello-world.cpp，生成可执行文件hello-world
add_executable(hello-world hello-world.cpp)

# 将静态库链接到可执行目标
target_link_libraries(hello-world message-shared)
