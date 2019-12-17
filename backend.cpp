//
// Created by Swung 0x48 on 2019/12/16.
//

#include "backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Book
{
    struct Book * prev = NULL;
    int No;
    char ISBN[20];
    char name[20];
    char author[20];
    struct Date date;
    double price;
    struct Book * next = NULL;
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

void SwapNode(struct Book * * a, struct Book * * b)
{
    struct Book * tmp = NULL;
    tmp = (struct Book *) malloc(sizeof(struct Book));

    tmp->No = (*a)->No;
    (*a)->No = (*b)->No;
    (*b)->No = tmp->No;

    strcpy(tmp->ISBN, (*a)->ISBN);
    strcpy((*a)->ISBN, (*b)->ISBN);
    strcpy((*b)->ISBN, tmp->ISBN);

    strcpy(tmp->name, (*a)->name);
    strcpy((*a)->name, (*b)->name);
    strcpy((*b)->name, tmp->name);

    strcpy(tmp->author, (*a)->author);
    strcpy((*a)->author, (*b)->author);
    strcpy((*b)->author, tmp->author);

    tmp->date.year = (*a)->date.year;
    (*a)->date.year = (*b)->date.year;
    (*b)->date.year = tmp->date.year;

    tmp->date.month = (*a)->date.month;
    (*a)->date.month = (*b)->date.month;
    (*b)->date.month = tmp->date.month;

    tmp->date.day = (*a)->date.day;
    (*a)->date.day = (*b)->date.day;
    (*b)->date.day = tmp->date.day;

    tmp->price = (*a)->price;
    (*a)->price = (*b)->price;
    (*b)->price = tmp->price;

    free(tmp);
}

void InputBookInfotoStruct(FILE * fileR, struct Book * cur)
{
    fscanf(fileR, "%s", cur->ISBN);
    getchar();
    fscanf(fileR, "%s", cur->name);
    getchar();
    fscanf(fileR, "%s", cur->author);
    getchar();
    fscanf(fileR, "%d/%d/%d", &cur->date.year, &cur->date.month, &cur->date.day);
    fscanf(fileR, "%lf", &cur->price);
}

void OutputList(FILE * fileW, struct Book * head)
{
    for (struct Book * cur = head; cur != NULL; cur = cur->next)
        OutputItem(fileW, cur);
    fprintf(fileW, "0");
}

void OutputItem(FILE * fileW, struct Book * cur)
{
    fprintf(fileW, "%d %s %s %s %d/%d/%d %.2lf\n",
            cur->No,
            cur->ISBN,
            cur->name,
            cur->author,
            cur->date.year, cur->date.month, cur->date.day,
            cur->price);
}

int QueryByNo(FILE * fileR, struct Book * head, int No)
{
    for (struct Book * cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->No == No)
        {
            printf("找到1条记录\n");
            OutputItem(stdout, cur);
            return 1;
        }
    }
    return 0;
}

struct Book * CreateList(FILE * fileR)
{
    struct Book *cur = NULL,
                *head = NULL;

    int tmp;
    fscanf(fileR, "%d", &tmp);

    if (cur == NULL)
    {
        if (tmp != 0)
        {
            cur = (struct Book *) malloc(sizeof(struct Book));
            head = cur;
            cur->No = tmp;
            InputBookInfotoStruct(fileR, cur);
            fscanf(fileR, "%d", &tmp);
        }
        else
            return NULL;
    }

    while (tmp != 0)
    {
        cur->next = (struct Book *) malloc(sizeof(struct Book));
        cur->next->prev = cur;
        cur = cur->next;
        cur->No = tmp;
        InputBookInfotoStruct(fileR, cur);

        fscanf(fileR, "%d", &tmp);

    }

    return head;
}

struct Book * DeleteItem(struct Book * cur)
{
    cur->prev = cur->next;
    cur = cur->next;
    free(cur->prev);
    return cur;
}

struct Book * DeleteList(struct Book * cur)
{
    struct Book * tail;
    tail = cur;
    cur->prev = NULL;
    for (struct Book * cur = cur->next; cur != NULL; cur = cur->next)
    {
        free(cur->prev);
    }
    free(cur);

    return tail;
}


void BubbleSort(struct Book * head)
{
    for (struct Book * i = head; i->next->next != NULL; i = i->next)
    {
        for (struct Book * j = head; j != i->prev; j = j->next)   //end-loop condition has problems
        {
            if (j->No > j->next->No)
                SwapNode(&j, &(j->next));
        }
    }

}
/*struct Book * AddItem(struct Book * head)
{
    struct Book * cur;
    cur = head;

    if (cur == NULL)
    {

    }
}
*/