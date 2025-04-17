#ifndef _shop_h_
#define _shop_h_



typedef struct record //购买记录
{
    char account[20]; //账户名
    int num[16]; //物品数量
    float sum;
    int state; //记录订单状态,未下单:-1/已经下单:1
} RECORD;

void check_record_dat(void);
int count_userinfo(void);
int seek_init_userinfo(char *account);
void add_userinfo(RECORD *ip);
void overwrite_userinfo(RECORD *ip);
void delete_userinfo(char *account);
void output_to_latest(char *account, int x1, int y1, int x2, int y2);
RECORD *output_record(char *account);
void output_to_screen(RECORD *rp);

#endif