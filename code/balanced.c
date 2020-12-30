#include "all.h"

//RETURN 1-as balanced
//RETURN 0-as not balanced

int balanced(Node root)
{       if(root==NULL)//if root is NULL which also means the tree is balanced
        {       return 1;
        }
        if(balanced(root->left)==1 && balanced(root->right)==1 && abs((height(root->left))-(height(root->right)))<=1)
        {       //if the different (absolute value) between the height of the left and right tree is equal to 1
		return 1;
        }
        return 0;
}

