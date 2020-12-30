#include "all.h"

void treeFree(Node root)//free_memory function that followed the LNR traversal pattern
{       if(root==NULL)
        return;
        treeFree(root->left);
        free(root->plate);
        free(root->first);
        free(root->last);
        treeFree(root->right);
	free(root);
}

