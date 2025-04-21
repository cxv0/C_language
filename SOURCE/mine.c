#include "config.h"
#include "shop.h"
#include "real_time.h"
#include "gtaccount.h"
#include "Avatarfunc.h"
#include "force_exit.h"
#include "address.h"
#include "mine.h"

/******
COPYRIGHT:  Jiang Yihan & Hu Yizhuo
FUNCTION:   Mine page func
******/

void mine_page()
{
    setbkcolor(CYAN);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 10, 150, 40); // 时间框
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 12, 148, 38);

    //绘制右上角头像
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    // 绘制左侧功能键
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 60, 150, 315);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 148, 313);
    setcolor(YELLOW);
    line(10, 145, 150, 145);
    line(10, 230, 150, 230);
    puthz(10, 60, "设置信息", 32, 36, WHITE);
    puthz(10, 145, "配送进度", 32, 36, WHITE);
    puthz(10, 230, "上次购买", 32, 36, WHITE); 

    // 绘制右侧详情
    bar(170, 60, 630, 400);

    // 绘制底部菜单栏
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
    floodfill(481, 428, YELLOW);
    puthz(12, 422, "首页", 32, 36, WHITE);
    puthz(167, 422, "快递", 32, 36, WHITE);
    puthz(322, 422, "外卖", 32, 36, WHITE);
    puthz(477, 422, "我的", 32, 36, RED);
}

int minefunc(INFO (*t)[16])
{
    char account[20];
    int num = 0;
    int i, address = 0;
    int avatar_state_val = 0;
    int last_state_val = 0;
    int click_able_val = 0;
    int *avatar_state = &avatar_state_val;
    int *last_state = &last_state_val;
    int *click_able = &click_able_val;
    int force_show = 1;
    int not_force_show = 0;
    unsigned char *m;
    unsigned char q=0;
    m=&q;

    clrmous(MouseX, MouseY);
    cleardevice();
    mine_page();

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        real_time(m, &not_force_show);
        
        if(forceexit == 1)
        {
            forceexit = 0;
            return 1;
        }

        if(mouse_press(600, 10, 630, 40) == 1)
        {
            *avatar_state = 1;
            MouseS = 1;
        }

        if(mouse_press(600, 10, 630, 40) == 3)
        {
            *avatar_state = 0;
            *last_state = 0;
            *click_able = 0;
            cleardevice();
            mine_page();
            real_time(m, &force_show);
            MouseS = 1;
            continue;
        }

        if(*avatar_state == 1 && *avatar_state != *last_state)
        {
            draw_avatarpage();
            real_time(m, &force_show);
            *click_able = 1;
            *last_state = *avatar_state;
        }

        else if(*avatar_state != 1 && *avatar_state != *last_state)
        {
            cleardevice();
            mine_page();
            *click_able = 0;
            *last_state = *avatar_state;
        }

        Avatarfunc(click_able);

        if(mouse_press(477, 422, 628, 458) == 2) //我的框
        {
            
            MouseS = 1;
            num = 4;
            continue;
        }

        else if(mouse_press(477, 422, 628, 458) == 1) //我的框
        {
            MouseS = 0;
            continue;
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

        else if(mouse_press(322, 422, 473, 458) == 2) //外卖框
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 3;
            }
            continue;
        }

        else if(mouse_press(322, 422, 473, 458) == 1) //外卖框
        {
            MouseS = 0;
            return 5;
        }

        else if(mouse_press(10, 60, 150, 145) == 2) //设置信息
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 4;
            }
            continue;
        }

        else if(mouse_press(10, 60, 150, 145) == 1) //设置信息
        {
            MouseS = 0;
            avatar_state_val = 0;
            last_state_val = 0;
            click_able_val = 0;
            address = choose_address();
            saveaddress(address);
            clrmous(MouseX, MouseY);
            cleardevice();
            mine_page();
            real_time(m, &force_show);
            continue;
        }

        else if(mouse_press(10, 145, 150, 230) == 2) //配送进度
        {
            if(num == 0)
            {
                MouseS = 1;
                num = 5;
            }
            continue;
        }

        else if(mouse_press(10, 145, 150, 230) == 1) //配送进度
        {
            MouseS = 0;
            avatar_state_val = 0;
            last_state_val = 0;
            click_able_val = 0;
            address = get_address_num();
            clrmous(MouseX, MouseY);
            cleardevice();
            show_deliver(address);
            clrmous(MouseX, MouseY);
            cleardevice();
            mine_page();
            real_time(m, &force_show);
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

float total(INFO (*t)[16])
{
    int i,j;
    float k;
    float sum = 0.0;
    char allsum[8];
    j=0;
    k=0.0;

    for(i=0;i<16;i++)
    {
        j=t[0][i].num;
        k=t[0][i].price;
        sum += j*k;
    }
    setcolor(WHITE);
    memset(allsum, 0, sizeof(allsum));
    itoa(sum, allsum, 10);
    
    

    // if(sum < 10e-6)
    // {
    //     puthz(200,200,"未购买商品",32,36,WHITE);
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
    puthz(280,230,"购买成功",32,36,WHITE);
    delay(1000);
}

void page_redraw()
{
    setbkcolor(CYAN);
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 10, 150, 40); // 时间框
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 12, 148, 38);

    //绘制右上角头像
    circle(615, 25, 15);
    circle(615, 20, 5);
    arc(615, 53, 60, 120, 26);
    floodfill(615, 20, LIGHTGRAY);
    floodfill(615, 35, LIGHTGRAY);

    // 绘制左侧功能键
    setfillstyle(SOLID_FILL, YELLOW);
    bar(10, 60, 150, 400);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(12, 62, 148, 398);
    line(10, 145, 150, 230);
    line(10, 315, 150, 315);

    // 绘制右侧详情
    bar(170, 60, 630, 400);

    // 绘制底部菜单栏
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
    floodfill(481, 428, YELLOW);
    puthz(12, 422, "首页", 32, 36, WHITE);
    puthz(167, 422, "快递", 32, 36, WHITE);
    puthz(322, 422, "外卖", 32, 36, WHITE);
    puthz(477, 422, "我的", 32, 36, RED);
}