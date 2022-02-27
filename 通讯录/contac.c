#define _CRT_SECURE_NO_WARNINGS 1
#include"contac.h"
void meun() {
	printf("******             ������ͨѶ¼               *******\n");
	printf("******     1.�½���ϵ��     2.ɾ����ϵ��      *******\n");
	printf("******     3.������ϵ��     4.�޸���ϵ��      *******\n");
	printf("******     5.������ϵ��     6.��ʾȫ����ϵ��  *******\n");
	printf("******     7.��ʽ��ͨѶ¼   8.����            *******\n");
	printf("******              9.�˳�������              *******\n");
	printf("******              0.�˳�������              *******\n");
}
void GetMemory(contact** p) {
	assert(*p);
	contact* t = (contact*)realloc(*p, sizeof(contact) + ((*p)->MemerSize + 2) * sizeof(peoInfor));
	if (t == NULL) {
		printf("����ʧ��!\n");
		printf("%s", strerror(errno));
		return;
	}
	*p = t;
	(*p)->MemerSize += 2;
}
void InitContact(contact** p) {
	*p=malloc(sizeof(**p)+2*sizeof(peoInfor));
	if (*p == NULL) {
		printf("��ʼ��ʧ��!\n");
		printf("%s", strerror(errno));
		return;
	}
	(*p)->MemerSize = 2;
	(*p)->dataSize = 0;
}
void LoadData(contact** p, FILE** pf) {
	*pf = fopen(DataFlie_NAME, "rb");
	if (*pf == NULL) {
		printf("%s\n(���˴ηǱ�������״����У�����%s�Ƿ���ʧ)\n", strerror(errno),DataFlie_NAME);
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
	printf("����������:>");
	scanf("%s", (*p)->data[(*p)->dataSize].name);
	printf("�������Ա�:>");
	scanf("%s", (*p)->data[(*p)->dataSize].sex);
	printf("����������:>");
	scanf("%d", &((*p)->data[(*p)->dataSize].age));
	printf("������סַ:>");
	scanf("%s", (*p)->data[(*p)->dataSize].addr);
	printf("������绰����:>");
	scanf("%s", (*p)->data[(*p)->dataSize].num);
	printf("��ӳɹ���\n");
	(*p)->dataSize++;
}
int FindContact(contact** p) {
	assert(*p);
	printf("����������:>");
	char name[NAME_MAX];
	scanf("%s",name);
	for (int i = 0; i < (*p)->dataSize; i++) {
		if (!strcmp((*p)->data[i].name,name ))
			return i;
	}
	return -1;
}
void SearchContact(contact** p) {//���Ҳ���ӡ��ϵ�ˣ�
	assert(p);
	if (!(*p)->dataSize) {
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
	printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", (*p)->data[i].name, (*p)->data[i].sex, (*p)->data[i].age, (*p)->data[i].addr, (*p)->data[i].num);
	printf("\n");
}

void DelContact(contact** p) {
	assert(*p);
	if (!(*p)->dataSize) {
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
	memmove((*p)->data + ret, (*p)->data + ret + 1, ((*p)->MemerSize - ret) * sizeof(peoInfor));
	(*p)->dataSize--;
	printf("ɾ���ɹ�!\n");
	printf("\n");

}
void ModifyContact(contact**p) {
	assert((*p));
	if (!(*p)->dataSize) {
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
	int input;
	do {
		printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "����", "�Ա�", "����", "סַ", "�绰");
		printf("%-10s\t%-5s\t%-5d\t%s\t%s\n", (*p)->data[ret].name, (*p)->data[ret].sex, (*p)->data[ret].age, (*p)->data[ret].addr, (*p)->data[ret].num);
		printf("��ѡ����Ҫ�޸ĵ�����:>\n");
		printf("1.%4s\t\t2.%4s\n", "����", "�Ա�");
		printf("3.%4s\t\t4.%4s\n", "����", "סַ");
		printf("5.%4s\t\t0.%4s\n", "�绰����", "����");
		scanf("%d", &input);

		switch (input) {
		case 0:
			break;
		case 1:
			printf("����������:>");
			scanf("%s", (*p)->data[ret].name);
			break;
		case 2:
			printf("�������Ա�:>");
			scanf("%s", (*p)->data[ret].sex);
			break;
		case 3:
			printf("����������:>");
			scanf("%d", &((*p)->data[ret].age));
			break;
		case 4:
			printf("������סַ:>");
			scanf("%s", (*p)->data[ret].addr);
			break;
		case 5:
			printf("������绰����:>");
			scanf("%s", (*p)->data[ret].num);
			break;
		default:
			printf("�����������������\n");
		}
		if (input)printf("�޸ĳɹ���\n");
	} while (input < 0 || input>5);
}
void ShowContact(contact **p) {
	assert((*p));
	if (!(*p)->dataSize) {
		printf("                      ���գ�                    \n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%s\t%s\n", "����", "�Ա�", "����", "סַ", "�绰");
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
		printf("��ǰͨѶ¼Ϊ�գ���������!\n");
	assert(*p);
	do {
		printf("1.����    2.�Ա�  \n");
		printf("3.��ַ    4.�绰  \n");
		printf("5.����    0.����  \n");
		printf("��ѡ������ʽ:>");
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
			printf("�������,��������:>");
		}
		if (!input )break;
		else
			printf("����ɹ�!\n");
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



