#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu() {
	printf("***************************\n");
	printf("*******   1. PLAY   *******\n");
	printf("*******   0. EXIT   *******\n");
	printf("*******   2. INFOR  *******\n");
	printf("***************************\n");

}
void menu_in() {
	printf("1.��Ϸ����\n");
	printf("2.������Ϣ\n");
	printf("3.����\n");
	printf("0.����\n");

}
void game_rules() {
	printf("\n�ȵ�ͱ���������Ӧ �к����� ��һ�е�һ�� Ӧ������ \"1 1\"\n�µ��׻ᱻը��,�ֲ��������ǻҶ��Ҳ���!!!\n�ȵ����׻���ʾ��������3X3���η�Χ���׵ĸ���.\n�����ʾ0���Զ�����չ��\n��ȷ��ǳ�������,���߲������з��׵㼴�ɻ�ʤ.\nthats it...\n\n");
}
void infor() {
	printf(".һ��һ������ʾ�� ��ȻҪը\n\n");
}
void reward() {
	printf("���1�����ɻ��:> ");

	printf("����Ĵ�Ĵָ������\n\n");

}

void INFOR() {
	int input;
	do {
		menu_in();
		printf("��ѡ�����:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game_rules();
			break;
		case 2:
			infor();
			break;
		case 3:
			reward();
			break;
		case 0:
			break;
		default:
			printf("������� ��������\n");//���������ʾ
		}
	} while (input);
}
