#include "all.h"

int height(Node root)
{       int leftH, rightH;
        if (root==NULL) return (-1);//if the root=NULL (tree is empty), then the height of an empty tree is (-1)
        leftH=height(root->left);//call height on the left-sub-tree
        rightH=height(root->right);//call hegiht on the right-sub-tree
        if(leftH>rightH)//if the height of the left is larger then the right, return the height of left +1 (+1 is the extra height from the given root) 
        {       return(leftH+1);
        }
        else//or else, return the height of the right +1
        return(rightH+1);
}

