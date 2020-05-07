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
    int swap_var, pos;
    for (int i = 0; i < arr.size() - 1; i++)
    {   pos=i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr.at(j) < arr.at(pos))
                pos = j;
        }
        swap_var = arr.at(i);
        arr.at(i) = arr.at(pos);
        arr.at(pos) = swap_var;
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