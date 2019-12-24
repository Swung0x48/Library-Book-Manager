//
// Created by Swung 0x48 on 2019/12/16.
//

#include <stdio.h>
#include <stdlib.h>

FILE *WRITE(struct Book *p)
{
    FILE *fp;
    if((fp=fopen("Bookdata.txt","wb"))==NULL)
    {
        printf("cannot open file\n");
        return NULL;
    }
    return fp;
}


FILE *READ()
{
    FILE *fp;
    struct Book *head;
    if((fp=fopen("Bookdata.txt","wb"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    return fp;
}