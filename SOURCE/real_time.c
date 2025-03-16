#include"config.h"
#include"custom.h"

void real_time(unsigned char *m) 
{
    time_t now;
    struct tm *local_time;
    char time_str[20];

    // ��ȡ��ǰʱ��
    time(&now);
    local_time = localtime(&now);

    // ��ʽ��ʱ��Ϊ�ַ���
    strftime(time_str, sizeof(time_str), "%m-%d %H:%M", local_time);

     if(local_time->tm_min!=*m)
     {
        *m=local_time->tm_min;

         // ����ʱ����ʾ����
        setcolor(LIGHTGRAY);
        setlinestyle(SOLID_LINE, 0, 1);
        setfillstyle(SOLID_FILL, YELLOW);
        bar(10, 10, 150, 40); // ʱ���
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(12, 12, 148, 38);

        // ����ʱ���ı���ɫ
        setcolor(BLACK);
        settextstyle(8, HORIZ_DIR, 1);

        // ����Ļ���Ͻ���ʾʱ��
        outtextxy(14, 10, time_str);
     }

}
