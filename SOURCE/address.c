#include "config.h"
#include "address.h"
#include "gtaccount.h"
#include "map.h"

/******
COPYRIGHT:  Jiang Yihan
FUNCTION:   Adress setting
DATE:       2025/4/21
******/

void check_address_dat() //确保address.dat存在
{
    FILE *fp1 = fopen("C:\\CODE\\TEXT\\address.dat", "rb"), *fp2 = NULL;
    if(fp1 == NULL) //查找该用户信息是否已经存在，若不存在则创建
    {
        if((fp2 = fopen("C:\\CODE\\TEXT\\address.dat", "wb+")) == NULL)
        {
            printf("\nError on create file %s!", "C:\\CODE\\TEXT\\address.dat");
            delay(3000);
            exit(1);
        }
        fclose(fp2);
    }
    
    else
    {
        fclose(fp1);
    }
}

void saveaddress(int position_num)
{
    int i = 0, found = 0;
    FILE *fp;
    ADDRESS addr;
    check_address_dat();
    strcpy(addr.account, output_account());
    addr.position = position_num;
    fp = fopen("C:\\CODE\\TEXT\\address.dat", "rb+");
    fseek(fp, -sizeof(ADDRESS), SEEK_END);

    while(fread(&addr, sizeof(ADDRESS), 1, fp) == 1)
    {
        if(strcmp(addr.account, output_account()) == 0)
        { //找到匹配的账号
            addr.position = position_num; //更新位置
            fseek(fp, -sizeof(ADDRESS), SEEK_CUR); //回到刚才读取的位置
            fwrite(&addr, sizeof(ADDRESS), 1, fp); //写入更新后的结构体
            found = 1;
            break;
        }
        fseek(fp, -2 * sizeof(ADDRESS), SEEK_CUR);
    }

    if(!found) //没找到就在文件末追加
    {
        if(1 <= position_num && position_num <= 6)
        {
            strcpy(addr.account, output_account());
            addr.position = position_num;
            fseek(fp, 0, SEEK_END);
            fwrite(&addr, sizeof(ADDRESS), 1, fp);
        }
        else
        {
            outtextxy(20, 20, "Invalid position!");
        }
    }    
    fclose(fp);
}

// void update_address_in_file(int new_position)
// {
//     FILE *fp;
//     ADDRESS addr;
//     int found = 0;
//     check_address_dat();
//     fp = fopen("C:\\CODE\\TEXT\\address.dat", "rb+");

//     while(fread(&addr, sizeof(ADDRESS), 1, fp) == 1)
//     {
//         if(!(1 <= new_position && new_position <= 6))
//         {
//             outtextxy(20, 20, "Invalid position!");
//             break;
//         }
//         if(strcmp(addr.account, output_account()) == 0)
//         { //找到匹配的账号
//             addr.position = new_position; //更新位置
//             fseek(fp, -sizeof(ADDRESS), SEEK_CUR); //回到刚才读取的位置
//             fwrite(&addr, sizeof(ADDRESS), 1, fp); //写入更新后的结构体
//             found = 1;
//             break;
//         }
//     }

//     fclose(fp); //关闭文件
//     if(!found)
//     {
//         outtextxy(20, 20, "No address found!");
//         delay(1000);
//     }
// }

void output_address()
{
    int i = 0, found = 0;
    long file_size, offset;
    FILE *fp;
    ADDRESS temp;
    char str[5];
    check_address_dat();
    fp = fopen("C:\\CODE\\TEXT\\address.dat", "rb");
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);

    setcolor(RED);

    if(file_size == 0)
    {
        outtextxy(20, 20, "No data in file address.dat!");
    }

    offset = file_size - sizeof(ADDRESS);
    while(offset > 0)
    {
        // printf("temp.account: %s  ", temp.account);
        // printf("account: %s  ", account);
        // delay(1000); //测试

        fseek(fp, offset, SEEK_SET);
        fread(&temp, sizeof(ADDRESS), 1, fp); //读取数据到temp
        if(strcmp(temp.account, output_account()) == 0)
        {
            found = 1;
            puthz(10, 75, "当前的地址", 24, 26, RED);
            itoa(temp.position, str, 10);
            outtextxy(160, 70, str);
            delay(1000);
            break;
        }
        offset -= sizeof(ADDRESS);
    }

    fclose(fp);
    if(!found)
    {
        outtextxy(20, 20, "No address found!");
        delay(1000);
    }
}

int get_address_num()
{
    int i = 0, found = 0;
    long file_size, offset;
    FILE *fp;
    ADDRESS temp;
    char str[5];
    check_address_dat();
    fp = fopen("C:\\CODE\\TEXT\\address.dat", "rb");
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);

    setcolor(RED);

    if(file_size == 0)
    {
        outtextxy(20, 20, "No data in file address.dat!");
    }

    offset = file_size - sizeof(ADDRESS);
    while(offset > 0)
    {
        // printf("temp.account: %s  ", temp.account);
        // printf("account: %s  ", account);
        // delay(1000); //测试

        fseek(fp, offset, SEEK_SET);
        fread(&temp, sizeof(ADDRESS), 1, fp); //读取数据到temp
        if(strcmp(temp.account, output_account()) == 0)
        {
            found = 1;
            delay(1000);
            return temp.position;
        }
        offset -= sizeof(ADDRESS);
    }

    fclose(fp);
    if(!found)
    {
        outtextxy(20, 20, "No address found!");
        delay(1000);
        return 0;
    }
}

int choose_address()
{
    int map[48][64];
    int position = 0;

    clrmous(MouseX, MouseY);
    cleardevice();

    draw_map();
    init_map(map);
    paint_road(map);

    setfillstyle(SOLID_FILL, BLUE);
    bar(270, 120, 290, 140);
    bar(340, 120, 360, 140);
    bar(175, 215, 195, 235);
    bar(250, 200, 270, 220);
    bar(175, 300, 195, 320);
    bar(250, 320, 270, 340);

    setcolor(RED);
    settextstyle(TRIPLEX_FONT, 0, 3);
    puthz(10, 20, "点击蓝色区域以选择收货地址", 24, 26, RED);
    puthz(10, 45, "点击返回键默认为地址一", 16, 18, RED);
    outtextxy(273, 117, "1");
    outtextxy(343, 117, "2");
    outtextxy(180, 212, "3");
    outtextxy(253, 197, "4");
    outtextxy(178, 297, "5");
    outtextxy(253, 317, "6");
    setfillstyle(SOLID_FILL, YELLOW);
    bar(550, 430, 610, 460);
    puthz(550, 430, "返回", 24, 26, RED);
    
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        
        if(mouse_press(270, 115, 290, 135) == 2)
        {
            MouseS = 1;
            continue;
        }
        
        else if(mouse_press(270, 115, 290, 135) == 1)
        {
            MouseS = 1;
            position = 1;
            saveaddress(position);
            output_address();
            return position;
        }

        else if(mouse_press(340, 115, 360, 135) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if(mouse_press(340, 115, 360, 135) == 1)
        {
            MouseS = 1;
            position = 2;
            saveaddress(position);
            output_address();
            return position;
        }

        else if(mouse_press(175, 210, 195, 230) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if(mouse_press(175, 210, 195, 230) == 1)
        {
            MouseS = 1;
            position = 3;
            saveaddress(position);
            output_address();
            return position;
        }

        else if(mouse_press(250, 195, 270, 215) == 2)
        {
            MouseS = 1;
            continue;
        }
        
        else if(mouse_press(250, 195, 270, 215) == 1)
        {
            MouseS = 1;
            position = 4;
            saveaddress(position);
            output_address();
            return position;
        }

        else if(mouse_press(175, 300, 195, 320) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if(mouse_press(175, 300, 195, 320) == 1)
        {
            MouseS = 1;
            position = 5;
            saveaddress(position);
            output_address();
            return position;
        }

        else if(mouse_press(250, 320, 270, 340) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if(mouse_press(250, 320, 270, 340) == 1)
        {
            MouseS = 1;
            position = 6;
            saveaddress(position);
            output_address();
            return position;
        }

        else if(mouse_press(550, 430, 610, 460) == 2)
        {
            MouseS = 1;
            continue;
        }

        else if(mouse_press(550, 430, 610, 460) == 1) //点击返回则默认为位置1
        {
            MouseS = 1;
            position = 1;
            saveaddress(position);
            output_address();
            return position;
        }

        else
        {
            MouseS = 0;
            continue;
        }
    }
}