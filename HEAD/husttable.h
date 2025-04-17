#ifndef _husttable_h_
#define _husttable_h_

#include "expressage.h"


unsigned int GetHustPosition(char *s);
ADMINHUST *InitHust(int length);
ADMINNODE *HustSearch(ADMINHUST *hust, char name[10]);
int Hustinsert(ADMINHUST *hust, ADMINOB *node);
int Hustdelete(ADMINHUST *hust, char name[10]);
void hustclean(ADMINHUST **phust);
void hustdestroy(ADMINHUST **phust);
void hustinput(ADMINHUST *hust);
void hustoutput(ADMINHUST *hust);
void output(ADMINHUST *hust, int page, int *state);


#endif

