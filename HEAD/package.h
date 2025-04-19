#ifndef _package_h_
#define _package_h_

typedef struct pack
{
	char name[25];
    char place[25];
    char number[10];
} PACKAGE; //快递信息结构体

int addpackage(void);
int delpackage(void);
int delete_package_by_name(char *filename, char *target_name);
int output_package(void);
int count_package(void); 

#endif