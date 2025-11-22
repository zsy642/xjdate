#include <stdio.h>
#include "systemTool.h"
#include <stdlib.h>
#include "defenceMistake.h"
char g_menu[] = "隐藏功能:\n0 1更新开学日期\n0 2打开校历\n0 3切换到校历转日期\n0 4批量处理模式\n0 5刷新\n\n";
void clsToMenu(char menu[])
{
	system("cls");
	printf(menu);
}

int getVarWithCMD(int* month, int* day, int argc, char** argv) {
	//argv[0]是程序名称,而且从图标进不是cmdargc会等于1
	if (argc > 1) {
		int date[2] = { 0 };
		date[0] = atoi(argv[1]);//2就是2 不是ASCII
		date[1] = atoi(argv[2]);
		if (date[0] >= 0 && date[0] <= 12) {
			*month = date[0];
			if (date[1] >= 0 && date[1] <= 31) {
				*day = date[1];
				return 0;
			}else {
				printf("数据输入错误请重新输入,请重新输入日,无需输入月\n");
			}
		}else {
			printf("数据输入错误请重新输入,输入数据不在正常范围\n");
		}
	}
	defenceMistake(month, 0, 12, "输入数据不在正常范围");
	defenceMistake(day, 0, 31, "请重新输入日,无需输入月");
	return 0;
}