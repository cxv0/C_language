#include "config.h"
#include "custom.h"

/****** 
COPYRIGHT:  Jiang Yihan
FUNCTION:   Send package function //取件功能
DATE:       2025/3/15
******/

void draw_sendpage(int *num)
{
    setfillstyle(SOLID_FILL, YELLOW);
    bar(170, 60, 630, 400);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(172, 62, 628, 398);

    setcolor(LIGHTGRAY);
    rectangle(172, 12, 628, 42);
    rectangle(172, 44, 628, 155);
    rectangle(172, 155, 628, 266);
    rectangle(172, 266, 628, 377);
    rectangle(172, 377, 628, 398);

    
}
