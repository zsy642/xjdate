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
	/*int a[2] = {0,3};
	//a[0] = atoi(argv[1]);
	//a[1] = atoi(argv[2]);
	//printf("%d\n",a[0]);
	//printf("%d\n", a[1]);*/
	//这段用来测试命令行参数的
	if (argc > 1) {
		int date[2] = { 0 };
		date[0] = atoi(argv[1]);//2就是2 不是ASCII
		date[1] = atoi(argv[2]);
		if (date[0] == 0 && date[1] == 6) {
			g_flag = 1;
			return 0;
		}
		//如果你想要这个效果把这行注释取消即可
		//printf("请输入日期(月 日,输入0 0退出程序):\n例如:6月5日,输入6 5\n");
		while (1) {
			if (date[0] >= 0 && date[0] <= 12) {
				*month = date[0];
				while (1) {
					if (date[1] >= 0 && date[1] <= 31) {
						*day = date[1];
						return 0;
					}
					else {
						printf("数据输入错误请重新输入,请重新输入日,无需输入月\n");
					}
				}
			}
			else {
				printf("数据输入错误请重新输入,输入数据不在正常范围\n");
			}
		}
	}else {
		g_flag = 1;
		return 0;
	}
}