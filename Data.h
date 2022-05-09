#ifndef DATA_T
#define DATA_T

// Data the tree holds
typedef struct Data
{
    int info;
}Data;

void printData(Data data);

void readData(Data *data);

void randomData(Data *data);

short cmpData(Data a, Data b);

#endif