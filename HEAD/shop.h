#ifndef _shop_h_
#define _shop_h_

#include "order.h"

typedef struct record //�����¼
{
    char account[20]; //�˻���
    int num[16]; //��Ʒ����
    float sum;
    int state; //��¼����״̬,δ�µ�:-1/�Ѿ��µ�:1
} RECORD;

void check_record_dat(void); //ȷ��record.dat����
int count_userrecord(void); //����record.dat�й��м����ṹ��
RECORD *new_record(RECORD *rp); //���ɿհ׼�¼
// void record_addnum(RECORD *rp, INFO *ip); //�˴���ip�ǵ����ṹ��ָ��,������ӵ���һ����Ʒ�����ݶ����ܼ���
void edit_record(RECORD *rp, INFO *ip); //�˴���ip�ǵ����ṹ��ָ��,�����޸ĵ���һ����Ʒ������
RECORD *ensure_record(RECORD *rp); //ȷ���µ�
void add_record(RECORD *rp); //�洢�����¼
RECORD *output_record(char *account); //�����ʷ��¼ָ��
void output_to_screen(RECORD *rp); //�������Ļ

#endif