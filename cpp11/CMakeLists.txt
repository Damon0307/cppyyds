message([INFO] "CPP11 was invoked by your project")

#Third 作为CPP11 的一个第三方库存在
add_subdirectory("ThirdLib")

aux_source_directory("STL"  STL_SRC_LIST)
aux_source_directory("UTIL" UTIL_SRC_LIST)
aux_source_directory("LearnNote" LearnNote_SRC_LIST)
aux_source_directory(.  ROOT_SRC_LIST)
 
add_library(cpp11_box SHARED ${STL_SRC_LIST} ${UTIL_SRC_LIST} ${LearnNote_SRC_LIST} ${ROOT_SRC_LIST} )