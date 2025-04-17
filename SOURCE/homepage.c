#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Homepage function //��ҳ
DATE:       2025/3/4
******/


extern float cost[20];
extern int shuzi;

void draw_homepage()
{
    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(60, 10, 150, 40); // ʱ���
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(62, 12, 148, 38);

    // ����������
    bar(170, 10, 580, 40); // ������

    //�������Ͻ�ͷ��
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    // �������֪ͨ��
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 60, 150, 400); // ֪ͨ��
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 148, 398);

    // �����Ҳ��������
    bar(170, 60, 630, 400); // �������

    // ���Ƶײ��˵���
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 420, 165, 460); // ��ҳ
    bar(165, 420, 320, 460); // ���
    bar(320, 420, 475, 460); // ����
    bar(475, 420, 630, 460); // �ҵ�
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 422, 163, 458); // ��ҳ
    bar(167, 422, 318, 458); // ���
    bar(322, 422, 473, 458); // ����
    bar(477, 422, 628, 458); // �ҵ�
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(16, 428, YELLOW);
    puthz(12, 422, "��ҳ", 32, 36, RED);
    puthz(167, 422, "���", 32, 36, WHITE);
    puthz(322, 422, "����", 32, 36, WHITE);
    puthz(477, 422, "�ҵ�", 32, 36, WHITE);
}



int homefunc()
{
    int num=0;
    unsigned char *m;
    unsigned char q=0;
    m=&q;

    clrmous(MouseX, MouseY);
    cleardevice();
    draw_homepage();
    draw_line();

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        real_time(m);
    
        if(mouse_press(12, 422, 163, 458) == 2) //��ҳ��
        {
            MouseS = 1;
            num = 1;
            continue;
        }

        else if(mouse_press(12, 422, 163, 458) == 1) //��ҳ��
        {
            MouseS = 0;
            continue;
        }

        else if(mouse_press(167, 422, 318, 458) == 2) //��ݿ�
        {
            
            if(num == 0)
            {
                MouseS = 1;
                num = 2;
            }
            continue;
        }

        else if(mouse_press(167, 422, 318, 458) == 1) //��ݿ�
        {
            MouseS = 0;
            return 4;
        }

        else if(mouse_press(322, 422, 473, 458) == 2) //������
        {
            
            if(num == 0)
            {
                MouseS = 1;
                num = 3;
            }
            continue;
        }

        else if(mouse_press(322, 422, 473, 458) == 1) //������
        {
            MouseS = 0;
            return 5;
        }

        else if(mouse_press(477, 422, 628, 458) == 2) //�ҵĿ�
        {
           
            if(num == 0)
            {
                MouseS = 1;
                num = 4;
            }
            continue;
        }

        else if(mouse_press(477, 422, 628, 458) == 1) //�ҵĿ�
        {
            MouseS = 0;
            return 6;
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





void draw_line()
{
    int i,temp,num1,num2;
    temp = shuzi;
    setcolor(RED);
    if(temp > 0)
    {
        for(i=0;i<temp;i++)
        {
            num1 = cost[i];
            if(i == 0)
            {
                num2 = 0;
            }
            if(i!=0)
            {
                num2 = cost[i - 1];
            }
            line(170 + ((460 / (temp + 1)) * i), 400 - (num2/2), 170 + ((460 / (temp + 1)) * (i + 1)), 400 - (num1/2));
        }
    }
    
}