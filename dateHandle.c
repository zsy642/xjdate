#define _CRT_SECURE_NO_WARNINGS
#include "dateHandle.h"
#include"fileHandle.h"
#include "defenceMistake.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int s_monthNum;
static int s_dayNum;

void dateHandle(int period,int specificday,int option) {
	int sum = 0;
	int MonthlyDayInTerm[12] = { 0 };
	dateFill(MonthlyDayInTerm);

	if (option == 1) {
		int specificmonth = period; //变量生命周期在大括号间,这个变量if(==2)那就用不了
		for (int i = 0; i < dateMapping(specificmonth); i++) {
			sum += MonthlyDayInTerm[i];
		}
		if (dateMapping(specificmonth) == dateMapping(s_monthNum)) {
			sum += specificday - s_dayNum + 1;
		}
		else {
			sum += specificday;
		}
		int week = 1;
		for (week = 1; 1; week++) { //for (int i = 1; 1; i++) {//c语言,函数内外变量重名的时候,内部优先,但我建议你别作,这样内部的出不来
			if (sum > 7) {
				sum -= 7;           //求这天星期几
			}
			else {
				break;
			}
		}
		printf("第%d周周%d\n", week, sum);
	}
	else if (option == 2) {
		int specificweek = period, increment = 0;
		sum = (specificweek - 1) * 7 + specificday;
		for (int i = dateMapping(s_monthNum); i < 12; i++) {
			if (sum > MonthlyDayInTerm[i]) {
				increment++;
				sum -= MonthlyDayInTerm[i];
			}
			else {
				if (increment == 0) {
					sum = sum - 1 + s_dayNum;
				}
				printf("%d月%d号\n", s_monthNum + increment, sum);
				break;
			}
		}
	}
}

void dateFill(int MonthlyDayInTerm[]) {
	char schoolStartTime[1024];  
	fileHandle(schoolStartTime);//month,day,week,现在是星期几,总共多少天
	int dayOfXjMonth[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 };//一个是长度,一个是索引.我服了//xj每个月的天数,用static数组里未定义的值是零,否则为垃圾值,后面的数组是西交这学期每个月的天数
	char year[5], month[3], day[3];
	strncpy(year, schoolStartTime + 0, 4);
	year[4] = '\0';                                     //获取年份
	strncpy(month, schoolStartTime + 4, 2);
	month[2] = '\0';
	strncpy(day, schoolStartTime + 6, 2);              //原理见字符串
	day[2] = '\0';                   //索引从0开始
	int yearNum;
	yearNum = atoi(year), s_monthNum = atoi(month), s_dayNum = atoi(day);   //你没包含他的头文件,用crtl看不了这个函数写的啥
	for (int i = 0; i < dateMapping(s_monthNum); i++) {
		MonthlyDayInTerm[i] = 0;
	}
	MonthlyDayInTerm[dateMapping(s_monthNum)] = dayOfXjMonth[dateMapping(s_monthNum)] - s_dayNum + 1;
	for (int i = 11; i > dateMapping(s_monthNum); i--) {
		MonthlyDayInTerm[i] = dayOfXjMonth[i];
	}
	if ((yearNum % 4 == 0 && yearNum % 100 != 0) || (yearNum % 400 == 0)) {
		MonthlyDayInTerm[5] += 1;
	}
}

int dateMapping(int dayOfCalendar) {
	return (dayOfCalendar + 3) % 12;
}

void dateUpdate() {
	char filepath[] = "date.txt";
	FILE* tofile = fopen(filepath, "w");
	FILE_CHECK(NULL == tofile, "日期更新出错");
	int cresult = fclose(tofile);
	FILE_CHECK(0 != cresult, "更新关闭出错");
}