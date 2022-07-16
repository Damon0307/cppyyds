//每个知识点学习过程的基类
//提供打印自己心得的接口
//提供自己测试代码的接口
#pragma once
#include <iostream>
class RunBase
{
private:
    /* data */
public:
    RunBase()
    {
        std::cout<<"RunBase Construct"<<std::endl;
    }
   virtual ~RunBase()
   {
       std::cout<<"can u c me ~RunBase()"<<std::endl;
   }
    //打印自己心得的接口
    virtual void ShowReadme(){};
    //子类需要实现的自己的测试接口
    virtual void RunTest(){};
};
 
 
