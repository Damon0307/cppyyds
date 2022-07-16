#pragma once
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
 