#ifndef __UTIL_H__
#define __UTIL_H__

 
#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <string.h> //for c 
#include <deque>
#include <map>
#include <chrono>

using namespace std;
 
class Util
{
private:
    /* data */
public:
    Util(/* args */);
    string Util_GetTopInfo()
    {
           return "This is an res from UTIL";
    }
    ~Util();
};


 
 #endif // __UTIL_H__