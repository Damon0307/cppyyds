#ifndef __LRUNTIME_H__
#define __LRUNTIME_H__




#include "../UTIL/UTIL.h"
#include "../RunBase.h"

using namespace std;

class LRunTime : public RunBase
{
private:
    function<void(const string& text)>  mCallOnBtn; // 一个处理按钮点击的回调
public:
    LRunTime():RunBase()
    { printf("LRunTime construct\n");};
    ~LRunTime()
    { cout<<"LRunTime dis construct "<<endl;};

    void ShowReadme()override;
    void RunTest()override;

};

class LDagong
{
private:
    /* data */
public:
    LDagong(/* args */)
    {}
    void DagongRen(const string& ppt)
    {
        cout<<"打工人处理了 "<<ppt<<endl;
    }
    ~LDagong()
    {
        cout<<"妈的 不打工了"<<endl;
    }
};

 


#endif // __LRUNTIME_H__