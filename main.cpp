#include <iostream>
#include "cpp11/Hello.h"
#include "cpp11/RunBase.h"
#include "cpp11/STL/FunctionAndBind.h"
#include "cpp11/TestForMe.h"
#include "cpp11/UTIL/UTIL.h"
//测试一下SPDlog
#include "cpp11/LOG/spdlog/spdlog.h"
 


using namespace std;

int  a =100 ;

int main(int, char**) 
{
 //还是SPD log 方便
    spdlog::info("Hello Jiacheng "," be you!");
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    
   // spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");    
    
    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    
    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");

    
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
    getchar();

    return 0;
}
 