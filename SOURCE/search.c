#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Search goods wanted
DATE:       2025/3/20
******/

void refresh(char *ptr) //�����ļ���,��ն�Ӧ�ļ�������ָ��
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
{ //���ض�Ӧ��info�ṹ��ָ��
    FILE *fp, *search_result;
    fp = fopen("C:\\code\\TEXT\\database.dat", "rb");
    char str[10] = "searchrs";
    refresh(str);
    search_result = fopen("C:\\code\\TEXT\\searchrs.dat", "a+"); //��.dat�ļ�����������
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
        init_infogroup(fp); //fp�ڴ洢����Ʒ��Ϣ
        for(i = 0; i < 30; i ++)
        {
            fread(ip, sizeof(info), 1, fp); //��fp��ȡһ���ṹ�����ip
            if(ip->code == code)
            {
                fwrite(ip, sizeof(info), 1, search_result); //����Ҫ����д��searchrs.dat
            }
            fseek(fp, SEEK_SET, (i + 1) * (sizeof(info))); //fpָ��ָ����һ���ṹ��
            *ip = NULL; //���ip
        }
    }

}