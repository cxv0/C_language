#include "config.h"
#include "initmenu.h" 
#include "regis.h"
#include "login.h"
#include "data.h"
#include "input_pass.h"
#include "user.h"
#include "homepage.h"
#include "real_time.h"
#include "expressage.h"
#include "package.h"
#include "market.h"
#include "order.h"
#include "mine.h"
#include "force_exit.h"

float cost[20] = {0};
int shuzi = 0;
int forceexit = 0;

void main()

{
	int huststate = 0;
	int page = welcome;
	int gdriver = VGA;
	int gmode = VGAHI;

	INFO q[16] = {
		{1,1.0,0},
		{2,2.0,0},
		{3,3.0,0},
		{4,4.0,0},
		{5,5.0,0},
		{6,6.0,0},
		{7,7.0,0},
		{8,8.0,0},
		{9,9.0,0},
		{10,10.0,0},
		{11,11.0,0},
		{12,12.0,0},
		{13,13.0,0},
		{14,14.0,0},
		{15,15.0,0},
		{16,16.0,0},
		};
	INFO *t = NULL;

	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	mouseinit();

	t = &q;


	while (1)
	{
		switch (page)
		{
		case welcome:
			page = initmenu();
			break;

		case login:
			page = login_fun(t);
			break;

		case regis:
			page = regis_fun();
			break;

		case menu:
			page = homefunc();
			break;

		case package:
			page = expagefunc();
			break;
		
		case takeout:
			page = orderfunc(t);
			break;
		
		case mine:
			page = minefunc(t);
			break;

		default:
			exit(1);
		}
	}

}

