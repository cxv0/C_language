#include "config.h"
#include "custom.h"

void repaint(int *page, int *num)  //���»��ư�ť
{
    if(*page == 0) //��ӭ����
    {
        setbkcolor(BLUE);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);  //�����������ɫ�����

        switch(*num)
        {
            case 1 :
            {
                bar(49, 400, 49 + 148, 430);
                puthz(49, 400, "��¼", 32, 36, WHITE);
                break;
            }
            case 2 :
            {
                bar(49 + (148 + 49) * 1, 400, 49 + 148 + (148 + 49) * 1, 430);
                puthz(49 + 148 + 49, 400, "ע��", 32, 36, WHITE);
                break;
            }
            case 3 :
            {
                bar(49 + (148 + 49) * 2, 400, 49 + 148 + (148 + 49) * 2, 430);
                puthz(49 + 148 + 49 + 148 + 49, 400, "�˳�", 32, 36, WHITE);
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
                puthz(220, 330, "����", 24, 28, WHITE);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "���", 24, 28, WHITE);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "����", 24, 28, WHITE);
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
                puthz(220, 330, "����", 24, 28, WHITE);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "���", 24, 28, WHITE);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "����", 24, 28, WHITE);
                break;
            }
            default : break;
        }
    }

    else if(*page == 3) //��ҳ
    {
        setbkcolor(CYAN);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);

        switch(*num)
        {
            case 2 :
            {
                bar(167, 422, 318, 458);
                puthz(167, 422, "���", 32, 36, WHITE);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "����", 32, 36, WHITE);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "�ҵ�", 32, 36, WHITE);
                break;
            }
            default : break;
        }
    }

    else if(*page == 4) //���ҳ
    {
        setbkcolor(CYAN);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        clrmous(MouseX, MouseY);

        switch(*num)
        {
            case 1 :
            {
                bar(12, 422, 163, 458);
                puthz(12, 422, "��ҳ", 32, 36, WHITE);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "����", 32, 36, WHITE);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "�ҵ�", 32, 36, WHITE);
                break;
            }
            default : break;
        }
    }
    
}