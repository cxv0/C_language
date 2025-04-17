#include "custom.h"
#include "config.h"
#include "shop.h"

extern float cost[20];
extern int shuzi;

void mine_page()
{
    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 10, 150, 40); // ʱ���
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(62, 12, 148, 38);

    //�������Ͻ�ͷ��
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(10, 60, 630, 400);

    setfillstyle(SOLID_FILL, GREEN);
    bar(200,240,280,280);

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
    floodfill(481, 428, YELLOW);
    puthz(12, 422, "��ҳ", 32, 36, WHITE);
    puthz(167, 422, "���", 32, 36, WHITE);
    puthz(322, 422, "����", 32, 36, WHITE);
    puthz(200, 240, "����", 32, 36, WHITE);
    puthz(477, 422, "�ҵ�", 32, 36, RED);
}

int minefunc(INFO t[16])
{
    char account[20] = "11111111";
    int num = 0;
    int i;
    unsigned char *m;
    unsigned char q=0;
    RECORD *rp = NULL;
    m=&q;

    clrmous(MouseX, MouseY);
    cleardevice();
    mine_page();
    total(t);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        real_time(m);

        if(mouse_press(477, 422, 628, 458) == 2) //�ҵĿ�
        {
            
            MouseS = 1;
            num = 4;
            continue;
        }

        else if(mouse_press(477, 422, 628, 458) == 1) //�ҵĿ�
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
        
        else if(mouse_press(200,240,280,280) == 2)
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 5;
            }
            continue;
        }

        else if(mouse_press(200,240,280,280) == 1) //����
        {
            MouseS = 0;
            draw_page();
            page_redraw();
            cost[shuzi]=total(t);
            shuzi++;
            
            new_record(rp, t);
            for(i = 0; i < 16; i ++)
            {
                edit_record(rp, &t[i]);
            }
            add_record(ensure_record(rp));
            check_record_dat();
            rp = output_record(account);
            output_to_screen(rp);

            if(shuzi == 20)
            {
                shuzi = 0;
            }
            for(i=0;i<16;i++)
            {
                t[i].num = 0;
            }
            total(t);
            continue;
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

float total(INFO t[16])
{
    int i,j;
    float k;
    float sum = 0.0;
    char allsum[8];
    j=0;
    k=0.0;

    for(i=0;i<16;i++)
    {
        j=t[i].num;
        k=t[i].price;
        sum += j*k;
    }
    setcolor(WHITE);
    memset(allsum, 0, sizeof(allsum));
    itoa(sum, allsum, 10);
    setfillstyle(SOLID_FILL, BLUE);
    bar(200,200,260,240); // ��ҳ
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(200,200,allsum);
    

    // if(sum < 10e-6)
    // {
    //     puthz(200,200,"δ������Ʒ",32,36,WHITE);
    // }
    // if(sum > 10e-6)
    // {
    //     setcolor(WHITE);
    //     memset(allsum, 0, sizeof(allsum));
    //     itoa(sum, allsum, 10);
    //     settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    //     outtextxy(200,200,allsum);
    // }
    return sum;
}

void draw_page()
{
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(270,200,420,280);
    puthz(280,230,"����ɹ�",32,36,WHITE);
    delay(1000);
}

void page_redraw()
{
    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    //�������Ͻ�ͷ��
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(10, 60, 630, 400);

    setfillstyle(SOLID_FILL, GREEN);
    bar(200,240,280,280);

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
    floodfill(481, 428, YELLOW);
    puthz(12, 422, "��ҳ", 32, 36, WHITE);
    puthz(167, 422, "���", 32, 36, WHITE);
    puthz(322, 422, "����", 32, 36, WHITE);
    puthz(200, 240, "����", 32, 36, WHITE);
    puthz(477, 422, "�ҵ�", 32, 36, RED);
}