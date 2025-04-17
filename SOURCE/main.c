#include "config.h"
#include "custom.h"


float cost[20] = {0};
int shuzi = 0;


void main()

{
	int page = welcome;
	int hashstate = 0;
	int gdriver = VGA;
	int gmode = VGAHI;

	ADMINHASH *hash = NULL;
	INFO t[16] = {
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

	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI"); 


	hash = InitHash(30);
	mouseinit();

	while (1)
	{
		switch (page)
		{
		case welcome:
			page = initmenu();
			break;

		case login:
			page = login_fun();
			break;

		case regis:
			page = regis_fun();
			break;

		case menu:
			page = homefunc();
			break;

		case package:
			if (hashstate == 0)
			{
				hashinput(hash);
				hashstate = 1;
			}
			page = expagefunc(hash);
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

