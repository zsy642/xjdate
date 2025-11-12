#include "batMode.h"
#include "defenceMistake.h"
#include "dateHandle.h"
void batMode(int option , char menu[]) {
	printf("\n请输入日期,不同日期之间用回车或空格间隔,输入0 0结束返回上一级模式\n");
	int period[100] = { 0 }, specificday[100] = { 0 };
	if (option == 1) {
		for (int i = 0;; i++) {
			defenceMistake(&period[i],0, 12, "输入的月份不在正常范围");
			defenceMistake(&specificday[i], 0,31, "输入的日期参数不在正常范围");
			if (period[i] == 0 && specificday[i] == 0) {
				break;
			}
		}
		for (int i = 0; period[i] != 0 && specificday[i]!= 0; i++) {
			dateHandle(period[i], specificday[i], option);
		}
	}
	else if (option == 2) {
		for (int i = 0;; i++) {
			defenceMistake(&period[i], 0, 23, "输入的星期不在正常范围");
			defenceMistake(&specificday[i], 0, 7, "输入的日期不在正常范围");//即使是数组也别少打&
			if (period[i] == 0 && specificday[i] == 0) {
				break;
			}
		}
		for (int i = 0; period[i] != 0 && specificday[i] != 0; i++) {
			dateHandle(period[i], specificday[i], option);
		}
	}
	printf("\n%s", menu);
	//stubFunction("批处理函数");
}