#include "config.h"
#include "husttable.h"





/*-------------------------------------------------------README---------------------------------------------------------------
���ļ�����Ϊ��ϣ������������ϣ������Ⱥ���
functionlist:  gethustposition ��ϣ������ȡ�ýڵ��λ��
               inithust         ��ʼ��һ�����ȵĹ�ϣ��
               hustsearch       ����ָ���Ĺ�ϣ�ڵ�
               hustinsert       �����ϣ�ڵ�
               hustdelete       ɾ����ϣ�ڵ�
             destroyhust      �ݻٹ�ϣ���ͷ��ڴ�
               hustinput        ���ļ�����Ϣ�����ϣ��
             hustoutput       ���ı�ֵ��Ĺ�ϣ��д���ļ�
             nodecount        ���ڵ���Ŀ
             hustclean        ��չ�ϣ������
             commentinput     ����������Ϣ
             stateinfoinput   ���Ľڵ�������Ϣ
structerlist:ADMINOB          �洢��Ʒ��Ϣ�Ľṹ��
             ADMINNODE        �����������ϣ��ײ�Ĺ�ϣ�ڵ�
             ADMINHUST        ��ϣ������
�������̣�
��ʼ��
    �ڳ���ʼʱ��inithust��ʼ����ϣ���ٴ�supeinfo�л�ȡһ����Ʒ����Ϣ�洢��ADMINOB�ṹ���У�
    ֮��gethustposition��������Ʒ��������õ���ֵ����ģ�����ʼ����ϣ��ĳ��ȵõ��ı��������Ʒ�ĵ�ַ��
    ͨ���洢����Ʒ��Ϣ��adminob����Hustnode�ṹ�壬���ýṹ��д���ϣ���ж�Ӧ��ַ�������ô��ѱ�ռ��������������������adminnode
�����Աҳ�������Ľ���
    �������ϼ�ͨ��hustsearch�ҵ���Ӧ�Ľڵ��޸Ĳ���
    ��ӻ���ͨ�������ϣ�ڵ�
    ɾ������ͨ��ɾ����ϣ�ڵ�
���û�ҳ��Ľ���
    �û��ڳ����е�ʱ����ɹ������乺�����������������Ŀ����������������ͨ����������hustsearch�ҵ��ڵ���޸Ĳ�������
��Ϣ�洢
    ÿ�θı��ϣ���ڲ������������ļ���������supeinfo�����Ϣ
----------------------------------------------------------end--------------------------------------------------------------------------------------
*/

/*********************
function name:Gethustposition
create:2/27
description:��ϣ����
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
} //��ϣ����
/*********************
function name:InitHust
create:2/27
description:��ʼ����ϣ��
input int length
return ADMINASH *
**********************/
ADMINHUST *InitHust(int length)
{
    ADMINHUST *hh = NULL; //��ϣ���ʼ��

    if (length == 0)
    {
        printf("parameter wrong int function InitHust\n");
        return NULL;
    }

    if ((hh = (ADMINHUST *)malloc(sizeof(ADMINHUST))) == NULL) //Ϊ��ϣ�����������ڴ�
    {
        printf("memoryallocation runs wrong in function InitHust");
        return NULL;
    }

    if ((hh->hustlist = (ADMINNODE **)malloc(length * sizeof(ADMINNODE *))) == NULL)
    {
        printf("memoryallocation runs wrong in function Inithust");
        free(hh);
        return NULL;
    } //����ָ�����ȵ�ָ������

    (void)memset(hh->hustlist, 0, length * sizeof(ADMINNODE *));

    hh->length = length;

    return hh;
}
/*********************
function name:HustSearch
create:2/27
description:������ϣ�ڵ�
input:ADMINHUST *hust,char *name
return ADMINNODE *
**********************/
ADMINNODE *HustSearch(ADMINHUST *hust, char name[10])
{
    unsigned int position;

    ADMINNODE *hustnode = NULL; //�ݴ���Ƚ���Ϣ�ĵĽڵ�

    if (hust == NULL || hust->hustlist == NULL)
    {
        printf("hust not initialize in hustsearch");
        return NULL;
    }

    position = GetHustPosition(name) % hust->length;

    hustnode = hust->hustlist[position];

    while (hustnode != NULL && hustnode->valid == 1) //������ͻ����
    {
        if (hustnode->valid == 1 && strcmp(hustnode->goods.name, name) == 0)
        {
            return hustnode; //���ؽ��
        }
        hustnode = hustnode->next; //ָ����һ��Ԫ��
    }

    return NULL;
}
/*********************
function name:Hustinsert
create:2/27
description:����ڵ�
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
    /*��ʼ��newhustnode��Ϣ*/
    if (hust->hustlist[position] == NULL)
    {
        hust->hustlist[position] = newhustNode;
        return 1;
    } //δ����hust collision
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
description:ɾ��ָ���ڵ����Ϣ
input ADMINHUST *hust, ADMINOB *node
return bool
**********************/
int Hustdelete(ADMINHUST *hust, char name[10])
{
    unsigned int position = 0;
    ADMINNODE *deleteawait = NULL; //�洢hustsearch�����ҵ��Ĵ�ɾ���ڵ�
    ADMINNODE *tempnode = NULL;    //�洢λ�ڴ�ɾ���ڵ���һ��λ�õĽڵ�

    if (hust == NULL)
    {
        printf("hust not initialize in hustdelete");
        return 0;
    }

    position = GetHustPosition(name) % hust->length; //��Ѱͷ�ڵ�
    deleteawait = HustSearch(hust, name);
    tempnode = hust->hustlist[position];

    if (deleteawait != NULL)
    {
        if (strcmp(tempnode->goods.name, name) == 0)
        {
            hust->hustlist[position] = deleteawait->next; //����ͷ�ڵ�
            free(deleteawait);                            //ɾ���ýڵ�
            return 1;
        } //��ɾ���ڵ�Ϊͷ�ڵ�ʱ
        else
        {
            while (tempnode != NULL)
            {
                if (strcmp(tempnode->next->goods.name, name) == 0)
                {
                    tempnode->next = deleteawait->next; //���Ӵ�ɾ���ڵ�ǰ�������ڵ�
                    free(deleteawait);
                    return 1;
                }
                tempnode = tempnode->next; //�����ǽڵ���һ����ΪĿ��ڵ㣬����������һ���ڵ���Ѱ
            }
        }
    }
    return 0;
}
/*********************
function name:nodecount
create:4/5
description:����ڵ����
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
description:��չ�ϣ��
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
description:ɾ����ϣ��
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
description:����Ϣ�����ϣ��
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
    delay(1);/*��Զ����*/
}
/*************************
function:husthoutput
description:����ϣ����Ϣд���ļ�
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
    int j;     //�����ϣ������Ϣ������
    int k = 0; //��ϣλ��
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
    } //��ҳ����λ���ݵ㣬һҳ�˸�

    for (j = 0; j < 8 && k < hust->length; k++)
    {
        while (hustnode != NULL && hustnode->valid == 1)
        {
            outtextxy(20, 100 + 30 * j, hustnode->goods.name);
            outtextxy(220, 100 + 30 * j, hustnode->goods.place);
            outtextxy(420, 100 + 30 * j, hustnode->goods.number);
            j++;
            hustnode = hustnode->next;
        } //����°˸����ݵ�
        hustnode = hust->hustlist[k];
    }

    if (j == 8)
    {
        *state = 1;
    }
    else
    {
        *state = 0;
    } //���ݸ�ҳ�Ƿ���������и��ķ�ҳ״̬
}


