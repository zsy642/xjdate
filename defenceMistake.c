#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "defenceMistake.h"
#include <errno.h>

void defenceMistake(int* checkVar,int start ,int over,char faultTip[]) { //待检查变量,开始,结束,错误提示
	if (start > over) {
		int tem = start;
		start = over;
		over = tem;
	}
	while (1) 
	{
		while (1) {
			int result = scanf("%d", checkVar);
			if (1 == result) {
				break;
			}
			printf("数据输入错误请重新输入,%s\n",faultTip);
			cleanCache();
		}
		if ((*checkVar) <= over && (*checkVar) >= start) {
			break;
		}else{
			printf("数据输入错误请重新输入,%s\n", faultTip);
		}
	}
}

void cleanCache() {
	int result = 56789;
	while (1) {
		result = getchar();
		if (10 == result) {//回车的asc,你总不可能不按回车吧,除非程序或文件结束 不然不可能返回-1
			break;
		}
	}
}

extern int errno;
void errorNumberHandle() {
	int errnoNum = errno;
	fprintf(stderr, "错误码: %d\n", errnoNum);
	perror("错误详情");
}

void stubFunction(char functionName[]) {
	printf("%s运行正常\n", functionName);//%s告诉printf从数组[0]开始一直打印到遇到\0为止
}