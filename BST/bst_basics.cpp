#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left_child;
    node *right_child;
};
node *root = NULL;

node *creation(int data)
{
    node *new_node = new node;
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

void insertion(int data)
{
    node *p = root, *r, *ele;
    if (root == NULL)
    {
        root = creation(data);
        return;
    }
    while (p)
    {
        r = p;
        if (p->data < data)
            p = p->left_child;
        else if (p->data > data)
            p = p->right_child;
        else
            return;
    }
    ele = creation(data);
    if (data < r->data)
        r->left_child = ele;
    else
        r->right_child = ele;
}

bool search(node *p, int data)
{
    while (p)
    {
        if (p->data == data)
            return true;
        else if (p->data < data)
            p = p->left_child;
        else
            p = p->right_child;
    }
    return false;
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

bool validateBST(node *tree, node *left = NULL, node *right = NULL)
{
    if (tree == NULL)
        return true;
    if (left != NULL && tree->data < left->data)
        return false;
    if (right != NULL && tree->data >= right->data)
        return false;
    return validateBST(tree->left_child, left, tree) && validateBST(tree->right_child, tree, right);
}

int main()
{
    int choice, data;
    char ch = 'Y';
    node *temp;
    while (1)
    {
        cout << "MENU\n"
             << "--------\n"
             << "1.Insertion\n"
             << "2.Search\n"
             << "3.Display\n"
             << "4.Validate BST\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            do
            {
                cout << "Enter the data : ";
                cin >> data;
                cout << endl;
                insertion(data);
                cout << "Want to insert more? (Y or y) : ";
                scanf("%s", &ch);
            } while (ch == 'Y' || ch == 'y');
        }
        break;
        case 2:
        {
            cout << "Enter data to search : ";
            cin >> data;
            cout << endl;
            if (search(root, data))
                cout << "Found" << endl;
            else
                cout << "Not found";
        }
        break;
        case 3:
            inorder(root);
            break;
        case 4:
            cout << bool(validateBST(root)) << endl;
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}