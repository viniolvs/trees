#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "bin_tree.h"
#include "search_tree.h"
#include "avl_tree.h"

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    Data d;
    int i;

    d.info = 8;
    root = insertAVL(root, d);
    d.info = 3;
    root = insertAVL(root, d);
    d.info = 1;
    root = insertAVL(root, d);
    d.info = 5;
    root = insertAVL(root, d);
    d.info = 6;
    root = insertAVL(root, d);
    d.info = 7;
    /*root = insertAVL(root, d);
    d.info = 11;
    root = insertAVL(root, d);
    d.info = 9;
    root = insertAVL(root, d);
    d.info = 10;
    root = insertAVL(root, d);
    d.info = 14;
    root = insertAVL(root, d);
    d.info = 12;
    root = insertAVL(root, d);
    d.info = 15;
    root = insertAVL(root, d);
    d.info = 13;
    root = insertAVL(root, d);*/

    
    printTree(root, getHeight(root));
    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");


    return 0;
}
