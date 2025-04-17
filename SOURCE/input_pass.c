#include"config.h"
#include"input_pass.h"

int Input_Vis(char *ip,int x,int y,int lim,int color) //输入内容，输入框左上角坐标x,y，字数限制，输入框颜�?
{                                                      //注意：该输入函数要求输入框宽度为25
	int i=0;
	int j=0;                                           //记录输入�?
	char c;                                            //读取键盘输入的内�?
	clrmous(MouseX, MouseY);
	setcolor(WHITE);                                   //设置显示字体为白�?
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);             //设置线型
	setfillstyle(SOLID_FILL,color);                    //保持填充颜色与输入框颜色一�?
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	line(x+10,y+6,x+10,y+20);                          //画输入提示光标（在给定坐标向�?10个像素点，画一条长14个像素点的竖�?
 	while(bioskey(1))
	{
		i=bioskey(0);
	}
	while(1)
	{
	    c=bioskey(0);                                  //读取键盘输入内容
		if(j<lim)
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)       //如果读入非换行、回车、空格或退�?
			{
				if(c!='\b')                            //如果读入非退�?
				{
					if((c>='0'&&c<='9')||(c>='a'&&c<='z'))
				  	{
					  	*(ip+j)=c;                         //将读入的c存入输入内容字符串ip
						*(ip+j+1)='\0';                    //结束字符串ip
						bar(x+8+j*18,y+3,x+12+j*18,y+24);  //清除光标（注意在原光标坐标上加上已经输入的内容）
						outtextxy(x+8+j*18,y-1,ip+j);      //在输入框中显示输入的字符（在其实光标右侧j*18处画字符�?
						j++;                               //输入数加一
						line(x+10+j*18,y+6,x+10+j*18,y+20);//在新输入的字符后重画光标
				  	}
				  	else
				  	{
						return  100;
				  	}
				}
				else if(c=='\b'&&j>0)                 //如果读入退�?
				{
					bar(x-10+j*18,y+3,x+7+j*18,y+24);  //清除上一输入字符
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //清除光标
					j--;                               //输入数减一
					line(x+10+j*18,y+6,x+10+j*18,y+20);//在上一输入的字符后重画光标
					*(ip+j)='\0';                      //清除字符串ip读入的上一字符
					*(ip+j+1)='\0';                    //结束字符串ip
				}
			}
			else                                       //如果读入换行、回车、空格或退�?
			{
				setfillstyle(SOLID_FILL, color);       //结束当前输入操作
				bar(x+8+j*18,y+3,x+12+j*18,y+24);      //清除光标
				break;
			}
		}
		else if(j>=lim)                               //如果达到输入限制
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)      //其余功能不变
			{                                         //读入除换行、回车、空格、退出或退格以外字符不再存储与显示
				if(c=='\b'&&j>0)
				{
					bar(x+8+j*18,y+3,x+12+j*18,y+24);
					bar(x-10+j*18,y+3,x+7+j*18,y+24);
					j--;
					line(x+10+j*18,y+6,x+10+j*18,y+20);
					*(ip+j)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x+8+j*18,y+3,x+12+j*18,y+24);
				break;
			}
		}
	}
	return 200;
}
int Input_Invis(char* ip,int x,int y,int lim,int color)//大体与Input_Vis函数相同，仅对显示的字符做不可视处理
{
	
	int i=0;
	int j=0;                                           //记录输入�?
	char c;                                            //读取键盘输入的内�?
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL,color);                    //设置填充形式
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);             //设置线型
	setcolor(WHITE);                                   //设置输出形式
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	line(x+10,y+6, x+10,y+20);                         //画输入提示光�?
	while(bioskey(1))
	{
		i=bioskey(0);
	}
	while(1)
	{
	    c=bioskey(0);                                  //读取键盘输入内容
		if(j<lim)
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)      //如果读入非换行、回车、空格或退�?
			{
				if(c!='\b')                           //如果读入非退�?
				{
					if((c>='0'&&c<='9')||(c>='a'&&c<='z'))
				  	{
				  		*(ip+j) =c;                        //将读入的c存入输入内容字符串ip
						*(ip+j+1) = '\0';                  //结束字符串ip
						bar(x+8+j*18,y+3,x+12+j*18,y+24);  //清除光标
						outtextxy(x+8+j*18,y+4,"*");       //在输入框中显示字符�?*�?
						j++;                               //输入数加一
						line(x+10+j*18,y+6,x+10+j*18,y+20);//重画光标
				 	}
					  else
			        {
				       return 100;
			        }
				}
				else if (c=='\b'&&j>0)                 //如果读入退�?
				{
					bar(x-10+j*18,y+3,x+7+j*18,y+24);  //清除上一输入字符
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //清除光标
					j--;                               //输入数减一
					line(x+10+j*18,y+6,x+10+j*18,y+20);//重画
					*(ip+j)='\0';                      //清除字符串ip读入的上一字符
					*(ip+j+1)='\0';                    //结束字符串ip
				}
			}
			else                                       //如果读入换行、回车、空格或退�?
			{
				setfillstyle(SOLID_FILL, color);       //结束当前输入操作
				bar(x+8+j*18,y+3,x+12+j*18,y+24);      //清除光标
				break;
			}
		}
		else if(j>=lim)                               //如果达到输入限制
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)      //其余功能不变
			{                                         //读入除换行、回车、空格、退出或退格以外字符不再存储与显示
				if (c=='\b'&&j>0)
				{
					bar(x+8+j*18,y+3,x+12+j*18,y+24);
					bar(x-10+j*18,y+3,x+7+j*18,y+24);
					j--;
					line(x+10+j*18,y+6,x+10+j*18,y+20);
					*(ip+j)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x+8+j*18,y+3,x+12+j*18,y+24);
				break;
			}
		}
	}
	return 200;
}