
#include "LAuto.h"
#include  <vector>
#include  <string>
using namespace std;

void LAuto::ShowReadme()
{
    cout<<"auto decltype 都是用来自动推导类型 "<<endl;
    cout<<"decltype 是根据表达式来推导，更原汁原味，对于 引用 const 之类的都保留 但是 auto 会去掉 const  & 属性 "<<endl;
    cout<<"auto decltype 都是用来自动推导类型 "<<endl;
    cout<<" 禁止无痛呻吟 int string 之类的情况"<<endl;
    cout<<" // 使用std::is_same<T,T1>::value 来判断是不是同一个类型 std::cout << std::is_same<int, std::int32_t>::value << '\n'; "<<endl;
 
}

void LAuto::RunTest()
{
    vector<string>v_str{"hello","world","2022","strong"};

    for(auto i : v_str)
    {
        cout<<"i "<<i<<endl;
    }

    for(auto &i : v_str) // 带引用才可以实际修改值， 否则是值传递
    {
       if (i=="world")
       {
            i=" wjc ";
       }
         cout<<"i "<<i<<endl;
    }

    string  str = "jiayou";

    string& str_1=str;
    cout<<" str_1 "<<str_1<<endl;
    str_1 = "changed";
    cout<<" str "<<str<<endl;
    auto str_2 =str_1;
    str_2="auto changed";       // 这里str_2 的改变影响不了 str 
    cout<<" str "<<str<<endl;

    auto &str_3 =str_1;
    str_3="auto changed";       // 这里str_3 改变影响了 str 
    cout<<" str "<<str<<endl;
//decltype

    decltype(str_1)  decl_str=str_1;
    cout<<"decl_str: "<<decl_str<< endl;
    decl_str= "decltype 万岁";
     cout<<" str "<<str<<endl;



}
