#ifndef DEFENCEMISTAKE_H
#define DEFENCEMISTAKE_H
#define _CRT_SECURE_NO_WARNINGS
#define FILE_CHECK(ptr,tip)	\
do{\
    if (ptr) {\
          errorNumberHandle();\
          printf("%s\n",(tip));\
          exit(-1);\
     }\
}while(0)  /*do,while没有啥含义就是个夹子,另外宏是直接替换,不是函数传参*/ 
/*原始宏定义中的 printf("tip\n") 会导致直接输出字符串 "tip"，而非传入的提示参数。
这是因为 tip 被包裹在双引号中，编译器会将其视为普通字符串，而非宏参数*/
void defenceMistake(int* checkVar, int start, int over, char faultTip[]);
void errorNumberHandle();
void cleanCache();
void stubFunction(char functionName[]);
#endif // !DEFENCEMISTAKE_H
//只能判断整数