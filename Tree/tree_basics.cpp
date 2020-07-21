#include <bits/stdc++.h>
using namespace std;

// Stucture of Node in the tree
struct node
{
    int data;
    node *left_child;
    node *right_child;
};
// Pointer to the root node :: GLOBAL
node *root = NULL;
queue<node *> q;

// Function to create a node to be inserted into the tree, returns a pointer to newly created node.
node *creation()
{
    node *new_node = new node;
    cin >> new_node->data;
    cout << endl;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

// Function used to create the tree, handles the insertion
void create_tree()
{
    int data;
    node *curr, *temp;
    cout << "Enter the root : ";
    root = creation();
    q.push(root);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        cout << "Enter the left child for " << curr->data << " : ";
        temp = creation();
        if (temp->data != -1)
        {
            curr->left_child = temp;
            q.push(temp);
        }
        cout << "Enter the right child for " << curr->data << " : ";
        temp = creation();
        if (temp->data != -1)
        {
            curr->right_child = temp;
            q.push(temp);
        }
    }
}

// TRAVERSALS

// Only- Recursion

// Recursive Pre-Order
void preorder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left_child);
        preorder(p->right_child);
    }
}

// Recursive In-Order
void inorder(node *p)
{
    if (p)
    {
        inorder(p->left_child);
        cout << p->data << " ";
        inorder(p->right_child);
    }
}

// Recursive Post-Order
void postorder(node *p)
{
    if (p)
    {
        postorder(p->left_child);
        postorder(p->right_child);
        cout << p->data << " ";
    }
}

// Iterative Level - Order
void levelorder(node *p)
{
    node *curr = root;
    queue<node *> qu;
    if (curr)
        cout << curr->data << " ";
    qu.push(curr);
    while (!qu.empty())
    {
        curr = qu.front();
        qu.pop();
        if (curr->left_child)
        {
            cout << curr->left_child->data << " ";
            qu.push(curr->left_child);
        }
        if (curr->right_child)
        {
            cout << curr->right_child->data << " ";
            qu.push(curr->right_child);
        }
    }
    cout << endl;
}

// Function to count the number of nodes in the tree
// Count is similar to postorder
int count(node *p)
{
    if (p)
        return count(p->left_child) + count(p->right_child) + 1;
    return 0;
}

// Function to calculate the sum of all the node values in a tree
int sum(node *p)
{
    if (p)
        return sum(p->left_child) + sum(p->right_child) + p->data;
    return 0;
}

// Count the number of nodes having degree 2
int count_deg_2(node *p)
{
    if (p)
    {
        if (p->left_child && p->right_child)
            return count_deg_2(p->left_child) + count_deg_2(p->right_child) + 1;
    }
    return 0;
}

// Count the number of leaf nodes
// To count internal nodes change condition to || instead of &&
int count_leaf_nodes(node *p)
{
    if (p)
    {
        if (p->left_child == NULL && p->right_child == NULL)
            return count_leaf_nodes(p->left_child) + count_leaf_nodes(p->right_child) + 1;
        else
            return count_leaf_nodes(p->left_child) + count_leaf_nodes(p->right_child);
    }
    return 0;
}

//  Function to Count the height of the tree
int height(node *p)
{
    if (p)
    {
        int left_height = height(p->left_child);
        int right_height = height(p->right_child);
        if (left_height < right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
    return 0;
}

// Function to invert or mirror the tree
void invertBinaryTree(node *p)
{
    if (p)
    {
        swap(p->left_child, p->right_child);
        invertBinaryTree(p->left_child);
        invertBinaryTree(p->right_child);
    }
}

// Function to find the diameter of the tree
int diameter(node *p)
{
    if (p == NULL)
        return 0;
    int left_height = height(p->left_child);
    int right_height = height(p->right_child);
    int left_diameter = diameter(p->left_child);
    int right_diameter = diameter(p->right_child);
    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}

// Function to find the sum of each branch of the tree

// Helper Function for branch Sum
void branchSumHelper(node *tree, int currentSum, vector<int> *result)
{
    if (tree)
    {
        currentSum += tree->data;
        if (tree->left_child == NULL && tree->right_child == NULL)
        {
            (*result).push_back(currentSum);
            currentSum = 0;
        }
        branchSumHelper(tree->left_child, currentSum, result);
        branchSumHelper(tree->right_child, currentSum, result);
    }
}

// Main Function for branch sums
void branchSum(node *root)
{
    int currentSum = 0;
    vector<int> branchSumList;
    branchSumHelper(root, currentSum, &branchSumList);
    for (auto i : branchSumList)
        cout << i << " ";
}

// Functions to find the Node Depths

// Helper Function
int nodeDepthsHelper(node *tree, int nodeDepthSum)
{
    if (tree)
        return nodeDepthSum + nodeDepthsHelper(tree->left_child, nodeDepthSum) + nodeDepthsHelper(tree->right_child, nodeDepthSum);
    return 0;
}
// Main Function
int nodeDepths(node *root)
{
    int nodeDepthSum = 0;
    return nodeDepthsHelper(root, nodeDepthSum);
}

int main()
{
    create_tree();
    cout << "Preorder traversal : ";
    preorder(root);
    cout << endl
         << "Inorder traversal : ";
    inorder(root);
    cout << endl
         << "Postorder traversal : ";
    postorder(root);
    cout << endl
         << "Levelorder traversal : ";
    levelorder(root);
    cout << endl
         << "Number of nodes : " << count(root);
    // cout << endl
    //    << "Number of node with degree 1 : " << count_deg_1(root);
    cout << endl
         << "Number of node with degree 2 : " << count_deg_2(root);
    cout << endl
         << "Sum of nodes : " << sum(root);
    cout << endl
         << "Height of tree : " << height(root) << endl;
    cout << endl
         << "Number of leaf nodes : " << count_leaf_nodes(root);
    cout << endl
         << "Diameter is : " << diameter(root);
    cout << endl
         << "Branch Sums : ";
    branchSum(root);
    cout << endl;
    cout << endl
         << nodeDepths(root);
    cout << endl
         << "Tree before inversion/ mirroring : ";
    levelorder(root);
    invertBinaryTree(root);
    cout << endl
         << "Tree after inversion / mirroring : ";
    levelorder(root);
    return 0;
}