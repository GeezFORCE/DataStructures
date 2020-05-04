#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;
int main()
{
    struct node *creation();
    void ins_node();
    void rev_node();
    void display_node();
    int choice;
    while (1)
    {
        cout << "MENU\n"
             << "-----------\n"
             << "1.Insert\n"
             << "2.Reverse\n"
             << "3.Display\n"
             << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ins_node();
            break;
        case 2:
            rev_node();
            break;
        case 3:
            display_node();
            break;
        default:
        {
            cout << "Invalid Option!!!\tExiting!!\n";
            exit(0);
        }
        break;
        }
    }
    return (0);
}
struct node *creation()
{
    struct node *new_node = new node;
    if (new_node == NULL)
    {
        cout << "No space available!!!\t Exiting\n";
    }
    cout << "Enter the data : ";
    cin >> new_node->data;
    cout << endl;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}
void ins_node()
{
    struct node *new_node = creation();
    if (start != NULL)
    {
        new_node->next = start;
        start->prev = new_node;
        new_node->prev = NULL;
    }
    start = new_node;
}
void display_node()
{
    struct node *head = start;
    while (head != NULL)
    {
        cout << head->data << "<------>";
        head = head->next;
    }
    cout << endl;
}
void rev_node()
{
    struct node *head = start;
    struct node *tail = start;
    int l = 0, swap_var;
    while (tail->next != NULL)
    {
        tail = tail->next;
        ++l;
    }
    for (int i = l / 2; i >= 0; i--)
    {
        swap_var = head->data;
        head->data = tail->data;
        tail->data = swap_var;
        head = head->next;
        tail = tail->prev;
    }
    display_node();
}