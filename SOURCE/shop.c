#include "config.h"
#include "order.h"
#include "shop.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Save & edit goods record
DATE:       2025/4/9 
******/

void check_record_dat() //确保record.dat存在
{
    FILE *fp1 = fopen("C:\\CODE\\TEXT\\record.dat", "rb"), *fp2 = NULL;
    if(fp1 == NULL) //查找该用户信息是否已经存在，若不存在则创建
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

int count_userrecord() //计数record.dat中共有几个结构体
{
    int count = 0;
    RECORD record;
    FILE *fp = NULL;
    check_record_dat();
    fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb");

    while(fread(&record, sizeof(RECORD), 1, fp))
    {
        count ++; //.dat中共有几个结构体
    }
    fclose(fp);
    return count;
}

RECORD *new_record(RECORD *rp) //生成空白记录
{
    int i = 0;
    check_record_dat();
    rp->sum = 0;
    rp->state = -1; //用于确认是否完成下单

    for(i = 0; i < 16; i++)
    {
        rp->num[i] = 0;
    }

    return rp;
}

void record_addnum(RECORD *rp, INFO *ip) //此处的ip是单个结构体指针,用于添加单独一种商品的数据而不能减少
{
    int i = ip->NO;
    rp->num[i - 1] += ip->num;
    rp->sum += ip->num * ip->price;
}

void edit_record(RECORD *rp, INFO *ip) //此处的ip是单个结构体指针,用于修改单独一种商品的数据
{
    int i = ip->NO;

    if(ip->num > rp->num[i - 1]) //如果购买数量增加
    {
        rp->sum += (ip->num - rp->num[i - 1]) * (ip->price); //增加总价
    }
    else if(ip->num < rp->num[i - 1]) //如果购买数量减少
    {
        rp->sum -= (rp->num[i - 1] - ip->num) * (ip->price); //减少总价
    }
    rp->num[i - 1] = ip->num;
}

RECORD *ensure_record(RECORD *rp) //确认下单
{
    rp->state = 1;
    return rp;
}

void add_record(RECORD *rp) //存储购买记录
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

    if(rp->state == 1) //检查是否确认购买行为
    {
        fseek(fp, 0, SEEK_END);
        fwrite(rp, sizeof(RECORD), 1, fp);
        fclose(fp);
    }
    return;
}

RECORD *output_record(char *account) //输出历史记录指针
{
    int i = 0, count = count_userrecord();
    int max_record = 1; //至多输出一次记录,可调
    int count_record = 0; //已经输出的次数
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
    char goods_name[16][20] = {"商品一", "商品二", "商品三", "商品四", "商品五", "商品六", "商品七", "商品八", "商品九", "商品十", "商品十一", "商品十二", "商品十三", "商品十四", "商品十五", "商品十六"};
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

/*int seek_init_userrecord(char *account, INFO *infp) //查找account对应结构体,没找到则新建用户名为account,其他项为空的结构体,并返回结构体数量;找到则返回位次i
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
        fseek(seek, i * sizeof(RECORD), SEEK_SET); //移到第i + 1个结构体开始处,从第一个开始
        fread(&record, sizeof(RECORD), 1, seek);
        if(strcmp(record.account, account) == 0) //找到最早的该account的购买记录
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

void add_userrecord(RECORD *ip) //在record.dat末尾追加信息,不覆写
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

/*void overwrite_userrecord(INFO *infp) //覆盖用户名为account的结构体,修改某一项商品数量
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
    
    fseek(fp, i * sizeof(RECORD), SEEK_SET); //移到结构体开始处,位置由seek_init_userrecord函数给出
    fwrite(&temp, sizeof(RECORD), 1, fp);
    fclose(fp);
    return;
} //因为要实现输出历史记录的功能,就不能直接覆写了,而是要另加内容,暂且保留着,也许可以用于删除某一记录
*/ //改到一半发现不如用别的功能,爆了!

/*void delete_userrecord(char *account) //删除account的最旧记录，保留最新的三次记录
{
    static int count = 0; // 静态变量用于计数
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

    // 查找account对应结构体的索引
    for(i = 0; i < count_userrecord(); i++)
    {
        fseek(fp, i * sizeof(RECORD), SEEK_SET);
        fread(&record, sizeof(RECORD), 1, fp);
        if(strcmp(record.account, account) == 0)
        {
            if(index == -1) // 找到第一个匹配的记录
                index = i;
            count ++; // 计数匹配的记录
        }
    }

    if(count > 3 && index != -1) // 如果记录数量超过三次且找到匹配的记录
    {
        // 删除记录
        for(i = index; i < count_userrecord() - 1; i ++)
        {
            fseek(fp, (i + 1) * sizeof(RECORD), SEEK_SET);
            fread(&record, sizeof(RECORD), 1, fp);
            fseek(fp, i * sizeof(RECORD), SEEK_SET);
            fwrite(&record, sizeof(IRECORD), 1, fp);
        }

        fclose(fp);

        // 递归调用，继续删除
        delete_userrecord(account);
    }
    else
    {
        fclose(fp);
    }
}*/ //诶我草这函数没用啊

/*void output_to_latest(char *account, int x1, int y1, int x2, int y2) //输出account的最后三次记录(如果有三次),并输出到左上(x1, y1)右下(x2, y2)的矩形框中
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
        fseek(fp, i * sizeof(RECORD), SEEK_SET); //移到第i + 1个结构体开始处,从第一个开始
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

    // 打开文件
    fp = fopen("C:\\CODE\\TEXT\\record.dat", "rb");
    if (fp == NULL)
    {
        printf("\nError on open file %s!", "C:\\CODE\\TEXT\\record.dat");
        delay(3000);
        exit(1);
    }

    // 初始化变量
    i = 0;
    record_y = y1;

    // 读取文件并筛选指定账户的记录
    while (fread(&record, sizeof(RECORD), 1, fp))
    {
        if (strcmp(record.account, account) == 0)
        {
            // 输出账户名
            outtextxy(x1, record_y, record.account);

            // 计算总和的输出位置
            sum_x = x1 + textwidth(record.account) + 5; // 在账户名右侧输出总和
            sprintf(sum_str, "%.2f", record.sum);
            outtextxy(sum_x, record_y, sum_str);

            // 计算商品购买数量的输出位置
            num_x = sum_x + textwidth(sum_str) + 5; // 在总和右侧输出商品购买数量
            num_str[0] = '\0'; // 初始化num_str为空字符串
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

            // 更新下一条记录的垂直位置
            record_y += textheight("A"); // 增加一行的高度

            // 确保不会超出矩形框的边界
            if (record_y >= y2)
            {
                break; // 超出边界则停止输出
            }
        }
    }

    fclose(fp);
}*/ //真的有必要引入x和y参数吗?