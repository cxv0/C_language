#ifndef _expressage_h_
#define _expressage_h_


typedef struct adminobject
{
	char name[25];
    char place[25];
    char number[10];
} ADMINOB; //����Ա��Ʒ��Ϣ�ṹ��

typedef struct ADMINhustNode
{
	struct ADMINhustNode *next;
	ADMINOB goods;
	int valid;
} ADMINNODE; //����Ա��ϣ�ڵ�ṹ��

typedef struct ADMINhust
{
	ADMINNODE **hustlist;
	int length;
} ADMINHUST; //����Ա��ϣ������ṹ��


void draw_expage(void);
int expagefunc(ADMINHUST *hust);
void delstuff(ADMINHUST *hust);
void inredraw(int page, ADMINHUST *hust, int *state);
void addstuff(ADMINHUST *hust);

#endif