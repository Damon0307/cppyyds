#include "Util.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

Util::Util(/* args */)
{
}

Util::~Util()
{
}

string Util::Util_GetTopInfo()
{
     
    char buffer[102400]={0};                         //定义缓冲区                        
    FILE* pipe = popen("top -n 1", "r");            //打开管道，并执行命令 
    if (!pipe)
          return "error";                      //返回0表示运行失败 
 
    while(read(fileno(pipe), buffer, sizeof(buffer)-1) > 0)
        {
            printf("len=%d, %s\n", strlen(buffer), buffer);
            
        }

    pclose(pipe);                            //关闭管道                                 //返回1表示运行成功 
        return  string(buffer,102400);

}
 