cmake_minimum_required(VERSION 3.0.0)
project(CPP VERSION 1.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
 
message("工程文件目录 " ${PROJECT_SOURCE_DIR})
message("工程可执行文件目录 " ${PROJECT_BINARY_DIR})
#处理器名称显示的不是很准
message("处理器名称" ${CMAKE_SYSTEM_PROCESSOR}) 
add_subdirectory("cpp11")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/cpp11)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/cpp11/LOG/)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/cpp11)


#LINK_DIRECTORIES()
#一些预定义且常用的变量
#EXECUTABLE_OUTPUT_PATH     可执行文件路径
#LIBRARY_OUTPUT_PATH        编译生成的库的路径
#使用EG 
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

##内部编译 外部编译， 外部编译就是自己建立一个build 文件在
 
file(GLOB_RECURSE cpp11_headers ${PROJECT_SOURCE_DIR}/cpp11/ *.h)

message("FILES  HEADER -> " ${cpp11_headers})
 
file(GLOB_RECURSE cpp11_impls ${PROJECT_SOURCE_DIR}/cpp11/ *.cpp)

#注意如果不加这个cpp11 的文件夹 他会显示重复定义main 
# file(GLOB_RECURSE cpp11_impls ${PROJECT_SOURCE_DIR}  *.cpp *.hpp) 
 
message("FILES IMPL-> " ${cpp11_impls})
 
 
include(CTest)
enable_testing()

#只有一个main.cpp 是自己编写， 其他的全部以库文件的形式发布，虽然我自己一直看得到源文件哈哈哈
#add_executable(CPPYYDS main.cpp ${cpp11_impls} )

#上面已经用源文件形式提供了 就不需要再连接库了，下面的这种是按照链接库文件形式生成可执行文件
add_executable(CPPYYDS main.cpp)
target_link_libraries(CPPYYDS -lcpp11_box)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
