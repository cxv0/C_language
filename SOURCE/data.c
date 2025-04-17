#include"config.h"
#include"custom.h"

void data(char* num1, char* num2)           //将新注册的用户信息写入文�?
{
	FILE  *fp;
	user *u;
	int l;
	if ((fp = fopen("C:\\code\\TEXT\\user.dat", "rb+")) == NULL) //打开存储用户信息的文�?
	{
		printf("\nError on open file user.dat!");
		delay(3000);
		exit(1);
	}
	if ((u = (user*)malloc(sizeof(user))) == NULL)                      //分配空间
	{
		printf("\nMemory not enough!");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	l = ftell(fp) / sizeof(user);    //计算用户总数
	u->num = l + 1;
	strcpy(u->account, num1);
	strcpy(u->password, num2);
	fseek(fp, 0, SEEK_END);                                          //文件指针移动至文件最�?
	fwrite(u, sizeof(user), 1, fp);                                   //把新用户信息写入文件最�?
	if (u != NULL)                                                 //释放u
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)                                             //关闭文件
	{
		printf("\nError on close user.dat!");
		delay(3000);
		exit(1);
	}
}