#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50;
class two_stack
{
    int *stk, top1, top2;

public:
    two_stack()
    {
        stk = new int[SIZE];
        top1 = -1;
        top2 = SIZE;
    }
    void push(int data, int stack_no)
    {
        if (top1 < top2 - 1)
        {
            if (stack_no == 1)
                stk[++top1] = data;
            else
                stk[--top2] = data;
        }
        else
        {
            cout << "Overflow" << endl;
            return;
        }
    }
    int pop(int stack_no)
    {
        int data;
        if (stack_no == 1)
        {
            if (top1 == -1)
            {
                cout << "No element to delete" << endl;
                return -1;
            }
            else
            {
                data = stk[top1];
                stk[top1] = 0;
                top1--;
                return (data);
            }
        }
        else
        {
            if (top2 == SIZE)
            {
                cout << "No element to delete" << endl;
            }
            else
            {
                data = stk[top2];
                stk[top2] = 0;
                top2++;
                return (data);
            }
        }
    }
    void display_stack(int stack_no)
    {
        if (stack_no == 1)
        {
            for (int i = top1; i >= 0; i--)
                cout << " | " << stk[i] << " | " << endl;
            cout << " ---- " << endl;
        }
        else
        {
            for (int i = top2; i < SIZE; i++)
                cout << " | " << stk[i] << " | " << endl;
            cout << " ---- " << endl;
        }
    }
};
int main()
{
    two_stack tstk;
    int determine_stack();
    int ins_data();
    int choice, data;
    while (1)
    {
        cout << "MENU\n"
             << "-------\n"
             << "1.Push\n"
             << "2.Pop\n"
             << "3.Display\n"
             << "Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            tstk.push(ins_data(), determine_stack());
            break;
        case 2:
        {
            data = tstk.pop(determine_stack());
            if (data != -1)
                cout << "Deleted Element : " << data << endl;
        }
        break;
        case 3:
            tstk.display_stack(determine_stack());
            break;
        default:
        {
            cout << "Invalid Chocie!!Exiting!!" << endl;
            exit(0);
        }
        break;
        }
    }
    return 0;
}
int determine_stack()
{
    int stack_no;
    cout << "Enter the stack no : ";
    cin >> stack_no;
    assert(1 <= stack_no <= 2);
    cout << endl;
    return stack_no;
}
int ins_data()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    cout << endl;
    return data;
}