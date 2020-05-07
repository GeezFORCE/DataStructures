#include <bits/stdc++.h>
using namespace std;
int main()
{
    void bubble_sort(vector<int>);
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
    bubble_sort(arr);
    return 0;
}
void bubble_sort(vector<int> arr)
{
    void display_vector(vector<int>);
    int swap_var;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr.at(j) > arr.at(j + 1))
            {
                swap_var = arr.at(j + 1);
                arr.at(j + 1) = arr.at(j);
                arr.at(j) = swap_var;
            }
        }
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