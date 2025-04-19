#include "config.h"
#include "expressage.h"
#include "package.h"
#include "order.h"
#include "real_time.h"
#include "Avatarfunc.h"


/******
COPYRIGHT: Jiang Yihan
FUNCTION:  Expressage function //��ݽ���
DATE:      2025/3/9
******/

void draw_expage()
{

    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 10, 150, 40); // ʱ���
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 12, 148, 38);

    bar(170, 10, 580, 40); // ������

    //�������Ͻ�ͷ��
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(10, 60, 630, 410);

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(80, 360, 260, 400); //һ����ȡ

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(380, 360, 560, 400); //��ӿ��

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
    floodfill(171, 428, YELLOW);
    puthz(12, 422, "��ҳ", 32, 36, WHITE);
    puthz(167, 422, "���", 32, 36, RED);
    puthz(322, 422, "����", 32, 36, WHITE);
    puthz(477, 422, "�ҵ�", 32, 36, WHITE);
    puthz(90, 370, "һ����ȡ", 32, 36, DARKGRAY);
    puthz(390, 370, "��ӿ��", 32, 36, DARKGRAY);
    puthz(20,60,"�������",32,36,DARKGRAY);
    puthz(220,60,"�Ĵ��",32,36,DARKGRAY);
    puthz(20,60,"�������",32,36,DARKGRAY);
    puthz(220,60,"�Ĵ��",32,36,DARKGRAY);

}



int expagefunc()
{
    int num = 0;
    int *avatar_state = 0;
    unsigned char *m;
    unsigned char q=0;
    m=&q;

    clrmous(MouseX, MouseY);
    cleardevice();
    draw_expage();
    output_package();
      
    
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        real_time(m, avatar_state);
        

        if(mouse_press(167, 422, 318, 458) == 2) //��ݿ�
        {
            MouseS = 1;
            num = 2;
            continue;
        }

        else if(mouse_press(167, 422, 318, 458) == 1) //��ݿ�
        {
            MouseS = 0;
            continue;
        }

        else if(mouse_press(12, 422, 163, 458) == 2) //��ҳ��
        {
            
            if(num == 0)
            {
                MouseS = 1;
                num = 1;
            }
            continue;
        }

        else if(mouse_press(12, 422, 163, 458) == 1) //��ҳ��
        {
            MouseS = 0;
            return 3;
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

        else if(mouse_press(80, 360, 260, 400) == 2) //��ȡ��
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 5;
            }
            continue;
        }

        else if(mouse_press(80, 360, 260, 400) == 1)
        {
            MouseS = 0;
            clrmous(MouseX,MouseY);
            delpackage();
            inredraw();
            real_time(m, avatar_state);
            continue;
        }
        
        else if(mouse_press(380, 360, 460, 400) == 2) //��Ӽ�
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 6;
            }
            continue;
        }

        else if(mouse_press(380, 360, 460, 400) == 1)
        {
            MouseS = 0;
            clrmous(MouseX,MouseY);
            addpackage();
            inredraw();
            real_time(m, avatar_state);
            continue;
        }

        // else if (mouse_press(280, 380, 300, 400) == 2)//��ҳ
        // {
        //     if (num == 0)
        //     {
        //         MouseS = 1;
        //     }
        //     continue;
        // }
        // else if (mouse_press(280, 380, 300, 400) == 1)
        // {
        //     MouseS = 0;
        //     if (page == 1)
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         if (page != 1)
        //         {
        //             page--;
        //             clrmous(MouseX, MouseY);
        //             inredraw(page,hust,&state);
        //         }
        //         continue;
        //     }
        // }
        // else if (mouse_press(340, 380, 360, 400) == 2)//��ҳ
        // {
        //     if (num == 0)
        //     {
        //         MouseS = 1;
        //     }
        //     continue;
        // }
        // else if (mouse_press(340, 380, 360, 400) == 1)
        // {
        //     MouseS = 0;
        //     if (state == 1)
        //     {
        //         page++;
        //         clrmous(MouseX, MouseY);
        //         inredraw(page,hust,&state);
        //     }
        //     continue;
        // }

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



void inredraw()
{

    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    bar(170, 10, 580, 40); // ������

    //�������Ͻ�ͷ��
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(10, 60, 630, 410);

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(80, 360, 260, 400); //һ����ȡ

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(380, 360, 560, 400); //��ӿ��

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
    floodfill(171, 428, YELLOW);
    puthz(12, 422, "��ҳ", 32, 36, WHITE);
    puthz(167, 422, "���", 32, 36, RED);
    puthz(322, 422, "����", 32, 36, WHITE);
    puthz(477, 422, "�ҵ�", 32, 36, WHITE);
    puthz(90, 370, "һ����ȡ", 32, 36, DARKGRAY);
    puthz(390, 370, "��ӿ��", 32, 36, DARKGRAY);
    puthz(20,60,"�������",32,36,DARKGRAY);
    puthz(220,60,"�Ĵ��",32,36,DARKGRAY);

    output_package();
}