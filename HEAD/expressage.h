#ifndef _expressage_h_
#define _expressage_h_


typedef struct srecord
{
	char name[25];
	char price[5];
	char number[3];
} REC;

typedef struct commodity
{
	char name[25];
	char stor[3];
	char price[5];
	char endyear[5];
	char endmonth[3];
	char endday[3];

	// char number[3];
} COM; //�û���Ʒ������Ϣ�ṹ��

typedef struct comments
{
	char name[25];
	char level[4];
} COMMENT; //������Ϣ�ṹ��

typedef struct adminobject
{
	char name[25];
    char place[25];
    char number[10];
} ADMINOB; //����Ա��Ʒ��Ϣ�ṹ��

typedef struct ADMINhashNode
{
	struct ADMINhashNode *next;
	ADMINOB goods;
	int valid;
} ADMINNODE; //����Ա��ϣ�ڵ�ṹ��

typedef struct ADMINhash
{
	ADMINNODE **hashlist;
	int length;
} ADMINHASH; //����Ա��ϣ������ṹ��


void draw_expage(void);
int expagefunc(ADMINHASH *hash);
void delstuff(ADMINHASH *hash);
void inredraw(int page, ADMINHASH *hash, int *state);
void addstuff(ADMINHASH *hash);

#endif