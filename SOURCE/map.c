#include "config.h"
#include "map.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Map and map tracking function //绘制地图与路径追踪
DATE:       2025/4/18
******/

void draw_map()
{
    setcolor(CYAN); //绘制地图
    moveto(70, 0); //左边缘
    lineto(70, 120);
    lineto(0, 120);
    lineto(0, 150);
    lineto(70, 150);
    lineto(70, 390);
    lineto(0, 390);
    lineto(0, 420);
    lineto(70, 420);
    lineto(70, 480);
    moveto(100, 0); //上边缘
    lineto(100, 20);
    lineto(640, 20);
    moveto(100, 480); //下边缘
    lineto(100, 420);
    lineto(640, 420);
    moveto(640, 50); //右边缘
    lineto(550, 50);
    lineto(550, 390);
    lineto(640, 390);

    moveto(100, 50); //绘制内侧
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

void map_tracking(int StartX, int StartY, int EndX, int EndY)
{
    int map[48][64];
    Point parent[48][64];
    Point start, end;
    start.x = StartX;
    start.y = StartY;
    end.x = EndX;
    end.y = EndY;
    setfillstyle(SOLID_FILL, MAGENTA);
    bar(StartX * 10, StartY * 10, (StartX + 1) * 10, (StartY + 1) * 10);
    bar(EndX * 10, EndY * 10, (EndX + 1) * 10, (EndY + 1) * 10);
    draw_map();
    init_map(map);

    if(bfs(start, end, map, parent))
    {
        draw_path(start, end, parent);
    }
    else
    {
        setcolor(RED);
        outtextxy(10, 10, "No path found!");
    }
}

bool bfs(Point start, Point end, int maze[48][64], Point parent[48][64]) {
    // Initialize visited array
    bool visited[48][64] = {false};
    int i, j, nx, ny;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    Point current, temp;
    
    // Queue for BFS
    Point queue[48*64];
    int front = 0, rear = 0;
    
    queue[rear].x = start.x;
    queue[rear].y = start.y;
    rear++;
    visited[start.y][start.x] = true;
    
    // Directions: up, right, down, left
    
    
    while (front < rear) {
        current.x = queue[front].x;
        current.y = queue[front].y;
        front++;
        
        // Check if we reached the end
        if (current.x == end.x && current.y == end.y) {
            return true;
        }
        
        // Explore all four directions
        for (i = 0; i < 4; i++) {
            nx = current.x + dx[i];
            ny = current.y + dy[i];
            
            // Check if the new position is valid
            if (nx >= 0 && nx < 64 && ny >= 0 && ny < 48 &&
                !visited[ny][nx] && maze[ny][nx] == 0) {
                visited[ny][nx] = true;
                parent[ny][nx] = current;
                temp.x = nx;
                temp.y = ny;
                queue[rear] = temp;
                rear++;
            }
        }
    }
    
    // Path not found
    return false;
}

void draw_path(Point start, Point end, Point parent[48][64])
{
    Point current = end;
    Point temp;
    
    // 检查起点和终点是否有效
    if (start.x < 0 || start.x >= 64 || start.y < 0 || start.y >= 48 ||
        end.x < 0 || end.x >= 64 || end.y < 0 || end.y >= 48) {
        setcolor(RED);
        outtextxy(10, 10, "Invalid start or end point!");
        return;
    }

    // 回溯路径并绘制
    while (!(current.x == start.x && current.y == start.y)) {
        if (current.x < 0 || current.x >= 64 || current.y < 0 || current.y >= 48) {
            setcolor(RED);
            outtextxy(10, 10, "Path reconstruction failed!");
            return;
        }

        if (parent[current.y][current.x].x == -1 && parent[current.y][current.x].y == -1) {
            setcolor(RED);
            outtextxy(10, 10, "Path reconstruction failed!");
            return;
        }

        setfillstyle(SOLID_FILL, GREEN);
        bar(current.x * 10, current.y * 10, 
            (current.x + 1) * 10, (current.y + 1) * 10);
        setfillstyle(SOLID_FILL, YELLOW);
        bar(temp.x * 10, temp.y * 10, 
            (temp.x + 1) * 10, (temp.y + 1) * 10);
        
        temp = current;
        current = parent[current.y][current.x];
        delay(50);
    }

    // 绘制起点和终点
    // setfillstyle(SOLID_FILL, RED);
    // bar(start.x * 10, start.y * 10, 
    //     (start.x + 1) * 10, (start.y + 1) * 10);

    // setfillstyle(SOLID_FILL, BLUE);
    // bar(end.x * 10, end.y * 10, 
    //     (end.x + 1) * 10, (end.y + 1) * 10);
}

void init_map(int map[48][64]) //64*48个方格,每个方格10px*10px
{ 
    int i = 0, j = 0;

    for(i = 0; i < 48; i++)
    {
        for(j = 0; j < 64; j++)
        {
            map[i][j] = 1;
        }
    }

    for(i = 0; i < 48; i++)
    {
        for(j = 0; j < 64; j++)
        {
            if((0 <= i && i <= 47) && (7 <= j && j <= 9))
            {
                map[i][j] = 0;
            }
            else if((12 <= i && i <= 14) && (0 <= j && j <= 29))
            {
                map[i][j] = 0;
            }
            else if((39 <= i && i <= 41) && (0 <= j && j <= 63))
            {
                map[i][j] = 0;
            }
            else if((2 <= i && i <= 4) && (7 <= j && j <= 63))
            {
                map[i][j] = 0;
            }
            else if((5 <= i && i <= 38) && (52 <= j && j <= 54))
            {
                map[i][j] = 0;
            }
            else if((12 <= i && i <= 14) && (33 <= j && j <= 51))
            {
                map[i][j] = 0;
            }
            else if((20 <= i && i <= 22) && (24 <= j && j <= 51))
            {
                map[i][j] = 0;
            }
            else if((12 <= i && i <= 14) && (0 <= j && j <= 29))
            {
                map[i][j] = 0;
            }
            else if((32 <= i && i <= 34) && (24 <= j && j <= 51))
            {
                map[i][j] = 0;
            }
            else if((15 <= i && i <= 24) && (17 <= j && j <= 19))
            {
                map[i][j] = 0;
            }
            else if((30 <= i && i <= 38) && (17 <= j && j <= 19))
            {
                map[i][j] = 0;
            }
        }
    }
    paint_road(map);
}

void paint_road(int map[48][64])
{
    int i = 0, j = 0;
    setbkcolor(YELLOW);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    for(i = 0; i < 48; i ++)
    {
        for(j = 0; j < 64; j ++)
        {
            if(map[i][j] == 1)
            {
                bar(j * 10, i * 10, (j + 1) * 10, (i + 1) * 10);
            }
        }
    }
}

int main()
{
    int map[48][64];
    int gdriver = VGA;
	int gmode = VGAHI;
    initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
    //map_tracking(8, 6, 34, 13);
    //map_tracking(26, 3, 25, 33);
    map_tracking(31, 40, 18, 22);
    delay(3000);
    return 0;
}