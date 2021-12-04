#define _CRT_SECURE_NO_WARNINGS 1
#include"menu.h"

void Main_menu() {
		printf("*************************\n");
		printf("*********1. PLAY*********\n");
		printf("*********0. EXIT*********\n");
		printf("*************************\n");
		printf("*********2. INFOR********\n");
	}
void Infor_menu() {
	printf("1.三子棋游戏规则\n");
	printf("2.游戏简介\n");
	printf("0.都懂了（EXIT）\n");
}
void rules() {
	
	printf("1. 下棋走子 需要输入棋盘坐标，输入时用空格隔开\n");
	printf("如 想在棋盘第一行第一列走子:应输入 \"1 1\" ; 三子一线即胜利:>\n");
	printf("\n");
}
void infor() {
	printf("该游戏的对手是凝聚了作者 目前所有的编程智慧结晶的AI副本\n"); 
	printf("难度极大，请谨慎尝试挑战，以免留下日后难以消除的心理阴影:>\n");
	printf("\n");

}
