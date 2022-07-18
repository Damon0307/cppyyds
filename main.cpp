#include <iostream>
#include "cpp11/Hello.h"
#include "cpp11/RunBase.h"
#include "cpp11/STL/FunctionAndBind.hpp"
//#include "cpp11/TestForMe.h"
#include "cpp11/TestForMe.cpp"
#include "cpp11/UTIL/Util.hpp"

using namespace std;
 

int main(int, char**) 
{

<<<<<<< HEAD
    // Hello* local_hello = new Hello("WW");
    // local_hello->SayHello();

    cout<<"from lib? "<<FunctionAndBind::AddNumber(1,4)<<endl;

    Util g_util;

    cout<<" Did it work ? "<<g_util.Util_GetTopInfo()<<endl;
     

    TestForMe ta;
    ta.ImplInAnotherFile();
=======
    // hello* local_hello = new hello("WW");
    // local_hello->SayHello();
>>>>>>> f71f7b9a35d280340c74fd76f42f61c0b2929dc1

    std::cout << "Hello, world!\n";
}
 