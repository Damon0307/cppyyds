#ifndef __LAUTO_H__
#define __LAUTO_H__


#include "../RunBase.h"
class LAuto : public RunBase
{
private:
  
public:
    LAuto( ) : RunBase()
    {

    }
    ~LAuto()
    {
        std::cout<< " ~LAuto() "<<std::endl;
    }
    void ShowReadme()override;
    void RunTest()override;
};
 
 #endif // __LAUTO_H__