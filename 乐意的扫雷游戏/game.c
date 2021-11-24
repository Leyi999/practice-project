#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include"print.h"

//��ʼ�����̵ĺ���
void InitBoard(char Board[ROWS][COLS],int rows,int cols,char set) {
	int i;
	int j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			Board[i][j] = set;
		}
	}
}

void DisplayBoard(char Board[ROWS][COLS], int row, int col) {
	int i;
	int j;
	
	printf("��������ɨ����Ϸ��������\n");
	for (j = 0; j < 10; j++) {
		if (0 == j) {
			printf("%d  ", j);
			continue;
		}
		printf("%d ",j);
	}
	printf("\n\n");
	for (i = 1; i <=row; i++) {
		printf("%d  ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
	printf("��������ɨ����Ϸ��������\n");

}
void SetMine(char Board[ROWS][COLS], int row, int col,int nub) {	 
	int i;
	int j;
	while (nub) {
		 i = rand() % row + 1;
		 j = rand() % col + 1;
		if (Board[i][j] == '*') {
			Board[i][j] = '#';
			nub--;

		}
	}
}
char CountMine(char Board[ROWS][COLS], char show[ROWS][COLS],int row, int col) {
	char count = '0';
	int i; int j;
	for (i = row - 1; i < row + 2; i++) {

		for (j = col - 1; j < col + 2; j++) {
			
			if (Board[i][j] == '#') {
				count++;

			}
		}

	}
	return count;
	}
	

void Extend(char Board[ROWS][COLS],char show[ROWS][COLS],int row,int col){
	show[row][col] = ' ';

	int i, j;
	for (i = row - 1; i < row + 2; i++) {
		for (j = col - 1; j < col + 2; j++) {
			
			if (show[i][j] == '*') {
				show[i][j] = CountMine(Board, show, i, j);
				if (show[i][j] == '0') {
					Extend(Board, show, i, j);
				}
			}
		}
		
	}
}
int Is_win(char Board[ROWS][COLS],char show[ROWS][COLS], int row, int col,int nub) {
	int i,j;
	int count = 0;//����ȷ�ı��
	int count0 = 0;//����ǵ��ܸ���
	int COUNT = 0;//��*�ź������׵ĸ���
	int COUNT0 = 0;//��*�ŵ��ܸ���
	for (i = 1; i <=row; i++) {
		for (j = 1; j <= col; j++) {
			if (show[i][j] == '!') {
				count0++;
				if (Board[i][j] == '#') {
					count++;
				}
			}if (show[i][j] == '*') {
				COUNT0++;
				if (Board[i][j] == '#') {
					COUNT++;


				}
			}
		}
	}
	if ((nub == count&&nub==count0)|| COUNT == COUNT0) {
		return 1;
	}
	else if (nub == count && nub <= count0) {
		return 2;
	}
	
	return 0;
}

char FindMine(char Board[ROWS][COLS],char show[ROWS][COLS], int row,int col,int nub) {
	int a, b;
	int input=1;
	while (1) {
		printf("��ѡ����Ҫ��(1)����Ҫ���(2):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1://��
			printf("������Ҫ�ߵ�����:>");
			while (1) {
				scanf("%d %d", &a, &b);
				if (a > 0 && a < 10 && b>0 && b < 10) {
					if (show[a][b] != '*' && show[a][b] != '!') {
						printf("����� (%d��%d��) �Ѿ��ȹ���,��������:>", a, b);
						continue;
					}
					break;
				}
				else
					printf("���������������:>");
			}
			if (Board[a][b] == '#') {
				return 'F';

			}
			else {
				show[a][b] = CountMine(Board, show, a, b);
				if (show[a][b] == '0') {
					Extend(Board, show, a, b);
				}
			}
			if (1 == Is_win(Board, show, row, col, nub)) {
				DisplayBoard(show, row, col);
				return 'W';
			}
			
			DisplayBoard(show, row, col);
		
			

			break;
		case 2://���
			printf("������Ҫ��ǵ�����:>");
			while (1) {
				scanf("%d %d", &a, &b);
				if (a > 0 && a < 10 && b>0 && b < 10) {
					if (show[a][b] == '!') {
						show[a][b] = '*';
						if (1 == Is_win(Board, show, row, col, nub)) {
							DisplayBoard(show, row, col);
							return 'W';
						}
						if (2 == Is_win(Board, show, row, col, nub)) {
							printf("��Ƕ���...");
						}
						
						break;
					}
					else {
						show[a][b] = '!';
						if (1==Is_win(Board, show, row, col,nub)) {
							return 'W';
						}
						if (2 == Is_win(Board, show, row, col, nub)) {
							printf("��Ƕ���...");
						}
						break;
					}
				}
				else {
					printf("�������,��������:>");
				}
			}
			DisplayBoard(show, row, col);
			break;
		default:
			printf("�������,��������:>");
			printf("\n");
		}
	}
	
}

void game() {
	char Board[ROWS][COLS] = { 0 };//���ú��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//�Ų���׵���Ϣ
	InitBoard(Board, ROWS, COLS, '*');
	InitBoard(show, ROWS, COLS, '*');
	printf("��ѡ����Ϸ�Ѷ�(1~3):>");
	int tmpe;
	int nub=0;
	do {
		scanf("%d", &tmpe);
		switch (tmpe)
		{
		case 1:
			nub = 10;
			break;
		case 2:
			nub = 15;
			break;
		case 3:
			nub = 20;
			break;
		default:
			printf("�������,��������:>");
			break;
		}
	} while (tmpe != 1 && tmpe != 3 && tmpe != 2);
	SetMine(Board, ROW, COL, nub);
	DisplayBoard(show, ROW, COL);
	
	char Result=FindMine(Board, show, ROW, COL,nub);
	switch (Result) {
	case 'F':
		SleepPrint("�㱻ը����");
		for (int i = 0; i < 3; i++) {
			printf(".");
			Sleep(600);
		}
		printf("\n");
		DisplayBoard(Board, ROW, COL);
		break;
	case'W':

		SleepPrint("��Ӯ��");
		for (int i = 0; i < 3; i++) {
			printf("!");
			Sleep(600);
		}
		printf("\n");
		DisplayBoard(Board, ROW, COL);
	}
}