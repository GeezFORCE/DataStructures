#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;
int main()
{
    struct node *creation();
    void ins_node();
    void display_node();
    void bubble_sort();
    int choice;
    while (1)
    {
        cout << "MENU\n"
             << "-------------\n"
             << "1.Insertion\n"
             << "2.Bubble Sort\n"
             << "3.Display\n"
             << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ins_node();
            break;
        case 2:
            bubble_sort();
            break;
        case 3:
            display_node();
            break;
        default:
        {
            cout << "Invalid Option!!\t Exiting!!";
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
        cout << "No Space Available!!! Exiting!!!";
        exit(0);
    }
    cout << "Enter the data : ";
    cin >> new_node->data;
    cout << endl;
    new_node->link = NULL;
    return (new_node);
}
void ins_node()
{
    struct node *new_node = creation();
    if (start != NULL)
        new_node->link = start;
    start = new_node;
}
void display_node()
{
    struct node *head = start;
    while (head != NULL)
    {
        cout << head->data << "------>";
        head = head->link;
    }
    cout << endl;
}
void bubble_sort()
{
    struct node *curr{start}, *next{start->link};
    int swap;
    for (curr = start; curr != NULL; curr = curr->link)
    {
        for (next = curr->link; next != NULL; next = next->link)
        {
            if (curr->data > next->data)
            {
                swap = curr->data;
                curr->data = next->data;
                next->data = swap;
            }
        }
    }
    display_node();
}