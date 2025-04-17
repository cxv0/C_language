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

    // ����������
    bar(170, 10, 580, 40); // ������

    //�������Ͻ�ͷ��
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(10, 60, 630, 400);

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(80, 360, 260, 400); //һ����ȡ

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(380, 360, 560, 400); //��ӿ��

    setfillstyle(SOLID_FILL, WHITE);
    bar(280, 380, 300, 400); //��ҳ
    
    setfillstyle(SOLID_FILL, WHITE);
    bar(340, 380, 360, 400); //��ҳ


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
    puthz(20,60,"�������",32,36,WHITE);
    puthz(220,60,"�Ĵ��",32,36,WHITE);
    puthz(420,60,"����",32,36,WHITE);
}

int expagefunc(ADMINHASH *hash)
{
    int num=0;
    int page = 1;
    int state = 1;
    unsigned char *m;
    unsigned char q=0;
    m=&q;

    clrmous(MouseX, MouseY);
    cleardevice();
    draw_expage();
    output(hash, page, &state);

    
    
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        real_time(m);

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
            delstuff(hash);
            inredraw(page,hash,&state);
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
            addstuff(hash);
            inredraw(page,hash,&state);
            continue;
        }

        else if (mouse_press(280, 380, 300, 400) == 2)//��ҳ
        {
            if (num == 0)
            {
                MouseS = 1;
            }
            continue;
        }
        else if (mouse_press(280, 380, 300, 400) == 1)
        {
            MouseS = 0;
            if (page == 1)
            {
                continue;
            }
            else
            {
                if (page != 1)
                {
                    page--;
                    clrmous(MouseX, MouseY);
                    inredraw(page,hash,&state);
                }
            }
        }
        else if (mouse_press(340, 380, 360, 400) == 2)//��ҳ
        {
            if (num == 0)
            {
                MouseS = 1;
            }
            continue;
        }
        else if (mouse_press(340, 380, 360, 400) == 1)
        {
            MouseS = 0;
            if (state == 1)
            {
                page++;
                clrmous(MouseX, MouseY);
                inredraw(page,hash,&state);
            }
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



void delstuff(ADMINHASH *hash)
{
    char name[20];

    setfillstyle(SOLID_FILL, CYAN);
    bar(120, 120, 520, 360);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(120, 120, 520, 160);

    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(480, 120, 520, 160);
    setcolor(RED);
    setlinestyle(0, 0, 3);
    line(485, 125, 515, 155);
    line(485, 155, 515, 125);
    line(485, 125, 485, 155);
    line(485, 125, 515, 125);
    line(515, 125, 515, 155);
    line(485, 155, 515, 155);

    puthz(140, 130, "һ����ȡ", 32, 32, DARKGRAY);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(430, 320, 515, 355); //ȷ����ť

    puthz(440, 337 - 16, "ȷ��", 32, 36, WHITE);
    puthz(140, 195, "����", 32, 36, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(250, 195, 500, 220);

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(430, 320, 515, 355) == 2)
        {
            MouseS = 1;
        }
        else if (mouse_press(430, 320, 515, 355) == 1)
        {
            MouseS = 0;
            if (HashSearch(hash, name) == NULL)
            {
                setfillstyle(SOLID_FILL, CYAN);
                bar(130, 320, 400, 355);
                puthz(140, 320, "δ�ҵ���ݣ�", 32, 36, RED);
                delay(1000);
            }
            else
            {
                Hashdelete(hash, name);
                setfillstyle(SOLID_FILL, CYAN);
                bar(130, 320, 400, 355);
                puthz(140, 320, "���", 32, 36, RED);
                delay(1000);
            }
        }
        else if (mouse_press(250, 190, 500, 220) == 2)
        {
            MouseS = 2;
        }
        else if (mouse_press(250, 190, 500, 220) == 1)
        {
            MouseS = 0;
            clrmous(MouseX, MouseY);
            num_input(name, 250, 190, 500, 220, 15);
        }
        else if (mouse_press(480, 120, 520, 170) == 2)
        {
            MouseS = 1;
        }
        else if (mouse_press(480, 120, 520, 170) == 1)
        {
            MouseS = 0;
            break; //�˳�
        }
        else
        {
            MouseS = 0;
        }
    }
    clrmous(MouseX, MouseY);

    return;
}


void addstuff(ADMINHASH *hash)
{
    ADMINOB *object;

    setfillstyle(SOLID_FILL, CYAN);
    bar(100, 80, 540, 400);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(100, 80, 540, 120);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(500, 80, 540, 120);
    setcolor(RED);
    setlinestyle(0, 0, 3);
    line(505, 85, 535, 115);
    line(505, 115, 535, 85);
    line(505, 85, 505, 115);
    line(535, 85, 535, 115);
    line(505, 85, 535, 85);
    line(505, 115, 535, 115);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(450, 340, 535, 375); //ȷ����ť

    puthz(460, 357 - 16, "ȷ��", 32, 32, WHITE);
    puthz(120, 90, "��ӿ��", 24, 32, DARKGRAY);

    puthz(120, 145, "����", 16, 16, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(160, 140, 520, 170);


    if ((object = (ADMINOB *)malloc(sizeof(ADMINOB))) == NULL)
    {
        printf("memorallocation runs wrong in addstuff");
    }

    memset(object, 0, sizeof(ADMINOB));

    delay(500);
    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(160, 140, 520, 170) == 2)
        {
            MouseS = 2;
        }
        else if (mouse_press(160, 140, 520, 170) == 1)
        {
            MouseS = 0;
            clrmous(MouseX, MouseY);
            num_input(object->name,160,140,520,170,15);
            strcpy(object->place,"yunyuan1dong");
            strcpy(object->number,"1234567890");
        }

        
        else if (mouse_press(450, 340, 535, 375) == 2)
        {
            MouseS = 1;
        }

        else if (mouse_press(450, 340, 535, 375) == 1)
        {
            if (strlen(object->name) != 0 )
            {
                Hashinsert(hash, object);
                puthz(120, 360, "���", 16, 16, RED);
                delay(1000);
                setfillstyle(SOLID_FILL, CYAN);
                bar(110, 350, 400, 385);
            }
            else
            {
                puthz(120, 360, "��Ϣȱ��", 16, 16, RED);
                delay(1000);
                setfillstyle(SOLID_FILL, CYAN);
                bar(110, 350, 400, 385);
            }
        }
        else if (mouse_press(500, 80, 540, 120) == 2)
        {
            MouseS = 1;
        }
        else if (mouse_press(500, 80, 540, 120) == 1)
        {
            MouseS = 0;
            clrmous(MouseX, MouseY);
            break; //�˳�
        }
        else
        {
            MouseS = 0;
        }
    }
}


void inredraw(int page, ADMINHASH *hash, int *state)
{
    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    // ����������
    bar(170, 10, 580, 40); // ������

    //�������Ͻ�ͷ��
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(10, 60, 630, 400);

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(80, 360, 260, 400); //һ����ȡ

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(380, 360, 560, 400); //��ӿ��

    setfillstyle(SOLID_FILL, WHITE);
    bar(280, 380, 300, 400); //��ҳ
    
    setfillstyle(SOLID_FILL, WHITE);
    bar(340, 380, 360, 400); //��ҳ

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
    puthz(20,60,"�������",32,36,WHITE);
    puthz(220,60,"�Ĵ��",32,36,WHITE);
    puthz(420,60,"����",32,36,WHITE);

    output(hash, page, state);
}