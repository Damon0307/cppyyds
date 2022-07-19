#include <iostream>
#include "cpp11/Hello.h"
#include "cpp11/RunBase.h"
#include "cpp11/STL/FunctionAndBind.h"
#include "cpp11/TestForMe.h"
#include "cpp11/UTIL/UTIL.h"

using namespace std;
 

int main(int, char**) 
{

    // Hello* local_hello = new Hello("WW");
    // local_hello->SayHello();

    cout<<"from lib? "<<FunctionAndBind::AddNumber(1,4)<<endl;

    Util g_util;

    cout<<" Did it work ? "<<g_util.Util_GetTopInfo()<<endl;
 
    TestForMe ta;
    ta.ImplInAnotherFile();

    std::cout << "Hello, world!\n";

    return 0;
}
 