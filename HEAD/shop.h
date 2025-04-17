#ifndef _shop_h_
#define _shop_h_



typedef struct record //�����¼
{
    char account[20]; //�˻���
    int num[16]; //��Ʒ����
    float sum;
    int state; //��¼����״̬,δ�µ�:-1/�Ѿ��µ�:1
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