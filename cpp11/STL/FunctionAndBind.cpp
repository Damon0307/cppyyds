#include  "FunctionAndBind.h"
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