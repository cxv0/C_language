#ifndef _shop_h_
#define _shop_h_

#include "order.h"

typedef struct record //购买记录
{
    char account[20]; //账户名
    int num[16]; //物品数量
    float sum;
    int state; //记录订单状态,未下单:-1/已经下单:1
} RECORD;

void check_record_dat(void); //确保record.dat存在
int count_userrecord(void); //计数record.dat中共有几个结构体
RECORD *new_record(RECORD *rp); //生成空白记录
// void record_addnum(RECORD *rp, INFO *ip); //此处的ip是单个结构体指针,用于添加单独一种商品的数据而不能减少
void edit_record(RECORD *rp, INFO *ip); //此处的ip是单个结构体指针,用于修改单独一种商品的数据
RECORD *ensure_record(RECORD *rp); //确认下单
void add_record(RECORD *rp); //存储购买记录
RECORD *output_record(char *account); //输出历史记录指针
void output_to_screen(RECORD *rp); //输出到屏幕

#endif