cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(recipe-08 LANGUAGES CXX)

# 打印当前编译器标志
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")
# 为目标准备了标志列表，其中一些将无法在Windows上使用
list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

add_library(geometry
  STATIC
  geometry_circle.cpp
  geometry_circle.hpp
  geometry_polygon.cpp
  geometry_polygon.hpp
  geometry_rhombus.cpp
  geometry_rhombus.hpp
  geometry_square.cpp
  geometry_square.hpp
  )
# 为库设置编译选项
target_compile_options(geometry
  PRIVATE
  ${flags}
  )

add_executable(compute-areas compute-areas.cpp)
# 为可执行目标设置编译选项
target_compile_options(compute-areas
  PRIVATE
  "-fPIC"
  )

target_link_libraries(compute-areas geometry)
