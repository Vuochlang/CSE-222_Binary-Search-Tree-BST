#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
        char *plate;
        char *first;
        char *last;
        struct node *left;
        struct node *right;
        };

typedef struct node* Node;

Node add(Node, char *, char*, char*);
void nodeDump(Node);
void LNR(Node);
void NLR(Node);
void LRN(Node);
void treeFree(Node);
int search(Node, char*, char*, char*);
Node delete(Node,char*);
int height(Node root);
int balanced(Node root);

