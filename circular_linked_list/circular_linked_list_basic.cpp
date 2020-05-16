//Did not implement insertions and deletions at begining and end
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *start{NULL}, *rear{NULL};
int main()
{
    struct node *creation();
    void ins_clist();
    void del_clist();
    void traversal_clist();
    int choice;
    while (1)
    {
        cout << "MENU\n"
             << "-------\n"
             << "1.Insertion\n"
             << "2.Deletion\n"
             << "3.Traversal\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            ins_clist();
            break;
        case 2:
            del_clist();
            break;
        case 3:
            traversal_clist();
            break;
        default:
        {
            cout << "Invalid Choice ! Exiting!\n";
            exit(0);
        }
        }
    }
    return 0;
}
struct node *creation()
{
    struct node *new_node = new node;
    if (new_node != NULL)
    {
        cout << "Enter the data  : ";
        cin >> new_node->data;
        cout << endl;
        new_node->link = NULL;
    }
    else
    {
        cout << "No Space Available!!" << endl;
        exit(0);
    }
}
void ins_clist()
{
    struct node *new_node = creation();
    if (start == NULL)
    {
        start = new_node;
        rear = new_node;
    }
    else
    {
        rear->link = new_node;
        new_node->link = start;
        rear = new_node;
    }
}
void traversal_clist()
{
    struct node *head = start;
    while (head->link != start)
    {
        cout << head->data << "---->";
        head = head->link;
    }
    cout << head->data << endl;
}
void del_clist()
{
    int pos;
    node *head{start}, *prev{NULL};
    cout << "Enter the position : ";
    cin >> pos;
    cout << endl;
    while (--pos)
    {
        prev = head;
        head = head->link;
    }
    prev->link = head->link;
    delete head;
}
