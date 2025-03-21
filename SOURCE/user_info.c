#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Create and add user info //创建和添加当前登录用户的info
DATE:       2025/3/16
******/

void create_user_info(char *account)
{
    FILE *search_fp, *create_fp;
    char file_path[255];
    sprintf(file_path, "C:\\code\\TEXT\\%s.dat", account);

    search_fp = fopen(file_path, "rb");
    if(search_fp == NULL) //查找该用户信息是否已经存在，若不存在则创建
    {
        printf("\nFile %s not esixt!", file_path);
        printf("\nFile %s has been created!", file_path);
        create_fp = fopen(file_path, "wb+");
        if(create_fp == NULL)
        {
            printf("\nError on create file %s!", file_path);
            delay(3000);
            exit(1);
        }
        
        fclose(create_fp);
    }
    
    else
    {
        fclose(search_fp);
    }    
    
}

void add_user_info(char *account, info *ip, char *item_name, float *item_price, int *item_status, long *item_code)
{
    FILE *fp;
    char file_path[255];
    sprintf(file_path, "C:\\code\\TEXT\\%s.dat", account);

    fp = fopen(file_path, "ab+");
    if(fp == NULL)
    {
        printf("\nError on add data in file %s!", file_path);
        delay(3000);
        exit(1);
    }

    strcpy(ip->name, item_name);
    ip->price = *item_price;
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

void edit_user_info(char *account, info *ip, char *item_name, float *item_price, int *item_status, long *item_code, int number)
{ //number代表要编辑的结构体在该文件的结构体中的位次，ip对应要修改的结构体
    FILE *fp;
    char file_path[255]; //该函数用于更改ip对应的info结构体在.dat中的数据
    sprintf(file_path, "C:\\code\\TEXT\\%s.dat", account);

    fp = fopen(file_path, "ab+");
    if(fp == NULL)
    {
        printf("\nError on edit data in file %s!", file_path);
        delay(3000);
        exit(1);
    }

    fseek(fp, (number - 1)* sizeof(info), SEEK_SET); //将指针移动到第number个info起始处
    strcpy(ip->name, item_name);
    ip->price = *item_price;
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