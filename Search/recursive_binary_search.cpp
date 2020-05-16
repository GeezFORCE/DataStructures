//Partial Output
#include <bits/stdc++.h>
using namespace std;
int main()
{
    void recursive_binary_search(vector<int> *, int, int, int, int);
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
    recursive_binary_search(v, 0, (*v).size() - 1, ((*v).size() - 1) / 2, ele);
    return 0;
}
void recursive_binary_search(vector<int> *v, int first, int last, int mid, int ele)
{
    if ((*v).at(mid) == ele)
    {
        cout << "Element found at index " << mid + 1 << endl;
        return;
    }
    else if (ele < (*v).at(mid))
        last = mid - 1;
    else if (ele > (*v).at(mid))
        first = mid + 1;

    mid = (first + last) / 2;
    recursive_binary_search(v, first, last, mid, ele);
    if (first > last)
        cout << "Element not found" << endl;
}