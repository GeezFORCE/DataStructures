// Works for both Binary Tree and BST, BST has a better solution.
struct Node{
    int value;
    Node *left;
    Node *right;
};

Node *lca(Node *root, int n1, int n2){
    if(!root)
        return NULL;
    if(root->value == n1 || root->value == n2)
        return root;
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);
    if(!left && !right)
        return NULL;
    if(left && right)
        return root;
    return !left ? right: left;
}