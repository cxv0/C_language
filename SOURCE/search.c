#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Search goods wanted
DATE:       2025/3/20
******/

void refresh(char *ptr) //输入文件名,清空对应文件并返回指针
{
    FILE *fp;
    char file_path[255];
    sprintf(file_path, "C:\\code\\TEXT\\%s.dat", ptr);
    fp = fopen(file_path, "w");

    if(fp == NULL)
    {
        printf("\nError on open file!");
        delay(3000);
        exit(1);
    }

}

info *searchfunc(long code)
{ //返回对应的info结构体指针
    FILE *fp, *search_result;
    fp = fopen("C:\\code\\TEXT\\database.dat", "rb");
    char str[10] = "searchrs";
    refresh(str);
    search_result = fopen("C:\\code\\TEXT\\searchrs.dat", "a+"); //该.dat文件存放搜索结果
    info *ip = NULL;
    int i = 0;
    rewind(fp);
    
    if(fp == NULL || search_result == NULL)
    {
        printf("\nError on open file!");
        delay(3000);
        exit(1);
    }
    else
    {
        init_infogroup(fp); //fp内存储着商品信息
        for(i = 0; i < 30; i ++)
        {
            fread(ip, sizeof(info), 1, fp); //从fp读取一个结构体存入ip
            if(ip->code == code)
            {
                fwrite(ip, sizeof(info), 1, search_result); //符合要求则写入searchrs.dat
            }
            fseek(fp, SEEK_SET, (i + 1) * (sizeof(info))); //fp指针指向下一个结构体
            *ip = NULL; //清空ip
        }
    }

}