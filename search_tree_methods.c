#include <stdlib.h>
#include <stdio.h>
#include "Data.h"
#include "tree.h"

Node* search (Data key, Node *root)
{
    Node *ptr = root;
    while (ptr != NULL && cmpData(*ptr->data, key))
    {
        if(cmpData(*ptr->data, key) == 2)
            ptr = ptr->right;
        else    
            ptr = ptr->left;
    }
    return ptr;
}

Node* insertSearchTree(Node *root, Data data)
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
		root->left = insertSearchTree(root->left, data);
		return root;
	}
	//go right
	else
	{
		root->right = insertSearchTree(root->right, data);
		return root;
	}	
}

Node* deleteSearchTree(Data data, Node *root)
{
    Node *ptr, *son;
    
    if(root == NULL)
        return root;
    else
    { 
        //go left
        if(cmpData(data, *root->data) == 2) 
        {
            root->left = deleteSearchTree(data, root->left);
            return root;
        }
        //go right
        else if(cmpData(data, *root->data) == 1)
        {
            root->right = deleteSearchTree(data, root->right);
            return root;
        }
        else
        {
            //2 sons
            if (root->right != NULL && root->left != NULL)
            {
                ptr = minimum(root->right);
                root->data = ptr->data;
                root->right = deleteSearchTree(*root->data, root->right);
                return root;
            }
            //1 son
            else
            {
                ptr = root;
                if (root->right != NULL)
                {
                    son = root->right;
                    return son;
                }
                else if(root->left != NULL)
                {
                    son = root->left;
                    return son;
                }
                else
                {
                    free(root); 
                    return NULL;
                }
            }
        }
    }
}