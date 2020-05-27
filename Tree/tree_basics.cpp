#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left_child;
    node *right_child;
};
node *root = NULL;
queue<node *> q;

node *creation()
{
    node *new_node = new node;
    cin >> new_node->data;
    cout << endl;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

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

void preorder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left_child);
        preorder(p->right_child);
    }
}

void inorder(node *p)
{
    if (p)
    {
        inorder(p->left_child);
        cout << p->data << " ";
        inorder(p->right_child);
    }
}

void postorder(node *p)
{
    if (p)
    {
        postorder(p->left_child);
        postorder(p->right_child);
        cout << p->data << " ";
    }
}

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

//Count is similar to postorder
int count(node *p)
{
    int left, right;
    if (p)
    {
        left = count(p->left_child);
        right = count(p->right_child);
        return left + right + 1;
    }
    return 0;
}

int sum(node *p)
{
    int left, right;
    if (p)
    {
        left = sum(p->left_child);
        right = sum(p->right_child);
        return left + right + p->data;
    }
    return 0;
}

int count_deg_2(node *p)
{
    int left, right;
    if (p)
    {
        left = count_deg_2(p->left_child);
        right = count_deg_2(p->right_child);
        if (p->left_child && p->right_child)
            return left + right + 1;
    }
    return 0;
}

int height(node *p)
{
    int left, right;
    if (p)
    {
        left = height(p->left_child);
        right = height(p->right_child);
        if (left < right)
            return left + 1;
        else
            return right + 1;
    }
    return 0;
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
    cout << endl
         << "Number of node with degree 2 : " << count_deg_2(root);
    cout << endl
         << "Sum of nodes : " << sum(root);
    cout << endl
         << "Height of tree : " << height(root) << endl;
    return 0;
}