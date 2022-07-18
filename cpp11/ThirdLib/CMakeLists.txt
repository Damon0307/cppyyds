
message("ok 我看好你哦")

aux_source_directory(. Third_SRC)
#妈的 想包含其他目录的还得在这里设置一下

include_directories("../UTIL/")
#add_library(Thirdlib STATIC ${Third_SRC})
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/Thirdlib/)
#add_library(Thirdlib  ${Third_SRC})  #静态连接

add_library(Thirdlib SHARED ${Third_SRC}) #动态


