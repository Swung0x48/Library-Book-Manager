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
#ifdef WINVER
    system("chcp 65001");
#endif

    //print_info();

    head = CreateList(stdin);
    BubbleSortByNo(head, '>');
    OutputList(stdout, head);

    printf("\n");

    head = DeleteBooksByNo(head, 5);
    OutputList(stdout, head);


    return 0;
}
