#include "config.h"
#include "map.h"
#include "gtaccount.h"
#include "address.h"
#include "show_good.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Show deliver on map
DATE:       2025/4/21
******/

void show_deliver(int address)
{
    int startpoint, StartX, StartY, EndX, EndY;
    srand((unsigned)time(NULL));
    startpoint = rand() % 3 + 1;
    
    if(startpoint == 1)
    {
        EndX = 8;
        EndY = 32;
    }

    else if(startpoint == 2)
    {
        EndX = 26;
        EndY = 3;
    }

    else
    {
        EndX = 32;
        EndY = 40;
    }

    if(address == 1)
    {
        StartX = 27;
        StartY = 13;
    }

    else if(address == 2)
    {
        StartX = 34;
        StartY = 13;
    }

    else if(address == 3)
    {
        StartX = 18;
        StartY = 22;
    }

    else if(address == 4)
    {
        StartX = 25;
        StartY = 21;
    }

    else if(address == 5)
    {
        StartX = 18;
        StartY = 31;
    }

    else if(address == 6)
    {
        StartX = 25;
        StartY = 33;
    }

    else
    {
        setcolor(RED);
        outtextxy(20, 20, "Invalid address value!");
    }

    map_tracking(StartX, StartY, EndX, EndY);
    setcolor(RED);
    outtextxy(20, 20, "The goods have arrived!");
    delay(1000);
}