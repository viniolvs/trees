#include <stdlib.h>
#include "Data.h"
#include "tree.h"

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