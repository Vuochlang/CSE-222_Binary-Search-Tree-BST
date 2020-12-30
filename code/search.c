#include "all.h"

//return 1-when the platenumber is in the tree
//reurn 0-when the platenumber is not in the tree
int search(Node root, char*platenumber, char*firstname, char*lastname)
{       if(root==NULL)//if the root is empty
        return 0;
        if(strcmp(root->plate,platenumber)==0)//when found the platenumber
        {       return 1;
        }
        if(strcmp(root->plate,platenumber)>0)//if the given plate is smaller than the root->plate, call search on the left-side, and get the return value
        {       return(search(root->left,platenumber,firstname,lastname));
        }
        else// or else, call search on the right-side
        return(search(root->right,platenumber,firstname,lastname));
}

