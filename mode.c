//你能写中文注释吗,选项卡是tab,退出esc
//全局变量在systemTool.c
#include <stdio.h>           //头文件包含的库主文件没必要写了
#include <stdlib.h>
#include "dateHandle.h"           //填充日期数组
#include "weekToDate.h"
#include "defenceMistake.h"
#include "batmode.h"
#include "systemTool.h"
#include "fileHandle.h"
int usenum = 0;
int main(int argc,char** argv) {
	int month = 0, day = 0;
	char schoolStartTime[1024];
	clsToMenu(g_menu);
	while (1)
	{
		fileHandle(schoolStartTime);//month,day,week,现在是星期几,总共多少天
		printf("请输入日期(月 日,输入0 0退出程序):\n例如:6月5日,输入6 5\n");
		fflush(stdout);
		if(usenum==0) {
			getVarWithCMD(&month, &day, argc, argv);
		}
		if (usenum > 0) {
			defenceMistake(&month, 0, 12, "输入数据不在正常范围");
			defenceMistake(&day, 0, 31, "请重新输入日,无需输入月");
		}
		usenum++;
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
			batMode(1);
		}
		else if (month == 0 && day == 5) {
			clsToMenu(g_menu);
		}else {
			dateHandle(month, day, 1);
		}
	}
}