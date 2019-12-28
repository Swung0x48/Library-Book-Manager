//
// Created by xingyang01 on 2019/12/16.
//
#include <stdio.h>
#include "backend.h"
#include <stdlib.h>

void print_info()
{
    CLEARPAGE;
    printf("+ ——————————————————————————————————+\n");
    printf("|           图书信息管理系统        |\n");
	printf("+ ——————————————————————————————————+\n");
	printf("1 列出所有图书\n2 查询指定图书\n3 更改排序方式\n4 添加记录\n5 删除记录\n6 清空图书列表\n7 从文件读取列表/写入当前列表到文件\n0 退出\n\n请选择：\n");
}

void OutputLabel()
{
    printf("Index       ISBN       name    Author    YYYY/MM/DD    Price\n");
}

void OutputPagePrompt()
{
    printf("输入w向前一页。\n");
    printf("输入s向后一页。\n");
    printf("输入任意其他按键返回主界面。\n");
}

void FilePrompt()
{
    printf("1 从文件读取列表\n2 写入列表到文件\n\n请选择：\n");
    getchar();
}