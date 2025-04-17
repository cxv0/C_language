#include "config.h"
#include "order.h"
#include "market.h"
#include "real_time.h"
#include "shop.h"
#include "Avatarfunc.h"
#include "force_exit.h"

#define SENSITIVITY 75 //���������,75���ҽϺ���

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Order function
DATE:       2025/3/29
******/

void draw_order_management_page()
{
    setbkcolor(WHITE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    // ���Ʊ�����
    setfillstyle(SOLID_FILL, YELLOW);
    bar(155, 10, 630, 40);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(157, 12, 628, 38);
    bar(12, 62, 628, 458);
    puthz(240, 15, "��������ϵͳ", 24, 28, WHITE);
    
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
    floodfill(326, 428, YELLOW);
    puthz(12, 422, "��ҳ", 32, 36, WHITE);
    puthz(167, 422, "���", 32, 36, WHITE);
    puthz(477, 422, "�ҵ�", 32, 36, WHITE);
    puthz(322, 422, "����", 32, 36, RED);

    setcolor(RED);
    rectangle(290, 390, 310, 410);
    rectangle(330, 390, 350, 410);
    line(305, 395, 295, 400);
    line(295, 400, 305, 405);
    line(335, 395, 345, 400);
    line(345, 400, 335, 405);
}

void pageup(int *orderpage)
{
    if(*orderpage < 4)
    {
        *orderpage += 1;
    }
}

void pagedown(int *orderpage)
{
    if(*orderpage > 1)
    {
        *orderpage -= 1;
    }
}

void switch_show_orderpage(int *orderpage)
{
    char str[1];
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(311, 385, 329, 409);
    draw_cartbutton();
    delay(15);
    sprintf(str, "%d", *orderpage);
    settextstyle(1, 0, 3); //����Ϊ����ʸ������,TRIPLEX_FONT
    outtextxy(315, 387, str);
}

void draw_setpage(int *orderpage)
{
    char goods_name[16][20] = {"��Ʒһ", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒʮ", "��Ʒʮһ", "��Ʒʮ��", "��Ʒʮ��", "��Ʒʮ��", "��Ʒʮ��", "��Ʒʮ��"};
    int i = 0, j = 0; //�˴�������Ϊ�����i,j������ʽ
    char (*ptr)[20] = goods_name; //��Ʒ����
    
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 628, 332);
    setfillstyle(SOLID_FILL, RED);
    setcolor(RED);

    for(i = 0; i < 3; i += 2) //i��������ַ�������
    {
        for(j = 0; j < 2; j ++) //j��������ַ�������
        { //(i, j)����Ϊ(0, 0), (0, 1), (2, 0), (2, 1),������i+j�Ĳ�ͬ������
            rectangle(13 + 336 * j, 63 + 170 * (i / 2), 293 + 336 * j, 163 + 170 * (i / 2));
            puthz(15 + 336 * j, 65 + 170 * (i / 2), *(ptr + (*orderpage - 1) * 4 + j + i), 16, 18, WHITE);
            bar(250 + 336 * j, 140 + 170 * (i / 2), 290 + 336 * j, 160 + 170 * (i / 2));
            puthz(250 + 336 * j, 140 + 170 * (i / 2), "����", 16, 18, WHITE);
        }
    }
}

void choose_number(int *m)
{
    int abc = 0;
    int num_buy = 1;
    char num_cuy[3];

    itoa(num_buy, num_cuy, 10);

    setfillstyle(SOLID_FILL, BLUE);
    bar(240, 140, 400, 300);

    puthz(260, 180, "ѡ��������", 24, 20, WHITE);
    setfillstyle(SOLID_FILL, RED);
    bar(270, 270, 310, 290);
    bar(330, 270, 370, 290);
    puthz(275, 272, "ȷ��", 16, 18, WHITE);
    puthz(335, 272, "ȡ��", 16, 18, WHITE); //�����Ի���

    setlinestyle(SOLID_LINE, 0, THICK_WIDTH); //��ʵ��
    setcolor(RED);
    sector(270, 235, 0, 360, 10, 10);
    sector(370, 235, 0, 360, 10, 10); //����Բ

    setcolor(DARKGRAY);
    line(262, 235, 278, 235); //����
    line(362, 235, 378, 235);
    line(370, 227, 370, 243); //�Ӻ�

    setfillstyle(SOLID_FILL, WHITE);
    bar(295, 215, 345, 255);                  //�м����ݿ�
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //�������� ����ʸ�����壬�������
    outtextxy(310, 215, num_cuy);             //������Ʒ����


    //������һϵ������������������Ʒ��������Ʒ������ֱ�ӽ�������
    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(260, 225, 280, 245) == 1) //������Ҫ�������Ʒ����
        {

            if (num_buy == 1)
                continue;
            else
                num_buy--;

            setfillstyle(SOLID_FILL, WHITE);
            bar(295, 215, 345, 255); //�м����ݿ����

            itoa(num_buy, num_cuy, 10);
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //�������� ����ʸ�����壬�������
            outtextxy(310, 215, num_cuy);
            delay(150);
            continue;
        }
        if (mouse_press(360, 225, 380, 245) == 1) //������Ҫ�������Ʒ����
        {
            if (num_buy >= 99)
                continue;
            else
                num_buy++;

            setfillstyle(SOLID_FILL, WHITE);
            bar(295, 215, 345, 255); //�м����ݿ����

            itoa(num_buy, num_cuy, 10);
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //�������� ����ʸ�����壬�������
            outtextxy(310, 215, num_cuy);
            delay(150);
            continue;
        }
        if (mouse_press(270, 270, 310, 290) == 1) //ȷ��������Ʒ
        {
            clrmous(MouseX, MouseY);
            *m = num_buy;
            break;
        }
        if (mouse_press(330, 270, 370, 290) == 1) //ȡ��������Ʒ
        {
            clrmous(MouseX, MouseY);
            *m = abc;
            break;
        }
        if (mouse_press(295, 215, 345, 255) == 1) //ֱ��������Ʒ
        {
            num_input(num_cuy, 295, 215, 345, 255, 2);
            if (num_cuy == '\0')
            {
                num_buy = 1;
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //�������� ����ʸ�����壬�������
                outtextxy(310, 255, num_cuy);
            }
            else
            {
                if (atoi(num_cuy) > 99)
                {
                    num_buy = 99;
                    itoa(num_buy, num_cuy, 10);

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(295, 255, 345, 295);                  //�м����ݿ����
                    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //�������� ����ʸ�����壬�������
                    outtextxy(310, 255, num_cuy);
                }
                else
                    num_buy = atoi(num_cuy);
            }
        }
    }
}


void num_input(char *s, int x1, int y1, int x2, int y2, int maxium)
{
    char t;
    int i = 0;
    int k;

    clrmous(MouseX, MouseY);
    setfillstyle(SOLID_FILL, WHITE);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setcolor(DARKGRAY);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //����ʸ�����壬ˮƽ�������С��
    settextjustify(LEFT_TEXT, TOP_TEXT);      //���뷽ʽ
    setfillstyle(SOLID_FILL, WHITE);
    bar(x1, y1, x2, y2); //�ڸ�ԭ������
    line(x1 + 10, y1 + 4, x1 + 10, y2 - 4);

    memset(s, '\0', sizeof(s));

    while (bioskey(1))
    {
        k = bioskey(0); //ɾ��buffer�е��ַ�
    }

    while (1)
    {

        t = bioskey(0); //��ȡ�����ֵ
        if (i < maxium)
        {
            if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
            {
                if (t != '\b')
                {
                    *(s + i) = t;
                    *(s + i + 1) = '\0';
                    bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2); //�ڸǹ��
                    outtextxy(x1 + 8 + i * 18, y1 - 1, s + i);          //���t�ַ�
                    i++;
                    line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y2 - 4);
                }
                else if (t == '\b' && i > 0) //�˸��
                {
                    bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2);       //�ڸǹ��
                    bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y2);       //�ڸ�����
                    i--;                                                      //����һ������
                    line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y2 - 4); //���ƹ��
                    *(s + i) = '\0';
                    *(s + i + 1) = '\0';
                }
            }
            else
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2); //�ڸǹ��
                break;
            }
        }
        else if (i >= maxium)
        {
            if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
            {
                if (t == '\b' && i > 0) //�˸��
                {
                    bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2);       //�ڸǹ��
                    bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y2);       //�ڸ�����
                    i--;                                                      //����һ������
                    line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y2 - 4); //���ƹ��
                    *(s + i) = '\0';
                }
            }
            else
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2); //�ڸǹ��
                break;
            }
        }
    }
}

void draw_cartbutton() //���ƹ��ﳵ��ť
{
    setcolor(BLUE);
    circle(600, 360, 15);
    floodfill(600, 360, BLUE);
    line(588, 355, 607, 355);
    line(607, 355, 604, 365);
    line(604, 365, 591, 365);
    line(591, 365, 588, 355);
    circle(593, 368, 2);
    circle(604, 368, 2);
    line(607, 355, 609, 352);
    line(609, 352, 611, 352);
}

/*void redraw_market(int *orderpage)
{
    draw_order_management_page();
    switch_show_orderpage(orderpage);
    draw_setpage(orderpage);
}*/

int orderfunc(INFO (*t)[16])
{

    int num = 0, order_page = 1, event_click = 0;
    int i = 0, j = 0;
    int *avatar_state = 0;
    int *click_able = 0;
    int buy_num[16] = {0};
    int *orderpage = &order_page;
    unsigned char *m;
    unsigned char q = 0;
    m = &q;

    clrmous(MouseX, MouseY);
    cleardevice();
    draw_order_management_page();
    draw_setpage(orderpage);
    switch_show_orderpage(orderpage);
    draw_cartbutton();

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        real_time(m, avatar_state);
        draw_avatarpage(avatar_state, click_able);
        Avatarfunc(click_able);

        if(forceexit == 1)
        {
            forceexit = 0;
            return 1;
        }
        
        if(*avatar_state == 2)
        {
            clrmous(MouseX, MouseY);
            cleardevice();
            draw_order_management_page();
            draw_setpage(orderpage);
            switch_show_orderpage(orderpage);
            draw_cartbutton();
            real_time(m, avatar_state);
        }

        if(mouse_press(322, 422, 473, 458) == 2) //������
        {
            MouseS = 1;
            num = 3;
            continue;
        }

        else if(mouse_press(322, 422, 473, 458) == 1) //������
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

        else if(mouse_press(585,345,615,375) == 2)//���ﳵ
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 5;
            }
            continue;
        }

        else if(mouse_press(585,345,615,375) == 1)//���ﳵ
        {
            MouseS = 0;
            draw_cartlist();
            cartfunc(t);
            continue;
        }

        else
        {  
            if(num != 0)
            {
                MouseS = 0;
                num = 0;
            }
        }

        if(mouse_press(290, 390, 310, 410) == 1)
        {
            event_click ++;
            if(event_click >= SENSITIVITY) //������ֵ����Ϊ�������ֵ���Խ���������
            {
                pagedown(orderpage);
                draw_setpage(orderpage); //�ú������ڻ���orderpage��Ӧ����Ʒ����
                event_click = 0;
                switch_show_orderpage(orderpage);
            }
        }

        if(mouse_press(330, 390, 350, 410) == 1)
        {
            event_click ++;
            if(event_click >= SENSITIVITY) //������ֵ����Ϊ�������ֵ���Խ���������
            {
                pageup(orderpage);
                draw_setpage(orderpage);
                event_click = 0;
                switch_show_orderpage(orderpage);
            }
        }

        //������Ҫ�Բ�ͬ��Ʒ��������������������Ӧ
        for(i = 0; i < 3; i += 2) //i��������ַ�������
        {
            for(j = 0; j < 2; j ++) //j��������ַ�������
            { //(i, j)����Ϊ(0, 0), (0, 1), (2, 0), (2, 1),������i+j�Ĳ�ͬ������
                if(mouse_press(250 + 336 * j, 140 + 170 * (i / 2), 290 + 336 * j, 160 + 170 * (i / 2)) == 1)
                {
                    MouseS = 0;
                    clrmous(MouseX, MouseY);
                    choose_number(&buy_num[(*orderpage - 1) * 4 + i + j]);
                    t[0][(*orderpage - 1) * 4 + i + j].num = buy_num[(*orderpage - 1) * 4 + i + j];
                    //choose_number(&buy_num[(*orderpage - 1) + i / 2 + j]);
                    //redraw_market(orderpage);
                    draw_order_management_page();
                    switch_show_orderpage(orderpage);
                    draw_setpage(orderpage);
                    continue;
                }
            }
        }
    }
}


void draw_cartlist()
{

    int i;
    setbkcolor(LIGHTGRAY);
    setcolor(RED);
    setfillstyle(SOLID_FILL, GREEN);

    bar(250,410,430,450);
    bar(570,445,630,475);

    
    puthz(10,20,"��Ʒ����",32,36,RED);
    puthz(300,20,"�۸�",32,36,RED);
    puthz(560,20,"����",32,36,RED);
    // puthz(540,400,"�ܼ�",24,28,RED);
    // puthz(280,415,"ȷ�Ϲ���",24,28,WHITE);
    // puthz(570,445,"����",24,28,WHITE);

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
    mouseinit();
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