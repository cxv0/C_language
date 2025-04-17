#include "config.h"
#include "husttable.h"





/*-------------------------------------------------------README---------------------------------------------------------------
本文件内容为哈希表创建函数及哈希表操作等函数
functionlist:  gethustposition 哈希函数获取该节点的位置
               inithust         初始化一定长度的哈希表
               hustsearch       搜索指定的哈希节点
               hustinsert       插入哈希节点
               hustdelete       删除哈希节点
             destroyhust      摧毁哈希表释放内存
               hustinput        将文件内信息读入哈希表
             hustoutput       将改变值后的哈希表写入文件
             nodecount        清点节点数目
             hustclean        清空哈希表数据
             commentinput     输入评价信息
             stateinfoinput   更改节点评价信息
structerlist:ADMINOB          存储商品信息的结构体
             ADMINNODE        拉链法处理哈希碰撞的哈希节点
             ADMINHUST        哈希表主体
工作过程：
初始化
    在程序开始时用inithust初始化哈希表，再从supeinfo中获取一个商品的信息存储在ADMINOB结构体中，
    之后gethustposition函数对商品名称运算得到的值，再模运算初始化哈希表的长度得到的便是这个商品的地址，
    通过存储了商品信息的adminob放入Hustnode结构体，将该结构体写入哈希表中对应地址处，若该处已被占据则利用链表在其后插入adminnode
与管理员页面库存管理的交互
    进货和上架通过hustsearch找到对应的节点修改参数
    添加货物通过插入哈希节点
    删除货物通过删除哈希节点
与用户页面的交互
    用户在出超市的时候完成购买活动，其购买活动产生的链表包含数目，名称两个参数，通过名称利用hustsearch找到节点后修改参数即可
信息存储
    每次改变哈希表内部参数后利用文件操作覆盖supeinfo里的信息
----------------------------------------------------------end--------------------------------------------------------------------------------------
*/

/*********************
function name:Gethustposition
create:2/27
description:哈希函数
input char *s
return unsigned int
**********************/
unsigned int GetHustPosition(char *s)
{
    int sum = 0;
    while (*s != '\0')
    {
        sum += (int)(*s);
        s++;
    }
    return sum;
} //哈希函数
/*********************
function name:InitHust
create:2/27
description:初始化哈希表
input int length
return ADMINASH *
**********************/
ADMINHUST *InitHust(int length)
{
    ADMINHUST *hh = NULL; //哈希表初始化

    if (length == 0)
    {
        printf("parameter wrong int function InitHust\n");
        return NULL;
    }

    if ((hh = (ADMINHUST *)malloc(sizeof(ADMINHUST))) == NULL) //为哈希表主体申请内存
    {
        printf("memoryallocation runs wrong in function InitHust");
        return NULL;
    }

    if ((hh->hustlist = (ADMINNODE **)malloc(length * sizeof(ADMINNODE *))) == NULL)
    {
        printf("memoryallocation runs wrong in function Inithust");
        free(hh);
        return NULL;
    } //申请指定长度的指针数组

    (void)memset(hh->hustlist, 0, length * sizeof(ADMINNODE *));

    hh->length = length;

    return hh;
}
/*********************
function name:HustSearch
create:2/27
description:搜索哈希节点
input:ADMINHUST *hust,char *name
return ADMINNODE *
**********************/
ADMINNODE *HustSearch(ADMINHUST *hust, char name[10])
{
    unsigned int position;

    ADMINNODE *hustnode = NULL; //暂存待比较信息的的节点

    if (hust == NULL || hust->hustlist == NULL)
    {
        printf("hust not initialize in hustsearch");
        return NULL;
    }

    position = GetHustPosition(name) % hust->length;

    hustnode = hust->hustlist[position];

    while (hustnode != NULL && hustnode->valid == 1) //遍历冲突链表
    {
        if (hustnode->valid == 1 && strcmp(hustnode->goods.name, name) == 0)
        {
            return hustnode; //返回结果
        }
        hustnode = hustnode->next; //指向下一个元素
    }

    return NULL;
}
/*********************
function name:Hustinsert
create:2/27
description:插入节点
input ADMINHUST *hust, ADMINOB *node
return int
**********************/
int Hustinsert(ADMINHUST *hust, ADMINOB *node)
{
    unsigned int position = 0;
    ADMINNODE *newhustNode = NULL;

    if (hust == NULL || node == NULL || hust->hustlist == NULL)
    {
        printf("hust not initialize in hustinsert");
        return 0;
    }

    if ((newhustNode = (ADMINNODE *)malloc(sizeof(ADMINNODE))) == NULL)
    {
        printf("memoryallocation runs wrong in function hustinsert");
        return 0;
    }

    memset(newhustNode, 0, sizeof(ADMINNODE));
    memcpy(&newhustNode->goods, node, sizeof(ADMINOB));
    newhustNode->valid = 1;
    newhustNode->next = NULL;

    position = GetHustPosition(newhustNode->goods.name) % hust->length;
    free(node);
    /*初始化newhustnode信息*/
    if (hust->hustlist[position] == NULL)
    {
        hust->hustlist[position] = newhustNode;
        return 1;
    } //未发生hust collision
    else
    {
        newhustNode->next = hust->hustlist[position]->next;
        hust->hustlist[position]->next = newhustNode;
        return 1;
    }
}

/*********************
function name:Hustdelete
create:2/27
description:删除指定节点的信息
input ADMINHUST *hust, ADMINOB *node
return bool
**********************/
int Hustdelete(ADMINHUST *hust, char name[10])
{
    unsigned int position = 0;
    ADMINNODE *deleteawait = NULL; //存储hustsearch函数找到的待删除节点
    ADMINNODE *tempnode = NULL;    //存储位于待删除节点上一个位置的节点

    if (hust == NULL)
    {
        printf("hust not initialize in hustdelete");
        return 0;
    }

    position = GetHustPosition(name) % hust->length; //找寻头节点
    deleteawait = HustSearch(hust, name);
    tempnode = hust->hustlist[position];

    if (deleteawait != NULL)
    {
        if (strcmp(tempnode->goods.name, name) == 0)
        {
            hust->hustlist[position] = deleteawait->next; //更换头节点
            free(deleteawait);                            //删除该节点
            return 1;
        } //待删除节点为头节点时
        else
        {
            while (tempnode != NULL)
            {
                if (strcmp(tempnode->next->goods.name, name) == 0)
                {
                    tempnode->next = deleteawait->next; //链接待删除节点前后两个节点
                    free(deleteawait);
                    return 1;
                }
                tempnode = tempnode->next; //如果标记节点下一个不为目标节点，则往链表下一个节点搜寻
            }
        }
    }
    return 0;
}
/*********************
function name:nodecount
create:4/5
description:计算节点个数
input ADMINHUST *hust
return int
**********************/
int nodecount(ADMINHUST *hust)
{
    int num;
    int i;
    ADMINNODE *hustnode;

    for (i = 0; i < hust->length; i++)
    {
        hustnode = hust->hustlist[i];
        while (hustnode != NULL)
        {
            num++;
            hustnode = hustnode->next;
        }
    }
    return num;
}
/*********************
function name:hustclean
create:4/1
description:清空哈希表
input ADMINHUST **phust
return void
**********************/
void hustclean(ADMINHUST **phust)
{
    int i;
    ADMINHUST *hust = NULL;
    ADMINNODE *hustnode = NULL;
    ADMINNODE *tempnode = NULL;

    if (phust == NULL)
    {
        printf("hust not initialize in cleanhust");
        return;
    }

    hust = *phust;
    if (hust->hustlist != NULL)
    {
        for (i = 0; i < hust->length; i++)
        {
            hustnode = hust->hustlist[i];
            while (hustnode != NULL && hustnode->valid == 1)
            {
                tempnode = hustnode;
                hustnode = hustnode->next;
                free(tempnode);
            }
            hust->hustlist[i] = NULL;
        }
    }
}
/*********************
function name:hustdestoy
create:2/27
description:删除哈希表
input ADMINHUST **phust
return void
**********************/
void hustdestroy(ADMINHUST **phust)
{
    int i;
    ADMINHUST *hust = NULL;
    ADMINNODE *hustnode = NULL;
    ADMINNODE *tempnode = NULL;

    if (phust == NULL)
    {
        printf("hust not initialize destroy hust");
        return;
    }

    hust = *phust;
    if (hust->hustlist != NULL)
    {
        for (i = 0; i < hust->length; i++)
        {
            hustnode = hust->hustlist[i];
            while (hustnode != NULL && hustnode->valid == 1)
            {
                tempnode = hustnode;
                hustnode = hustnode->next;
                free(tempnode);
            }
        }
        free(hust->hustlist);
    }
    free(hust);
    *phust = NULL;
}


/*************************
function:hustinput
description:将信息输入哈希表
create:2022/3/5
input:void
output:void
**************************/
void hustinput(ADMINHUST *hust)
{
    FILE *fp;
    int len;
    int i;
    ADMINOB *object;

    if (hust == NULL)
    {
        printf("hust not initialize in function hustinput");
        delay(3000);
    }

    if ((fp = fopen("C:\\code\\TEXT\\package.dat", "rb+")) == NULL)
    {
        printf("cannot open file in function hustinput");
        delay(3000);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(ADMINOB);

    for (i = 0; i < len; i++)
    {
        if ((object = (ADMINOB *)malloc(sizeof(ADMINOB))) == NULL)
        {
            printf("memoryallocation runs wrong in hustinput");
        }

        memset(object, 0, sizeof(ADMINOB));
        fseek(fp, i * sizeof(ADMINOB), SEEK_SET);
        fread(object, sizeof(ADMINOB), 1, fp);

        if (Hustinsert(hust, object) == 0)
        {
            printf("hustinput wrong");
            delay(3000);
        }

        free(object);
    }
    
    fclose(fp);
    delay(1);/*永远的神*/
}
/*************************
function:husthoutput
description:将哈希表信息写入文件
create:2022/3/12
input:ADMINHUST *hust
output:void
**************************/
void hustoutput(ADMINHUST *hust)
{
    FILE *fp;
    int i;
    ADMINNODE *hustnode;
    ADMINOB *deposit;

    if ((fp = fopen("C:\\code\\TEXT\\package.dat", "wb")) == NULL)
    {
        printf("cannot open file in function hustSinput");
        delay(3000);
    }

    rewind(fp);

    for (i = 0; i < hust->length; i++)
    {
        hustnode = hust->hustlist[i];
        while (hustnode != NULL && hustnode->valid == 1)
        {
            deposit = &hustnode->goods;
            fwrite(deposit, sizeof(ADMINOB), 1, fp);
            hustnode = hustnode->next;
        }
    }

    fclose(fp);
}


void output(ADMINHUST *hust, int page, int *state)
{
    int j;     //输出哈希表内信息的行数
    int k = 0; //哈希位置
    ADMINNODE *hustnode;

    setcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);

    for (j = 0; j < (page - 1) * 8 && k < hust->length; k++)
    {
        hustnode = hust->hustlist[k];
        while (hustnode != NULL && hustnode->valid == 1)
        {
            hustnode = hustnode->next;
            j++;
        }
    } //按页数定位数据点，一页八个

    for (j = 0; j < 8 && k < hust->length; k++)
    {
        while (hustnode != NULL && hustnode->valid == 1)
        {
            outtextxy(20, 100 + 30 * j, hustnode->goods.name);
            outtextxy(220, 100 + 30 * j, hustnode->goods.place);
            outtextxy(420, 100 + 30 * j, hustnode->goods.number);
            j++;
            hustnode = hustnode->next;
        } //输出下八个数据点
        hustnode = hust->hustlist[k];
    }

    if (j == 8)
    {
        *state = 1;
    }
    else
    {
        *state = 0;
    } //根据该页是否输出满八行更改翻页状态
}


