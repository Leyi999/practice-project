#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void sign() {
	char arr1[] = "##########  ###";
	char arr2[] = "#########  ####";
	char arr3[] = "########  #####";
	char arr4[] = "#  ####  ######";
	char arr5[] = "##  ##  #######";
	char arr6[] = "###    ########";
	Sleep(999);
	printf("%s\n", arr1);
	Sleep(600);
	printf("%s\n", arr2);	
	Sleep(600);
	printf("%s\n", arr3);	
	Sleep(600);
	printf("%s\n", arr4);
	Sleep(600);
	printf("%s\n", arr5);
	Sleep(600);
	printf("%s\n", arr6);
	Sleep(600);
	printf("\n\n\n");
}


void memu() {
	printf("*************************\n");
	printf("*********1. play*********\n");
	printf("*********0. exit*********\n");
	printf("*************************\n");
}
void game() {
	printf("�²�����(0��100):>");
	int a = rand()%100, guess;
	while (1)
	{
		scanf("%d", &guess);
		if (guess < a) {
			printf("��С��\n�ٲ²�:>");
		}
		else if (guess > a) {
			printf("�´���\n�ٲ²�:>");
		}
		else {
			printf("\n\n����,�¶���!!!\n\n");
			sign();
			break;
		}
	}
}
int main() {
	int input;
	srand((unsigned int)time(NULL));
	do {
		memu();
		printf("��ѡ�����:");
		scanf("%d",& input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�����������˳�");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
			return 0;
}
