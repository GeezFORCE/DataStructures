#include <bits/stdc++.h>
using namespace std;
int main()
{
    int choice, ele;
    void display_queue(queue<int>);
    queue<int> qu;
    while (1)
    {
        cout << "MENU\n"
             << "-----------\n"
             << "1.Insertion\n"
             << "2.Deletion\n"
             << "3.Display\n"
             << "4.Check if Empty\n"
             << "5.Print first element\n"
             << "6.Print last element\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the element : ";
            cin >> ele;
            qu.push(ele);
        };
        break;
        case 2:
        {
            cout << "Deleted element : " << qu.front() << endl;
            qu.pop();
        };
        break;
        case 3:
        {
            cout << "The Queue is : ";
            display_queue(qu);
            cout << endl;
        }
        break;
        case 4:
        {
            if (qu.empty())
                cout << "Queue is Empty\n";
            else
                cout << "Queue is not Empty\n";
        }
        break;
        case 5:
        {
            cout << "First Element : " << qu.front() << endl;
        }
        break;
        case 6:
        {
            cout << "Last Element : " << qu.back() << endl;
        }
        break;
        default:
        {
            cout << "Exiting !! " << endl;
            exit(0);
        }
        break;
        }
    }
    return (0);
}
void display_queue(queue<int> qu)
{
    if (qu.empty())
        return;
    int x = qu.front();
    qu.pop();
    cout << x << "\t";
    display_queue(qu);
    qu.push(x);
}