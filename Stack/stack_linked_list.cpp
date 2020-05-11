#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *top{NULL};
int main()
{
    int choice;
    struct node *creation();
    void push();
    int pop();
    void display_stack();
    int top_stack();
    bool check_empty();
    while (1)
    {
        cout << "MENU\n"
             << "------\n"
             << "1.Insertion\n"
             << "2.Deletion\n"
             << "3.Display\n"
             << "4.Top of stack\n"
             << "5.Check if Empty\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
        {
            int res = pop();
            if (res != -1)
                cout << "Deleted Element : " << res << endl;
        }
        break;
        case 3:
            display_stack();
            break;
        case 4:
            cout << "Top of stack : " << top_stack() << endl;
            break;
        case 5:
        {
            if (check_empty())
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
        }
        break;
        default:
        {
            cout << "Invalid Choice \n";
            exit(0);
            cout << endl;
        }
        break;
        }
    }
    return 0;
}
struct node *creation()
{
    struct node *new_node = new node;
    if (new_node == NULL)
    {
        cout << "No Space Available !! Exiting \n";
        exit(0);
    }
    cout << "Enter data : ";
    cin >> new_node->data;
    cout << endl;
    new_node->link = NULL;
    return (new_node);
}
void push()
{
    struct node *new_node = creation();
    if (top != NULL)
        new_node->link = top;
    top = new_node;
}
int top_stack()
{
    return top->data;
}
bool check_empty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
void display_stack()
{
    struct node *head = top;
    while (head != NULL)
    {
        cout << " | " << head->data << " | " << endl;
        head = head->link;
    }
    cout << "----" << endl;
}
int pop()
{
    bool check_empty();
    struct node *temp = top;
    int item;
    if (check_empty())
    {
        cout << "No element to delete" << endl;
        return -1;
    }
    else
    {
        item = top->data;
        top = top->link;
        free(temp);
        return item;
    }
}