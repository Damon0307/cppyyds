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

FunctionAndBind::FunctionAndBind(/* args */)
{
}

 

 

//h哈哈 c++ helper 搞定了这个老大难问题
void FunctionAndBind::GeneralFunc(const string& p_str)
{
      cout<<"this is an general func "<<p_str<<endl;
}

int FunctionAndBind::Sum(int a,int b)
{
    return a+b;
}

int FunctionAndBind::AddNumber(int a,int b)
{
    cout<<"this is the static function"<<endl;
    return a+b;
}

FunctionAndBind::~FunctionAndBind()
{
       cout<<" FunctionAndBind say bye bye"<<endl;
}

int FunctionAndBind::operator()(int a,int b)
{
    cout<<" this is an function from operator "<<endl;
    return a+b;
}

#endif // __FUNCTIONANDBIND_H__