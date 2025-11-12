#include <stdio.h>
#include <stdlib.h>
#include "weekToDate.h"
#include "defenceMistake.h"
int weekToDate() {
	int week = 0, dayOfWeek = 0;
	system("cls");//清屏
	printf("您已进入新程序\n");
	printf("\n隐藏功能:\n0 0退出程序\n0 1返回默认程序\n\n");
	while (1) {
		printf("请输入校历(周 日):\n例如:第6周星期五,输入6 5\n");
		fflush(stdout);//强制刷新缓存保障printf的东西可以立即出来
		defenceMistake(&week, 0, 23, "输入周数不在正常范围");
		defenceMistake(&dayOfWeek, 0, 7, "请重新输入日,无需输入周");
		if (week == 0 && dayOfWeek == 0) {
			exit(1);
		}
		else if (week == 0 && dayOfWeek == 1) {
			system("cls");//清屏
			printf("隐藏功能:\n0 1更新开学日期\n0 2打开校历\n0 3切换到校历转日期\n\n");
			return 0;
		}
		else {
			dateHandle(week, dayOfWeek, 2);
		}
	}
}