struct Node{
    int value;
    Node *left;
    Node *right;
};

Node *lcaBST(Node *root, int n1, int n2){
    if(root->value > max(n1, n2))
        return lcaBST(root->left, n1, n2);
    else if(root->value < min(n1, n2) )
        return lcaBST(root->right, n1, n2);
    else
        return root;
}