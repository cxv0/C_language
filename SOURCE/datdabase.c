#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Database of goods //创建与修改商品数据库
DATE:       2025/3/19
******/

void database()
{     
    FILE *searchfp = fopen("C:\\code\\TEXT\\database.dat", "r");
    if(searchfp == NULL)
    {
        printf("\nError on open file or file does not exist!");
        FILE *createfp = fopen("C:\\code\\TEXT\\database.dat", "wb+");
        if(createfp == NULL)
        {
            printf("\nError on create file!");
        }
        else
        {
            fclose(createfp);
        }
    }

    else
    {
        fclose(searchfp);
    }
}

void save_to_database(FILE *fp, info *ip)
{
    if(fp == NULL)
    {
        printf("\nError on open database file!");
        delay(3000);
        exit(1);
    }

    fwrite(ip, sizeof(info), 1, fp);
    fclose(fp);
}

void init_infogroup(FILE *fp)
{
    struct info infogroup[30] = 
    { //在这里输入商品信息
        {"炒饭", 0, 15, 20250001},
        {"面条", 0, 12, 20250002},
    };
    int i = 0;
    for(i = 0; i < 30; i ++)
    {
        save_to_database(fp, &infogroup[i]);
        delay(20);
    }
    
}