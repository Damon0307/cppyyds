#ifndef __HELLO_H__
#define __HELLO_H__


#include <string>
#include <iostream>
 
 using namespace std;

class Hello
{
private:
  
public:
    Hello(const std::string& name);
    //重载默认的拷贝构造函数
    Hello(const Hello& h)
    {
        std::cout<<"小伙子基本功不错啊"<<std::endl;
        this->name=h.name;
    }
    //赋值构造函数
    Hello& operator=(const Hello& h)=delete;
    ~Hello();

    std::string name;

     void SayHello();

};

Hello::Hello(const std::string& name)
{
     this->name=name;
}

void Hello::SayHello()
{
    cout<<this->name<<" say hi to you"<<endl;
}


#endif // __HELLO_H__