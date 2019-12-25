#include <stdio.h>
#include "backend.h"
#include <stdlib.h>

void print_info()
{
    CLEARPAGE;
    printf("+ ——————————————————————————————————+\n");
    printf("|           图书信息管理系统           |\n");
	printf("+ ——————————————————————————————————+\n");
	printf("1 列出所有图书\n2 查询指定图书\n3 排序图书\n4 添加记录\n5 删除记录\n6 清空图书列表\n7 从文件读取列表/写入当前列表到文件\n0 退出\n\n请选择：");
}

void OutputLabel()
{
    printf("Index       ISBN       name    Author    YYYY/MM/DD    Price\n");
}

void OutputPagePrompt()
{
    printf("Press w for previous page.\n");
    printf("Press s for next page.\n");
    printf("Press any other key to return to menu.\n");
}

