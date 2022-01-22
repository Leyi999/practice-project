#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define DATA_MAX 1000
#define NAME_MAX 20
#define SEX_MAX 6
#define ADDR_MAX 50 
#define NUM_MAX 20
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct peoInfor {//�������ṹ�巽�����
	int age;
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char num[NUM_MAX];
}peoInfor;
typedef struct contact {//�������ṹ�巽�����
	peoInfor data[DATA_MAX];
	int dataSize;
}contact;
void InitContact(contact*p);//��ʼ��ͨѶ¼

void meun();//ͨѶ¼�˵�

void AddContact(contact*p);//�½���ϵ��

void DelContact(contact*p);//ɾ����ϵ��

int FindContact(contact*p);//������ϵ�˵�data�±�

void SearchContact(contact* p);//���Ҳ���ӡ��ϵ�ˣ�

void ModifyContact(contact*p);//�޸���ϵ��

void SortContact(contact*p);//������ϵ��

void ShowContact(contact* p);//��ʾ��ϵ��
