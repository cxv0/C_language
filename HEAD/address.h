#ifndef _address_h_
#define _address_h_

#pragma pack(push, 1) // ����Ϊ1�ֽڶ���

typedef struct address
{
    char account[50];
    int position;
} ADDRESS;

#pragma pack(pop) // �ָ�Ĭ�϶���

void check_adress_dat(void);
void saveaddress(int position_num);
// void update_address_in_file(int new_position);
void output_address(void);
int get_address_num(void);
int choose_address(void); //ͨ���ڵ�ͼ�ϵ��������ȷ����ַ

#endif