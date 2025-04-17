#include "config.h"
#include "custom.h"


/******
initmenu.c
COPYRIGHT:  Jiang Yihan
FUNCTION:   页面跳转
DATE:       2025/2/17
******/

void welcome_page()
{
    int i;

    setbkcolor(BLUE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    moveto(64, 64);
    lineto(576, 64);
    lineto(576, 128);
    lineto(64, 128);
    lineto(64, 64);

    bar(64, 64, 576, 128);

    for(i = 0; i < 3; i ++)
    {
        moveto(49 + (148 + 49) * i, 400);
        lineto(49 + 148 + (148 + 49) * i, 400);
        lineto(49 + 148 + (148 + 49) * i, 430);
        lineto(49 + (148 + 49) * i, 430);
        lineto(49 + (148 + 49) * i, 400);
    }
    
    for(i = 0; i < 3; i ++)
    {
        bar(49 + (148 + 49) * i, 400, 49 + 148 + (148 + 49) * i, 430);
    }

    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);

    puthz(64, 64, "校园快递外卖投递系统", 32, 36, WHITE);
    puthz(49, 400, "登录", 32, 36, WHITE);
    puthz(49 + 148 + 49, 400, "注册", 32, 36, WHITE);
    puthz(49 + 148 + 49 + 148 + 49, 400, "退出", 32, 36, WHITE);

}



int initmenu()
{
    int num=0;
    clrmous(MouseX, MouseY);
    cleardevice();
    welcome_page();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(49, 400, 49 + 148, 430) == 2) 
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 1;
            }
            continue;
        }

        else if(mouse_press(49, 400, 49 + 148, 430) == 1) 
        {
            MouseS = 0;
            return 1;
        }

        else if(mouse_press(49 + (148 + 49) * 1, 400, 49 + (148 + 49) * 1 + 148, 430) == 2)  
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 2;
            }
            continue;
        }

        else if(mouse_press(49 + (148 + 49) * 1, 400, 49 + (148 + 49) * 1 + 148, 430) == 1)  
        {
            MouseS = 0;
            return 2;
        }

        else if(mouse_press(49 + (148 + 49) * 2, 400, 49 + (148 + 49) * 2 + 148, 430) == 2)  
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 3;
            }
            continue;
        }

        else if(mouse_press(49 + (148 + 49) * 2, 400, 49 + (148 + 49) * 2 + 148, 430) == 1)  
        {
            MouseS = 0;
            delay(200);
            exit(EXIT_SUCCESS);
        }
   
        else
        {
            if(num != 0)
            {
                MouseS = 0;
                num = 0;
            }
            continue;
        }
    }
}