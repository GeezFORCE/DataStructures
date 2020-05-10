#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50;
int main()
{
    void display_stack(int[], int);
    bool empty_stack(int[], int);
    int top_stack(int[], int);
    int s[SIZE], choice, top{-1};
    while (1)
    {
        cout << "MENU\n"
             << "------\n"
             << "1.Insertion\n"
             << "2.Deletion\n"
             << "3.Display\n"
             << "4.Check if Empty\n"
             << "5.Top of stack\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            top++;
            cout << "Enter the data : ";
            cin >> s[top];
            cout << endl;
        }
        break;
        case 2:
        {
            if (empty_stack(s, top))
                cout << "No Element to delete\n";
            else
            {
                cout << "Deleted Element : " << s[top] << endl;
                s[top] = 0;
                top--;
            }
        }
        break;
        case 3:
            display_stack(s, top);
            break;
        case 4:
            cout << "Top of stack is : " << top_stack(s, top) << endl;
            break;
        case 5:
        {
            if (empty_stack(s, top))
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
void display_stack(int s[], int top)
{
    bool empty_stack(int[], int);
    if (empty_stack(s, top))
        cout << "Stack is Empty\n";
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << " | " << s[i] << " | " << endl;
        }
        cout << " ---- " << endl;
    }
}
bool empty_stack(int s[], int top)
{
    if (top == -1)
        return true;
    else
        return false;
}
int top_stack(int s[], int top)
{
    return (s[top]);
}
