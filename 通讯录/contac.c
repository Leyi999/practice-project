#define _CRT_SECURE_NO_WARNINGS 1
#include"contac.h"
void meun() {
	printf("******          ͨѶ¼          *******\n");
	printf("******     1.�½�     2.ɾ��    *******\n");
	printf("******     3.����     4.�޸�    *******\n");
	printf("******     5.����     6.��ʾ    *******\n");
	printf("******     7.���     0.�˳�    *******\n");
}
void InitContact(contact* p) {
	assert(p);
	memset(p,0, sizeof(*p));
}
void AddContact(contact* p) {
	assert(p);
	if (p->dataSize>=1000) {
		printf("ͨѶ¼�������޷����!\n");
		return;
	}
	printf("����������:>");
	scanf("%s", p->data[p->dataSize].name);
	printf("�������Ա�:>");
	scanf("%s", p->data[p->dataSize].sex);
	printf("����������:>");
	scanf("%d", &(p->data[p->dataSize].age));
	printf("������סַ:>");
	scanf("%s", p->data[p->dataSize].addr);
	printf("������绰����:>");
	scanf("%s", p->data[p->dataSize].num);
	printf("��ӳɹ���\n");
	p->dataSize++;
}
int FindContact(contact* p) {
	assert(p);
	printf("����������:>");
	char name[NAME_MAX];
	scanf("%s",name);
	for (int i = 0; i < p->dataSize; i++) {
		if (!strcmp(p->data[i].name,name ))
			return i;
	}
	return -1;
}
void SearchContact(contact* p) {//���Ҳ���ӡ��ϵ�ˣ�
	assert(p);
	if (!p->dataSize) {
		printf("��ǰͨѶ¼Ϊ��!\n");
		printf("\n");

		return;
	}
	int i = FindContact(p);
	if (i == -1) {
		printf("���Ҳ�������ϵ��!\n");
		printf("\n");

		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "����", "�Ա�", "����", "סַ", "�绰");
	printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].addr, p->data[i].num);

	printf("\n");

}

void DelContact(contact* p) {
	assert(p);
	if (!p->dataSize) {
		printf("��ǰͨѶ¼Ϊ�գ��޷�ɾ��!\n");
		return;
		printf("\n");
	}
	int ret = FindContact(p);
	if (ret == -1) {
		printf("���Ҳ�������ϵ�ˣ�ɾ��ʧ��!\n");
		printf("\n");
		return;
	}
	memmove(p->data + ret, p->data + ret + 1, (DATA_MAX - ret) * sizeof(p->data[0]));
	p->dataSize--;
	printf("ɾ���ɹ�!\n");
	printf("\n");

}
void ModifyContact(contact* p) {
	assert(p);
	if (!p->dataSize) {
		printf("��ǰͨѶ¼Ϊ�գ��޷��޸�!\n");
		printf("\n");
		return;
	}
	int ret = FindContact(p);
	if (ret == -1) {
		printf("���Ҳ�������ϵ��!\n");
		printf("\n");
		return;
	}
	printf("��ʼ����¼�����ϵ����Ϣ:>\n");
	printf("����������:>");
	scanf("%s", p->data[ret].name);
	printf("�������Ա�:>");
	scanf("%s", p->data[ret].sex);
	printf("����������:>");
	scanf("%d", &(p->data[ret].age));
	printf("������סַ:>");
	scanf("%s", p->data[ret].addr);
	printf("������绰����:>");
	scanf("%s", p->data[ret].num);
	printf("�޸ĳɹ���\n");

}
void ShowContact(contact* p) {
	assert(p);
	if (!p->dataSize) {
		printf("                ���գ�                    \n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "����", "�Ա�", "����", "סַ", "�绰");
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
		printf("��ǰͨѶ¼Ϊ�գ���������!\n");
	assert(p);
	do {
		printf("1.����    2.�Ա�  \n");
		printf("3.��ַ    4.�绰  \n");
		printf("5.����    0.����  \n");
		printf("��ѡ������ʽ:>");
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
			printf("�������,��������:>");
		}
		if (!input )break;
		else
			printf("����ɹ�!\n");
	} while (input > 5 || input < 1);
}



