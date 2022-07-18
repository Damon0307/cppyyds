#ifndef TESTFORME_HPP
#define TESTFORME_HPP

#include <iostream>
#include <string>
using namespace std;

class TestForMe
{
private:
    /* data */
public:
    TestForMe(/* args */);
    void ImplInAnotherFile();
    ~TestForMe();
};

TestForMe::TestForMe(/* args */)
{
    cout<<" Test For Me "<<endl;
}



TestForMe::~TestForMe()
{
}



#endif // TESTFORME_HPP