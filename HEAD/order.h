#ifndef _order_h_
#define _order_h_

#define SENSITIVITY 75 //点击灵敏度,75左右较合适

#include "shop.h"

typedef struct info//物品信息
{
    int NO; //物品名称
    float price; //物品价格
    int num;
} INFO;

//void redraw_market(int *orderpage);
void draw_order_management_page(void);
void pageup(int *orderpage);
void pagedown(int *orderpage);
void switch_show_orderpage(int *orderpage);
void draw_setpage(int *orderpage);
void choose_number(int *m);
void num_input(char *s, int x1, int y1, int x2, int y2, int maxium);
int orderfunc(INFO (*t)[16]);
void draw_cartlist(void);
void draw_cartbutton(void);
int cartfunc(INFO (*t)[16]);

#endif