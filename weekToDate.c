#include <stdio.h>
#include <stdlib.h>
#include "weekToDate.h"
#include "batMode.h"
#include "systemTool.h"
#include "dateHandle.h"
#include "defenceMistake.h"
int weekToDate() {
	int week = 0, dayOfWeek = 0;
	system("cls");//清屏
	printf("您已进入新程序\n");
	char menu[] = "\n隐藏功能:\n0 0退出程序\n0 1返回默认程序\n0 4批量处理模式\n0 5刷新\n\n";
	printf(menu);
	while (1) {
		printf("请输入校历(周 日):\n例如:第6周星期五,输入6 5\n");
		fflush(stdout);//强制刷新缓存保障printf的东西可以立即出来
		defenceMistake(&week, 0, 23, "输入数据不在正常范围");
		defenceMistake(&dayOfWeek, 0, 7, "请重新输入日,无需输入周");
		if (week == 0 && dayOfWeek == 0) {
			exit(1);
		}
		else if (week == 0 && dayOfWeek == 1) {
			clsToMenu(g_menu);
			return 0;
		}
		else if (week == 0 && dayOfWeek == 4) {
			batMode(2);
		}
		else if (week == 0 && dayOfWeek == 5) {
			clsToMenu(menu);
		}else {
			dateHandle(week, dayOfWeek, 2);
		}
	}
}