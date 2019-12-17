//
// Created by Swung 0x48 on 2019/12/16.
//

#include "backend.h"
#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Book
{
    int num;
    char ISBN[20];
    char name[20];
    char author[20];
    struct Date;
    double price;
    struct Book *next;
};

int isISBNCorrect(char ISBN[20], int WillCorrect)
{
    int ISBN_digit[20];

    for (int i = 0, j = 0; i < 13; i++)
    {

        if (ISBN[i] == '-');
        else if (ISBN[i] == 'X')
            ISBN_digit[j] = 'X';
        else
        {
            ISBN_digit[j] = ISBN[i] - '0';
            j++;
        }
    }

    long long sum = 0;
    int checksum = 0;
    for (int i = 0; i < 9; i++)
    {
        sum += ISBN_digit[i] * (i + 1);

    }

    checksum = sum % 11;
    if (checksum == ISBN_digit[9])
        return 1;
    else if (checksum == 10 && ISBN_digit[9] == 'X')
        return 1;
    else
    {
        if (WillCorrect == 1)
        {
            if (checksum != 10)
                ISBN[12] = checksum + '0';
            else
                ISBN[12] = 'X';

            return 0;
        }
        else
            return 0;
    }

    return 2;
}




