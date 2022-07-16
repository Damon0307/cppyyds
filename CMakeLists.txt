cmake_minimum_required(VERSION 3.0.0)
project(CPP VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include directories
INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}/cpp11
)

message("工程文件目录 "${PROJECT_SOURCE_DIR})
message("工程可执行文件目录 " ${PROJECT_BINARY_DIR})


include(CTest)
enable_testing()

add_executable(CPP main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
