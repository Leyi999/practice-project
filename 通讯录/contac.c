#define _CRT_SECURE_NO_WARNINGS 1
#include"contac.h"
void meun() {
	printf("******             乐意牌通讯录               *******\n");
	printf("******     1.新建联系人     2.删除联系人      *******\n");
	printf("******     3.查找联系人     4.修改联系人      *******\n");
	printf("******     5.排序联系人     6.显示全部联系人  *******\n");
	printf("******     7.格式化通讯录   8.保存            *******\n");
	printf("******              9.退出不保存              *******\n");
	printf("******              0.退出并保存              *******\n");
}
void GetMemory(contact** p) {
	assert(*p);
	contact* t = (contact*)realloc(*p, sizeof(contact) + ((*p)->MemerSize + 2) * sizeof(peoInfor));
	if (t == NULL) {
		printf("增容失败!\n");
		printf("%s", strerror(errno));
		return;
	}
	*p = t;
	(*p)->MemerSize += 2;
}
void InitContact(contact** p) {
	*p=malloc(sizeof(**p)+2*sizeof(peoInfor));
	if (*p == NULL) {
		printf("初始化失败!\n");
		printf("%s", strerror(errno));
		return;
	}
	(*p)->MemerSize = 2;
	(*p)->dataSize = 0;
}
void LoadData(contact** p, FILE** pf) {
	*pf = fopen(DataFlie_NAME, "rb");
	if (*pf == NULL) {
		printf("%s\n(若此次非本程序的首次运行，请检查%s是否遗失)\n", strerror(errno),DataFlie_NAME);
		return ;
	}
	peoInfor tmp;
	while (fread(&tmp, sizeof(peoInfor), 1, *pf)) {
		if ((*p)->dataSize == (*p)->MemerSize)
			GetMemory(p);
		(*p)->data[(*p)->dataSize++] = tmp;
	}
}
void AddContact(contact** p) {
	assert(*p);
	if ((*p)->dataSize==(*p)->MemerSize)
		GetMemory(p);
	printf("请输入姓名:>");
	scanf("%s", (*p)->data[(*p)->dataSize].name);
	printf("请输入性别:>");
	scanf("%s", (*p)->data[(*p)->dataSize].sex);
	printf("请输入年龄:>");
	scanf("%d", &((*p)->data[(*p)->dataSize].age));
	printf("请输入住址:>");
	scanf("%s", (*p)->data[(*p)->dataSize].addr);
	printf("请输入电话号码:>");
	scanf("%s", (*p)->data[(*p)->dataSize].num);
	printf("添加成功！\n");
	(*p)->dataSize++;
}
int FindContact(contact** p) {
	assert(*p);
	printf("请输入姓名:>");
	char name[NAME_MAX];
	scanf("%s",name);
	for (int i = 0; i < (*p)->dataSize; i++) {
		if (!strcmp((*p)->data[i].name,name ))
			return i;
	}
	return -1;
}
void SearchContact(contact** p) {//查找并打印联系人；
	assert(p);
	if (!(*p)->dataSize) {
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
	printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", (*p)->data[i].name, (*p)->data[i].sex, (*p)->data[i].age, (*p)->data[i].addr, (*p)->data[i].num);
	printf("\n");
}

void DelContact(contact** p) {
	assert(*p);
	if (!(*p)->dataSize) {
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
	memmove((*p)->data + ret, (*p)->data + ret + 1, ((*p)->MemerSize - ret) * sizeof(peoInfor));
	(*p)->dataSize--;
	printf("删除成功!\n");
	printf("\n");

}
void ModifyContact(contact**p) {
	assert((*p));
	if (!(*p)->dataSize) {
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
	int input;
	do {
		printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "姓名", "性别", "年龄", "住址", "电话");
		printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", (*p)->data[ret].name, (*p)->data[ret].sex, (*p)->data[ret].age, (*p)->data[ret].addr, (*p)->data[ret].num);
		printf("请选择需要修改的内容:>\n");
		printf("1.%4s\t\t2.%4s\n", "姓名", "性别");
		printf("3.%4s\t\t4.%4s\n", "年龄", "住址");
		printf("5.%4s\t\t0.%4s\n", "电话号码", "返回");
		scanf("%d", &input);

		switch (input) {
		case 0:
			break;
		case 1:
			printf("请输入姓名:>");
			scanf("%s", (*p)->data[ret].name);
			break;
		case 2:
			printf("请输入性别:>");
			scanf("%s", (*p)->data[ret].sex);
			break;
		case 3:
			printf("请输入年龄:>");
			scanf("%d", &((*p)->data[ret].age));
			break;
		case 4:
			printf("请输入住址:>");
			scanf("%s", (*p)->data[ret].addr);
			break;
		case 5:
			printf("请输入电话号码:>");
			scanf("%s", (*p)->data[ret].num);
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
		if (input)printf("修改成功！\n");
	} while (input < 0 || input>5);
}
void ShowContact(contact **p) {
	assert((*p));
	if (!(*p)->dataSize) {
		printf("                      （空）                    \n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "姓名", "性别", "年龄", "住址", "电话");
	for (int i = 0; i < (*p)->dataSize; i++) {
		printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", (*p)->data[i].name, (*p)->data[i].sex, (*p)->data[i].age, (*p)->data[i].addr, (*p)->data[i].num);
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
void SortContact(contact** p) {
	int input;
	if(!((*p)->dataSize))
		printf("当前通讯录为空，无需排序!\n");
	assert(*p);
	do {
		printf("1.年龄    2.性别  \n");
		printf("3.地址    4.电话  \n");
		printf("5.姓名    0.返回  \n");
		printf("请选择排序方式:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			qsort((*p)->data, (*p)->dataSize, sizeof((*p)->data[0]), cmp_byage);
			break;
		case 2:
			qsort((*p)->data, (*p)->dataSize, sizeof((*p)->data[0]), cmp_bysex);
			break;
		case 3:
			qsort((*p)->data, (*p)->dataSize, sizeof((*p)->data[0]), cmp_byaddr);
			break;
		case 4:
			qsort((*p)->data, (*p)->dataSize, sizeof((*p)->data[0]), cmp_bynum);
			break;
		case 5:
			qsort((*p)->data, (*p)->dataSize, sizeof((*p)->data[0]), cmp_byname);
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
void SaveContact(contact** p,FILE**pf) {
	*pf = fopen(DataFlie_NAME, "wb");
	if (*pf == NULL) {
		printf("\nSaveContact:: %s\n", strerror(errno));
		return;
	}
	fwrite((*p)->data, sizeof(peoInfor), (*p)->dataSize, *pf);

}
void FreeContact(contact** p,FILE** pf) {
	assert(*p&&*pf);
	fclose(*pf);
	*pf = NULL;
	free(*p);
	*p = NULL;
}



