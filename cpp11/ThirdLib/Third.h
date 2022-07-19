#ifndef __THIRD_H__
#define __THIRD_H__



#include  "../UTIL/UTIL.h"

class Third
{
private:
    /* data */
  int mres_id;              //工作结果编号
  std::string mres_str;     //工作结果字符串

public:
    Third(int id ,const std::string& str)
    {
        this->mres_id =id;
        this->mres_str =str;
    }
    
   
    std::function<void(int,const string&)> mGuoShi;

     //std::function 是一种更安全的函数指针，不限定 被调用者的实际类型

    void Third_DeliverOBJ();

    ~Third();
};


#endif // __THIRD_H__