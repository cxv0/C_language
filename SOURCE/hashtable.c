#include "config.h"
#include "custom.h"





/*-------------------------------------------------------README---------------------------------------------------------------
本文件内容为哈希表创建函数及哈希表操作等函数
functionlist:gethashposition 哈希函数获取该节点的位置
             inithash         初始化一定长度的哈希表
             hashsearch       搜索指定的哈希节点
             hashinsert       插入哈希节点
             hashdelete       删除哈希节点
             destroyhash      摧毁哈希表释放内存
             hashinput        将文件内信息读入哈希表
             hashoutput       将改变值后的哈希表写入文件
             nodecount        清点节点数目
             hashclean        清空哈希表数据
             commentinput     输入评价信息
             stateinfoinput   更改节点评价信息
structerlist:ADMINOB          存储商品信息的结构体
             ADMINNODE        拉链法处理哈希碰撞的哈希节点
             ADMINHASH        哈希表主体
工作过程：
初始化
    在程序开始时用inithash初始化哈希表，再从supeinfo中获取一个商品的信息存储在ADMINOB结构体中，
    之后gethashposition函数对商品名称运算得到的值，再模运算初始化哈希表的长度得到的便是这个商品的地址，
    通过存储了商品信息的adminob放入Hashnode结构体，将该结构体写入哈希表中对应地址处，若该处已被占据则利用链表在其后插入adminnode
与管理员页面库存管理的交互
    进货和上架通过hashsearch找到对应的节点修改参数
    添加货物通过插入哈希节点
    删除货物通过删除哈希节点
与用户页面的交互
    用户在出超市的时候完成购买活动，其购买活动产生的链表包含数目，名称两个参数，通过名称利用hashsearch找到节点后修改参数即可
信息存储
    每次改变哈希表内部参数后利用文件操作覆盖supeinfo里的信息
pushuchen 2022.2.27
finish:2022.3.5 这辈子不想愿在搓哈希表
modify:2022.3.8 修改了通过名字字符串获取位置的函数
modify:2022.3.12 哈希搜索函数出现问题
                 11：42累加忘初始化，哈希删除函数无法工作
modify:2022.3.16 调整了输出函数，删除函数问题没解决，写入函数出现问题，哈希碰撞解决
modify:2022.3.18 删除函数问题解决
modify:2022.3.19 写入输出问题解决
modify:2022.4.2添加功能
----------------------------------------------------------end--------------------------------------------------------------------------------------
*/

/*********************
function name:Gethashposition
create:2/27
description:哈希函数
input char *s
return unsigned int
**********************/
unsigned int GetHashPosition(char *s)
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
function name:InitHash
create:2/27
description:初始化哈希表
input int length
return ADMINASH *
**********************/
ADMINHASH *InitHash(int length)
{
    ADMINHASH *hh = NULL; //哈希表初始化

    if (length == 0)
    {
        printf("parameter wrong int function InitHash\n");
        return NULL;
    }

    if ((hh = (ADMINHASH *)malloc(sizeof(ADMINHASH))) == NULL) //为哈希表主体申请内存
    {
        printf("memoryallocation runs wrong in function InitHash");
        return NULL;
    }

    if ((hh->hashlist = (ADMINNODE **)malloc(length * sizeof(ADMINNODE *))) == NULL)
    {
        printf("memoryallocation runs wrong in function Inithash");
        free(hh);
        return NULL;
    } //申请指定长度的指针数组

    (void)memset(hh->hashlist, 0, length * sizeof(ADMINNODE *));

    hh->length = length;

    return hh;
}
/*********************
function name:HashSearch
create:2/27
description:搜索哈希节点
input:ADMINHASH *hash,char *name
return ADMINNODE *
**********************/
ADMINNODE *HashSearch(ADMINHASH *hash, char name[10])
{
    unsigned int position;

    ADMINNODE *hashnode = NULL; //暂存待比较信息的的节点

    if (hash == NULL || hash->hashlist == NULL)
    {
        printf("hash not initialize in hashsearch");
        return NULL;
    }

    position = GetHashPosition(name) % hash->length;

    hashnode = hash->hashlist[position];

    while (hashnode != NULL && hashnode->valid == 1) //遍历冲突链表
    {
        if (hashnode->valid == 1 && strcmp(hashnode->goods.name, name) == 0)
        {
            return hashnode; //返回结果
        }
        hashnode = hashnode->next; //指向下一个元素
    }

    return NULL;
}
/*********************
function name:Hashinsert
create:2/27
description:插入节点
input ADMINHASH *hash, ADMINOB *node
return int
**********************/
int Hashinsert(ADMINHASH *hash, ADMINOB *node)
{
    unsigned int position = 0;
    ADMINNODE *newhashNode = NULL;

    if (hash == NULL || node == NULL || hash->hashlist == NULL)
    {
        printf("hash not initialize in hashinsert");
        return 0;
    }

    if ((newhashNode = (ADMINNODE *)malloc(sizeof(ADMINNODE))) == NULL)
    {
        printf("memoryallocation runs wrong in function hashinsert");
        return 0;
    }

    memset(newhashNode, 0, sizeof(ADMINNODE));
    memcpy(&newhashNode->goods, node, sizeof(ADMINOB));
    newhashNode->valid = 1;
    newhashNode->next = NULL;

    position = GetHashPosition(newhashNode->goods.name) % hash->length;
    free(node);
    /*初始化newhashnode信息*/
    if (hash->hashlist[position] == NULL)
    {
        hash->hashlist[position] = newhashNode;
        return 1;
    } //未发生hash collision
    else
    {
        newhashNode->next = hash->hashlist[position]->next;
        hash->hashlist[position]->next = newhashNode;
        return 1;
    }
}

/*********************
function name:Hashdelete
create:2/27
description:删除指定节点的信息
input ADMINHASH *hash, ADMINOB *node
return bool
**********************/
int Hashdelete(ADMINHASH *hash, char name[10])
{
    unsigned int position = 0;
    ADMINNODE *deleteawait = NULL; //存储hashsearch函数找到的待删除节点
    ADMINNODE *tempnode = NULL;    //存储位于待删除节点上一个位置的节点

    if (hash == NULL)
    {
        printf("hash not initialize in hashdelete");
        return 0;
    }

    position = GetHashPosition(name) % hash->length; //找寻头节点
    deleteawait = HashSearch(hash, name);
    tempnode = hash->hashlist[position];

    if (deleteawait != NULL)
    {
        if (strcmp(tempnode->goods.name, name) == 0)
        {
            hash->hashlist[position] = deleteawait->next; //更换头节点
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
input ADMINHASH *hash
return int
**********************/
int nodecount(ADMINHASH *hash)
{
    int num;
    int i;
    ADMINNODE *hashnode;

    for (i = 0; i < hash->length; i++)
    {
        hashnode = hash->hashlist[i];
        while (hashnode != NULL)
        {
            num++;
            hashnode = hashnode->next;
        }
    }
    return num;
}
/*********************
function name:hashclean
create:4/1
description:清空哈希表
input ADMINHASH **phash
return void
**********************/
void hashclean(ADMINHASH **phash)
{
    int i;
    ADMINHASH *hash = NULL;
    ADMINNODE *hashnode = NULL;
    ADMINNODE *tempnode = NULL;

    if (phash == NULL)
    {
        printf("hash not initialize in cleanhash");
        return;
    }

    hash = *phash;
    if (hash->hashlist != NULL)
    {
        for (i = 0; i < hash->length; i++)
        {
            hashnode = hash->hashlist[i];
            while (hashnode != NULL && hashnode->valid == 1)
            {
                tempnode = hashnode;
                hashnode = hashnode->next;
                free(tempnode);
            }
            hash->hashlist[i] = NULL;
        }
    }
}
/*********************
function name:hashdestoy
create:2/27
description:删除哈希表
input ADMINHASH **phash
return void
**********************/
void hashdestroy(ADMINHASH **phash)
{
    int i;
    ADMINHASH *hash = NULL;
    ADMINNODE *hashnode = NULL;
    ADMINNODE *tempnode = NULL;

    if (phash == NULL)
    {
        printf("hash not initialize destroy hash");
        return;
    }

    hash = *phash;
    if (hash->hashlist != NULL)
    {
        for (i = 0; i < hash->length; i++)
        {
            hashnode = hash->hashlist[i];
            while (hashnode != NULL && hashnode->valid == 1)
            {
                tempnode = hashnode;
                hashnode = hashnode->next;
                free(tempnode);
            }
        }
        free(hash->hashlist);
    }
    free(hash);
    *phash = NULL;
}


/*************************
function:hashinput
description:将信息输入哈希表
create:2022/3/5
input:void
output:void
**************************/
void hashinput(ADMINHASH *hash)
{
    FILE *fp;
    int len;
    int i;
    ADMINOB *object;

    if (hash == NULL)
    {
        printf("hash not initialize in function hashinput");
        delay(3000);
    }

    if ((fp = fopen("C:\\code\\TEXT\\package.dat", "rb+")) == NULL)
    {
        printf("cannot open file in function hashinput");
        delay(3000);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(ADMINOB);

    for (i = 0; i < len; i++)
    {
        if ((object = (ADMINOB *)malloc(sizeof(ADMINOB))) == NULL)
        {
            printf("memoryallocation runs wrong in hashinput");
        }

        memset(object, 0, sizeof(ADMINOB));
        fseek(fp, i * sizeof(ADMINOB), SEEK_SET);
        fread(object, sizeof(ADMINOB), 1, fp);

        if (Hashinsert(hash, object) == 0)
        {
            printf("hashinput wrong");
            delay(3000);
        }

        free(object);
    }
    
    fclose(fp);
    delay(1);/*永远的神*/
}
/*************************
function:hashoutput
description:将哈希表信息写入文件
create:2022/3/12
input:ADMINHASH *hash
output:void
**************************/
void hashoutput(ADMINHASH *hash)
{
    FILE *fp;
    int i;
    ADMINNODE *hashnode;
    ADMINOB *deposit;

    if ((fp = fopen("C:\\code\\TEXT\\package.dat", "wb")) == NULL)
    {
        printf("cannot open file in function hashinput");
        delay(3000);
    }

    rewind(fp);

    for (i = 0; i < hash->length; i++)
    {
        hashnode = hash->hashlist[i];
        while (hashnode != NULL && hashnode->valid == 1)
        {
            deposit = &hashnode->goods;
            fwrite(deposit, sizeof(ADMINOB), 1, fp);
            hashnode = hashnode->next;
        }
    }

    fclose(fp);
}


void output(ADMINHASH *hash, int page, int *state)
{
    int j;     //输出哈希表内信息的行数
    int k = 0; //哈希位置
    ADMINNODE *hashnode;

    setcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);

    for (j = 0; j < (page - 1) * 8 && k < hash->length; k++)
    {
        hashnode = hash->hashlist[k];
        while (hashnode != NULL && hashnode->valid == 1)
        {
            hashnode = hashnode->next;
            j++;
        }
    } //按页数定位数据点，一页十二个

    for (j = 0; j < 8 && k < hash->length; k++)
    {
        while (hashnode != NULL && hashnode->valid == 1)
        {
            outtextxy(20, 100 + 30 * j, hashnode->goods.name);
            outtextxy(220, 100 + 30 * j, hashnode->goods.place);
            outtextxy(420, 100 + 30 * j, hashnode->goods.number);
            j++;
            hashnode = hashnode->next;
        } //输出下十二个数据点
        hashnode = hash->hashlist[k];
    }

    if (j == 8)
    {
        *state = 1;
    }
    else
    {
        *state = 0;
    } //根据该页是否输出满十二行更改翻页状态
}


