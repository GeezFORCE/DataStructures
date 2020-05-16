#include <bits/stdc++.h>
using namespace std;
int main()
{
    void recursive_linear_search(vector<int> *, int, int);
    int size, item, ele;
    vector<int> *v = new vector<int>;
    cout << "Enter the size : ";
    cin >> size;
    cout << endl;
    cout << "Enter the data : ";
    while (size--)
    {
        cin >> item;
        (*v).push_back(item);
    }
    cout << "Enter element to be searched : ";
    cin >> ele;
    cout << endl;
    recursive_linear_search(v, 0, ele);
    return 0;
}
void recursive_linear_search(vector<int> *v, int j, int ele)
{
    if ((*v).at(j) == ele)
        cout << "Item found at index " << j + 1 << endl;
    else if (j == (*v).size() - 1)
        cout << "Item not found" << endl;
    else
        recursive_linear_search(v, j + 1, ele);
}