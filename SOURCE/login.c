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
				break;
			}
			else if (strcmp(p, temp->password) == 0)
			{
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


void login_fun(int *page,int *num)
{
	char num1[20],num2[20];
	while(1)
	{
		if(*page==1)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			login_page();

			while(*page==1)
			{
				newmouse(&MouseX,&MouseY,&press);
				if(mouse_press(230,150,430,174)==1)
				{
					MouseS=0;
					num1[0]='\0';
					setfillstyle(1,LIGHTGRAY);
					bar(230,150,430,174);
					Input_Vis(num1,230,150,8,LIGHTGRAY);
				}
		
				else if(mouse_press(230,250,430,274)==1)
				{
					num2[0]='\0';
					setfillstyle(1,LIGHTGRAY);
					bar(230,250,430,274);
					Input_Invis(num2,230,250,8,LIGHTGRAY);
				}

				else if(mouse_press(560,430,620,460)==2)
				{
					MouseS=1;
					if(*num == 0)
                    {
                        *num = 3;
                        hlbutton(page, num);
                    }
					continue;
				}
		
				else if(mouse_press(560,430,620,460)==1)
				{
                    *num = 3;
                    *page = 0;
                    break;
				}

				else if(mouse_press(220, 330, 280, 360) == 2)
				{
					MouseS=1;
					if(*num == 0)
                    {
                        *num = 1;
                        *page = 1;
                        hlbutton(page, num);
                    }
					continue;
				}
		
				else if(mouse_press(220, 330, 280, 360) == 1)
				{
					num1[0] = '\0';
					num2[0] = '\0';
                    *num = 1;
                    *page = 1;
                    break;
				}

				else if(mouse_press(330, 330, 390, 360) == 2)
				{
					MouseS=1;
					if(*num == 0)
                    {
                        *num = 2;
                        *page = 1;
                        hlbutton(page, num);
                    }
					continue;
				}
		
				else if(mouse_press(330, 330, 390, 360) == 1)
				{
					*num = 2;
                    *page = 1;
					if (Judge_Login(num1,num2))
					{
						setfillstyle(1, WHITE);
						bar(270, 225, 410, 255);
						puthz(270,225,"µÇÂ¼³É¹¦",32,36,GREEN);
						create_user_info(*num1);
						delay(1000); 
						*page=3;                                    
						break;
					}
					else
					{
						setfillstyle(1, DARKGRAY);
						bar(270, 225, 410, 255);
						puthz(270,225,"ÃÜÂë´íÎó",32,36,GREEN);
						delay(1000);
						break;
					}
				}
		
				else
				{
					MouseS = 0;
                    if(*num != 0)
                    {
                        repaint(page, num);
                        *num = 0;
                    }
                    continue;
				}
			}
		}

		else if(*page==0)
		{
			clrmous(MouseX, MouseY);
            cleardevice();
			initmenu(page,num);
            break;
		}

		else if(*page == 3)  //ï¿½Ú¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò³
        {   
			clrmous(MouseX, MouseY);
			cleardevice();
			homefunc(page,num);
            break;
        }

	}
 }

 void login_page()
 {
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
	setfillstyle(1, LIGHTGRAY);
	bar(220, 330, 280, 360);
	bar(330, 330, 390, 360);
	puthz(150,150,"ÕËºÅ",24,28,RED);
	puthz(150,250,"ÃÜÂë",24,28,RED);
	puthz(220,330,"ÖØÖÃ",24,28,WHITE);
	puthz(330,330,"Íê³É",24,28,WHITE);
	puthz(560,430,"·µ»Ø",24,28,WHITE);
 }

 
	

