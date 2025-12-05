#ifndef SYSTEMTOOL_H
#define SYSTEMTOOL_H
extern char g_menu[];
extern int g_flag;
void clsToMenu(char menu[]);
int getVarWithCMD(int* month, int* day, int argc, char** argv);
#endif // !SYSTEMTOOL_H
//全局变量定义在源文件,头文件extern,别的文件引用它后直接用,不能定义在头文件