#include"config.h"
#include"data.h"
#include"regis.h"
#include"input_pass.h"

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

int regis_fun()
{
	char num1[20],num2[20];
	int num=0;
	clrmous(MouseX,MouseY);
	cleardevice();
	regis_page();
	while(1)
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
			MouseS=0;
			num2[0]='\0';
			setfillstyle(1,LIGHTGRAY);
			bar(230,250,430,274);
			Input_Invis(num2,230,250,8,LIGHTGRAY);
		}

		else if(mouse_press(560,430,620,460)==2)
		{
			
			if(num == 0)
			{
				MouseS=1;
				num = 3;
			}
			continue;
		}

		else if(mouse_press(560,430,620,460)==1)
		{
			MouseS=0;
			return 0;
		}

		else if(mouse_press(220, 330, 280, 360) == 2)
		{
			
			if(num == 0)
			{
				MouseS=1;
				num = 1;

			}
			continue;
		}

		else if(mouse_press(220, 330, 280, 360) == 1)
		{
			num1[0] = '\0';
			num2[0] = '\0';
			MouseS=0;
			setfillstyle(1,LIGHTGRAY);
			bar(230,150,430,174);
			bar(230,250,430,274);
			continue;
		}

		else if(mouse_press(330,330,390,360)==2)
		{
			
			if(num == 0)
			{
				MouseS=1;
				num = 2;
			}
			continue;
		}
	
		else if (mouse_press(330,330,390,360)==1)
		{
			data(num1, num2);
			delay(1000);
			return 0;
		}
	
		else
		{
			
			if(num != 0)
			{
				MouseS=0;
				num = 0;
			}
			continue;
		}
	}
}
