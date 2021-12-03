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
	printf("1.游戏规则\n");
	printf("2.制作信息\n");
	printf("3.奖励\n");
	printf("0.返回\n");

}
void game_rules() {
	printf("\n踩点和标记需输入对应 行和列如 第一行第一列 应该输入 \"1 1\"\n猜到雷会被炸死,恐怖至极，骨灰都找不到!!!\n踩到非雷会显示以它中心3X3矩形范围内雷的个数.\n如果显示0会自动帮你展开\n正确标记出所有雷,或者踩完所有非雷点即可获胜.\n纯手打 纯想 花了一天多的时间，水平有限还有一些意料之外bug\nthats it...\n\n");
}
void infor() {
	//printf("\n\n現在是2021年11月1日的22時零七分鐘，我在宿舍裏寫這些文字。\n當我嘗試著刻意模仿王家衛的文字風格，寫出來的感覺卻怎麼也不對。\n也許生活也是這樣，越是刻意做的事，完成起來越麻煩，越是執著要等的人，往往卻是等不到訊息。\n就像我現在寫下的這五句話一樣。\n你在2021年的11月1日，截止到此時此刻,只給我發了五條微信訊息（by now）....\n\n");
	printf(".一步一步按提示来 不然要炸\n\n");
}
void reward() {
	printf("完成1级即可获得:> ");
	//printf("《糖豆人：终极淘汰赛》!!!\n");
	printf("乐意的大拇指！！！\n");

}

void INFOR() {
	menu_in();
	int input;
	do {
		printf("请选择序号:>");
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
		}
	} while (input);





}
void SleepPrint(char*p) {
	int i;
	int len = strlen(p);
	for (i = 0; i < len; i+=2) {
		printf("%c%c", *(p + i), *(p + i + 1));
		Sleep(600);
	}
	
}
