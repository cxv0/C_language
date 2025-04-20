#include "force_exit.h"
#include "config.h"
#include "input_pass.h"
#include "gtaccount.h"
#include "login.h"
#include "Avatarfunc.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Avatar function //�����˳�������л��˺����ڵĹ���
DATE:       2025/4/17
******/

void draw_avatarpage()
{
    setfillstyle(SOLID_FILL, YELLOW);
    clrmous(MouseX, MouseY);
    bar(500, 45, 640, 140);
    outtextxy(502, 47, output_account());
    setfillstyle(SOLID_FILL, RED);
    bar(502, 75, 638, 105);
    setfillstyle(SOLID_FILL, BLUE);
    bar(502, 108, 638, 138);
    puthz(502, 75, "�л��˺�", 24, 26, YELLOW);
    puthz(502, 108, "�˳�����", 24, 26, RED);
    newmouse(&MouseX, &MouseY, &press);
}

void Avatarfunc(int *click_able)
{
    if(mouse_press(502, 75, 638, 105) == 1 && *click_able == 1)
    {
        forceexit = 1;
    }
    else if(mouse_press(502, 108, 638, 138) == 1 && *click_able == 1)
    {
        delay(1500);
        exit(1);
    }
}