#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "bin_tree.h"

int main(int argc, char const *argv[])
{
    Node *root;
    root = newBinTree(10,1);
    Data *data;
    
    printTree(root, root->height);
    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}
