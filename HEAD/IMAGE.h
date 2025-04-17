#ifndef _IMAGE_H_
#define _IMAGE_H_

int bmp_convert(char *bmp,char *dbm);	//�? *.bmp 变为 *.dbm,字�?�串bmp�?为bmp所在地址，字dbmp为输出地址
int show_dbm(int x,int y,char *dbm);	//输入dbmp的路�?,�?(x,y)输出图片(x需�?8的倍数)
void cir_bar(int x1,int y1,int x2,int y2,int color);	//在指定位�?画出一�?圆�?�矩形�?? 
void movetopage(int x1, int y1, int x2, int y2,int page1 ,int page2);
void set_color(int color_no,int red,int green,int blue); //指定颜色编号，修改其对应的rgb�? 

/*此为用汇编编写的�?持跨段�?�址的数�?传输函数，来�?《VGA页面图形数据移动技�?在特殊显示效果中的应用》一�?*/
int quick_move1(int Start,int End,int Size);	//Start为原处�?�地址，End为目标位�?首地址 
int quick_move2(int Start,int End,int Size);	//Start为原处�?�地址，End为目标位�?首地址 
 
void close_display(void);		//关闭屏幕显示
void open_display(void);		//打开屏幕显示
 
#endif
