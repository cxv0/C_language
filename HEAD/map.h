#ifndef _map_h_
#define _map_h_

typedef struct point
{
    int x;
    int y;
} Point;

void draw_map(void);
void map_tracking(int StartX, int StartY, int EndX, int EndY);
void draw_path(Point start, Point end, Point parent[48][64]);
void init_map(int map[48][64]); //64*48个方格,每个方格10px*10px
bool bfs(Point start, Point end, int map[48][64], Point parent[48][64]);
void paint_road(int map[48][64]);
void show_deliver(int address);

#endif