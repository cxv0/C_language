#include "custom.h"
#include "config.h"


/******
initmenu.c
COPYRIGHT:  Jiang Yihan
FUNCTION:   初始界面初始�??
DATE:       2025/2/17
******/

void initmenu(int *page, int *num)
{
    while(1)
    {
        if(*page == 0)  //��ӭ����
        {
            clrmous(MouseX, MouseY);
            cleardevice();
            welcome_page();

            while(*page == 0)
            {
                newmouse(&MouseX, &MouseY, &press);

                if(mouse_press(49, 400, 49 + 148, 430) == 2)  //登录框内未点�??
                {
                    MouseS = 1;
                    if(*num == 0)
                    {
                        *num = 1;
                        *page = 0;
                        hlbutton(page, num);
                    }
                    continue;
                }

                else if(mouse_press(49, 400, 49 + 148, 430) == 1)  //点击登录�??
                {
                    MouseS = 1;
                    *num = 1;
                    *page = 1;
                    continue;
                }
        
                else if(mouse_press(49 + (148 + 49) * 1, 400, 49 + (148 + 49) * 1 + 148, 430) == 2)  //注册框内未点�??
                {
                    MouseS = 1;
                    if(*num == 0)
                    {
                        *num = 2;
                        *page = 0;
                        hlbutton(page, num);
                    }
                    continue;
                }

                else if(mouse_press(49 + (148 + 49) * 1, 400, 49 + (148 + 49) * 1 + 148, 430) == 1)  //点击注册�??
                {
                    MouseS = 1;
                    *num = 2;
                    *page = 2;
                    continue;
                }
        
                else if(mouse_press(49 + (148 + 49) * 2, 400, 49 + (148 + 49) * 2 + 148, 430) == 2)  //退出框内未点击
                {
                    MouseS = 1;
                    if(*num == 0)
                    {
                        *num = 3;
                        *page = 0;
                        hlbutton(page, num);
                    }
                    continue;
                }

                else if(mouse_press(49 + (148 + 49) * 2, 400, 49 + (148 + 49) * 2 + 148, 430) == 1)  //点击退�??
                {
                    MouseS = 1;
                    delay(200);
                    exit(EXIT_SUCCESS);
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
        
        else if(*page == 1)  //��ת����һ������ҳ
        {
            clrmous(MouseX, MouseY);
            cleardevice();
            login_page(page);
            login_fun(page);
            continue;
        }
        
        else if(*page == 2)  //�ڶ�������ҳ
        {   
            clrmous(MouseX, MouseY);
            cleardevice();
            regis_page(page);
            regis_fun(page);
            continue;
        }
        
    }
}



void repaint(int *page, int *num)  //重新绘制按钮
{
    if(*page == 0)
    {
        setbkcolor(BLUE);
        setcolor(LIGHTGRAY);
        setlinestyle(SOLID_LINE, 0, 1);
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        settextjustify(LEFT_TEXT, TOP_TEXT);
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);

        clrmous(MouseX, MouseY);  //��������ᵼ�����»�ɫ�߿�?

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
}



void welcome_page()
{
    int i;

    setbkcolor(BLUE);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    moveto(64, 64);
    lineto(576, 64);
    lineto(576, 128);
    lineto(64, 128);
    lineto(64, 64);

    bar(64, 64, 576, 128);

    for(i = 0; i < 3; i ++)
    {
        moveto(49 + (148 + 49) * i, 400);
        lineto(49 + 148 + (148 + 49) * i, 400);
        lineto(49 + 148 + (148 + 49) * i, 430);
        lineto(49 + (148 + 49) * i, 430);
        lineto(49 + (148 + 49) * i, 400);
    }
    
    for(i = 0; i < 3; i ++)
    {
        bar(49 + (148 + 49) * i, 400, 49 + 148 + (148 + 49) * i, 430);
    }

    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(150, 450, "Made by AI 2403 JYH and HYZ");

    puthz(64, 64, "У԰�������ģ��ϵͳ", 32, 36, WHITE);
    puthz(49, 400, "��¼", 32, 36, WHITE);
    puthz(49 + 148 + 49, 400, "ע��", 32, 36, WHITE);
    puthz(49 + 148 + 49 + 148 + 49, 400, "�˳�", 32, 36, WHITE);

}



void hlbutton(int *page, int *num)
{  
    if(*page == 0)
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
}

