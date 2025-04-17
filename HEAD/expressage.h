#ifndef _expressage_h_
#define _expressage_h_


typedef struct adminobject
{
	char name[25];
    char place[25];
    char number[10];
} ADMINOB; //管理员物品信息结构体

typedef struct ADMINhustNode
{
	struct ADMINhustNode *next;
	ADMINOB goods;
	int valid;
} ADMINNODE; //管理员哈希节点结构体

typedef struct ADMINhust
{
	ADMINNODE **hustlist;
	int length;
} ADMINHUST; //管理员哈希表主体结构体


void draw_expage(void);
int expagefunc(ADMINHUST *hust);
void delstuff(ADMINHUST *hust);
void inredraw(int page, ADMINHUST *hust, int *state);
void addstuff(ADMINHUST *hust);

#endif