
// 1000�� ���� ���� �绰 סַ �Ա� 
//���� ɾ�� ���� �޸�
#include"contac.h"
contact con;
int main() {
	contact* pc = &con;
	InitContact(pc);
	int input;
	do {
		meun();
		printf("��ѡ�����:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			AddContact(pc);
			break;
		case 2:
			DelContact(pc);
			break;
		case 3:
			SearchContact(pc);
			break;
		case 4:
			ModifyContact(pc);
			break;
		case 5:
			SortContact(pc);
			break;
		case 6:
			ShowContact(pc);
			break;
		case 7:
			InitContact(pc);
		case 0:
			break;
		default:
			printf("���������������!\n");
		}

	} while (input);

	return 0;
}