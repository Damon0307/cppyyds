#include <iostream>
#include "cpp11/Hello.h"
#include "cpp11/RunBase.h"
#include "cpp11/STL/FunctionAndBind.h"
#include "cpp11/TestForMe.h"
#include "cpp11/UTIL/UTIL.h"
//测试一下SPDlog
#include "cpp11/LOG/spdlog/spdlog.h"
#include "cpp11/LOG/spdlog/sinks/basic_file_sink.h"  //基础文件日志
#include "cpp11/LOG/spdlog/sinks/rotating_file_sink.h" //循环文件日志
 

using namespace std;

int  a =100 ;

int main(int, char**) 
{
    cout<<"main thread id "<<this_thread::get_id()<<endl;

    auto mlogger=spdlog::basic_logger_mt("file_logger","logs/basic.txt");
 
 //还是SPD log 方便
    spdlog::info("Hello Jiacheng "," be you!");
   // mlogger.get()->set_level(spdlog::level::debug);
       mlogger.get()->set_level(spdlog::level::trace);
   // mlogger.get()->set_pattern("[%H:%M:%S] [%n] [%l] [thread %t] [%@]  %v");
 
     mlogger->set_pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> [%l] [%@] %v");


    mlogger.get()->info("自带的行号不行了 得用这个__LINE__ {}",__LINE__);
    mlogger.get()->debug("this is an debug file: {}",a);
    mlogger.get()->debug("too many args {3}",1,2,43,4,5," niu bi ");
    
    #if 0 
    spdlog::info("Welcome to spdlog!");
    
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
 
   // spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");    
    
    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    
    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
#endif
    
    // Hello* local_hello = new Hello("WW");
    // local_hello->SayHello();
/*
    cout<<"from lib? "<<FunctionAndBind::AddNumber(1,4)<<endl
    Util g_util;
    cout<<" Did it work ? "<<g_util.Util_GetTopInfo()<<endl;
    TestForMe ta;
    ta.ImplInAnotherFile();
    std::cout << "Hello, world!\n";
*/
    char c = getchar();

    mlogger.get()->debug("console input {}",c);
 
    spdlog::drop_all();

    return 0;
}
 