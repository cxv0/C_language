#include "config.h"
#include "custom.h"

void hlbutton(int *page, int *num)
{  
    if(*page == 0) //1��¼2ע��3�˳�
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 1 :
            {
                bar(49, 400, 49 + 148, 430);
                puthz(49, 400, "��¼", 32, 36, RED);
                break;
            }
            case 2 :
            {
                bar(49 + (148 + 49) * 1, 400, 49 + 148 + (148 + 49) * 1, 430);
                puthz(49 + 148 + 49, 400, "ע��", 32, 36, RED);
                break;
            }
            case 3 :
            {
                bar(49 + (148 + 49) * 2, 400, 49 + 148 + (148 + 49) * 2, 430);
                puthz(49 + 148 + 49 + 148 + 49, 400, "�˳�", 32, 36, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 1) //1����2���3����
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);

        switch(*num)
        {
            case 1 :
            {
                bar(220, 330, 280, 360);
                puthz(220, 330, "����", 24, 28, RED);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "���", 24, 28, RED);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "����", 24, 28, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 2) //1����2���3����
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 1 :
            {
                bar(220, 330, 280, 360);
                puthz(220, 330, "����", 24, 28, RED);
                break;
            }
            case 2 :
            {
                bar(330, 330, 390, 360);
                puthz(330, 330, "���", 24, 28, RED);
                break;
            }
            case 3 :
            {
                bar(560, 430, 620, 460);
                puthz(560, 430, "����", 24, 28, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 3) //��ҳ //1��ҳ2���3����4�ҵ�
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 2 :
            {
                bar(167, 422, 318, 458);
                puthz(167, 422, "���", 32, 36, RED);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "����", 32, 36, RED);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "�ҵ�", 32, 36, RED);
                break;
            }
            default : break;
        }
    }

    else if(*page == 4) //���ҳ //1��ҳ2���3����4�ҵ�5ȡ��6�ļ�7��������
    {
        clrmous(MouseX, MouseY);
        delay(20);
        setfillstyle(SOLID_FILL, YELLOW);
        
        switch(*num)
        {
            case 1 :
            {
                bar(12, 422, 163, 458);
                puthz(12, 422, "��ҳ", 32, 36, RED);
                break;
            }
            case 3 :
            {
                bar(322, 422, 473, 458);
                puthz(322, 422, "����", 32, 36, RED);
                break;
            }
            case 4 :
            {
                bar(477, 422, 628, 458);
                puthz(477, 422, "�ҵ�", 32, 36, RED);
                break;
            }
            default : break;
        }
    }
}