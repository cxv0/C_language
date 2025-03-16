#include"config.h"
#include"custom.h"

void regis_page()
{
	clrmous(MouseX,MouseY);
	cleardevice();
	setbkcolor(BLUE);
	setfillstyle(1,LIGHTGRAY);
	bar(230,150,430,175);
	bar(230,250,430,275);
	bar(560,430,620,460);
	setfillstyle(1,GREEN);
	bar(150,150,210,175);
	bar(150,250,210,275);
	setfillstyle(1,LIGHTGRAY);
	bar(220, 330, 280, 360);
	bar(330, 330, 390, 360);
	puthz(150,150,"账号",24,28,RED);
	puthz(150,250,"密码",24,28,RED);
	puthz(220,330,"重置",24,28,WHITE);
	puthz(330,330,"完成",24,28,WHITE);
	puthz(560,430,"返回",24,28,WHITE);
}

void regis_fun(int *page,int *num)
{
	char num1[20],num2[20];
	while(1)
	{
		if(*page==2)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			regis_page();

			while(*page==2)
			{
				newmouse(&MouseX,&MouseY,&press);
	

				if(mouse_press(230,150,430,175)==1)
				{
					Input_Vis(num1,230,150,8,LIGHTGRAY);
				}
			
				else if(mouse_press(230,250,430,275)==1)
				{
					Input_Vis(num2,230,250,8,LIGHTGRAY);
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
					*num=3;
					*page=0;
					break;
				}

				else if(mouse_press(220,330,280,360)==2)
				{
					MouseS=1;
					if(*num == 0)
                    {
                        *num = 1;
						*page = 2;
                        hlbutton(page, num);
                    }
					continue;
				}
			
				else if(mouse_press(220,330,280,360)==1)
				{
					num1[0]='\0';
					num2[0]='\0';
					*num = 1;
					*page = 2;
					break;
				}

				else if(mouse_press(330,330,390,360)==2)
				{
					MouseS=1;
					if(*num == 0)
                    {
                        *num = 2;
                        hlbutton(page, num);
                    }
					continue;
				}
			
				else if (mouse_press(330,330,390,360)==1)
				{
					data(num1, num2);
					*num=2;
					*page=0;
					break;
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
		
	}
}
