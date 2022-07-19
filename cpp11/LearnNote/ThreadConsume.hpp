#ifndef __THREADCONSUME_H__
#define __THREADCONSUME_H__


#include "../UTIL/UTIL.h"
#include <thread>
#include <mutex>
#include <chrono>
 
//对于一个厕所肯定是一个 一个🔒 锁一个门，要是每个想上这个厕所的人都带一把自己的锁，那就乱了（除非每个人都是连接着🔒，区块链）

using namespace std;

class ThreadConsume
{
private:
    /* data */
public:
    ThreadConsume(/* args */);

    void Consume(int& money , std::mutex& mtx)
    {
        while (1)
        {
          std::this_thread::sleep_for(std::chrono::microseconds(1000));
           std::lock_guard<std::mutex>lg(mtx);
            if(money>0)
            {
             cout<<"thread id"<<this_thread::get_id()<<"  花了一块钱 还剩"<<--money<<endl;
            }
        }
    }

        //等别人来通知自己上新茶了
    void  Consume_with_condition_variable(int& wallet,std::mutex& mtx, std::condition_variable& cv)
    {
        while (1)
        {
                std::unique_lock<std::mutex>uni_lock(mtx);//先锁上
            //然后就等着呗
               cv.wait(uni_lock); //等的时候其实已经把所释放出去了
                if(wallet>0)
                {
                    cout<<"拿来把你！ "<<wallet<<endl;
                    wallet=0;
                }
        }
    }
//原子变量  
    void ConsumeWithAtomic(atomic_int& money)
    {

        while (money > 0)
        {
        cout<<"Current money "<<money<<endl;
         this_thread::sleep_for(chrono::microseconds(10));
          money-=1;
          cout<<" thread id    "<<this_thread::get_id()<<"     consume"<<endl;
        }
      
    }
    
 
    ~ThreadConsume();
};

ThreadConsume::ThreadConsume(/* args */)
{
    string readme=R"(我想先用mutext 的方式实现 消费生产，再用 conditional_var 实现以下，然后再用atomic 
    实现无所化设计 ,但请注意这里是 hpp 可能对于static 变量的定义会有问题？ )";


    cout<< readme <<endl;
}

ThreadConsume::~ThreadConsume()
{
       cout<< "ThreadConsume destory" <<endl; 
}

#endif // __THREADCONSUME_H__