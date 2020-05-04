#include <bits/stdc++.h>
using namespace std;
int main()
{
    void print_stack(stack<int>);
    int choice;
    stack<int> s;
    while (1)
    {
        cout << "MENU\n"
             << "1.Insert\n"
             << "2.Delete\n"
             << "3.Display\n"
             << "4.Check if Empty\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data : ";
            cin >> data;
            s.push(data);
            cout << endl;
        }
        break;
        case 2:
        {
            int data;
            data = s.top();
            cout << "Deleted Data : " << data << endl;
            s.pop();
        }
        break;
        case 3:
        {
            cout << "Stack : "<<endl;
            print_stack(s);
            cout <<" ----- "<<endl;
        }
        break;
        case 4:{
            if(s.empty())
                cout<<"Stack is empty"<<endl;
            else
                cout<<"Stack is not empty"<<endl;
        }break;
        default:
        {
            cout << "Invalid Option! Exiting!!!";
            exit(0);
        }
        break;
        }
    }
    return (0);
}
void print_stack(stack<int> s)
{
    if (s.empty())
        return;
    int data = s.top();
    s.pop();
    cout <<" | "<< data <<" | "<<endl;
    print_stack(s);
    s.push(data);
}