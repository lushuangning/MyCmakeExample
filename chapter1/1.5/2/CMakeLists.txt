# 设置CMake所需的最低版本，低于该版本将报错
cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)
# 声明项目名称recipe-04，编程语言CXX表示C++
project(recipe-05 LANGUAGES CXX)
option(USE_LIBRARY "Compile sources into a library" OFF)
# 打印变量的值
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

# 引入一个变量_source，包括Message.hpp和Message.cpp
list(APPEND _sources Message.hpp Message.cpp)

include(CMakeDependentOption)
# second option depends on the value of the first
cmake_dependent_option(
  MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
  "USE_LIBRARY" ON
  )

# third option depends on the value of the first
cmake_dependent_option(
  MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
  "USE_LIBRARY" ON
  )

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# 引入一个基于USE_LIBRARY的if-else语句，如果逻辑为真，则Message.hpp和Message.cpp将打包成一个库
if(USE_LIBRARY)
  message(STATUS "Compile sources into a STATIC library?${MAKE_STATIC_LIBRARY}")
  message(STATUS "Compile sources into a SHARED library?${MAKE_SHARED_LIBRARY}")

  if(MAKE_SHARED_LIBRARY)
    add_library(message SHARED ${_sourecs})
  
    add_executable(hello-world hello-world.cpp)

    target_link_libraries(hello-world message)
  endif()

  if(MAKE_STATIC_LIBRARY)
    add_library(message STATIC ${_sourecs})
  
    add_executable(hello-world hello-world.cpp)

    target_link_libraries(hello-world message)
  endif()
  
else()
  add_executable(hello-world hello-world.cpp ${_sources})
endif()
