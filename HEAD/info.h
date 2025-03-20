#ifndef _info_h_
#define _info_h_


typedef struct //物品信息
{
    char name[30]; //物品名称
    float price; //物品价格
    int status; //物品状态(运输/送达但未签收/已签收)
    long code; //物品编码
}info;


#endif