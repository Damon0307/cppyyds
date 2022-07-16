#include "hello.h"

using namespace std;

hello:: hello(const std::string& name)
{
    cout<<" hi "<<name<<endl;
    this->name=name;
}
 
hello::~hello()
{
    std::cout<<" hello  disconstruct "<<std::endl;
}

void hello::SayHello()
{
cout<<name<<" say hello to u"<<endl;
}