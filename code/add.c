#include "all.h"

Node add(Node root, char* plate_number, char* firstname, char* lastname)
{       if(root==NULL)//if the root is NULL, add the given information to the root according to their position, and return root
        {       root=malloc(sizeof(struct node));
                root->plate=malloc(sizeof(plate_number));
                strcpy(root->plate,plate_number);
                root->first=malloc(sizeof(firstname));
                strcpy(root->first,firstname);
                root->last=malloc(sizeof(lastname));
                strcpy(root->last,lastname);
                return (root);
        }
        if(strcmp(root->plate,plate_number)<0)//if the given platenumber is larger then the root plate, then add to the right-sub-tree, and return root
        {       root->right=add(root->right,plate_number,firstname,lastname);
                return(root);
        }
        else
        {       root->left=add(root->left,plate_number,firstname,lastname);//or else, add to the left-sub-tree, and return root
                return(root);
        }
}

