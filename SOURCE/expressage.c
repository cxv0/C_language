#include "config.h"
#include "custom.h"

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

    // ������๦����
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 60, 150, 160); //ȡ��
    bar(10, 180, 150, 280); //�ļ�
    bar(10, 300, 150, 400); //��������
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 148, 158);
    bar(12, 182, 148, 278);
    bar(12, 302, 148, 398);
    puthz(12, 62, "ȡ��", 32, 36, WHITE);
    puthz(12, 182, "�ļ�", 32, 36, WHITE);
    puthz(12, 302, "", 32, 36, WHITE);

    // �����Ҳ๦����
    setfillstyle(SOLID_FILL, YELLOW);
    bar(170, 10, 630, 400);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(172, 12, 628, 398);

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

            if(mouse_press(167, 422, 318, 458) == 2) //��ݿ�
            {
                MouseS = 1;
                *num = 2;
                continue;
            }

            else if(mouse_press(167, 422, 318, 458) == 1) //��ݿ�
            {
                MouseS = 1;
                *num = 2;
                continue;
            }

            else if(mouse_press(12, 422, 163, 458) == 2) //��ҳ��
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

            else if(mouse_press(12, 422, 163, 458) == 1) //��ҳ��
            {
                MouseS = 1;
                *num = 1;
                *page = 3;
                break;
            }

            else if(mouse_press(322, 422, 473, 458) == 2) //������
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

            else if(mouse_press(322, 422, 473, 458) == 1) //������
            {
                MouseS = 1;
                *num = 3;
                *page = 5;
                break;
            }

            else if(mouse_press(477, 422, 628, 458) == 2) //�ҵĿ�
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

            else if(mouse_press(477, 422, 628, 458) == 1) //�ҵĿ�
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

