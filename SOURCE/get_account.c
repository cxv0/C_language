#include "config.h"
#include "gtaccount.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Get current account
DATE:       2025/4/17
******/

void check_getacc_dat() //确保getacc.dat存在
{
    FILE *fp1 = fopen("C:\\CODE\\TEXT\\getacc.dat", "rb"), *fp2 = NULL;
    if(fp1 == NULL) //查找getacc.dat是否已经存在，若不存在则创建
    {
        printf("\nFile %s not exist!", "C:\\CODE\\TEXT\\getacc.dat");
        printf("\nTry to create file %s!", "C:\\CODE\\TEXT\\getacc.dat");
        if((fp2 = fopen("C:\\CODE\\TEXT\\getacc.dat", "wb+")) == NULL)
        {
            printf("\nError on create file %s!", "C:\\CODE\\TEXT\\getacc.dat");
            delay(3000);
            exit(1);
        }
        fclose(fp2);
    }
    
    else
    {
        fclose(fp1);
    }
}

void get_acc_to_dat(char *account)
{
    char str[20];
    FILE *fp;
    check_getacc_dat();
    strcpy(str, account);
    fp = fopen("C:\\CODE\\TEXT\\getacc.dat", "wb+");
    fseek(fp, 0, SEEK_SET);
    fwrite(str, sizeof(str), 1, fp);
    fclose(fp);
}

char *output_account()
{
    static char str[20];
    FILE *fp;
    check_getacc_dat();
    fp = fopen("C:\\CODE\\TEXT\\getacc.dat", "rb");
    fseek(fp, 0, SEEK_SET);
    fread(str, 8, 1, fp);
    fclose(fp);
    return str;
}