//你能写中文注释吗,选项卡是tab,退出esc
#include <stdio.h>           //头文件包含的库主文件没必要写了
#include <stdlib.h>
#include "dateHandle.h"           //填充日期数组
#include "weekToDate.h"
#include "defenceMistake.h"
#include "batmode.h"
#include "fileHandle.h"
int main() {
	int month = 0, day = 0;
	char schoolStartTime[1024];
	printf("隐藏功能:\n0 1更新开学日期\n0 2打开校历\n0 3切换到校历转日期\n0 4批量处理模式\n\n");
	while (1)
	{
		fileHandle(schoolStartTime);//month,day,week,现在是星期几,总共多少天
		printf("请输入日期(月 日,输入0 0退出程序):\n例如:6月5日,输入6 5\n");
		fflush(stdout);
		defenceMistake(&month, 0, 12,"输入月份不在正常范围");
		defenceMistake(&day, 0, 31, "请重新输入日,无需输入月");
		if (month == 0 && day == 0) {
			return 0;
		}
		else if (month == 0 && day == 1) {
			dateUpdate();
		}
		else if (month == 0 && day == 2) {
			system("schoolcalendar.jpg");
		}
		else if (month == 0 && day == 3) {
			weekToDate();
		}
		else if (month == 0 && day == 4) {
			batmode();
		}else {
			dateHandle(month, day, 1);
		}
	}
}