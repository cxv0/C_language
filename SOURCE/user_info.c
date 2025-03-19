#include "config.h"
#include "custom.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Create and add user info //��������ӵ�ǰ��¼�û���info
DATE:       2025/3/16
******/

void create_user_info(char *account)
{
    FILE *search_fp, *create_fp;
    char file_path[255];
    sprintf(file_path, "C:\\code\\TEXT\\%s.dat", account);

    search_fp = fopen(file_path, "rb");
    if(search_fp == NULL) //���Ҹ��û���Ϣ�Ƿ��Ѿ����ڣ����������򴴽�
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

void add_user_info(char *account, info *ip, char *item_name, int *item_time, int *item_status, long *item_code)
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
{ //number����Ҫ�༭�Ľṹ���ڸ��ļ��Ľṹ���е�λ�Σ�ip��ӦҪ�޸ĵĽṹ��
    FILE *fp;
    char file_path[255]; //�ú������ڸ���ip��Ӧ��info�ṹ����.dat�е�����
    sprintf(file_path, "C:\\code\\TEXT\\%s.dat", account);

    fp = fopen(file_path, "ab+");
    if(fp == NULL)
    {
        printf("\nError on edit data in file %s!", file_path);
        delay(3000);
        exit(1);
    }

    fseek(fp, (number - 1)* sizeof(info), SEEK_SET); //��ָ���ƶ�����number��info��ʼ��
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