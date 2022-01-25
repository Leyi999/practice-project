
// 1000人 姓名 年龄 电话 住址 性别 
//增加 删除 查找 修改
#include"contac.h"
contact* con;
int main() {
	contact** pc = &con;
	InitContact(pc);
	int input;
	do {
		meun();
		printf("请选择序号:>");
		scanf("%d", &input);
		switch (input) {
		case Add:
			AddContact(pc);
			break;
		case Del:
			DelContact(pc);
			break;
		case Srch:
			SearchContact(pc);
			break;
		case Moidfy:
			ModifyContact(pc);
			break;
		case Sort:
			SortContact(pc);
			break;
		case Show:
			ShowContact(pc);
			break;
		case Init:
			InitContact(pc);
		case Exit:
			break;
		default:
			printf("输入错误，重新输入!\n");
		}

	} while (input);

	return 0;
}