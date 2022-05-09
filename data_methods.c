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
