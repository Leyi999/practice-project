#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
#include"menu.h"

void Main_menu() {
	printf("*************************\n");
	printf("******1. ��ʼ����********\n");
	printf("******0. �˳�����********\n");
	printf("*************************\n");
	printf("******2. ����ʲô********\n");
}

void game() {
	//�������� ��ά����
	char Board[ROW][COL];
	//��ʼ������ - ��ʼ��Ϊ�ո�
	InitBoard(Board,ROW,COL);
	char A ;
	//��ӡ���� �� ��ӡ��������
	DisplayBoard(Board, ROW, COL);
	//�����- ʵ�ָ�ֵ�ĺ���
	while(1) {
		Player_Move(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		 A = Is_win(Board, ROW, COL);
		if (A != 'C')
			break;
		Computer_Move(Board, ROW, COL);
		Sleep(1000);
		DisplayBoard(Board, ROW, COL);
		A = Is_win(Board, ROW, COL);
		if (A != 'C')
			break;
	}
	switch (A) {
	case 'P':
		Sleep(1000);
		printf("ƽ����,����һ�Ѱ�!\n");
		break;
	case'X':
		Sleep(1000); 
		printf("��Ӯ�ˣ�������!\n");
		break;
	case'O':
		Sleep(1000); 
		printf("����Ӯ�ˣ�����!\n");
		break;
	}
}

void INFOR() {
	int input = 1;

	while (input) {
		Infor_menu();
		printf("��ѡ�����:");
		scanf("%d", &input);
		printf("\n");
		switch (input) {
		case 1:rules();
			break;
		case 2:infor();
			break;
		case 0:
			printf("�����˾�������ɣ�\n");
			game();
			break;
		default:
			printf("������Ч������������\n");

		}
	}
}
int main() {
	srand((unsigned int)time(NULL));
	int input;
	do {
		Main_menu();
		printf("��ѡ�����:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("\n��Ҫ��������\n\n");
			printf("1. ��Ҫ���Ҳ�֪����ô��\n");
			printf("2. ����Ҫ�����Ǹ���\n");
			int tmp;
			scanf(" %d", &tmp);
			switch (tmp) {
			case 1:
				INFOR();
				break;
			case 2:
				printf("��:>\n");
				game();
				break;
			}
			break;
		case 0:
			printf("�����˳�����");
			break;
		case 2:
			printf("\n����һ�� ���˹����ܶ��ĵ�������!!!\n\n");
			break;
		default:
			printf("ѡ���������������ѡ��>\n");

		}
	} while (input != 0);


	return 0;
}