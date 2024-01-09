#include <graphics.h>
#include <time.h>
#include "mmsystem.h"//多媒体音频接口
#pragma comment(lib,"winmm.lib")
#define SCREEN_WIDTH   1345   /*屏幕的宽度*/
#define SCREEN_HEIGHT   640    /*屏幕的高度*/
#define RAIN_NUM           200  // /*字符串数量统一时间有多少个字符串落下

/*数字雨字符串*///RAIN_NUM同一时间落下多少条数字雨  10每一条10个字母
char  g_StrRain[RAIN_NUM][15] = { 0 };
/*数字雨开始的位置*/
POINT g_RainPos[RAIN_NUM] = { 0 };

//初始化字母和位置
void InitGame()
{
    /*随机生成数字雨*/
    char RandChar = 0;
    for (int i = 0; i < RAIN_NUM; i++)
    {
        for (int j = 0; j < 15; j++)//每条数字雨10个字母
        {
            while (1)
            {
                RandChar = rand() % 123;//char类型的范围-128 -127  随机产生0-123中间的数
                //ASCII码表 65-90为大写字母   97-122为小写字符
                if ((RandChar >= 65 && RandChar <= 90) || (RandChar >= 97 && RandChar <= 122))
                    break;
            }
            g_StrRain[i][j] = RandChar;//把产生的数 赋值给这个字符串数组  这个字符串数组是char类型会转换成字母
        }
    }

    /*随机生成位置*/
    for (int i = 0; i < RAIN_NUM; i++)//遍历每一条字符串 总共有RAIN_NUM条
    {
        g_RainPos[i].x = rand() % SCREEN_WIDTH;  //0-1345
        g_RainPos[i].y = rand() % SCREEN_HEIGHT;//0-640
    }
}
//当一数字雨落完后重新赋值即游戏更新
void UpdateGame()
{
    for (int i = 0; i < RAIN_NUM; i++)//遍历每一条数字雨，总共有RAIN_NUM条
    {
        g_RainPos[i].y += 15;    //字母的宽度
        if (g_RainPos[i].y - 10 * 15 >= SCREEN_HEIGHT)//一个字母的宽度为g_RainPos[i].y ，10*15字母就是最顶上的字母的坐标
        {
            g_RainPos[i].x = rand() % SCREEN_WIDTH;//第一个字母重新初始化x，从最上面落下
            g_RainPos[i].y = 0;//从最上面落下第一个字母的y的没0
        }
    }
}
//打印数字雨
void RenderGame()
{
    BeginBatchDraw();//批量打印
    cleardevice();  //清空屏幕
    //用两个for循环给RAIN_NUM*10个字母打印
    for (int i = 0; i < RAIN_NUM; i++)
    {
        //设置字体颜色，RGB为红绿蓝255，255，255 为颜色透明度从0-255
        settextcolor(RGB(rand() % 255, rand() % 255, rand() % 255));  //白色 第一个字母白色
        for (int j = 0; j < 15; j++)
        {
            outtextxy(g_RainPos[i].x, g_RainPos[i].y - 15 * j, g_StrRain[i][j]);//g_RainPos[i].y - 15 * j从第一个字母到第十个字母的最后一个字母的Y坐标
            settextcolor(RGB(0, 255 - 50 * j, 0));

            //settextcolor(RGB(rand() % 255, rand() % 255, rand() % 255));


        }
    }
    EndBatchDraw();//结束批量绘制，并完成未执行的任务
    Sleep(100);     //延时0.1秒    
}

int main()
{
    //initgraph(SCREEN_WIDTH,SCREEN_HEIGHT);


    //创建窗口
    //GetSystemMetrics(SM_CXSCREEN)获取屏幕宽
    //GetSystemMetrics(SM_CYSCREEN)获取屏幕高
    HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    //设置窗口风格 
    //GetWindowLong（）获得窗口风格
    //GWL_STYLE窗口风格的一种，设定一个新的窗口风格
    //WS_CAPTION标题要减掉
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
    //设置窗口位置
    //将窗口置于所有非最顶层窗口之上HWND_TOPMOST一个位置
    //窗口大小和定位标志SWP_SHOWWINDOW
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
    //设置为透明 
    //设定一个新的扩展风格。GWL_EXSTYLE
    LONG WindowLong = GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
    //设置窗口风格
    SetWindowLong(hwnd, GWL_EXSTYLE, WindowLong);
    //背景修改为黑色
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    srand((unsigned)time(NULL));
    mciSendString("open 音乐//xx.mp3", 0, 0, 0);
    mciSendString("play 音乐//xx.mp3", 0, 0, 0);
    InitGame();//调用初始化 
    while (1)//无线落下数字雨用死循环
    {
        RenderGame();//调用打印数字雨函数
        UpdateGame();//游戏更新初始化数字雨
    }
    closegraph();//关闭图形库
    return 0;
}