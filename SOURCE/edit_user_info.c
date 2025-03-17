#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Create and add user info //创建和添加当前登录用户的info
DATE:       2025/3/16
******/

void create_user_info(char *account)
{
    char file_path[255];
    sprintf(file_path, "C:\\code\\TEXT\\%s_info.dat", account);

    FILE *search_fp = fopen(file_path, "rb");
    if(search_fp == NULL) //查找该用户信息是否已经存在，若不存在则创建
    {
        FILE *create_file = fopen(file_path, "wb+");
        if(create_file == NULL)
        {
            printf("\nError on create file %s!", file_path);
            delay(3000);
            exit(1);
        }
        printf("\nError on open %s_info.dat!",account);
    }

    fclose(fp);
}

void add_user_info(char *account, info *ip, char *item_name, int *item_time, int *item_status, long *item_code)
{
    char file_path[255];
    sprintf(file_path, "C:\\code\\TEXT\\%s_info.dat", account);

    FILE *fp = fopen(file_path, "ab+");
    if(fp == NULL)
    {
        printf("\nError on add data in file %s!", file_path);
        delay(3000);
        exit(1);
    }

    strcpy(ip->name, item_name);
    ip->time = *item_time;
    ip->status = *item_status;
    ip->code = *item_code;
    fwrite(ip, sizeof(info), 1, fp);

    if(fclose(fp) != 0)
    {
        printf("\nError on close file %s!", file_path);
        delay(3000);
        exit(1);
    }
}

void edit_user_info(char *account, info *ip, char *item_name, int *item_time, int *item_status, long *item_code, int number)
{ //number代表要编辑的结构体在该文件的结构体中的位次
    char file_path[255]; //该函数用于更改ip对应的info结构体在.dat中的数据
    sprintf(file_path, "C:\\code\\TEXT\\%s_info.dat", account);

    FILE *fp = fopen(file_path, "ab+");
    if(fp == NULL)
    {
        printf("\nError on edit data in file %s!", file_path);
        delay(3000);
        exit(1);
    }

    fseek(fp, (number - 1)* sizeof(info), SEEK_SET); //将指针移动到第number个info起始处
    strcpy(ip->name, item_name);
    ip->time = *item_time;
    ip->status = *item_status;
    ip->code = *item_code;
    fwrite(ip, sizeof(info), 1, fp);

    if(fclose(fp) != 0)
    {
        printf("\nError on close file %s!", file_path);
        delay(3000);
        exit(1);
    }
}