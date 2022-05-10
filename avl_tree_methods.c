#include <stdlib.h>
#include <stdio.h>
#include "avl_tree.h"

Node* rotation_left(Node *root)
{
    Node *son = root->right;
    root->right = son->left;
    son->left = root;

    root->height = getHeight(root);
    son->height = getHeight(son);

    return son;
}

Node* rotation_right(Node *root)
{
    Node *son = root->left;
    root->left = son->right;
    son->right = root;

    root->height = getHeight(root);
    son->height = getHeight(son);

    return son;
}

Node* double_rotation_left(Node *root)
{
    root->left = rotation_right(root->left);
    return rotation_left(root);
}

Node* double_rotation_right(Node *root)
{
    root->right = rotation_left(root->right);
    return rotation_right(root);
}

Node* balanceAVL(Node *root)
{
    int L,R;
	if(root == NULL)
		return root;
	else
	{
		L = getHeight(root->left);
		R = getHeight(root->right);
		
		if((module (L - R)) >= 2)
		{
			if(R > L) //Lado direito maior
            {
                if(root->right!=NULL && root->right->left!=NULL)
                    root = double_rotation_left(root);
                else
                    root = rotation_left(root);

            }
			else //Lado esquerdo maior
            {
                if(root->left!=NULL && root->left->right!=NULL)
                    root = double_rotation_right(root);
                else
				    root = rotation_right(root);
            }
		}
		return root;
	}
}

//DOESNT WORK IN ALL CASES YET
Node* insertAVL(Node *root, Data data)
{
	Node *new;
	//Verifica se a raiz é nula
	if (root == NULL)
	{
		new = (Node*)malloc(sizeof(Node));
		if (new==NULL)
		{
			printf("Malloc error\n");
			return NULL;
		}
        new->data = (Data*)malloc(sizeof(Data));
        new->data->info = data.info;
        new->height = getHeight(new);
        new->left = NULL;
        new->right = NULL;
        return new;
	}

	//go left
	else if (cmpData(data, *root->data) == 2)
	{
		root->left = insertAVL(root->left, data);
        root = balanceAVL(root);
		return root;
	}
	//go right
	else
	{
		root->right = insertAVL(root->right, data);
        root = balanceAVL(root);
		return root;
	}	
}