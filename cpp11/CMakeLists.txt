message([INFO] "CPP11 was invoked by your project")

#这里的 PROJECT_SOURCE_DIR 指的是顶层包含他的CMakeLists.txt 并不是当前路径
#message([INFO] "Current Project CPP11 Dir is " ${PROJECT_SOURCE_DIR})

#GLOB_RECURSE 与GLOB类似，区别在于它会遍历匹配目录的所有文件以及子目录下面的文件 
#file(GLOB cpp11_headers  TRUE "./cpp11/"  *.h) 这样不能递归

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cpp11/ )
  
aux_source_directory("STL"  STL_SRC_LIST)
aux_source_directory("UTIL" UTIL_SRC_LIST)
aux_source_directory("LearnNote" LearnNote_SRC_LIST)
aux_source_directory(.  ROOT_SRC_LIST)

add_library(cpp11_box SHARED ${STL_SRC_LIST} ${UTIL_SRC_LIST} ${LearnNote_SRC_LIST} ${ROOT_SRC_LIST})

 