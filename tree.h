#include "Data.h"

#ifndef NODE_T
#define NODE_T

typedef struct Node
{
    struct Node *left;  // left son
    struct Node *right; // right son
    Data *data;
    int height; 
}Node;

void printTree(Node *root, int level);

int bigger(int a, int b);

int module(int a);

int getHeight(Node *node);

void setHeight(Node *root);

void preOrder(Node *root);

void inOrder(Node *root);

void postOrder(Node *root);

Node* minimum(Node *root);

#endif