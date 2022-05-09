#include "Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printData(Data data)
{
    printf("%d ", data.info);
}

void readData(Data *data)
{
    printf("Type a number: ");
    int n;
    scanf("%d", &n);
    data->info = n;
}

void randomData(Data *data)
{
    int n = (rand())%100;
    data->info = n;
}

//return 0 if equal, 1 if a greater than b, and 2 if b greater then a
short cmpData(Data a, Data b)
{
    if(a.info == b.info)
        return 0;
    else if(a.info > b.info)
        return 1;
    else 
        return 2;
}