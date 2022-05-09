#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "bin_tree.h"
#include "search_tree.h"

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    Data d;
    int i;
    for(i = 0; i < 20; i++)
    {    
        readData(&d);
        root = insertSearchTree(root, d);
    }

    
    printTree(root, getHeight(root));
    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    Node *ptr = root;
    ptr = minimum(ptr);
    if(ptr != NULL);
        printData(*ptr->data);

    return 0;
}
