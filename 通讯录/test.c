
// 1000�� ���� ���� �绰 סַ �Ա� 
//���� ɾ�� ���� �޸�
#include"contac.h"
contact* con;

int main() {

	contact** pc = &con;
	InitContact(pc);
	LoadData(pc);
	int input;
	do {
		meun();
		printf("��ѡ�����:>");
		scanf("%d", &input);
		switch (input) {
		case Add:
			AddContact(pc);
			break;
		case Del:
			DelContact(pc);
			break;
		case Srch:
			SearchContact(pc);
			break;
		case Moidfy:
			ModifyContact(pc);
			break;
		case Sort:
			SortContact(pc);
			break;
		case Show:
			ShowContact(pc);
			break;
		case Init:
			InitContact(pc);
			break;
		case Save:
			SaveContact(pc);
			break;
		case ExitwithoutSave:
			printf("�˳�����...\n");
			break;
		case ExitandSave:
			printf("���沢�˳�...");
			SaveContact(pc);
			break;
		default:
			printf("���������������!\n");
		}

	} while (input != ExitandSave && input != ExitwithoutSave);
	FreeContact(pc);
	return 0;
}