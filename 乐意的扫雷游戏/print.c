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
	printf("\n�ȵ�ͱ���������Ӧ �к����� ��һ�е�һ�� Ӧ������ \"1 1\"\n�µ��׻ᱻը��,�ֲ��������ǻҶ��Ҳ���!!!\n�ȵ����׻���ʾ��������3X3���η�Χ���׵ĸ���.\n�����ʾ0���Զ�����չ��\n��ȷ��ǳ�������,���߲������з��׵㼴�ɻ�ʤ.\n���ִ� ���� ����һ����ʱ�䣬ˮƽ���޻���һЩ����֮��bug\nthats it...\n\n");
}
void infor() {
	//printf("\n\n�F����2021��11��1�յ�22�r���߷�犣����������Y���@Щ���֡�\n���҇Lԇ������ģ�������l�������L�񣬌�����ĸ��X�s���NҲ������\nҲ�S����Ҳ���@�ӣ�Խ�ǿ��������£��������Խ�韩��Խ�ǈ���Ҫ�ȵ��ˣ������s�ǵȲ���ӍϢ��\n�����ҬF�ڌ��µ��@���Ԓһ�ӡ�\n����2021���11��1�գ���ֹ���˕r�˿�,ֻ�o�Ұl����l΢��ӍϢ��by now��....\n\n");
	printf(".һ��һ������ʾ�� ��ȻҪը\n\n");
}
void reward() {
	printf("���1�����ɻ��:> ");
	//printf("���Ƕ��ˣ��ռ���̭����!!!\n");
	printf("����Ĵ�Ĵָ������\n");

}

void INFOR() {
	menu_in();
	int input;
	do {
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
