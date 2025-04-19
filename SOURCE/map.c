#include "config.h"
#include "map.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Map and map tracking function //»æÖÆµØÍ¼ÓëÂ·¾¶×·×Ù
DATE:       2025/4/18
******/

void draw_map()
{
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    bar(0, 0, 640, 480); //»æÖÆµØÍ¼
    moveto(70, 0); //×ó±ßÔµ
    lineto(70, 120);
    lineto(0, 120);
    lineto(0, 150);
    lineto(70, 150);
    lineto(70, 390);
    lineto(0, 390);
    lineto(0, 420);
    lineto(70, 420);
    lineto(70, 480);
    moveto(100, 0); //ÉÏ±ßÔµ
    lineto(100, 20);
    lineto(640, 20);
    moveto(100, 480); //ÏÂ±ßÔµ
    lineto(100, 420);
    lineto(640, 420);
    moveto(640, 50); //ÓÒ±ßÔµ
    lineto(550, 50);
    lineto(550, 390);
    lineto(640, 390);

    moveto(100, 50); //»æÖÆÄÚ²à
    lineto(520, 50);
    lineto(520, 120);
    lineto(330, 120);
    lineto(330, 150);
    lineto(520, 150);
    lineto(520, 200);
    lineto(240, 200);
    lineto(240, 230);
    lineto(520, 230);
    lineto(520, 320);
    lineto(240, 320);
    lineto(240, 350);
    lineto(520, 350);
    lineto(520, 390);
    lineto(200, 390);
    lineto(200, 300);
    lineto(170, 300);
    lineto(170, 390);
    lineto(100, 390);
    lineto(100, 150);
    lineto(170, 150);
    lineto(170, 250);
    lineto(200, 250);
    lineto(200, 150);
    lineto(300, 150);
    lineto(300, 120);
    lineto(100, 120);
    lineto(100, 50);
}

void map_tracking()
{
    
}