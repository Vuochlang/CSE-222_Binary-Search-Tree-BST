#include "all.h"

void LNR(Node root)//Left-Node-Right function, print data from Left side, then the Node(Root), then the Right side
{       if(root==NULL)
        {       return;
        }
        LNR(root->left);
        printf("Plate: <%s> ",root->plate);
        printf("Name: %s, ",root->last);
        printf("%s\n", root->first);
        LNR(root->right);
}
////////////////////////////////////////////////////////////////////////////
void NLR(Node root)//Node-Left-Right function, print data from the Node(root), then the Left side, then the Right side
{       if(root==NULL)
        {       return;
        }
        printf("Plate: <%s> ",root->plate);
        printf("Name: %s, ",root->last);
        printf("%s\n", root->first);
        NLR(root->left);
        NLR(root->right);
}
/////////////////////////////////////////////////////////////////////////////////
void LRN(Node root)//Left-Node-Right function, print data from the Left side, then the Right side, then the Node(root)
{       if(root==NULL)
        {       return;
        }
        LRN(root->left);
        LRN(root->right);
        printf("Plate: <%s> ",root->plate);
        printf("Name: %s, ",root->last);
        printf("%s\n", root->first);
}
//////////////////////////////////////////////////////////////////////////
void nodeDump(Node root)//when user type *DUMP, main.c will call this function
{       printf("\nTREE HEIGHT: %d\n",height(root));//call height function to get the height of the tree and print it out
        if(balanced(root)==1)//call balanced function to check if the tree is balanced or not
        {       printf("BALNACED: YES\n\n");
        }
        else
        {       printf("BALANCED: NO\n\n");
        }
	//calling LNR,NLR,LRN Taversal functions
        printf("LNR TRAVERSAL:\n");
        LNR(root);
        printf("\nNLR TRAVERSAL: \n");
        NLR(root);
        printf("\nLRN TRAVERSAL:\n");
        LRN(root);
        printf("\n");
}

