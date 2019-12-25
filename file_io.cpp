//
// Created by Swung 0x48 on 2019/12/16.
// Collab with 
//

#include <stdio.h>
#include <stdlib.h>

FILE *WRITE()
{
    FILE *fp;
    if((fp=fopen("Bookdata.txt","w+")) == NULL)
    {
        printf("无法打开文件。\n");
        return NULL;
    }
    return fp;
}


FILE *READ()
{
    FILE *fp;
    
    if((fp=fopen("Bookdata.txt","r")) == NULL)
    {
        printf("无法打开文件。\n");
        return NULL;
    }
    return fp;
}