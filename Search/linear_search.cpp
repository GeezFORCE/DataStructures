#include <bits/stdc++.h>
using namespace std;
int main()
{
    void linear_search(vector<int>);
    int size, item;
    vector<int> v;
    cout << "Enter the size : ";
    cin >> size;
    cout << endl;
    cout << "Enter the data : ";
    while (size--)
    {
        cin >> item;
        v.push_back(item);
    }
    linear_search(v);
    return 0;
}
void linear_search(vector<int> v)
{
    int ele;
    cout << "Enter element to be searched : ";
    cin >> ele;
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ele)
        {
            cout << "Element found at index " << i + 1 << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}