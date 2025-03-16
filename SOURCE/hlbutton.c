#include "config.h"
#include "custom.h"

void hlbutton(int *page, int *num)
{  
    if(*page == 0) //1登录2注册3退出
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 1 :
            {
                bar(49, 400, 49 + 148, 430);
                puthz(49, 400, "登录", 32, 36, RED);
                break;
            }
            case 2 :
            {
                bar(49 + (148 + 49) * 1, 400, 49 + 148 + (148 + 49) * 1, 430);
                puthz(49 + 148 + 49, 400, "注册", 32, 36, RED);
                break;
            }
            case 3 :
            {
                bar(49 + (148 + 49) * 2, 400, 49 + 148 + (148 + 49) * 2, 430);
                puthz(49 + 148 + 49 + 148 + 49, 400, "退出", 32, 36, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 1) //1重置2完成3返回
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);

        switch(*num)
        {
            case 1 :
            {
                bar(220, 330, 280, 360);
                puthz(220, 330, "重置", 24, 28, RED);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "完成", 24, 28, RED);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "返回", 24, 28, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 2) //1重置2完成3返回
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 1 :
            {
                bar(220, 330, 280, 360);
                puthz(220, 330, "重置", 24, 28, RED);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "完成", 24, 28, RED);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "返回", 24, 28, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 3) //首页 //1首页2快递3外卖4我的
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 2 :
            {
                bar(167, 422, 318, 458);
                puthz(167, 422, "快递", 32, 36, RED);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "外卖", 32, 36, RED);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "我的", 32, 36, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 4) //快递页 //1首页2快递3外卖4我的5取件6寄件7待定功能
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 1 :
            {
                bar(12, 422, 163, 458);
                puthz(12, 422, "首页", 32, 36, RED);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "外卖", 32, 36, RED);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "我的", 32, 36, RED);
                break;
            }
            default : break;
        }
    }
}