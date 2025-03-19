#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Homepage function //首页
DATE:       2025/3/4
******/

void draw_homepage()
{
    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 10, 150, 40); // 时间框
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 12, 148, 38);

    // 绘制搜索框
    bar(170, 10, 580, 40); // 搜索框

    //绘制右上角头像
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    // 绘制左侧通知栏
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 60, 150, 400); // 通知栏
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 148, 398);

    // 绘制右侧消费情况
    setfillstyle(SOLID_FILL, YELLOW);
    bar(170, 60, 630, 400); // 消费情况
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(172, 62, 628, 398);

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
    floodfill(16, 428, YELLOW);
    puthz(12, 422, "首页", 32, 36, RED);
    puthz(167, 422, "快递", 32, 36, WHITE);
    puthz(322, 422, "外卖", 32, 36, WHITE);
    puthz(477, 422, "我的", 32, 36, WHITE);
}



void homefunc(int *page, int *num)
{
    unsigned char q = 0;
    unsigned char *m;
    m = &q;

    if(*page == 3)
    {
        clrmous(MouseX, MouseY);
        cleardevice();
        draw_homepage();

        while(1)
        {
            newmouse(&MouseX, &MouseY, &press);
            real_time(m);
        
            if(mouse_press(12, 422, 163, 458) == 2) //首页框
            {
                MouseS = 1;
                *num = 1;
                continue;
            }

            else if(mouse_press(12, 422, 163, 458) == 1) //首页框
            {
                MouseS = 1;
                *num = 1;
                continue;
            }

            else if(mouse_press(167, 422, 318, 458) == 2) //快递框
            {
                MouseS = 1;
                if(*num == 0)
                {
                    *num = 2;
                    *page = 3;
                    hlbutton(page, num);
                }
                continue;
            }

            else if(mouse_press(167, 422, 318, 458) == 1) //快递框
            {
                MouseS = 1;
                *num = 2;
                *page = 4;
                break;
            }

            else if(mouse_press(322, 422, 473, 458) == 2) //外卖框
            {
                MouseS = 1;
                if(*num == 0)
                {
                    *num = 3;
                    *page = 3;
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
                    *page = 3;
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

    if(*page == 4) //不用elseif是因为这样会跳过执行其他elseif语句
    {
        expagefunc(page, num);
    }
    
}