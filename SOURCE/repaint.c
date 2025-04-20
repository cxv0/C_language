#include "config.h"
#include "custom.h"

void repaint(int *page, int *num)  //重新绘制按钮
{
    if(*page == 0) //欢迎界面
    {
        setbkcolor(BLUE);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);  //不清除鼠标会有色块残留

        switch(*num)
        {
            case 1 :
            {
                bar(49, 400, 49 + 148, 430);
                puthz(49, 400, "登录", 32, 36, WHITE);
                break;
            }
            case 2 :
            {
                bar(49 + (148 + 49) * 1, 400, 49 + 148 + (148 + 49) * 1, 430);
                puthz(49 + 148 + 49, 400, "注册", 32, 36, WHITE);
                break;
            }
            case 3 :
            {
                bar(49 + (148 + 49) * 2, 400, 49 + 148 + (148 + 49) * 2, 430);
                puthz(49 + 148 + 49 + 148 + 49, 400, "退出", 32, 36, WHITE);
                break;
            }
            default : break;
        }
    }
    
    else if(*page == 1)
    {
        setbkcolor(BLUE);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);

        switch(*num)
        {
            case 1 :
            {
                bar(220, 330, 280, 360);
                puthz(220, 330, "重置", 24, 28, WHITE);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "完成", 24, 28, WHITE);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "返回", 24, 28, WHITE);
                break;
            }
            default : break;
        }
    }

    else if(*page == 2)
    {
        setbkcolor(BLUE);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);

        switch(*num)
        {
            case 1 :
            {
                bar(220, 330, 280, 360);
                puthz(220, 330, "重置", 24, 28, WHITE);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "完成", 24, 28, WHITE);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "返回", 24, 28, WHITE);
                break;
            }
            default : break;
        }
    }

    else if(*page == 3) //首页
    {
        setbkcolor(CYAN);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);

        switch(*num)
        {
            case 2 :
            {
                bar(167, 422, 318, 458);
                puthz(167, 422, "快递", 32, 36, WHITE);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "外卖", 32, 36, WHITE);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "我的", 32, 36, WHITE);
                break;
            }
            default : break;
        }
    }

    else if(*page == 4) //快递页
    {
        setbkcolor(CYAN);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);

        switch(*num)
        {
            case 1 :
            {
                bar(12, 422, 163, 458);
                puthz(12, 422, "首页", 32, 36, WHITE);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "外卖", 32, 36, WHITE);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "我的", 32, 36, WHITE);
                break;
            }
            default : break;
        }
    }
    
}