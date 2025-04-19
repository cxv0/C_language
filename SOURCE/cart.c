#include "config.h"
#include"cart.h"
#include "order.h"

void draw_cartlist()
{

    int i;
    setbkcolor(LIGHTGRAY);
    setcolor(RED);
    setfillstyle(SOLID_FILL, GREEN);

    bar(250,410,430,450);
    bar(570,445,630,475);

    puthz(280,415,"ȷ�Ϲ���",24,28,WHITE);
    puthz(570,445,"����",24,28,WHITE);

    
    puthz(10,20,"��Ʒ����",24,28,RED);
    puthz(300,20,"�۸�",24,28,RED);
    puthz(560,20,"����",24,28,RED);
    puthz(540,400,"�ܼ�",24,28,RED);

    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, 1);
    for(i=0;i<16;i++)
    {
        line(20,100+20*i,620,100+20*i);
    }

}

int cartfunc(INFO (*t)[16])
{
    int num = 0;

    clrmous(MouseX, MouseY);
    cleardevice();
    draw_cartlist();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(250,410,430,450) == 2) //ȷ�Ϲ���
        {
            MouseS = 1;
            num = 1;
            continue;
        }

        else if(mouse_press(250,410,430,450) == 1) //ȷ�Ϲ���
        {
            MouseS = 0;
            continue;
        }

        else if(mouse_press(570,445,630,475) == 2) //����
        {
            MouseS = 1;
            num = 2;
            continue;
        }

        else if(mouse_press(570,445,630,475) == 1) //����
        {
            MouseS = 0;
            return 5;
        }
        else
        {
            if(num != 0)
            {
                MouseS = 0;
                num = 0;
            }
        }

    }
}