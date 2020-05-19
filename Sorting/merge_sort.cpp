#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int first, int mid, int last)
{
    int lpt = first, upt = mid + 1, size = last - first + 1, j = 0, b[size];
    while (lpt < mid + 1 && upt < last + 1)
    {
        if (arr[lpt] < arr[upt])
            b[j++] = arr[lpt++];
        else
            b[j++] = arr[upt++];
    }
    while (lpt < mid + 1)
        b[j++] = arr[lpt++];
    while (upt < last + 1)
        b[j++] = arr[upt++];
    for (lpt = first, j = 0; j < size; lpt++, j++)
        arr[lpt] = b[j];

    return;
}

void merge_sort(int arr[], int first, int last)
{
    int mid;
    if (first == last)
        return;
    else
    {
        mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main()
{
    int size;
    cout << "Enter array size : ";
    cin >> size;
    cout << endl;
    int arr[size];
    cout << "Enter the elements : ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << endl;
    merge_sort(arr, 0, size - 1);
    cout << "After Sorting : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    return 0;
}