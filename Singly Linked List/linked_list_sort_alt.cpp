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
    void sort_list();
    int choice;
    while (1)
    {
        cout << "MENU\n"
             << "-------------\n"
             << "1.Insertion\n"
             << "2.Sort\n"
             << "3.Display\n"
             << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ins_node();
            break;
        case 2:
            sort_list();
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
void sort_list()
{   
    struct node *head{start};
    vector <int> contents;
    for(;head!=NULL;head=head->link)
        contents.push_back(head->data);
    sort(contents.begin(),contents.end());
    head=start;
    for(auto &i:contents){
        head->data=i;
        head=head->link;
    }
    display_node();
}
//Reversing linked list
//reverse(contents.begin(),contents.end());
/*alt output 
    for(int i=contents.size()-1;i>=0;i--){
        head->data=contents.at(i);
        head=head->link;
    }
*/