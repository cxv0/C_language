#ifndef _database_h_
#define _database_h_
#include <stdio.h> //不添加该头文件会导致无法识别FILE *fp

void database(void);
void save_to_database(FILE *fp, info *ip);
void init_infogroup(FILE *fp);

#endif