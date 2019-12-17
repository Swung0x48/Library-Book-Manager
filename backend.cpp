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
    struct Date date;
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

void InputBookInfo(FILE * file, struct Book * cur)
{
    fscanf(file, "%s", cur->ISBN);
    fscanf(file, "%s", cur->name);
    fscanf(file, "%s", cur->author);
    fscanf(file, "%d", &cur->date.year);
    fscanf(file, "%d", &cur->date.month);
    fscanf(file, "%d", &cur->date.day);
    fscanf(file, "%lf", &cur->price);
}

void OutputList(FILE * file, struct Book * head)
{
    for (struct Book * cur = head; cur != NULL; cur = cur->next)
    {
        fprintf(file, "%s %s %s %d/%d/%d\n", cur->ISBN, cur->name, cur->author, cur->date.year, cur->date.month, cur->date.day);
    }
    fprintf(file, "0");
}


struct Book * CreateList(FILE * file)
{
    struct Book *cur,
                *head;

    int tmp;
    fscanf(file, "%d", &tmp);

    if (head == NULL)
    {
        if (tmp != 0)
        {
            cur = (struct Book *) malloc(sizeof(struct Book));
            head = cur;
            cur->num = tmp;
            InputBookInfo(file, cur);
            fscanf(file, "%d", &tmp);
        }
        else
            return NULL;
        }
    else
    {
        while (tmp != 0)
        {
            cur->next = (struct Book *) malloc(sizeof(struct Book));
            cur = cur->next;
            cur->num = tmp;
            InputBookInfo(file, cur);

            fscanf(file, "%d", &tmp);
        }
    }


    return head;
}

