#include "LRunTime.h"
 
 using namespace std;
 
void LRunTime::ShowReadme()
{
    printf("该类主要聚标运行时后 C++11给我们带来的变化 ：lambda function bind\
    这些玩意主要就是想实现多态 \n");
     printf("注意lambda 的延迟调用，在值传递时候它只捉住定义lambda之前的变量的状态，之后变量的改变并不会被捕捉到，\
     如果想获得任意状态的值 需要进行引用捕捉,看来还是直接这样[&] 比较方便\n");

 }
void  LRunTime::RunTest()
{
    // int fuck = 1;
    // auto ff=[fuck](){
    //     printf("观察我的值:%d\n",fuck);
    // };
    // auto ff_1=[&fuck](){
    //     printf("观察我的值:%d\n",fuck);
    // };
    // fuck=66;
    // ff();  // wocao 当值传递时候 值是1  即使ff 在后面运行！！！
    // ff_1();

    mCallOnBtn = [](const string& text){
        cout<<"lambda dealed the"<<text<<endl;
    };
    
    mCallOnBtn("2:30 下班");  


    unique_ptr<LDagong>uni_dagong(new LDagong());
//绑定一个类成员函数， 注意前面是提供 函数指针，后面提供一个对象，然后 占位符留着传递参数
    mCallOnBtn = std::bind(&LDagong::DagongRen,uni_dagong.get(),placeholders::_1);

    mCallOnBtn("这个 可是 类成员函数呢");

}