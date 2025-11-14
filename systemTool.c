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
