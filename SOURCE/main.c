#include "custom.h"
#include "config.h"

/****** 
main.c
COPYRIGHT:  Jiang Yihan
FUNCTION:   main function
DATE:       2025/2/10
******/

void main()
{
    int graphdriver = VGA, graphmode = VGAHI;
    int i = 0, p = 0, n = 0, t = 0;
    int *page = &p, *num = &n;
    initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
    mouseinit();
    welcome_page();

    initmenu(page, num);
}
