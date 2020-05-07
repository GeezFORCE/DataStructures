#include <bits/stdc++.h>
using namespace std;
int main()
{
    void selection_sort(vector<int>);
    void display_vector(vector<int>);
    int size, inp;
    cout << "Enter the size: ";
    cin >> size;
    //--size;
    cout << endl;
    vector<int> arr;
    cout << "Enter the inputs : ";
    while (size--)
    { //&& size>=0){
        cin >> inp;
        arr.push_back(inp);
    }
    selection_sort(arr);
    return 0;
}
void selection_sort(vector<int> arr)
{
    void display_vector(vector<int>);
    int key, j;
    for (int i = 1; i < arr.size(); i++)
    {
        key = arr.at(i);
        j = i - 1;
        while (j >= 0 && arr.at(j) > key)
        {
            arr.at(j + 1) = arr.at(j);
            j--;
        }
        arr.at(j + 1) = key;
        cout << "At stage " << i + 1 << ":\t";
        display_vector(arr);
    }
    cout << "After Sorting \n";
    display_vector(arr);
}
void display_vector(vector<int> arr)
{
    for (auto &i : arr)
        cout << i << "\t";
    cout << endl;
}