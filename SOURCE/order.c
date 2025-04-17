#include "config.h"
#include "order.h"
#include "market.h"
#include "real_time.h"
#include "shop.h"
#include "Avatarfunc.h"
#include "force_exit.h"

#define SENSITIVITY 75 //点击灵敏度,75左右较合适

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

    // 绘制标题栏
    setfillstyle(SOLID_FILL, YELLOW);
    bar(155, 10, 630, 40);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(157, 12, 628, 38);
    bar(12, 62, 628, 458);
    puthz(240, 15, "订单管理系统", 24, 28, WHITE);
    
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 420, 165, 460); // 首页
    bar(165, 420, 320, 460); // 快递
    bar(320, 420, 475, 460); // 外卖
    bar(475, 420, 630, 460); // 我的
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 422, 163, 458); // 首页
    bar(167, 422, 318, 458); // 快递
    bar(322, 422, 473, 458); // 外卖
    bar(477, 422, 628, 458); // 我的
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(326, 428, YELLOW);
    puthz(12, 422, "首页", 32, 36, WHITE);
    puthz(167, 422, "快递", 32, 36, WHITE);
    puthz(477, 422, "我的", 32, 36, WHITE);
    puthz(322, 422, "外卖", 32, 36, RED);

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
    settextstyle(1, 0, 3); //字体为三重矢量字体,TRIPLEX_FONT
    outtextxy(315, 387, str);
}

void draw_setpage(int *orderpage)
{
    char goods_name[16][20] = {"商品一", "商品二", "商品三", "商品四", "商品五", "商品六", "商品七", "商品八", "商品九", "商品十", "商品十一", "商品十二", "商品十三", "商品十四", "商品十五", "商品十六"};
    int i = 0, j = 0; //此处乱序是为了配合i,j的排序方式
    char (*ptr)[20] = goods_name; //商品名表
    
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 628, 332);
    setfillstyle(SOLID_FILL, RED);
    setcolor(RED);

    for(i = 0; i < 3; i += 2) //i控制输出字符纵坐标
    {
        for(j = 0; j < 2; j ++) //j控制输出字符横坐标
        { //(i, j)依次为(0, 0), (0, 1), (2, 0), (2, 1),是利用i+j的不同来排序
            rectangle(13 + 336 * j, 63 + 170 * (i / 2), 293 + 336 * j, 163 + 170 * (i / 2));
            puthz(15 + 336 * j, 65 + 170 * (i / 2), *(ptr + (*orderpage - 1) * 4 + j + i), 16, 18, WHITE);
            bar(250 + 336 * j, 140 + 170 * (i / 2), 290 + 336 * j, 160 + 170 * (i / 2));
            puthz(250 + 336 * j, 140 + 170 * (i / 2), "购买", 16, 18, WHITE);
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

    puthz(260, 180, "选择购买数量", 24, 20, WHITE);
    setfillstyle(SOLID_FILL, RED);
    bar(270, 270, 310, 290);
    bar(330, 270, 370, 290);
    puthz(275, 272, "确定", 16, 18, WHITE);
    puthz(335, 272, "取消", 16, 18, WHITE); //弹出对话框

    setlinestyle(SOLID_LINE, 0, THICK_WIDTH); //粗实线
    setcolor(RED);
    sector(270, 235, 0, 360, 10, 10);
    sector(370, 235, 0, 360, 10, 10); //两个圆

    setcolor(DARKGRAY);
    line(262, 235, 278, 235); //减号
    line(362, 235, 378, 235);
    line(370, 227, 370, 243); //加号

    setfillstyle(SOLID_FILL, WHITE);
    bar(295, 215, 345, 255);                  //中间数据框
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //设置字体 三重矢量字体，横向输出
    outtextxy(310, 215, num_cuy);             //购买商品数量


    //接下来一系列鼠标操作包括增加商品，减少商品，或者直接进行输入
    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(260, 225, 280, 245) == 1) //减少想要购买的商品数量
        {

            if (num_buy == 1)
                continue;
            else
                num_buy--;

            setfillstyle(SOLID_FILL, WHITE);
            bar(295, 215, 345, 255); //中间数据框清除

            itoa(num_buy, num_cuy, 10);
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //设置字体 三重矢量字体，横向输出
            outtextxy(310, 215, num_cuy);
            delay(150);
            continue;
        }
        if (mouse_press(360, 225, 380, 245) == 1) //增加想要购买的商品数量
        {
            if (num_buy >= 99)
                continue;
            else
                num_buy++;

            setfillstyle(SOLID_FILL, WHITE);
            bar(295, 215, 345, 255); //中间数据框清除

            itoa(num_buy, num_cuy, 10);
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //设置字体 三重矢量字体，横向输出
            outtextxy(310, 215, num_cuy);
            delay(150);
            continue;
        }
        if (mouse_press(270, 270, 310, 290) == 1) //确定购买商品
        {
            clrmous(MouseX, MouseY);
            *m = num_buy;
            break;
        }
        if (mouse_press(330, 270, 370, 290) == 1) //取消购买商品
        {
            clrmous(MouseX, MouseY);
            *m = abc;
            break;
        }
        if (mouse_press(295, 215, 345, 255) == 1) //直接输入商品
        {
            num_input(num_cuy, 295, 215, 345, 255, 2);
            if (num_cuy == '\0')
            {
                num_buy = 1;
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //设置字体 三重矢量字体，横向输出
                outtextxy(310, 255, num_cuy);
            }
            else
            {
                if (atoi(num_cuy) > 99)
                {
                    num_buy = 99;
                    itoa(num_buy, num_cuy, 10);

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(295, 255, 345, 295);                  //中间数据框清除
                    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //设置字体 三重矢量字体，横向输出
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
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); //三重矢量字体，水平输出，大小二
    settextjustify(LEFT_TEXT, TOP_TEXT);      //对齐方式
    setfillstyle(SOLID_FILL, WHITE);
    bar(x1, y1, x2, y2); //遮盖原有内容
    line(x1 + 10, y1 + 4, x1 + 10, y2 - 4);

    memset(s, '\0', sizeof(s));

    while (bioskey(1))
    {
        k = bioskey(0); //删除buffer中的字符
    }

    while (1)
    {

        t = bioskey(0); //读取输入键值
        if (i < maxium)
        {
            if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
            {
                if (t != '\b')
                {
                    *(s + i) = t;
                    *(s + i + 1) = '\0';
                    bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2); //遮盖光标
                    outtextxy(x1 + 8 + i * 18, y1 - 1, s + i);          //输出t字符
                    i++;
                    line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y2 - 4);
                }
                else if (t == '\b' && i > 0) //退格键
                {
                    bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2);       //遮盖光标
                    bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y2);       //遮盖文字
                    i--;                                                      //减少一个字数
                    line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y2 - 4); //绘制光标
                    *(s + i) = '\0';
                    *(s + i + 1) = '\0';
                }
            }
            else
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2); //遮盖光标
                break;
            }
        }
        else if (i >= maxium)
        {
            if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
            {
                if (t == '\b' && i > 0) //退格键
                {
                    bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2);       //遮盖光标
                    bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y2);       //遮盖文字
                    i--;                                                      //减少一个字数
                    line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y2 - 4); //绘制光标
                    *(s + i) = '\0';
                }
            }
            else
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y2); //遮盖光标
                break;
            }
        }
    }
}

void draw_cartbutton() //绘制购物车按钮
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

        if(mouse_press(322, 422, 473, 458) == 2) //外卖框
        {
            MouseS = 1;
            num = 3;
            continue;
        }

        else if(mouse_press(322, 422, 473, 458) == 1) //外卖框
        {
            MouseS = 0;
            continue;
        }

        else if(mouse_press(12, 422, 163, 458) == 2) //首页框
        {
            
            if(num == 0)
            {
                MouseS = 1;
                num = 1;
            }
            continue;
        }

        else if(mouse_press(12, 422, 163, 458) == 1) //首页框
        {
            MouseS = 0;
            return 3;
        }

        else if(mouse_press(167, 422, 318, 458) == 2) //快递框
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 2;
            }
            continue;
        }

        else if(mouse_press(167, 422, 318, 458) == 1) //快递框
        {
            MouseS = 0;
            return 4;
        }

        else if(mouse_press(477, 422, 628, 458) == 2) //我的框
        {
            
            if(num == 0)
            {
                MouseS = 1;
                num = 4;
            }
            continue;
        }

        else if(mouse_press(477, 422, 628, 458) == 1) //我的框
        {
            MouseS = 0;
            return 6;
        }

        else if(mouse_press(585,345,615,375) == 2)//购物车
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 5;
            }
            continue;
        }

        else if(mouse_press(585,345,615,375) == 1)//购物车
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
            if(event_click >= SENSITIVITY) //将该数值调整为更大的数值可以降低灵敏度
            {
                pagedown(orderpage);
                draw_setpage(orderpage); //该函数用于绘制orderpage对应的商品界面
                event_click = 0;
                switch_show_orderpage(orderpage);
            }
        }

        if(mouse_press(330, 390, 350, 410) == 1)
        {
            event_click ++;
            if(event_click >= SENSITIVITY) //将该数值调整为更大的数值可以降低灵敏度
            {
                pageup(orderpage);
                draw_setpage(orderpage);
                event_click = 0;
                switch_show_orderpage(orderpage);
            }
        }

        //接下来要对不同商品界面和鼠标点击坐标作出相应
        for(i = 0; i < 3; i += 2) //i控制输出字符纵坐标
        {
            for(j = 0; j < 2; j ++) //j控制输出字符横坐标
            { //(i, j)依次为(0, 0), (0, 1), (2, 0), (2, 1),是利用i+j的不同来排序
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

    
    puthz(10,20,"商品名称",32,36,RED);
    puthz(300,20,"价格",32,36,RED);
    puthz(560,20,"数量",32,36,RED);
    // puthz(540,400,"总价",24,28,RED);
    // puthz(280,415,"确认购买",24,28,WHITE);
    // puthz(570,445,"返回",24,28,WHITE);

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

        if(mouse_press(250,410,430,450) == 2) //确认购买
        {
            MouseS = 1;
            num = 1;
            continue;
        }

        else if(mouse_press(250,410,430,450) == 1) //确认购买
        {
            MouseS = 0;
            continue;
        }

        else if(mouse_press(570,445,630,475) == 2) //返回
        {
            MouseS = 1;
            num = 2;
            continue;
        }

        else if(mouse_press(570,445,630,475) == 1) //返回
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