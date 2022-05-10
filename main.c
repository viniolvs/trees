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

    d.info = 8;
    root = insertSearchTree(root, d);
    d.info = 3;
    root = insertSearchTree(root, d);
    d.info = 1;
    root = insertSearchTree(root, d);
    d.info = 5;
    root = insertSearchTree(root, d);
    d.info = 6;
    root = insertSearchTree(root, d);
    d.info = 7;
    root = insertSearchTree(root, d);
    d.info = 11;
    root = insertSearchTree(root, d);
    d.info = 9;
    root = insertSearchTree(root, d);
    d.info = 10;
    root = insertSearchTree(root, d);
    d.info = 14;
    root = insertSearchTree(root, d);
    d.info = 12;
    root = insertSearchTree(root, d);
    d.info = 15;
    root = insertSearchTree(root, d);
    d.info = 13;
    root = insertSearchTree(root, d);

    
    printTree(root, getHeight(root));
    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    Node *ptr = root;
    ptr = minimum(ptr->left);

    d.info = 11;
    deleteSearchTree(d, root);
    printTree(root,getHeight(root));

    printData(*ptr->data);
    printf("\n");

    return 0;
}
