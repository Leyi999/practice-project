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

typedef enum opintion //可能选项的枚举类型
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
typedef struct peoInfor {//重命名结构体方便编码
	int age;
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char num[NUM_MAX];
}peoInfor;
typedef struct contact {//重命名结构体方便编码
	int dataSize;
	int MemerSize;
	peoInfor data[];
}contact;

void InitContact(contact **p);//初始化通讯录

void GetMemory(contact **p);//给通讯录增容

void FreeContact(contact** p, FILE** pf);

void meun();//通讯录菜单

void AddContact(contact **p);//新建联系人

void DelContact(contact **p);//删除联系人

int FindContact(contact **p);//返回联系人的data下标

void SearchContact(contact **p);//查找并打印联系人；

void ModifyContact(contact **p);//修改联系人

void SortContact(contact **p);//排序联系人

void ShowContact(contact **p);//显示联系人

void SaveContact(contact** p, FILE** pf);//存储联系人

void LoadData(contact** p, FILE** pf);//读取磁盘中存储的信息