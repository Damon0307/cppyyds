
根据上述概念的组合，我们可以将常见的 I/O 操作归属不同的 I/O 模型：

同步模型（synchronous I/O ）
 
多路复用 I/O （multiplexing I/O ）
利用select和epoll等函数同时监视多个socket，本质上是非阻塞 I/O ，但这些监视函数在轮询时是阻塞的，因此将 I/O 请求阻塞在这些监视函数上了，用户进程不需要轮询数据是否准备好了。

信号驱动式 I/O （signal-driven I/O ）
系统会为监视的数据准备设置信号，用户进程进行 I/O 请求之后，不会阻塞，当内核数据准备完毕，会通过信号通知用户进程，随后进行 I/O 操作。
异步 I/O （asynchronous I/O ）

异步 I/O
向内核中传递 I/O 操作参数，并立即返回。内核 I/O 操作完毕后，通过回调函数的方式通知用户进程。

关于这些 I/O 模型的概念，网上就太多重复的了，此处给出一篇参考：I/O 模型详解
 
 
# 山雨欲来风满楼 
## serial_port_plotter

# 这是一个新的标题


你一句 唯有长江天际流，我就真的(两个空格+回车 才可以换行)  
烟花三月下扬州

 
也许表中的***cloud***是**真**的在线（两个** 加粗 三个是斜体）

>目前来看，从外部传入动画ID给 CNode 节点的方法可行  
> 这个箭头是引用段落的意思  
>>从左到有动画可以做 ，就是把下面的content_w 改的要足够大

# 这是你喜欢的圆点 
>* hello    

1. 这就是普通的有序列表
2. 只不过上面就不需要换行了
3.
4.
  
# 代码块
        for (int i =0;i<10; i++)
        {
            printf("hello this is the code block\n");
        }


***山僧对棋坐，局上竹叶青***  
***映竹无人见，时闻下子声***  
***小娃撑小艇，偷采白莲回。不解藏踪迹，浮萍一道开***

 多一事不如少一事
 --[[  
    if seq == most_close_seq and tonumber(most_close_seq) > tonumber(current_expand_seq) then -- string 类型相互比较
        print("god i hate u 需要强制设置层的偏移量")
        for _, v in pairs(G_UINodeList) do
            if v.control_key == mapargs.context_control then
                print("v:getXvalue() ", v:getXvalue())
                gre.set_layer_attrs_global(
                    "NML",
                    {
                        xoffset = -v:getXvalue() + 405
                    }
                )
            end
        end
    end
    --对于层偏移的控制  也许有用
    if most_close_seq ~= "" and tonumber(seq) == tonumber(most_close_seq) - 1 then
        print("god i hate u 你竟然颠倒了更左边的位置")
        for _, v in pairs(G_UINodeList) do
            if v.control_key == mapargs.context_control then
                print("v:getXvalue() ", v:getXvalue())
                gre.set_layer_attrs_global(
                    "NML",
                    {
                        xoffset = -v:getXvalue() + 400
                    }
                )
            end
        end
    end
]]
 
lua check 得搞一下静态分析
 
 
‘在线烘’功能
 
mathbit 
 
老李的生产测试
awesome cpp

多语言  直接用JSON 做
然后 绑定一个 事件监听

 
# 避免信息泄露的方法  
## 信息隐藏， 别掉进去 时间分解的陷阱
### 出现这个问题的现象
>* 太多的类 
>they 经常设计出大量的浅层类，但是你单独使用一个类的时候又完成不了很多事情，需要借助其他的类，这导致了类之前的信息泄露
>当两个类中大量的信息逻辑是重复的，尽量把这两个类合并，可以起到提供更简单且更高级的接口
 
当分解系统模块时候 ，尽量不要按照 面向过程的思路分解下去（尤其是时间 temporal decomposition）,尽量按照每个阶段所需要的
知识来进行分解， 并将每个模块尽量封装好所需要的一个或几个知识
 
Utools  牛逼

# 通用模块更深入
> 模块也许是为了 today's needs 开发的， 但是接口一定是通用的
> 类的设计目标之一是 这个类可以进行独立开发
> 通用接口比专用接口具有许多优点，使用的方法更少，他还提供了类之间更清晰的间隔，  
> 而专用接口则倾向于在类之间泄漏信息。使模块具有某种通用性是降低整体系统复杂性的最佳方法之一。
> 
# 不同的层，不同的抽象
## Red Flag 直通方法（直通方法是一种不执行任何操作的方法，只是将其参数传递给另一个方法，通常使用与直通方法相同的 API。这通常表示各类之间没有明确的职责划分。
## 具有类似名称方法有用的场景
1. 分派器 它可以选择其他几种中的任一种来执行任务

# 注释的必要性
1. 注释应该描写代码中不明显的内容
2. 在记录变量时候，请考虑名词而不是动词，换句话说就是关注变量代表什么，而不是如何操作这个变量

# AUTOSAR cooperation on standards. compete on implementation  
> 标准的出现不仅实现了解耦,还让同一份代码高效的集成到不同的地方，被大量重复使用，发现bug的概率大大提高，从而可以很快的得到修补.

# 需要做隔离的地方

1.  云程序卡片释放  function NM_Cloud_Released(mapargs) 没有用到mapargs
2.  云程序卡片按下 在按住以后滑动也属于释放 function NM_Cloud_Press(mapargs) 用到了mapargs
3.  云程序卡片释放 function NM_Cloud_Released(mapargs) 没有用到mapargs   
4.  function NM_UINodeTouchSmooth(mapargs) 用到了mapargs 
5.  层正在滑动的信号已经绑定在 NML grd_xoffset 上,滑动的时候会自动发出信号
 

0621
完善各策略下云程序入口

在云程序情况只刷新数据

 应该退出云程序的情况
 {
切换上下筒
选择策略
离开/进入 主界面
 }
 
# 基于范围的for 循环
## algorithm

for_each 竟然是藏在 algorithm的  记住 for_each 和 C# foreach 是不同的，后面是基于范围的， 不需要限定容器的两端
前面这个 for_each 是需要这样使用的  std::for_each(arr.begin(), arr.end(), func)
 

欢迎界面需要处理  主动升级  已修复

用户扫码登录体验优化   ing 

 DE_UpdateRemindInfo 加入 进度条丢失处理
 
云程序时候  结束菜单与 运行效果 重叠
 
烘干羊毛 温度只有两个
 
欢迎界面停留问题

"NML.M_NEWUI_01.precision_x"

下发一个  notification    G_Notification_ENUM

云程序断电记忆洗  --done 
 
 https://zhuanlan.zhihu.com/p/162015675  chrome 设置黑色


C++11 增加了std::function 和std::bind，不仅让我们使用标准库函数时变得更加方便，
而且还能方便地实现延迟求值。
 
18.5 
9 
4.5
 
 
状态中心里的新风防皱取消掉。        --done
上筒 烘干程序，参数选项中的干燥程度改为干燥度。   --done
定时类程序，启动后，烘干时间应该不可调   --wpdone
上筒防皱结束的时候，还是显示防皱中，没有结束蜂鸣音，防皱结束后，不要再体现防皱中的字样了，结束要有蜂鸣音
判干类程序，在程序列表界面，显示：  干燥度 储藏  温度 高温  定时类程序，在程序列表界面，显示：  温度  高温。 --done


 下筒洗涤 桶里有水  暂停 返回 等待LOCK报警  点LOCK 确定 界面异常

 todo 
 "Detail_Self_Info_Layer"

云程序的请求点击过滤   --done
 

上筒 冷却 1分钟 不进入      防皱时间已开始递减
下筒 洗涤完成  丝绸   默认参数
 
智能排序 上筒 AUTO  分 丢失 --done

底部导航栏显示优化  

背景框再改回来 

拉高出货一般是3-5个点  3个点时候我出过 广东鸿图 结果他妈的他涨到了10个点，然后周一近乎跌停


 