//
// Created by Swung 0x48 on 2019/12/12.
// Collab with GhostYouling.
//
#include <stdio.h>
#include "ui.h"
#include "backend.h"
#include "file_io.h"
#include "kb_io.h"
#include <zconf.h>
#include <stdlib.h>


int main()
{
    struct Book * head = NULL;
    FILE * fp = NULL;
    char SortOp = '<';
	int No;


		//printf("请输入初始数据（输入结束后请键入 0）\n");

		if (READ() != NULL)
		{
			fp = READ();
		}
		else
		{
		    CLEARPAGE;
			printf("文件可能不存在，将新建一个文件。\n");
			fp = WRITE();
			fprintf(fp, "0");
			fclose(fp);

            printf("请按任意键继续...\n");
            sleep(1);
            CLEARPAGE;
		}
		// TODO : 如果不存在,要求用户用键盘输入数据。 否则，从文件读出数据 
		// 用 CreateList()
		

		if (fp == NULL)
		{
			head = CreateList(stdin);
		}
		else
		{
			head = CreateList(fp);
		}
		
		
		
        //print_info();


    while (1)
    {
        print_info();
		char sit;
		sit=getchar();
		CLEARPAGE;

		switch(sit)
		{
			case '1':		//列出所有图书
				if (head != NULL)
					OutputListToScreen(head);
				else
				{
					printf("图书列表是空的...\n");
					printf("将返回主菜单...\n");
					sleep(1);
				}
				

			break;

			case '2':		//查询指定图书

				printf("请输入图书编号\n");
				scanf("%d",&No);
				printf("以下是查询到的图书：\n");
				QueryByNo(stdout, head, No);
			

			break;

			case '3':		//排序图书
			    getchar();
				printf("请选择进行升序或者降序排列。升序请键入'<'，降序为'>'，其他按键返回主菜单。\n");
				printf("当前为 ");
                if(SortOp == '<')
                    printf("升序\n");
                else if (SortOp == '>')
                    printf("\n");


				SortOp = getchar();

				if(SortOp == '<')
				{
                    printf("已更改为升序\n");
                    BubbleSortByNo(head, '<');
                    CLEARPAGE;
                }
				else if (SortOp == '>')
				{
                    printf("已更改为降序\n");
                    BubbleSortByNo(head, '>');
                    CLEARPAGE;
                }

				else
					break;
				
				
			break;

			case '4':		//添加记录
				printf("请依次输出各书的编号、ISBN、书名、作者名、购买日期、价格，用空格隔开。\n");
				printf("用回车结束一本书的输入。另起一行输入0回车表示结束输入。\n");
				head = AddBooks(stdin, head);
				if (SortOp == '<')
					BubbleSortByNo(head, '<');
				else if (SortOp == '>')
					BubbleSortByNo(head, '>');

			break;

			case '5':		//删除记录

				printf("请输入图书编号\n");
				scanf("%d",&No);
				head = DeleteBooksByNo(head, No);
                if (SortOp == '<')
                    BubbleSortByNo(head, '<');
                else if (SortOp == '>')
                    BubbleSortByNo(head, '>');

			break;

			case '6':		//清空图书列表
			    DeleteList(head);

			break;

			case '7':		//从文件读取列表/写入当前列表到文件
			

			break;
			
			case '0':		//退出
				return 0;
			break;

		}


    }

    return 0;
}
