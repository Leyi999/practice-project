#define _CRT_SECURE_NO_WARNINGS 1
#include"contac.h"
void meun() {
	printf("******          通讯录          *******\n");
	printf("******     1.新建     2.删除    *******\n");
	printf("******     3.查找     4.修改    *******\n");
	printf("******     5.排序     6.显示    *******\n");
	printf("******     7.清空     0.退出    *******\n");
}
void InitContact(contact* p) {
	assert(p);
	memset(p,0, sizeof(*p));
}
void AddContact(contact* p) {
	assert(p);
	if (p->dataSize>=1000) {
		printf("通讯录已满，无法添加!\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", p->data[p->dataSize].name);
	printf("请输入性别:>");
	scanf("%s", p->data[p->dataSize].sex);
	printf("请输入年龄:>");
	scanf("%d", &(p->data[p->dataSize].age));
	printf("请输入住址:>");
	scanf("%s", p->data[p->dataSize].addr);
	printf("请输入电话号码:>");
	scanf("%s", p->data[p->dataSize].num);
	printf("添加成功！\n");
	p->dataSize++;
}
int FindContact(contact* p) {
	assert(p);
	printf("请输入姓名:>");
	char name[NAME_MAX];
	scanf("%s",name);
	for (int i = 0; i < p->dataSize; i++) {
		if (!strcmp(p->data[i].name,name ))
			return i;
	}
	return -1;
}
void SearchContact(contact* p) {//查找并打印联系人；
	assert(p);
	if (!p->dataSize) {
		printf("当前通讯录为空!\n");
		printf("\n");

		return;
	}
	int i = FindContact(p);
	if (i == -1) {
		printf("查找不到该联系人!\n");
		printf("\n");

		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "姓名", "性别", "年龄", "住址", "电话");
	printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].addr, p->data[i].num);

	printf("\n");

}

void DelContact(contact* p) {
	assert(p);
	if (!p->dataSize) {
		printf("当前通讯录为空，无法删除!\n");
		return;
		printf("\n");
	}
	int ret = FindContact(p);
	if (ret == -1) {
		printf("查找不到该联系人，删除失败!\n");
		printf("\n");
		return;
	}
	memmove(p->data + ret, p->data + ret + 1, (DATA_MAX - ret) * sizeof(p->data[0]));
	p->dataSize--;
	printf("删除成功!\n");
	printf("\n");

}
void ModifyContact(contact* p) {
	assert(p);
	if (!p->dataSize) {
		printf("当前通讯录为空，无法修改!\n");
		printf("\n");
		return;
	}
	int ret = FindContact(p);
	if (ret == -1) {
		printf("查找不到该联系人!\n");
		printf("\n");
		return;
	}
	printf("开始重新录入该联系人信息:>\n");
	printf("请输入姓名:>");
	scanf("%s", p->data[ret].name);
	printf("请输入性别:>");
	scanf("%s", p->data[ret].sex);
	printf("请输入年龄:>");
	scanf("%d", &(p->data[ret].age));
	printf("请输入住址:>");
	scanf("%s", p->data[ret].addr);
	printf("请输入电话号码:>");
	scanf("%s", p->data[ret].num);
	printf("修改成功！\n");

}
void ShowContact(contact* p) {
	assert(p);
	if (!p->dataSize) {
		printf("                （空）                    \n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "姓名", "性别", "年龄", "住址", "电话");
	for (int i = 0; i < p->dataSize; i++) {
		printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].addr, p->data[i].num);
	}
	printf("\n");
}
int cmp_byage(void const* e1, void const* e2) {
	return ((peoInfor*)e1)->age-((peoInfor*)e2)->age;
}
int cmp_bysex(void const * e1, void const * e2) {
	return strcmp(((peoInfor*)e1)->sex, ((peoInfor*)e2)->sex);
}
int cmp_byaddr(void const* e1, void const* e2) {
	return strcmp(((peoInfor*)e1)->addr, ((peoInfor*)e2)->addr);
}
int cmp_byname(void const* e1, void const* e2) {
	return strcmp(((peoInfor*)e1)->name, ((peoInfor*)e2)->name);
}
int cmp_bynum(void const* e1, void const* e2) {
	return strcmp(((peoInfor*)e1)->num, ((peoInfor*)e2)->num);
}
void SortContact(contact* p) {
	int input;
	if(!p->dataSize)
		printf("当前通讯录为空，无需排序!\n");
	assert(p);
	do {
		printf("1.年龄    2.性别  \n");
		printf("3.地址    4.电话  \n");
		printf("5.姓名    0.返回  \n");
		printf("请选择排序方式:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			qsort(p->data, p->dataSize, sizeof(p->data[0]), cmp_byage);
			break;
		case 2:
			qsort(p->data, p->dataSize, sizeof(p->data[0]), cmp_bysex);
			break;
		case 3:
			qsort(p->data, p->dataSize, sizeof(p->data[0]), cmp_byaddr);
			break;
		case 4:
			qsort(p->data, p->dataSize, sizeof(p->data[0]), cmp_bynum);
			break;
		case 5:
			qsort(p->data, p->dataSize, sizeof(p->data[0]), cmp_byname);
			break;
		case 0:
			break;
		default:
			printf("输入错误,重新输入:>");
		}
		if (!input )break;
		else
			printf("排序成功!\n");
	} while (input > 5 || input < 1);
}



