#ifndef _database_h_
#define _database_h_
#include <stdio.h> //����Ӹ�ͷ�ļ��ᵼ���޷�ʶ��FILE *fp

void database(void);
void save_to_database(FILE *fp, info *ip);
void init_infogroup(FILE *fp);

#endif