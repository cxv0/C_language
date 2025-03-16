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
    sprintf(file_path, "C:\\code\\TEXT\\%s_info.txt", account);

    FILE *fp = fopen(file_path, "wb+");
    if(fp == NULL)
    {
        printf("\nError on create file %s!", file_path);
        delay(3000);
        exit(1);
    }

    fclose(fp);
}

void add_user_info(char *account, info *ip)
{
    char file_path[255];
    sprintf(file_path, "C:\\code\\TEXT\\%s_info.txt", account);

    FILE *fp = fopen(file_path, "ab+");
    if(fp == NULL)
    {
        printf("\nError on create file %s!", file_path);
        delay(3000);
        exit(1);
    }

    fwrite(ip, sizeof(info), 1, fp);

    if(fclose(fp) != 0)
    {
        printf("\nError on close file %s!", file_path);
        delay(3000);
        exit(1);
    }
}