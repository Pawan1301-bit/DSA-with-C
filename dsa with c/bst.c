//implimentation of binary search tree ::: Time Complexity : 0(log n)
//work : file system to organise and store files, dictionaries
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}n;

n* createNode(int val){
    n* newnode = (n*)malloc(sizeof(n));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

n* insertNode(n* root , int val){
    if(root == NULL)    return createNode(val);
    else if(val < root->data){
         root->left = insertNode(root->left, val);    
    }
    else if(val > root->data){
         root->right = insertNode(root->right, val);    
    }
    return root;
}

void inorderTraverse(n* root){
    if(root != NULL){
        inorderTraverse(root->left);
        printf("%d , " ,root->data);
        inorderTraverse(root->right);
    }
}

void preorderTraverse(n* root){
    if(root != NULL){
        printf("%d , " ,root->data);
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
}

void postorderTraverse(n* root){
    if(root != NULL){
        postorderTraverse(root->left);
        postorderTraverse(root->right);
        printf("%d , " ,root->data);
    }
}

int countNode(n* root){
    if(root == NULL)    return 0;
    return countNode(root->left) + countNode(root->right)+1;
}

int countLeftNode(n* root){
    if(root == NULL || root->left == NULL) return 0;
    return countLeftNode(root->left)+countLeftNode(root->right)+1;
}
int countOnlyOneLeftNode(n* root){
            int count = 0;
            if(root->left!= NULL && root->right==NULL){
                count++;
            }
            count += countOnlyOneLeftNode(root->right);
            count += countOnlyOneLeftNode(root->left);
            return count;
}
int countOnlyOneRightNode(n* root){
            int count = 0;
            if(root->left== NULL && root->right!=NULL){
                count++;
            }
            count += countOnlyOneRightNode(root->right);
            count += countOnlyOneRightNode(root->left);
            return count;
}
int countNodeWithBothChild(n* root){
            int count = 0;
            if(root->left!= NULL && root->right!=NULL){
                count++;
            }
            count += countNodeWithBothChild(root->right);
            count += countNodeWithBothChild(root->left);
            return count ;
}
int countLeftOfRootNode(n* root){
    int count=0;
   // if(root == NULL || root->left == NULL)  return 0;
    if(root->left!=NULL)    count++;
    count += countLeftOfRootNode(root->left);
    return count;
}
//nodes having highest value
int highestValue(n* root){
    while(root!= NULL && root->right != NULL){
            root = root -> right;        
    }
    return (root!=NULL)?root->data:-1; 
}
int lowestValue(n* root){
    while(root!= NULL && root->left != NULL){
            root = root -> left;        
    }
    return (root!=NULL)?root->data:-1;
}
n* findMin(n* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
n* deleteNode(n*root , int val){
    if(root == NULL)    return root;
    if(val < root->data){
        root->left = deleteNode(root->left , val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right , val);
    } 
    else{
        if(root->left == NULL){
            n*temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            n* temp = root->left;
            free(root); 
            return temp;
        }
        //if node have 2 child:::
        n*temp = findMin(root->right);
        root->data = temp->data; 
        root->right = deleteNode(root->right , temp->data);
    }
    return root;
}

int main(){
    n* root = NULL;
    root = insertNode(root, 60);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 70);
    root = insertNode(root, 80);
    root = insertNode(root, 30);
    printf("inorder Traversing of the tree is :");
    inorderTraverse(root);
    printf("\npreorder Traversing of the tree is :");
    preorderTraverse(root);
    printf("\npostorder Traversing of the tree is :");
    postorderTraverse(root);
    printf("\n total number of nodes are : %d",countNode(root));
    printf("\nhighest value of nodes is : %d",highestValue(root));
    printf("\nlowest value of nodes is : %d",lowestValue(root));
    root = deleteNode(root , 60);
    printf("\ninorder Traversing of the tree is :");
    inorderTraverse(root);
    
    return 0;
}