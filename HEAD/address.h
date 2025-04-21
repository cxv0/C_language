#ifndef _address_h_
#define _address_h_

#pragma pack(push, 1) // 设置为1字节对齐

typedef struct address
{
    char account[50];
    int position;
} ADDRESS;

#pragma pack(pop) // 恢复默认对齐

void check_adress_dat(void);
void saveaddress(int position_num);
// void update_address_in_file(int new_position);
void output_address(void);
int get_address_num(void);
int choose_address(void); //通过在地图上点击区域来确定地址

#endif