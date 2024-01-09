#include <graphics.h>
#include <time.h>
#include "mmsystem.h"//��ý����Ƶ�ӿ�
#pragma comment(lib,"winmm.lib")
#define SCREEN_WIDTH   1345   /*��Ļ�Ŀ��*/
#define SCREEN_HEIGHT   640    /*��Ļ�ĸ߶�*/
#define RAIN_NUM           200  // /*�ַ�������ͳһʱ���ж��ٸ��ַ�������

/*�������ַ���*///RAIN_NUMͬһʱ�����¶�����������  10ÿһ��10����ĸ
char  g_StrRain[RAIN_NUM][15] = { 0 };
/*�����꿪ʼ��λ��*/
POINT g_RainPos[RAIN_NUM] = { 0 };

//��ʼ����ĸ��λ��
void InitGame()
{
    /*�������������*/
    char RandChar = 0;
    for (int i = 0; i < RAIN_NUM; i++)
    {
        for (int j = 0; j < 15; j++)//ÿ��������10����ĸ
        {
            while (1)
            {
                RandChar = rand() % 123;//char���͵ķ�Χ-128 -127  �������0-123�м����
                //ASCII��� 65-90Ϊ��д��ĸ   97-122ΪСд�ַ�
                if ((RandChar >= 65 && RandChar <= 90) || (RandChar >= 97 && RandChar <= 122))
                    break;
            }
            g_StrRain[i][j] = RandChar;//�Ѳ������� ��ֵ������ַ�������  ����ַ���������char���ͻ�ת������ĸ
        }
    }

    /*�������λ��*/
    for (int i = 0; i < RAIN_NUM; i++)//����ÿһ���ַ��� �ܹ���RAIN_NUM��
    {
        g_RainPos[i].x = rand() % SCREEN_WIDTH;  //0-1345
        g_RainPos[i].y = rand() % SCREEN_HEIGHT;//0-640
    }
}
//��һ��������������¸�ֵ����Ϸ����
void UpdateGame()
{
    for (int i = 0; i < RAIN_NUM; i++)//����ÿһ�������꣬�ܹ���RAIN_NUM��
    {
        g_RainPos[i].y += 15;    //��ĸ�Ŀ��
        if (g_RainPos[i].y - 10 * 15 >= SCREEN_HEIGHT)//һ����ĸ�Ŀ��Ϊg_RainPos[i].y ��10*15��ĸ������ϵ���ĸ������
        {
            g_RainPos[i].x = rand() % SCREEN_WIDTH;//��һ����ĸ���³�ʼ��x��������������
            g_RainPos[i].y = 0;//�����������µ�һ����ĸ��y��û0
        }
    }
}
//��ӡ������
void RenderGame()
{
    BeginBatchDraw();//������ӡ
    cleardevice();  //�����Ļ
    //������forѭ����RAIN_NUM*10����ĸ��ӡ
    for (int i = 0; i < RAIN_NUM; i++)
    {
        //����������ɫ��RGBΪ������255��255��255 Ϊ��ɫ͸���ȴ�0-255
        settextcolor(RGB(rand() % 255, rand() % 255, rand() % 255));  //��ɫ ��һ����ĸ��ɫ
        for (int j = 0; j < 15; j++)
        {
            outtextxy(g_RainPos[i].x, g_RainPos[i].y - 15 * j, g_StrRain[i][j]);//g_RainPos[i].y - 15 * j�ӵ�һ����ĸ����ʮ����ĸ�����һ����ĸ��Y����
            settextcolor(RGB(0, 255 - 50 * j, 0));

            //settextcolor(RGB(rand() % 255, rand() % 255, rand() % 255));


        }
    }
    EndBatchDraw();//�����������ƣ������δִ�е�����
    Sleep(100);     //��ʱ0.1��    
}

int main()
{
    //initgraph(SCREEN_WIDTH,SCREEN_HEIGHT);


    //��������
    //GetSystemMetrics(SM_CXSCREEN)��ȡ��Ļ��
    //GetSystemMetrics(SM_CYSCREEN)��ȡ��Ļ��
    HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    //���ô��ڷ�� 
    //GetWindowLong������ô��ڷ��
    //GWL_STYLE���ڷ���һ�֣��趨һ���µĴ��ڷ��
    //WS_CAPTION����Ҫ����
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
    //���ô���λ��
    //�������������з���㴰��֮��HWND_TOPMOSTһ��λ��
    //���ڴ�С�Ͷ�λ��־SWP_SHOWWINDOW
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
    //����Ϊ͸�� 
    //�趨һ���µ���չ���GWL_EXSTYLE
    LONG WindowLong = GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
    //���ô��ڷ��
    SetWindowLong(hwnd, GWL_EXSTYLE, WindowLong);
    //�����޸�Ϊ��ɫ
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    srand((unsigned)time(NULL));
    mciSendString("open ����//xx.mp3", 0, 0, 0);
    mciSendString("play ����//xx.mp3", 0, 0, 0);
    InitGame();//���ó�ʼ�� 
    while (1)//������������������ѭ��
    {
        RenderGame();//���ô�ӡ�����꺯��
        UpdateGame();//��Ϸ���³�ʼ��������
    }
    closegraph();//�ر�ͼ�ο�
    return 0;
}