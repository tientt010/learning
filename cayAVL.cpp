#include<iostream>
#define COUNT 10
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node *root){
    if(root==NULL)return 0;
    //return 1+max(getHeight(root->left),getHeight(root->right));
    return root->height;
}

Node* leftRotate(Node *root){
    Node *p=root->left;
    root->left=p->right;
    p->right=root;
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    p->height=1+max(getHeight(p->left),getHeight(p->right));
    return p;
}

Node* rightRotate(Node *root){
    Node *p=root->right;
    root->right=p->left;
    p->left=root;
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    p->height=1+max(getHeight(p->left),getHeight(p->right));
    return p;
}

Node* Insert(Node *root,int value){
    if(root==NULL)
        return new Node{value,NULL,NULL,1};
    if(value>root->data)
        root->right=Insert(root->right,value);
    else if(value<root->data)
        root->left=Insert(root->left,value);
    else 
        return root;
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int valBalance=getHeight(root->left)-getHeight(root->right);
    if(valBalance>1&&value<root->left->data)
        return rightRotate(root);
    if(valBalance>1&&value>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(valBalance<-1&&value>root->right->data)
        return leftRotate(root);
    if(valBalance<-1&&value<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main(){
    Node* tree = NULL;
    tree = Insert(tree, 18);
    tree = Insert(tree, 12);
    tree = Insert(tree, 30);
    tree = Insert(tree, 25);
    tree = Insert(tree, 69);
    tree = Insert(tree, 23);  
    return 0;
}