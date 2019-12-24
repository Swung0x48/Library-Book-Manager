//
// Created by Swung 0x48 on 2019/12/12.
//
#include <stdio.h>
#include "ui.h"
#include "backend.h"
#include "file_io.h"
#include "kb_io.h"

struct Book * head;

int main()
{
	//testsfdafd


///test
    while (1)
    {
		printf("请输入初始数据（输入结束后请键入 0）\n");

        head = CreateList(stdin);
        BubbleSortByNo(head, '<');
        //OutputListToScreen(head);


		print_info();

        printf("\n");


		switch ()
		{
			case 1：
			{

			};
			case 2:
			{

			};
		}



        return 0;
    }


}
