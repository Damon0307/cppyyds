atomic_flag  the_flag  只支持bool 类型 但是可以保证是原子的
比如 之前  需要判断一个东西 
if (num >=10)
多线程情况下 判断之前就得加锁 防止冲入，这也是为什么 单例模式有时候需要双检索，双检索在内存重整时候又不能保证完全正确shit 

下次要使用懒汉模式 我就用 atomic_flag<bool> = ATOMIC_FLAG_INIT 然后 test_and_set() 来实例化一个单例

现在使用  atomic_flag 可以保证此判断是原子的
比如 if (the_flag.test_and_set() )    //此时可以保证当时是原子判断的
{
。。。/ 这部分操作 原不原子 就另说了
}
但是 他妈的这个判断也是真他妈 的绕人


  while(ato_zhamen.test_and_set(std::memory_order_acquire))
  { //如果test_and_set 执行时候 test 之前就返回了true 说明锁被别人用着呢那就等待
    ;
  }
这里的test_and_set 返回的是之前的结果 然后这个语句执行完了以后就一定是set 的状态了，可以通过clear 清除状态
比如想使用这个 atomic_flag 进行同步你也许需要这样

while(1)
{
if(atomic_flag_var.test_and_set(内存模型顺序) == true)
{//==true 能进来不是说现在开始你处理了。哈哈哈，TMD真扰人
this_thread::yield();先阻塞者
}
然后如果出来了 就说明你获得锁了
{
。。。/ 这部分操作 原不原子 就另说了 取决于本身的操作
}

}





std::atomic_flag  ato_zhamen=ATOMIC_FLAG_INIT;   // 

atomic_int money(3); //原子变量 钱！
 
int main (int argc, char *argv[])
{
 
auto thread_func=[](){

  while(ato_zhamen.test_and_set())
  { //如果test_and_set 执行时候 test 之前就返回了true 说明锁被别人用着呢那就等待
    ;
  }
  cout<< this_thread::get_id()<<"溜了溜了"<<endl;
  this_thread::sleep_for(chrono::seconds(1));
  ato_zhamen.clear();
  
};

 std::vector<std::thread> ths;
  for (size_t i = 0; i < 10; i++)
  {
   ths.push_back(thread(thread_func));
  }

  for ( auto& i :ths)
  {
    i.join();
  }
  cout<<" OVER "<<endl;
  终于可以
