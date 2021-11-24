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
	printf("3.游戏首胜奖励\n");
	printf("0.都懂了（EXIT）\n");
}
void rules() {
	
	printf("1. 下棋走子 需要输入棋盘坐标，输入时用空格隔开\n");
	printf("如 想在棋盘第一行第一列走子:应输入 \"1 1\" ; 三子一线即胜利:>\n");
	printf("\n");
}
void infor() {
	printf("该游戏的对手是凝聚了乐意 目前所有的编程智慧结晶的AI副本\n"); 
	printf("难度极大，请谨慎尝试挑战，以免留下日后难以消除的心理阴影:>\n");
	printf("\n");

}
void rewards() {
	printf("若在此游戏中战胜了乐意的AI副本 定是千年难得一遇的奇才\n");
	printf("必将活得丰厚的奖励 如有胜利者，将获胜的 游戏截图和电话 地址\n");
	printf("发送至1779579409@qq.com即可获得开发者亲自邮寄的\n");
	printf("哈尔滨红场,以及俄罗斯大列巴，和一份特殊奖励\n");
	printf("奖励将在开发者受到邮件的7个工作日后发出，因为 翻墙出去采购奖品需要时间\n请耐心等待:>\n");
	printf("2021.10.30 更新,收疫情影响，奖励发出的时间可能不定期延迟\n请耐心等待:>\n");

	printf("\n");


}