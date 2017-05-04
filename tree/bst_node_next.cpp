#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

typedef struct node* Node;
typedef struct node node;

Node newNode(int data)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

class BSTIterator{

    
}
