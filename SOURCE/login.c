#include"config.h"
#include"custom.h"

int Judge_Login(char* a, char* p)
{
	int l;
	int i;
	FILE* fp;
	user* temp = NULL;
	if ((fp = fopen("C:\\code\\TEXT\\user.dat", "rb+")) == NULL)
	{
		printf("\nError on open file user.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	l = ftell(fp) / sizeof(user);
	for (i = 0; i < l; i++)
	{
		if ((temp = (user*)malloc(sizeof(user))) == NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(user), SEEK_SET);
		fread(temp, sizeof(user), 1, fp);
		if (strcmp(a, temp->account) == 0)
		{
			if (strcmp(p, temp->password) != 0)
			{
				printf("√‹¬Î¥ÌŒÛ£°");
				break;
			}
			else if (strcmp(p, temp->password) == 0)
			{
				printf("√‹¬Î’˝»∑£°");
				if (temp != NULL)
				{
					free(temp);
					temp = NULL;
				}
				if (fclose(fp) != 0)
				{
					printf("\nError on close user.dat!");
					delay(3000);
					exit(1);
				}
				return 1;
			}
		}
	}
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close user.dat!");
		delay(3000);
		exit(1);
	}
	return 0;
}


void login_fun(int *page)
{
	char num1[20],num2[20];
	while(*page == 1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if(MouseS!=0)
		{
			MouseS=0;
		}

		else if(mouse_press(230,150,430,174)==1)
		{
			Input_Vis(num1,230,150,8,LIGHTGRAY);
		}

  		else if(mouse_press(230,250,430,274)==1)
  		{
			Input_Invis(num2,230,250,8,LIGHTGRAY);
		}

		else if(mouse_press(560,430,620,460)==2)
		{
			MouseS=1;
		}

		else if(mouse_press(560,430,620,460)==1)
		{
			*page=0;
			break;
		}

		else if(mouse_press(220, 330, 280, 360) == 1)
		{
			num1[0] = '\0';
			num2[0] = '\0';
			break;
		}

		else if(mouse_press(330, 330, 390, 360) == 1)
		{
			if (Judge_Login(num1,num2))
			{
				setfillstyle(1, WHITE);
				bar(270, 225, 370, 255);
				delay(3000);                                     
				break;
			}
			else
			{
				setfillstyle(1, DARKGRAY);
				bar(270, 225, 370, 255);
				delay(3000);
				return;
			}
		}

	}
 }

 void login_page(int *page)
 {
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"C:\\borlandc\\bgi");
	clrmous(MouseX,MouseY);
	cleardevice();
	setbkcolor(BLUE);
	setfillstyle(1,LIGHTGRAY);
	bar(230,150,430,174);
	bar(230,250,430,274);
	bar(560,430,620,460);
	setfillstyle(1,GREEN);
	bar(150,150,210,174);
	bar(150,250,210,274);
	setfillstyle(1, RED);
	bar(220, 330, 280, 360);
	bar(330, 330, 390, 360);
 }
	

