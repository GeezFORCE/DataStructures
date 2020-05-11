#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *front{NULL}, *rear{NULL};
int main()
{
    int choice;
    struct node *creation();
    void en_queue();
    int de_queue();
    void display_queue();
    //int top_stack();
    bool check_empty();
    while (1)
    {
        cout << "MENU\n"
             << "------\n"
             << "1.Insertion\n"
             << "2.Deletion\n"
             << "3.Display\n"
             << "4.Check if Empty\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            en_queue();
            break;
        case 2:
        {
            int res = de_queue();
            if (res != -1)
                cout << "Deleted Element : " << res << endl;
        }
        break;
        case 3:
            display_queue();
            break;
        case 4:
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
void en_queue()
{
    struct node *new_node = creation();
    if (front == NULL && rear == NULL)
        front = new_node;
    if (rear != NULL)
        rear->link = new_node;
    rear = new_node;
}
bool check_empty()
{
    if (front == NULL || rear == NULL)
        return true;
    else
        return false;
}
void display_queue()
{
    struct node *head = front;
    while (head != NULL)
    {
        cout << " | " << head->data << " | " << endl;
        head = head->link;
    }
    cout << "----" << endl;
}
int de_queue()
{
    bool check_empty();
    struct node *temp = front;
    int item;
    if (check_empty())
    {
        cout << "No element to delete" << endl;
        return -1;
    }
    else
    {
        item = front->data;
        front = front->link;
        free(temp);
        return item;
    }
}