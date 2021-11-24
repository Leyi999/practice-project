#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char Board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			Board[i][j] = ' ';
	}
}
void DisplayBoard(char Board[ROW][COL], int row, int col) {
	int r;
	int c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			printf(" % c ", Board[r][c]);
			if (c + 1 < col)
				printf("|");
		}
		printf("\n");
		printf("---|---|---\n");

	}

}
void Player_Move(char Board[ROW][COL], int row, int col) {
	printf("欣雨走:>");
	int ro, co;
	while (1) {
		scanf("%d %d", &ro, &co);
		if (ro <= row && co <= col && ro > 0 && co > 0 && Board[ro - 1][co - 1] == ' ') {
			Board[ro - 1][co - 1] = 'X';
			break;
		}
		else {
			if (!(ro <= row && co <= col && ro > 0 && co > 0))
			{
				printf("输错了 重新输入:>\n");
			}
			else
			{
				printf("这个点(%d,%d)已经有棋子了，不许叠罗汉\n",ro,co);
			}
			DisplayBoard(Board, row, col);
		}
	}
}
void Computer_Move(char Board[ROW][COL], int row, int col) {
	int ro, co;
	printf("乐意走:>\n");
	while (1) {
		ro = rand() % row;
		co = rand() % col;
		if (Board[ro][co] == ' ') {
			Board[ro][co] = 'O';
			break;
		}
	}

}
int Is_full(char Board[ROW][COL], int row, int col) {
	int i = row;
	int j = col;
	int flag = 1;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (Board[i][j] == ' ')
				flag = 0;
		}
	}
	return flag;
}
char Is_win(char Board[ROW][COL], int row, int col) {
	int i;
	int j;
	int flag_row;
	int flag_col;
	int flag_left;
	int flag_right;
	flag_row = flag_col=flag_left=flag_right= 0;
	for (i = 0; i < row; i++, flag_row = 0) {
		
		for (j = 1; j < col; j++) {
			if (' ' == Board[i][j - 1] || ' ' == Board[i][j]) {
				continue;
			}
			if (Board[i][j] == Board[i][j-1]) {
				flag_row++;
				if (flag_row == 2)
					return Board[i][j];
			}
			
		}
		
	}

	for (j = 0; j < col; j++, flag_col = 0) {

		for (i = 1; i < row; i++) {

			if (' ' == Board[i-1][j] || ' ' == Board[i][j]) {
				continue;
			}
			if (Board[i][j] == Board[i-1][j])
				flag_col++;
			if (2 == flag_col)
				return Board[i][j];
		}
		
	}
	
	for (i = 1; i < row; i++) {
		
		if ((Board[i][i] == Board[i - 1][i - 1])&&Board[i][i]!=' ') {
			flag_left++;
		}
		if (2==flag_left) {
			return Board[i][i];
		}
	}

	for (i = 1; i < row;i++) {
		//0,2 //1,1 //2,0 
		for (j = col - 2; j >= 0; j--) {
			if ((Board[i][j] == Board[i - 1][j + 1]) && Board[i][j] != ' ') {
				flag_right++;
			}
			if (2 == flag_right) {
				return Board[i][j];
			}
		}
			
		}
	
	if(Is_full(Board,row,col)){
		return 'P';
	}
	return 'C';
}

	