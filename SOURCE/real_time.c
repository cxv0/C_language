#include"config.h"
#include"custom.h"

void real_time(unsigned char *m) 
{
    time_t now;
    struct tm *local_time;
    char time_str[20];

    // 获取当前时间
    time(&now);
    local_time = localtime(&now);

    // 格式化时间为字符串
    strftime(time_str, sizeof(time_str), "%m-%d %H:%M", local_time);

     if(local_time->tm_min!=*m)
     {
        *m=local_time->tm_min;

         // 绘制时间显示区域
        setcolor(LIGHTGRAY);
        setlinestyle(SOLID_LINE, 0, 1);
        setfillstyle(SOLID_FILL, YELLOW);
        bar(10, 10, 150, 40); // 时间框
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(12, 12, 148, 38);

        // 设置时间文本颜色
        setcolor(BLACK);
        settextstyle(8, HORIZ_DIR, 1);

        // 在屏幕左上角显示时间
        outtextxy(14, 10, time_str);
     }

}
