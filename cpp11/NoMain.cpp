// A simple program that computes the square root of a number
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <array>
#include <map>
#include <thread>
#include <atomic> // 原子变量 王炸！
#include <future> //async 都在这里里面哦 正经人 谁玩thread
#include "TutorialConfig.h"
#include "hello.h"
#include "RunBase.h"
#include "Third/Third.h"
#include "UTIL/Util.h"
#include "LearnNote/LAuto.h"
#include "LearnNote/ThreadProduce.hpp"
#include "LearnNote/ThreadConsume.hpp"
#include "LearnNote/LRunTime.h"
#include "STL/W_Vector.hpp"
#include "STL/FunctionAndBind.hpp"


using namespace std;

using CopyWhatYouWrite = std::function<void(const string &)>;

int G_Sum(int a, int b)
{
  return a + b;
}

void CallWhenBig(int a, int b, std::function<int(int, int)> the_func)
{

  if (a > 10 || b > 10)
  {
    cout << "大数加倍！ " << the_func(a, b) * 100 << endl;
  }
  else
  {
    cout << "小的数我自己来 " << a + b << endl;
  }
}

int main_of_github()
{
#if 0
  std::shared_ptr<hello> hellp_ptr = std::make_shared<hello>("JIACHENG");
  hellp_ptr.get()->SayHello();

  cout << "not only 11 but also 14" << endl;

  std::map<int, string> stu_list = {{1, "hello"}, {2, "world"}};
  for (auto i : stu_list)
  {
    cout << "i first    " << i.first << endl;  //注意这个 . 而不是 ->
    cout << "i second   " << i.second << endl;
  }

/*
1）for 循环中val 的类型是std::pair。因此，对于map 这种关联性容器而言，需要使用
val.f irst 或val.second 来提取键值。
2）auto 自动推导出的类型是容器中的value_type，而不是迭代器。 
*/


  auto func = []()
  {
    return make_pair(15, "ta");
  };

  auto hello = func();

  cout << hello.first << "  who is " << hello.second << endl; //! 哈哈竟然是OK的

  // typedef pair<string,string>  Chinese_name  == using Chinese_name = pair<string,string> = ;
  using Chinese_name = pair<string, string>;
  Chinese_name wjc("魏", "嘉成");
  cout << wjc.first << " ~ " << wjc.second << endl;

  W_Vector vec_int{{1, 2, 3, 4}, "shit bro "};

  vec_int.TraverseTheVector();

#endif
  //使用function 配合绑定器。实现延迟（换绑就是变更）机制
  std::shared_ptr<FunctionAndBind> fab_ptr = std::make_shared<FunctionAndBind>();
  cout << " 相加结果 " << fab_ptr.get()->AddNumber(1, 5) << endl;
  //声明一个 拥有加法能力的接口
  std::function<int(int, int)> g_callback;
  //在程序的某个地上去实现它，
  // 1 用普通函数实现它
  g_callback = G_Sum;
  cout << "Call back 普通函数 " << g_callback(1, 8) << endl;
  // 2 用lambda 函数实现它
  g_callback = [](int a, int b) -> int
  { return a + b; };
  cout << "Call back lambda " << g_callback(1, 8) << endl;
  // 3 用类的对象成员函数实现 不能用= 赋值了，需要借用一下std::bind
  g_callback = std::bind(&FunctionAndBind::Sum, fab_ptr.get(), std::placeholders::_1, std::placeholders::_2);
  cout << "Call back Class member func " << g_callback(1, 8) << endl;
  // 4用类的静态成员函数实现
  g_callback = std::bind(&FunctionAndBind::AddNumber, std::placeholders::_1, std::placeholders::_2);
  cout << "Call back static Class function " << g_callback(1, 8) << endl;
  // 5用伪函数实现
  g_callback = std::bind(&FunctionAndBind::Sum, fab_ptr.get(), std::placeholders::_1, std::placeholders::_2);
  cout << "Call back operator " << g_callback(1, 8) << endl;

  // std::function 还可以作为参数来传递 我去的
  CallWhenBig(1, 1, g_callback);

  CallWhenBig(20, 5, g_callback);
  /*
  挺骚的
  然后，我们需要一个判断是否小于10的功能闭包：
  std:bind(std::less equal<int>(),std:placeholders::1,10);
  有了这两个闭包之后，只需要用逻辑与把它们连起来：
  using std::placeholders::1;
  std:bind(std:logical and<bool>(),
  std:bind(std:greater<int>(),1,5),
  std:bind(std::less equal<int>(),1,10));
  然后就可以复合多个函数（或者说闭包）的功能：
  using std:placeholders::1;
  ∥查找集合中大于5小于10的元素个数
  auto f std:bind(std::logical and<bool>(),
  std:bind(std:greater<int>(),1,5),
  std:bind(std::1ess equal<int>(),1,10));
  int count std:count if (coll.begin(),coll.end(),f);
  */
  // lambda 学的挺多的了 这里就不说了

  //搞一个单独的线程 记录一下输入内容的时间
  CopyWhatYouWrite copy_impl = [](string content)
  {
 
       static  ofstream  fs;
       fs.open("hello_wjc.txt");
       fs.write(content.c_str(),content.size());
      
       fs.close();
       
  };
  // std::thread copy_thread(CopyWhatYouWrite);

 

  while (1)
  {
   string hello = "";

    getline(cin,hello);
    
    copy_impl(hello);
  
  }
 

  return 0;
}

#if 0
  // deque<shared_ptr<RunBase>> run_obj_deque;
  // run_obj_deque.push_back(make_shared<LAuto>());  
  // run_obj_deque.push_back(make_shared<LRunTime>()); 
  // for(auto i : run_obj_deque)
  // {
  //     i.get()->ShowReadme();
  //     i.get()->RunTest();
  // }
 
   unique_ptr<ThreadProduce>xinku(new ThreadProduce());
   shared_ptr<ThreadConsume>b1=make_shared<ThreadConsume>();
   shared_ptr<ThreadConsume>b2=make_shared<ThreadConsume>();
 
  //thread th_produce(&ThreadProduce::Procuce,xinku.get(),std::ref(normal_family),std::ref(mtx));
 // thread th_consume_1(&ThreadConsume::Consume,b1.get(),std::ref(normal_family),std::ref(mtx));
//  thread th_consume_2(&ThreadConsume::Consume,b2.get(),std::ref(normal_family),std::ref(mtx));


 //thread th_produce(&ThreadProduce::Produce_with_condition_variable,xinku.get(),std::ref(normal_family),std::ref(mtx),std::ref(cv));
 //thread th_consume_1(&ThreadConsume::Consume_with_condition_variable,b1.get(),std::ref(normal_family),std::ref(mtx),std::ref(cv));
 //thread th_consume_2(&ThreadConsume::Consume,b2.get(),std::ref(normal_family),std::ref(mtx));

   thread th_produce(&ThreadProduce::ProduceAtomic,xinku.get(),std::ref(money));
   thread th_consume_1(&ThreadConsume::ConsumeWithAtomic,b1.get(),std::ref(money));
   thread th_consume_2(&ThreadConsume::ConsumeWithAtomic,b2.get(),std::ref(money));

 

 th_produce.join();
 th_consume_1.join();
 th_consume_2.join();
#endif