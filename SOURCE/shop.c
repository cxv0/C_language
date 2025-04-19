#include "config.h"
#include "order.h"
#include "shop.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Save & edit goods record
DATE:       2025/4/9 
******/

void check_record_dat() //ȷ��record.dat����
{
    FILE *fp1 = fopen("C:\\CODE\\TEXT\\record.dat", "rb"), *fp2 = NULL;
    if(fp1 == NULL) //���Ҹ��û���Ϣ�Ƿ��Ѿ����ڣ����������򴴽�
    {
        if((fp2 = fopen("C:\\CODE\\TEXT\\record.dat", "wb+")) == NULL)
        {
            printf("\nError on create file %s!", "C:\\CODE\\TEXT\\record.dat");
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

int count_userrecord() //����record.dat�й��м����ṹ��
{
    int count = 0;
    RECORD record;
    FILE *fp = NULL;
    check_record_dat();
    fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb");

    while(fread(&record, sizeof(RECORD), 1, fp))
    {
        count ++; //.dat�й��м����ṹ��
    }
    fclose(fp);
    return count;
}

RECORD *new_record(RECORD *rp) //���ɿհ׼�¼
{
    int i = 0;
    check_record_dat();
    rp->sum = 0;
    rp->state = -1; //����ȷ���Ƿ�����µ�

    for(i = 0; i < 16; i++)
    {
        rp->num[i] = 0;
    }

    return rp;
}

void record_addnum(RECORD *rp, INFO *ip) //�˴���ip�ǵ����ṹ��ָ��,������ӵ���һ����Ʒ�����ݶ����ܼ���
{
    int i = ip->NO;
    rp->num[i - 1] += ip->num;
    rp->sum += ip->num * ip->price;
}

void edit_record(RECORD *rp, INFO *ip) //�˴���ip�ǵ����ṹ��ָ��,�����޸ĵ���һ����Ʒ������
{
    int i = ip->NO;

    if(ip->num > rp->num[i - 1]) //���������������
    {
        rp->sum += (ip->num - rp->num[i - 1]) * (ip->price); //�����ܼ�
    }
    else if(ip->num < rp->num[i - 1]) //���������������
    {
        rp->sum -= (rp->num[i - 1] - ip->num) * (ip->price); //�����ܼ�
    }
    rp->num[i - 1] = ip->num;
}

RECORD *ensure_record(RECORD *rp) //ȷ���µ�
{
    rp->state = 1;
    return rp;
}

void add_record(RECORD *rp) //�洢�����¼
{
    FILE *fp = NULL;
    check_record_dat();
    fp = fopen("C:\\CODE\\TEXT\\record.dat", "ab+");

    if(fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }

    if(rp->state == 1) //����Ƿ�ȷ�Ϲ�����Ϊ
    {
        fseek(fp, 0, SEEK_END);
        fwrite(rp, sizeof(RECORD), 1, fp);
        fclose(fp);
    }
    return;
}

RECORD *output_record(char *account) //�����ʷ��¼ָ��
{
    int i = 0, count = count_userrecord();
    int max_record = 1; //�������һ�μ�¼,�ɵ�
    int count_record = 0; //�Ѿ�����Ĵ���
    RECORD temp;
    static RECORD output;
    FILE *fp = NULL;
    check_record_dat();
    fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb");

    if(fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }

    strcpy(temp.account, account);
    fseek(fp, 0, SEEK_END);
    for(i = count; i > 0; i --)
    {
        fseek(fp, (i - 1) * sizeof(RECORD), SEEK_SET);
        fread(&temp, sizeof(RECORD), 1, fp);
        if(strcmp(temp.account, account) == 0)
        {
            output = temp;
            count_record ++;
            if(count_record >= max_record)
            {
                fclose(fp);
                return &output;
            }
        }
    }
    fclose(fp);
    return NULL;
}

void output_to_screen(RECORD *rp)
{
    int i = 0;
    int conut_zero = 0;
    char goods_name[16][20] = {"��Ʒһ", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒ��", "��Ʒʮ", "��Ʒʮһ", "��Ʒʮ��", "��Ʒʮ��", "��Ʒʮ��", "��Ʒʮ��", "��Ʒʮ��"};
    int price[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    char str[10];
    RECORD temp = *rp;
    settextstyle(TRIPLEX_FONT, 0, 2);

    for(i = 0; i < 16; i ++)
    {
        str[0] = '\0';
        itoa(temp.num[i], str, 10);
        if(temp.num[i] == 0)
        {
            conut_zero ++;
        }
        else
        {
            outtextxy(590, 75 + 1 + 20 * (i - conut_zero), str);
            puthz(50, 75 + 7 + 20 * (i - conut_zero), goods_name[i], 16, 18, MAGENTA);
            itoa(temp.num[i] * price[i], str, 10);
            outtextxy(310, 75 + 1 + 20 * (i - conut_zero), str);
        }
    }
    str[0] = '\0';
    itoa(temp.sum, str, 10);
    outtextxy(555, 400, str);
}

/*int seek_init_userrecord(char *account, INFO *infp) //����account��Ӧ�ṹ��,û�ҵ����½��û���Ϊaccount,������Ϊ�յĽṹ��,�����ؽṹ������;�ҵ��򷵻�λ��i
{
    int i = 0, count = count_userrecord();
    RECORD record, temp, *ip = &temp;
    FILE *seek = NULL;
    check_record_dat();
    seek = fopen("C:\\CODE\\TEXT\\record.dat", "rb+");

    strcpy(temp.account, account);
    rewind(seek);
    for(i = 0; i < count; i ++)
    {
        fseek(seek, i * sizeof(RECORD), SEEK_SET); //�Ƶ���i + 1���ṹ�忪ʼ��,�ӵ�һ����ʼ
        fread(&record, sizeof(RECORD), 1, seek);
        if(strcmp(record.account, account) == 0) //�ҵ�����ĸ�account�Ĺ����¼
        {
            fclose(seek);
            return i;
        }
    }
    
    fseek(seek, 0, SEEK_END);
    fwrite(ip, sizeof(RECORD), 1, seek);
    fclose(seek);
    return count;
}

void add_userrecord(RECORD *ip) //��record.datĩβ׷����Ϣ,����д
{
    int i = count_userrecord();
    FILE *fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb+");
    RECORD record;
    
    if(fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    fwrite(ip, sizeof(RECORD), 1, fp);
    fclose(fp);
    return;
}*/

/*void overwrite_userrecord(INFO *infp) //�����û���Ϊaccount�Ľṹ��,�޸�ĳһ����Ʒ����
{
    int i = seek_init_userrecord(ip->account);
    int j = 0;
    int NO = infp->NO;
    FILE *fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb+");
    RECORD temp;
    
    temp.num[NO - 1] = infp->num;
    for(j = 0;j < 16;j ++)
    {
        temp.sum += temp.num[j];
    }

    if(fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }
    
    fseek(fp, i * sizeof(RECORD), SEEK_SET); //�Ƶ��ṹ�忪ʼ��,λ����seek_init_userrecord��������
    fwrite(&temp, sizeof(RECORD), 1, fp);
    fclose(fp);
    return;
} //��ΪҪʵ�������ʷ��¼�Ĺ���,�Ͳ���ֱ�Ӹ�д��,����Ҫ�������,���ұ�����,Ҳ���������ɾ��ĳһ��¼
*/ //�ĵ�һ�뷢�ֲ����ñ�Ĺ���,����!

/*void delete_userrecord(char *account) //ɾ��account����ɼ�¼���������µ����μ�¼
{
    static int count = 0; // ��̬�������ڼ���
    int index = -1;
    int i = 0;
    RECORD record;
    FILE *fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb+");
    
    if(fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }

    // ����account��Ӧ�ṹ�������
    for(i = 0; i < count_userrecord(); i++)
    {
        fseek(fp, i * sizeof(RECORD), SEEK_SET);
        fread(&record, sizeof(RECORD), 1, fp);
        if(strcmp(record.account, account) == 0)
        {
            if(index == -1) // �ҵ���һ��ƥ��ļ�¼
                index = i;
            count ++; // ����ƥ��ļ�¼
        }
    }

    if(count > 3 && index != -1) // �����¼���������������ҵ�ƥ��ļ�¼
    {
        // ɾ����¼
        for(i = index; i < count_userrecord() - 1; i ++)
        {
            fseek(fp, (i + 1) * sizeof(RECORD), SEEK_SET);
            fread(&record, sizeof(RECORD), 1, fp);
            fseek(fp, i * sizeof(RECORD), SEEK_SET);
            fwrite(&record, sizeof(IRECORD), 1, fp);
        }

        fclose(fp);

        // �ݹ���ã�����ɾ��
        delete_userrecord(account);
    }
    else
    {
        fclose(fp);
    }
}*/ //���Ҳ��⺯��û�ð�

/*void output_to_latest(char *account, int x1, int y1, int x2, int y2) //���account��������μ�¼(���������),�����������(x1, y1)����(x2, y2)�ľ��ο���
{
    int i = 0, j = 0, count = count_userrecord();
    delete_userrecord(account);
    int width = x2 - x1, height = y1 - y2;
    FILE *fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb");
    RECORD record;

    delete_userrecord(account);
    settextstyle(1, 0, 3);
    
    if(fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }
    
    for(i = 0; i < count; i++)
    {
        fseek(fp, i * sizeof(RECORD), SEEK_SET); //�Ƶ���i + 1���ṹ�忪ʼ��,�ӵ�һ����ʼ
        fread(&record, sizeof(RECORD), 1, fp);
        for(j = 0; j < 3; j++)
        {
            if(strcmp(record.account, account) == 0)
            {
                outtextxy(x1, y1 + j * (height / 9), record.account);
                outtextxy(x1, y1 + j * (2 * height / 9), record.account);
                outtextxy(x1, y1 + j * (3 * height / 9), record.account);
            }
        }
    }
    
    fclose(fp);
}*/

/*void output_to_latest(char *account, int x1, int y1, int x2, int y2)
{
    int i, k;
    int record_y;
    int sum_x, num_x;
    int width, height;
    char sum_str[20];
    char num_str[100];
    char temp[10];
    RECORD record;
    FILE *fp;

    // ���ļ�
    fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb");
    if (fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }

    // ��ʼ������
    i = 0;
    record_y = y1;

    // ��ȡ�ļ���ɸѡָ���˻��ļ�¼
    while (fread(&record, sizeof(RECORD), 1, fp))
    {
        if (strcmp(record.account, account) == 0)
        {
            // ����˻���
            outtextxy(x1, record_y, record.account);

            // �����ܺ͵����λ��
            sum_x = x1 + textwidth(record.account) + 5; // ���˻����Ҳ�����ܺ�
            sprintf(sum_str, "%.2f", record.sum);
            outtextxy(sum_x, record_y, sum_str);

            // ������Ʒ�������������λ��
            num_x = sum_x + textwidth(sum_str) + 5; // ���ܺ��Ҳ������Ʒ��������
            num_str[0] = '\0'; // ��ʼ��num_strΪ���ַ���
            for (k = 0; k < 16; k++)
            {
                if (k > 0)
                {
                    strcat(num_str, ", ");
                }
                sprintf(temp, "%d", record.num[k]);
                strcat(num_str, temp);
            }
            outtextxy(num_x, record_y, num_str);

            // ������һ����¼�Ĵ�ֱλ��
            record_y += textheight("A"); // ����һ�еĸ߶�

            // ȷ�����ᳬ�����ο�ı߽�
            if (record_y >= y2)
            {
                break; // �����߽���ֹͣ���
            }
        }
    }

    fclose(fp);
}*/ //����б�Ҫ����x��y������?