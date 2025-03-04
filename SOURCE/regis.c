#include"config.h"
#include"custom.h"

void regis_page(int *page)
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"C:\\borlandc\\bgi");
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
	setfillstyle(1,RED);
	bar(220, 330, 280, 360);
	bar(330, 330, 390, 360);
}

void regis_fun(int *page)
{
	char num1[20],num2[20];
	while(*page == 2)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if(MouseS!=0)
		{
			MouseS=0;
		}

		else if(mouse_press(230,150,430,175)==1)
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
		}

		else if(mouse_press(560,430,620,460)==1)
		{
			*page=0;
			break;
		}

		else if(mouse_press(220,330,280,360)==1)
		{
			num1[0]='\0';
			num2[0]='\0';
			break;
		}

		else if (mouse_press(330,330,390,360)==1)
		{
			data(num1, num2);
			*page=0;
			break;
		}

	}
 }
