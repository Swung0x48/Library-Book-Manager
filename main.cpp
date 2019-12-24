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

    while (1)
    {
        print_info();

        head = CreateList(stdin);
        BubbleSortByNo(head, '<');
        OutputListToScreen(head);

        printf("\n");

        return 0;
    }


}
