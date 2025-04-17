#include "config.h"
#include "custom.h"





/*-------------------------------------------------------README---------------------------------------------------------------
���ļ�����Ϊ��ϣ������������ϣ������Ⱥ���
functionlist:gethashposition ��ϣ������ȡ�ýڵ��λ��
             inithash         ��ʼ��һ�����ȵĹ�ϣ��
             hashsearch       ����ָ���Ĺ�ϣ�ڵ�
             hashinsert       �����ϣ�ڵ�
             hashdelete       ɾ����ϣ�ڵ�
             destroyhash      �ݻٹ�ϣ���ͷ��ڴ�
             hashinput        ���ļ�����Ϣ�����ϣ��
             hashoutput       ���ı�ֵ��Ĺ�ϣ��д���ļ�
             nodecount        ���ڵ���Ŀ
             hashclean        ��չ�ϣ������
             commentinput     ����������Ϣ
             stateinfoinput   ���Ľڵ�������Ϣ
structerlist:ADMINOB          �洢��Ʒ��Ϣ�Ľṹ��
             ADMINNODE        �����������ϣ��ײ�Ĺ�ϣ�ڵ�
             ADMINHASH        ��ϣ������
�������̣�
��ʼ��
    �ڳ���ʼʱ��inithash��ʼ����ϣ���ٴ�supeinfo�л�ȡһ����Ʒ����Ϣ�洢��ADMINOB�ṹ���У�
    ֮��gethashposition��������Ʒ��������õ���ֵ����ģ�����ʼ����ϣ��ĳ��ȵõ��ı��������Ʒ�ĵ�ַ��
    ͨ���洢����Ʒ��Ϣ��adminob����Hashnode�ṹ�壬���ýṹ��д���ϣ���ж�Ӧ��ַ�������ô��ѱ�ռ��������������������adminnode
�����Աҳ�������Ľ���
    �������ϼ�ͨ��hashsearch�ҵ���Ӧ�Ľڵ��޸Ĳ���
    ��ӻ���ͨ�������ϣ�ڵ�
    ɾ������ͨ��ɾ����ϣ�ڵ�
���û�ҳ��Ľ���
    �û��ڳ����е�ʱ����ɹ������乺�����������������Ŀ����������������ͨ����������hashsearch�ҵ��ڵ���޸Ĳ�������
��Ϣ�洢
    ÿ�θı��ϣ���ڲ������������ļ���������supeinfo�����Ϣ
pushuchen 2022.2.27
finish:2022.3.5 �Ⱳ�Ӳ���Ը�ڴ��ϣ��
modify:2022.3.8 �޸���ͨ�������ַ�����ȡλ�õĺ���
modify:2022.3.12 ��ϣ����������������
                 11��42�ۼ�����ʼ������ϣɾ�������޷�����
modify:2022.3.16 ���������������ɾ����������û�����д�뺯���������⣬��ϣ��ײ���
modify:2022.3.18 ɾ������������
modify:2022.3.19 д�����������
modify:2022.4.2��ӹ���
----------------------------------------------------------end--------------------------------------------------------------------------------------
*/

/*********************
function name:Gethashposition
create:2/27
description:��ϣ����
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
} //��ϣ����
/*********************
function name:InitHash
create:2/27
description:��ʼ����ϣ��
input int length
return ADMINASH *
**********************/
ADMINHASH *InitHash(int length)
{
    ADMINHASH *hh = NULL; //��ϣ���ʼ��

    if (length == 0)
    {
        printf("parameter wrong int function InitHash\n");
        return NULL;
    }

    if ((hh = (ADMINHASH *)malloc(sizeof(ADMINHASH))) == NULL) //Ϊ��ϣ�����������ڴ�
    {
        printf("memoryallocation runs wrong in function InitHash");
        return NULL;
    }

    if ((hh->hashlist = (ADMINNODE **)malloc(length * sizeof(ADMINNODE *))) == NULL)
    {
        printf("memoryallocation runs wrong in function Inithash");
        free(hh);
        return NULL;
    } //����ָ�����ȵ�ָ������

    (void)memset(hh->hashlist, 0, length * sizeof(ADMINNODE *));

    hh->length = length;

    return hh;
}
/*********************
function name:HashSearch
create:2/27
description:������ϣ�ڵ�
input:ADMINHASH *hash,char *name
return ADMINNODE *
**********************/
ADMINNODE *HashSearch(ADMINHASH *hash, char name[10])
{
    unsigned int position;

    ADMINNODE *hashnode = NULL; //�ݴ���Ƚ���Ϣ�ĵĽڵ�

    if (hash == NULL || hash->hashlist == NULL)
    {
        printf("hash not initialize in hashsearch");
        return NULL;
    }

    position = GetHashPosition(name) % hash->length;

    hashnode = hash->hashlist[position];

    while (hashnode != NULL && hashnode->valid == 1) //������ͻ����
    {
        if (hashnode->valid == 1 && strcmp(hashnode->goods.name, name) == 0)
        {
            return hashnode; //���ؽ��
        }
        hashnode = hashnode->next; //ָ����һ��Ԫ��
    }

    return NULL;
}
/*********************
function name:Hashinsert
create:2/27
description:����ڵ�
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
    /*��ʼ��newhashnode��Ϣ*/
    if (hash->hashlist[position] == NULL)
    {
        hash->hashlist[position] = newhashNode;
        return 1;
    } //δ����hash collision
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
description:ɾ��ָ���ڵ����Ϣ
input ADMINHASH *hash, ADMINOB *node
return bool
**********************/
int Hashdelete(ADMINHASH *hash, char name[10])
{
    unsigned int position = 0;
    ADMINNODE *deleteawait = NULL; //�洢hashsearch�����ҵ��Ĵ�ɾ���ڵ�
    ADMINNODE *tempnode = NULL;    //�洢λ�ڴ�ɾ���ڵ���һ��λ�õĽڵ�

    if (hash == NULL)
    {
        printf("hash not initialize in hashdelete");
        return 0;
    }

    position = GetHashPosition(name) % hash->length; //��Ѱͷ�ڵ�
    deleteawait = HashSearch(hash, name);
    tempnode = hash->hashlist[position];

    if (deleteawait != NULL)
    {
        if (strcmp(tempnode->goods.name, name) == 0)
        {
            hash->hashlist[position] = deleteawait->next; //����ͷ�ڵ�
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
description:��չ�ϣ��
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
description:ɾ����ϣ��
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
description:����Ϣ�����ϣ��
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
    delay(1);/*��Զ����*/
}
/*************************
function:hashoutput
description:����ϣ����Ϣд���ļ�
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
    int j;     //�����ϣ������Ϣ������
    int k = 0; //��ϣλ��
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
    } //��ҳ����λ���ݵ㣬һҳʮ����

    for (j = 0; j < 8 && k < hash->length; k++)
    {
        while (hashnode != NULL && hashnode->valid == 1)
        {
            outtextxy(20, 100 + 30 * j, hashnode->goods.name);
            outtextxy(220, 100 + 30 * j, hashnode->goods.place);
            outtextxy(420, 100 + 30 * j, hashnode->goods.number);
            j++;
            hashnode = hashnode->next;
        } //�����ʮ�������ݵ�
        hashnode = hash->hashlist[k];
    }

    if (j == 8)
    {
        *state = 1;
    }
    else
    {
        *state = 0;
    } //���ݸ�ҳ�Ƿ������ʮ���и��ķ�ҳ״̬
}


