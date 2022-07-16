#include <iostream>
#include "cpp11/hello.h"
#include "cpp11/RunBase.h"


int main(int, char**) 
{

    hello* local_hello = new hello("WW");
    local_hello->SayHello();

    std::cout << "Hello, world!\n";
}
 