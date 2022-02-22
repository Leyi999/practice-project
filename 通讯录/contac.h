#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#define NAME_MAX 20
#define SEX_MAX 6
#define ADDR_MAX 50 
#define NUM_MAX 20

#define DataFlie_NAME "infodata.txt"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<errno.h>

FILE* pf;

typedef enum opintion //����ѡ���ö������
{
	ExitandSave,
	Add,
	Del,
	Srch,
	Moidfy,
	Sort,
	Show,
	Init,
	Save,
	ExitwithoutSave,
}opintion;
typedef struct peoInfor {//�������ṹ�巽�����
	int age;
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char num[NUM_MAX];
}peoInfor;
typedef struct contact {//�������ṹ�巽�����
	int dataSize;
	int MemerSize;
	peoInfor data[];
}contact;

void InitContact(contact **p);//��ʼ��ͨѶ¼

void GetMemory(contact **p);//��ͨѶ¼����

void FreeContact(contact** p);

void meun();//ͨѶ¼�˵�

void AddContact(contact **p);//�½���ϵ��

void DelContact(contact **p);//ɾ����ϵ��

int FindContact(contact **p);//������ϵ�˵�data�±�

void SearchContact(contact **p);//���Ҳ���ӡ��ϵ�ˣ�

void ModifyContact(contact **p);//�޸���ϵ��

void SortContact(contact **p);//������ϵ��

void ShowContact(contact **p);//��ʾ��ϵ��

void SaveContact(contact** p);//�洢��ϵ��

void LoadData(contact** p);//��ȡ�����д洢����Ϣ