cmake_minimum_required(VERSION 3.0.0)
project(CPP VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include directories
 
message("工程文件目录 "${PROJECT_SOURCE_DIR})
message("工程可执行文件目录 " ${PROJECT_BINARY_DIR})

add_subdirectory("cpp11")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/cpp11)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/cpp11)


#LINK_DIRECTORIES()
#一些预定义且常用的变量
#EXECUTABLE_OUTPUT_PATH     可执行文件路径
#LIBRARY_OUTPUT_PATH        编译生成的库的路径
#使用EG 
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

##内部编译 外部编译， 外部编译就是自己建立一个build 文件在


include(CTest)
enable_testing()

#只有一个main.cpp 是自己编写， 其他的全部以库文件的形式发布，虽然我自己一直看得到源文件哈哈哈
add_executable(CPPYYDS main.cpp )

target_link_libraries(CPPYYDS -lcpp11_box)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
