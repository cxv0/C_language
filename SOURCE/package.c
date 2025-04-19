#include "config.h"
#include "package.h"



int addpackage()
{
    // ����һ���½ṹ��
    PACKAGE newPackage;
    int i;
    char s[2],number[11];
    // ���ļ�������ļ��������򴴽������������׷�ӵ�ĩβ��
    FILE *file = fopen("C:\\code\\TEXT\\package.dat", "ab"); // ʹ��׷��ģʽ
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
    bar(450, 340, 535, 375); //ȷ����ť

    puthz(460, 357 - 16, "ȷ��", 32, 32, WHITE);
    puthz(120, 90, "��ӿ��", 24, 32, DARKGRAY);

    puthz(120, 145, "����", 16, 16, WHITE);

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
                puthz(120, 360, "���", 16, 16, RED);
                delay(1000);
                setfillstyle(SOLID_FILL, CYAN);
                bar(110, 350, 400, 385);

                if (file == NULL) 
                {
                    printf("Failed to open file");
                    return 1;
                }

                // ���½ṹ��׷�ӵ��ļ�
                if (fwrite(&newPackage, sizeof(PACKAGE), 1, file) != 1) 
                {
                    printf("Failed to write to file");
                    fclose(file);
                    return 1;
                }

                // �ر��ļ�
                fclose(file);

                clrmous(MouseX, MouseY);
                break; //�˳�
            }

            else
            {
                puthz(120, 360, "��Ϣȱ��", 16, 16, RED);
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
            break; //�˳�
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

    puthz(140, 130, "һ����ȡ", 32, 32, DARKGRAY);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(430, 320, 515, 355); //ȷ����ť

    puthz(440, 337 - 16, "ȷ��", 32, 36, WHITE);
    puthz(140, 195, "����", 32, 36, WHITE);

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
                puthz(140, 320, "���", 32, 36, RED);
                delay(1000);
                break;
            } 

            else 
            {
                setfillstyle(SOLID_FILL, CYAN);
                bar(130, 320, 400, 355);
                puthz(140, 320, "δ�ҵ���ݣ�", 32, 36, RED);
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
            break; //�˳�
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



int delete_package_by_name(char *filename, char *target_name)   // ���ļ���ɾ������ָ��name�Ľṹ���¼
{
    FILE *file = NULL;
    FILE *temp_file = NULL;
    PACKAGE pack;
    int found = 0;
    char *temp_filename = "temp.dat"; // ��ʱ�ļ���

    // ��Դ�ļ����ж�ȡ
    file = fopen(filename, "rb");
    if (file == NULL) 
    {
        printf("Failed to open file for reading");
        return 1;
    }

    // ������ʱ�ļ�����д��
    temp_file = fopen(temp_filename, "wb");
    if (temp_file == NULL) 
    {
        printf("Failed to create temporary file");
        fclose(file);
        return 1;
    }

    // ��ȡԴ�ļ��е�ÿ����¼������nameƥ��ļ�¼
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

    // �ر��ļ�
    fclose(file);
    fclose(temp_file);

    // ����ʱ�ļ��滻ԭ�ļ�
    if (remove(filename)) 
    {
        printf("Failed to remove original file");
        remove(temp_filename); // ������ʱ�ļ�
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

    // ��ȡ�ļ���С������ṹ������
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp); // ���ص��ļ���ͷ

    num_records = file_size / sizeof(PACKAGE);

    // ��̬����ṹ������
    packages = (PACKAGE *)malloc(num_records * sizeof(PACKAGE));
    if (packages == NULL) 
    {
        printf("Failed to allocate memory");
        fclose(fp);
        return 1;
    }

    // ��ȡ�ļ����ݵ��ṹ������
    result = fread(packages, sizeof(PACKAGE), num_records, fp);
    if (result != (size_t)num_records) 
    {
        printf("Failed to read file");
        free(packages);
        fclose(fp);
        return 1;
    }

    // ����ṹ����������
    for (i = 0; i < num_records; i++) 
    {
        setcolor(RED);
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
        outtextxy(20, 100 + 30 * i, packages[i].name);
        outtextxy(220, 100 + 30 * i, packages[i].place);
        outtextxy(420, 100 + 30 * i, packages[i].number);
    }

    // �ͷ���Դ
    free(packages);
    fclose(fp);
    return 0;
}



int count_package() //����package.dat�й��м����ṹ��
{
    int count = 0;
    PACKAGE hust;
    FILE *fp = NULL;

    fp = fopen("C:\\code\\TEXT\\package.dat", "rb");

    if (fp == NULL) 
    {
        printf("Failed to open file");
        return 1; // ���ش������ʾ�ļ���ʧ��
    }

    while (1) 
    {
        // ���Զ�ȡһ�� PACKAGE �ṹ��
        size_t result = fread(&hust, sizeof(PACKAGE), 1, fp);
        if (result == 0) 
        {
            if (feof(fp)) 
            {
                // �ļ���ȡ����
                break;
            } else {
                // ��ȡʧ�ܣ������Ǵ��̴����
                printf("Failed to read file");
                fclose(fp);
                return 1; // ���ش������ʾ��ȡʧ��
            }
        }
        count++; // �ɹ���ȡһ���ṹ��������� 1
    }

    fclose(fp);
    return count;
}