#ifndef _mine_h_
#define _mine_h_

#include "order.h"
#include "map.h"

void mine_page(void);
int minefunc(INFO (*t)[16]);
float total(INFO (*t)[16]);
void draw_page(void);
void page_redraw(void);


#endif