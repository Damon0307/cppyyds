#pragma once
#include "../UTIL/Util.h"
#include <chrono>
#include <thread>
#include <mutex>            //作用不是同步而是 保护临界区
#include <condition_variable>        //作用是 同步  而不能保护 临界区
using namespace std;

class ThreadProduce
{
private:
 
public:
    ThreadProduce(/* args */);
    //普通的生产者， 共相全局的变量 加上锁，各自的处理逻辑加上 if 业务判断
    void Procuce(int&wallet,std::mutex& mtx )   
    {
        while (1)
        {
                 if (wallet<10)
                {
                 std::this_thread::sleep_for(std::chrono::seconds(3));
                 std::lock_guard<mutex> lg(mtx);
                 wallet+=3;
             }
        }
    }
    //使用线程条件变量 通知某一个线程开始执行
    void  Produce_with_condition_variable(int&wallet,std::mutex& mtx, std::condition_variable& cv)
    {
        
                for ( int i = 0; i < 100; i++)
                { 
                    this_thread::sleep_for(chrono::seconds(2));
                    std::lock_guard<std::mutex>uni_lock(mtx);
                    wallet = 1;
                    cv.notify_one();
                }
    }
//原子变量 Atomic 
    void ProduceAtomic(atomic_int& money)
    {
            while (1)
            {   
            cout<<"Produce "<<endl;
            this_thread::sleep_for(chrono::seconds(2));
             
            }
            
    }


    ~ThreadProduce();
};

ThreadProduce::ThreadProduce(/* args */)
{
    string readme=R"(生产者线程)";
}

ThreadProduce::~ThreadProduce()
{
}
