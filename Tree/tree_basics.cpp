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
    cout << endl;
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
    cout << endl;
    return 0;
}