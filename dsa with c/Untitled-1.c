//implementing binary search tree 

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}n;


n* create_node(int val){
    n* newnode = (n*)malloc(sizeof(n));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

n* insert_node(n* root , int val){
    if(root == NULL){
        return create_node(val);
    } else if (root->data > val){
        root->left = insert_node(root->left, val);
    } else {
        root->right = insert_node(root->right, val);
    }
    return root;
}


void inorder_traverse(n* root){
    if(root != NULL){
        inorder_traverse(root->left);
        printf(root->data);
        inorder_traverse(root->right);
    }
}

void preorder_traverse(n* root){
    if(root != NULL){
        printf(root->data);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void postorder_traverse(n* root){
    if(root != NULL){
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        printf(root->data);
    }
}


int main(){
    n *root  = NULL;
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 3);
    root = insert_node(root, 6);
    root = insert_node(root, 52);

    inorder_traverse(root);

    return 0;
}