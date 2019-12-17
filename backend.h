//
// Created by Swung 0x48 on 2019/12/16.
//

#ifndef P1_BACKEND_H
#define P1_BACKEND_H

#include <stdio.h>

int isISBNCorrect(char ISBN[20], int WillCorrect);
void InputBookInfo(FILE * file, struct Book * cur);
void OutputList(FILE * file, struct Book * head);
struct Book * CreateList(FILE * file);



#endif //P1_BACKEND_H
