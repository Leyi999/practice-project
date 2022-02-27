
// 1000人 姓名 年龄 电话 住址 性别 
//增加 删除 查找 修改
#include"contac.h"
contact* con;
FILE* pf;

int main() {

	contact** pc = &con;
	InitContact(pc);
	LoadData(pc, &pf);
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
			break;
		case Save:
			SaveContact(pc, &pf);
			break;
		case ExitwithoutSave:
			printf("退出程序...\n");
			break;
		case ExitandSave:
			printf("保存并退出...");
			SaveContact(pc, &pf);
			break;
		default:
			printf("输入错误，重新输入!\n");
		}

	} while (input != ExitandSave && input != ExitwithoutSave);
	FreeContact(pc, &pf);
	return 0;
}