#ifndef __FUNCTIONANDBIND_H__
#define __FUNCTIONANDBIND_H__

 
//搞一手 function and bind

#include <string>
#include <iostream>

using namespace std;

class FunctionAndBind
{
private:
    /* data */
public:
    FunctionAndBind(/* args */);
    ~FunctionAndBind();
    //重载一个() 函数 ，保证一个单独的对象也是可调用函数    仿函数
    int operator()(int a,int b);

//普通成员函数
    void GeneralFunc(const string& p_str);
    int  Sum(int a,int b);
//静态成员函数
 static int AddNumber(int a,int b);
 
    
};


 
 #endif // __FUNCTIONANDBIND_H__