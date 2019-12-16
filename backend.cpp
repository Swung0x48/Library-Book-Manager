//
// Created by Swung 0x48 on 2019/12/16.
//

#include "backend.h"
struct Date
{
    int year;
    int month;
    int day;
};
typedef Date date;

struct Book
{
    char ISBN[20];
    char name[20];
    char author[20];
    date;
    double price;
    struct Book * next;
};