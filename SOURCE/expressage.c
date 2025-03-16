#include "config.h"
#include "custom.h"

/******
COPYRIGHT: Jiang Yihan
FUNCTION:  Expressage function //快递界面
DATE:      2025/3/9
******/

void draw_expage()
{
    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 10, 150, 40); // 时间框
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 12, 148, 38);

    // 绘制左侧功能栏
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 60, 150, 160); //取件
    bar(10, 180, 150, 280); //寄件
    bar(10, 300, 150, 400); //待定功能
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 148, 158);
    bar(12, 182, 148, 278);
    bar(12, 302, 148, 398);
    puthz(12, 62, "取件", 32, 36, WHITE);
    puthz(12, 182, "寄件", 32, 36, WHITE);
    puthz(12, 302, "", 32, 36, WHITE);

    // 绘制右侧功能栏
    setfillstyle(SOLID_FILL, YELLOW);
    bar(170, 10, 630, 400);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(172, 12, 628, 398);

    // 绘制底部菜单栏
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 420, 165, 460); // 首页
    bar(165, 420, 320, 460); // 快递
    bar(320, 420, 475, 460); // 外卖
    bar(475, 420, 630, 460); // 我的
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 422, 163, 458); // 首页
    bar(167, 422, 318, 458); // 快递
    bar(322, 422, 473, 458); // 外卖
    bar(477, 422, 628, 458); // 我的
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(171, 428, YELLOW);
    puthz(12, 422, "首页", 32, 36, WHITE);
    puthz(167, 422, "快递", 32, 36, RED);
    puthz(322, 422, "外卖", 32, 36, WHITE);
    puthz(477, 422, "我的", 32, 36, WHITE);
}

void expagefunc(int *page, int *num)
{
    unsigned char *m;
    time_t now;
    struct tm *local_time;
    char time_str[20];
    *m=00;

    if(*page == 4)
    {
        clrmous(MouseX, MouseY);
        cleardevice();
        draw_expage();

        while(1)
        {
            newmouse(&MouseX, &MouseY, &press);
            real_time(m);

            if(mouse_press(167, 422, 318, 458) == 2) //快递框
            {
                MouseS = 1;
                *num = 2;
                continue;
            }

            else if(mouse_press(167, 422, 318, 458) == 1) //快递框
            {
                MouseS = 1;
                *num = 2;
                continue;
            }

            else if(mouse_press(12, 422, 163, 458) == 2) //首页框
            {
                MouseS = 1;
                if(*num == 0)
                {
                    *num = 1;
                    *page = 4;
                    hlbutton(page, num);
                }
                continue;
            }

            else if(mouse_press(12, 422, 163, 458) == 1) //首页框
            {
                MouseS = 1;
                *num = 1;
                *page = 3;
                break;
            }

            else if(mouse_press(322, 422, 473, 458) == 2) //外卖框
            {
                MouseS = 1;
                if(*num == 0)
                {
                    *num = 3;
                    *page = 4;
                    hlbutton(page, num);
                }
                continue;
            }

            else if(mouse_press(322, 422, 473, 458) == 1) //外卖框
            {
                MouseS = 1;
                *num = 3;
                *page = 5;
                break;
            }

            else if(mouse_press(477, 422, 628, 458) == 2) //我的框
            {
                MouseS = 1;
                if(*num == 0)
                {
                    *num = 4;
                    *page = 4;
                    hlbutton(page, num);
                }
                continue;
            }

            else if(mouse_press(477, 422, 628, 458) == 1) //我的框
            {
                MouseS = 1;
                *num = 4;
                *page = 6;
                break;
            }
            
            else
            {
                MouseS = 0;
                if(*num != 0)
                {
                    repaint(page, num);
                    *num = 0;
                }
                continue;
            }
        }
    }
    
    if(*page == 3)
    {
        homefunc(page, num);
    }

    if(*page == 5)
    {
        
    }
}

