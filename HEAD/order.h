#ifndef _order_h_
#define _order_h_

#define SENSITIVITY 75 //���������,75���ҽϺ���

#include "shop.h"

typedef struct info//��Ʒ��Ϣ
{
    int NO; //��Ʒ����
    float price; //��Ʒ�۸�
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