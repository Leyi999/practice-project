
// 1000人 姓名 年龄 电话 住址 性别 
//增加 删除 查找 修改
#include"contac.h"
contact con;
int main() {
	contact* pc = &con;
	InitContact(pc);
	int input;
	do {
		meun();
		printf("请选择序号:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			AddContact(pc);
			break;
		case 2:
			DelContact(pc);
			break;
		case 3:
			SearchContact(pc);
			break;
		case 4:
			ModifyContact(pc);
			break;
		case 5:
			SortContact(pc);
			break;
		case 6:
			ShowContact(pc);
			break;
		case 7:
			InitContact(pc);
		case 0:
			break;
		default:
			printf("输入错误，重新输入!\n");
		}

	} while (input);

	return 0;
}