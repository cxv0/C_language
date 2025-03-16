#ifndef _info_h_
#define _info_h_


typedef struct info //物品信息
{
    char name[30]; //物品名称
    int time; //预计到达时间
    int status; //物品状态(运输/送达但未签收/已签收)
    long int code; //物品编码
};


#endif