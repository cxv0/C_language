#include "config.h"
#include "package.h"



int addpackage()
{
    // 创建一个新结构体
    PACKAGE newPackage;
    int i;
    char s[2],number[11];
    // 打开文件（如果文件不存在则创建，如果存在则追加到末尾）
    FILE *file = fopen("C:\\code\\TEXT\\package.dat", "ab"); // 使用追加模式
    srand(time(0));
    s[0] = '0' + (rand()%10+1);
    s[1] = '\0';
    for(i = 0;i < 10;i++)
    {
        number[i] = '\0';
    }
    number[10] = '\0';

    setfillstyle(SOLID_FILL, CYAN);
    bar(100, 80, 540, 400);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(100, 80, 540, 120);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(500, 80, 540, 120);
    setcolor(RED);
    setlinestyle(0, 0, 3);
    line(505, 85, 535, 115);
    line(505, 115, 535, 85);
    line(505, 85, 505, 115);
    line(535, 85, 535, 115);
    line(505, 85, 535, 85);
    line(505, 115, 535, 115);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(450, 340, 535, 375); //确定按钮

    puthz(460, 357 - 16, "确定", 32, 32, WHITE);
    puthz(120, 90, "添加快递", 24, 32, DARKGRAY);

    puthz(120, 145, "名字", 16, 16, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(160, 140, 520, 170);

    delay(500);
    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(160, 140, 520, 170) == 2)
        {
            MouseS = 2;
            continue;
        }

        else if (mouse_press(160, 140, 520, 170) == 1)
        {
            MouseS = 0;
            clrmous(MouseX, MouseY);
            num_input(newPackage.name,160,140,520,170,15);
            strcpy(newPackage.place,"yunyuan");
            strcat(newPackage.place,s);
            strcat(newPackage.place,"dong");
            strcpy(newPackage.number,number);
            continue;
        }

        
        else if (mouse_press(450, 340, 535, 375) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if (mouse_press(450, 340, 535, 375) == 1)
        {
            if (strlen(newPackage.name) != 0 )
            {
                puthz(120, 360, "完成", 16, 16, RED);
                delay(1000);
                setfillstyle(SOLID_FILL, CYAN);
                bar(110, 350, 400, 385);

                if (file == NULL) 
                {
                    printf("Failed to open file");
                    return 1;
                }

                // 将新结构体追加到文件
                if (fwrite(&newPackage, sizeof(PACKAGE), 1, file) != 1) 
                {
                    printf("Failed to write to file");
                    fclose(file);
                    return 1;
                }

                // 关闭文件
                fclose(file);

                clrmous(MouseX, MouseY);
                break; //退出
            }

            else
            {
                puthz(120, 360, "信息缺项", 16, 16, RED);
                delay(1000);
                setfillstyle(SOLID_FILL, CYAN);
                bar(110, 350, 400, 385);
                continue;
            }
        }
        else if (mouse_press(500, 80, 540, 120) == 2)
        {
            MouseS = 1;
            continue;
        }
        else if (mouse_press(500, 80, 540, 120) == 1)
        {
            MouseS = 0;
            clrmous(MouseX, MouseY);
            break; //退出
        }
        else
        {
            MouseS = 0;
            continue;
        }
    }
    return 0;
}



int delpackage()
{
    char name[25] = {'\0'};

    setfillstyle(SOLID_FILL, CYAN);
    bar(120, 120, 520, 360);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(120, 120, 520, 160);

    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(480, 120, 520, 160);
    setcolor(RED);
    setlinestyle(0, 0, 3);
    line(485, 125, 515, 155);
    line(485, 155, 515, 125);
    line(485, 125, 485, 155);
    line(485, 125, 515, 125);
    line(515, 125, 515, 155);
    line(485, 155, 515, 155);

    puthz(140, 130, "一键代取", 32, 32, DARKGRAY);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(430, 320, 515, 355); //确定按钮

    puthz(440, 337 - 16, "确定", 32, 36, WHITE);
    puthz(140, 195, "名字", 32, 36, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(250, 195, 500, 220);

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(430, 320, 515, 355) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if (mouse_press(430, 320, 515, 355) == 1)
        {
            MouseS = 0;
            if (delete_package_by_name("C:\\code\\TEXT\\package.dat", name) == 0) 
            {
                setfillstyle(SOLID_FILL, CYAN);
                bar(130, 320, 400, 355);
                puthz(140, 320, "完成", 32, 36, RED);
                delay(1000);
                break;
            } 

            else 
            {
                setfillstyle(SOLID_FILL, CYAN);
                bar(130, 320, 400, 355);
                puthz(140, 320, "未找到快递！", 32, 36, RED);
                delay(1000);
                continue;
            }
        }

        else if (mouse_press(250, 190, 500, 220) == 2)
        {
            MouseS = 2;
            continue;
        }

        else if (mouse_press(250, 190, 500, 220) == 1)
        {
            MouseS = 0;
            clrmous(MouseX, MouseY);
            num_input(name, 250, 190, 500, 220, 15);
            continue;
        }

        else if (mouse_press(480, 120, 520, 170) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if (mouse_press(480, 120, 520, 170) == 1)
        {
            MouseS = 0;
            break; //退出
        }

        else
        {
            MouseS = 0;
            continue;
        }
    }
    clrmous(MouseX, MouseY);

    return 0;
}



int delete_package_by_name(char *filename, char *target_name)   // 从文件中删除具有指定name的结构体记录
{
    FILE *file = NULL;
    FILE *temp_file = NULL;
    PACKAGE pack;
    int found = 0;
    char *temp_filename = "temp.dat"; // 临时文件名

    // 打开源文件进行读取
    file = fopen(filename, "rb");
    if (file == NULL) 
    {
        printf("Failed to open file for reading");
        return 1;
    }

    // 创建临时文件用于写入
    temp_file = fopen(temp_filename, "wb");
    if (temp_file == NULL) 
    {
        printf("Failed to create temporary file");
        fclose(file);
        return 1;
    }

    // 读取源文件中的每个记录，跳过name匹配的记录
    while (fread(&pack, sizeof(PACKAGE), 1, file)) 
    {
        if (strcmp(pack.name, target_name) != 0) 
        {
            fwrite(&pack, sizeof(PACKAGE), 1, temp_file);
        } 
        else 
        {
            found = 1;
        }
    }

    // 关闭文件
    fclose(file);
    fclose(temp_file);

    // 用临时文件替换原文件
    if (remove(filename)) 
    {
        printf("Failed to remove original file");
        remove(temp_filename); // 清理临时文件
        return 1;
    }
    if (rename(temp_filename, filename)) 
    {
        printf("Failed to rename temporary file");
        return 1;
    }

    return found ? 0 : 1;
}



int output_package()
{
    int i;
    int num_records;
    long file_size;
    PACKAGE *packages;
    size_t result;
    FILE *fp = fopen("C:\\code\\TEXT\\package.dat", "rb");
    if (fp == NULL) 
    {
        printf("Failed to open file");
        return 1;
    }

    // 获取文件大小，计算结构体数量
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp); // 光标回到文件开头

    num_records = file_size / sizeof(PACKAGE);

    // 动态分配结构体数组
    packages = (PACKAGE *)malloc(num_records * sizeof(PACKAGE));
    if (packages == NULL) 
    {
        printf("Failed to allocate memory");
        fclose(fp);
        return 1;
    }

    // 读取文件内容到结构体数组
    result = fread(packages, sizeof(PACKAGE), num_records, fp);
    if (result != (size_t)num_records) 
    {
        printf("Failed to read file");
        free(packages);
        fclose(fp);
        return 1;
    }

    // 输出结构体数组内容
    for (i = 0; i < num_records; i++) 
    {
        setcolor(RED);
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
        outtextxy(20, 100 + 30 * i, packages[i].name);
        outtextxy(220, 100 + 30 * i, packages[i].place);
        outtextxy(420, 100 + 30 * i, packages[i].number);
    }

    // 释放资源
    free(packages);
    fclose(fp);
    return 0;
}



int count_package() //计数package.dat中共有几个结构体
{
    int count = 0;
    PACKAGE hust;
    FILE *fp = NULL;

    fp = fopen("C:\\code\\TEXT\\package.dat", "rb");

    if (fp == NULL) 
    {
        printf("Failed to open file");
        return 1; // 返回错误码表示文件打开失败
    }

    while (1) 
    {
        // 尝试读取一个 PACKAGE 结构体
        size_t result = fread(&hust, sizeof(PACKAGE), 1, fp);
        if (result == 0) 
        {
            if (feof(fp)) 
            {
                // 文件读取结束
                break;
            } else {
                // 读取失败，可能是磁盘错误等
                printf("Failed to read file");
                fclose(fp);
                return 1; // 返回错误码表示读取失败
            }
        }
        count++; // 成功读取一个结构体则计数加 1
    }

    fclose(fp);
    return count;
}