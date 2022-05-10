#include "bin_tree.h"
#include <stdio.h>
#include <stdlib.h>

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

Node* minimum(Node *root)
{
    Node *ptr = root, *l = NULL, *r = NULL, *minor = NULL;
    if (ptr->left == NULL && ptr->right == NULL)
        return ptr;
    else
    {
        if(ptr->right)
            r = minimum(ptr->right);
        if(ptr->left)
            l = minimum(ptr->left);

        if(l != NULL && r != NULL)
        {
            if(cmpData(*l->data, *r->data) == 1)
                minor = r;
            else if (cmpData(*l->data, *r->data) == 2)
                minor = l;
        }
        else if(r != NULL && l==NULL)
            minor = r;
        else
            minor = l;

        if (cmpData(*ptr->data, *minor->data) == 2)
            minor = ptr;

        return minor;
    }
}