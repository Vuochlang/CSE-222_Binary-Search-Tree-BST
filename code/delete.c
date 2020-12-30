#include "all.h"

Node delete(Node root,char *platenumber)
{       if(strcmp(root->plate,platenumber)>0)//if the plate is smaller than the root plate, call delete to the root->left and return root
        {       root->left=delete(root->left,platenumber);
                return(root);
        }
        if(strcmp(root->plate,platenumber)<0)//if the plate is larger than the root->plate, call delete to the root->right and return root
        {       root->right=delete(root->right,platenumber);
                return(root);
        }
        if(strcmp(root->plate,platenumber)==0)//if the plate is equal to the root->plate
        {       //first case, if the root has no left child
		if(root->left==NULL)//when the root does not hasve left-child, set the new-root to be the root->right and free old-root and return new-root
                {       Node temp=root->right;
                        free(root->plate);
			free(root->first);
			free(root->last);
			free(root);
                        return(temp);
                }
		//second case, if the root->left has no right child
                Node LeftSubTree=root->left;//make a pointer for the root->left
                if(LeftSubTree->right==NULL)//if the root->left->right is NULL, set the root->left->right to be root->right, free old-root and return pointer
                {       LeftSubTree->right=root->right;
                        free(root->plate);
                        free(root->first);
                        free(root->last);
			free(root);
                        return(LeftSubTree);
                }
		//third case, when the root has both childs
                Node PriorTree=LeftSubTree;//pointer for root->left
                Node current=LeftSubTree->right;//pointer for root->left->right
                while(current->right!=NULL)//loop to go through the tree until it reaches the last level of the tree
                {       PriorTree=current;
                        current=current->right;
                }
                PriorTree->right=current->right;//change the connection between the childs
                current->left=LeftSubTree;
                current->right=root->right;
                free(root->plate);//free the information fo the plate that need to be deleted
                free(root->first);
                free(root->last);
                free(root);
                return(current);
        }
}

