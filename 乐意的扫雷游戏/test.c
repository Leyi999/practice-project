#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include"infor.h"

int main() {
	srand((unsigned int)time(NULL));
	int input;
	do {
		menu();
		printf("��ѡ�����:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 2:
			INFOR();
			break;
		default:
			printf("������� ��������\n");
		}

	} while (input);

	return 0;
}