#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50;
int main()
{
    void display_queue(int[], int, int);
    bool empty_queue(int[], int, int);
    //int top_queue(int[], int);
    int q[SIZE], choice, front{-1}, rear{-1};
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
        {
            rear++;
            if (front == -1)
                front++;
            cout << "Enter the data : ";
            cin >> q[rear];
            cout << endl;
        }
        break;
        case 2:
        {
            if (empty_queue(q, front, rear))
                cout << "No Element to delete\n";
            else
            {
                cout << "Deleted Element : " << q[front] << endl;
                q[front] = 0;
                front++;
            }
        }
        break;
        case 3:
            display_queue(q, front, rear);
            break;
        case 4:
        {
            if (empty_queue(q, front, rear))
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
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
void display_queue(int q[], int front, int rear)
{
    bool empty_queue(int[], int, int);
    if (empty_queue(q, front, rear))
        cout << "Queue is Empty\n";
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << " | " << q[i] << " | " << endl;
        }
        cout << " ---- " << endl;
    }
}
bool empty_queue(int q[], int front, int rear)
{
    if (front == -1 || front == rear)
        return true;
    else
        return false;
}
