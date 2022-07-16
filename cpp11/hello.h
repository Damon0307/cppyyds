#ifndef __HELLO_H__
#define __HELLO_H__
// #pragma once 编译器不支持？

#include <string>
#include <iostream>
 

class hello
{
private:
  
public:
    hello(const std::string& name);
    //重载默认的拷贝构造函数
    hello(const hello& h)
    {
        std::cout<<"小伙子基本功不错啊"<<std::endl;
        this->name=h.name;
    }
    //赋值构造函数
    hello& operator=(const hello& h)=delete;
    ~hello();

    std::string name="";

     void SayHello();

};


#endif