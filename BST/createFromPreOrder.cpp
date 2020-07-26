#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node *creation(int data){
    node *new_node = new node;
    if(new_node){
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    return NULL;
}

node *constructTreeHelper(int pre[], int *preIdx, int low, int high, int n){
    if(*preIdx <= n || low < high){
        node *tree = creation(pre[*preIdx]);
        (*preIdx)++;
        if(low == high)
            return tree;
        int i;
        for(i = low; i <= high; i++)
            if(pre[i] > tree->data)
                break;
        tree->left = constructTreeHelper(pre, preIdx, *preIdx, i - 1, n);
        tree->right = constructTreeHelper(pre, preIdx, i , high, n);
        return tree;
    }
    return NULL;
}

node *constructTree(int pre[], int n){
    int preIdx = 0;
    return constructTreeHelper(pre, &preIdx, 0, n - 1, n);
}

void InOrder(node *p){
    if(p){
        InOrder(p->left);
        cout<<p->data<<" ";
        InOrder(p->right);
    }
}

int main(){
    int n, pre[n];
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the elements of the pre-order traversal : ";
    for(int i = 0; i < n; i++)
        cin>>pre[i];
    root = constructTree(pre, n);
    cout<<"In-Order of the constructed tree : ";
    InOrder(root);
    return 0;
}