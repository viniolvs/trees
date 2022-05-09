#include "bin_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printTree(Node *root, int level)
{
	int i;
	Node *bt=root;
	if (!bt)
		return;
	else
	{
		printTree(bt->right, level + 1);
		for (i = 0; i < level; i++)
			printf("---|");
		printf("%d\n", bt->data->info);
		printTree(bt->left, level + 1);
	}
}

//return the bigger number
int bigger(int a, int b)
{
    if (a>=b)
        return a;
    else 
        return b;
}

int getHeight(Node *node)
{
    Node *aux = node;
    int a,b;
    if (aux==NULL)
        return 0;
    else
    {
        a = getHeight(aux->left);
        b = getHeight(aux->right);
        return (1+bigger(a,b));
    }
}

void setHeight(Node *root)
{
    root->height = getHeight(root);
}

//creates a balanced binary tree
//random = 1 : fill tree with random data
//random = 0 : read data from terminal
Node* newBinTree(int num_node, int random)
{	
	if (num_node == 0)
		return NULL;

	int left_nodes = num_node/2;
	int right_nodes = num_node - left_nodes - 1;

    Node *new;
    Data *data;
    new = (Node*)malloc(sizeof(Node));
    data = (Data*)malloc(sizeof(Data));
    
    if(random)
        randomData(data);
    else
        readData(data);

    new->data = data;
    setHeight(new);
	new->left = newBinTree(left_nodes, random);
	new->right = newBinTree(right_nodes, random);
	
	return new;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printData(*root->data);
        preOrder(root->left);
        preOrder(root->right);    
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printData(*root->data);
        inOrder(root->right);    
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printData(*root->data);    
    }
}