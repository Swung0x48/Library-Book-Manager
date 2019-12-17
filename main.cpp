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

    //print_info();

    head = CreateList(stdin);
    BubbleSort(head);
    OutputList(stdout, head);
            /*
    char opt;

    opt = getchar();

    switch(opt)
    {
        case '1': OutputList(stdout, head); break;
        case '2':

        case '3':
        case '4':
        case '5':
        case '6':
        case '0':
    }
     */
    return 0;
}
