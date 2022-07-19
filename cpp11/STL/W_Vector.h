#ifndef __W_VECTOR_H__
#define __W_VECTOR_H__

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class W_Vector
{
private:
    /* data */
    vector<int> mvector;
    string     mstr;  // 没想到吧 这个str 也可以同时和vec 使用初始化列表
public:
    W_Vector(std::initializer_list<int>a,const string& b)
    {
        cout<<" fuck 竟然被调用了"<<endl;
        for(auto i:a)
        {
            mvector.push_back(i);
        }
        mstr = b ; 
    };
    ~W_Vector();
    void TraverseTheVector();

};

// W_Vector::W_Vector(/* args */)
// {
// }

#endif // __W_VECTOR_H__