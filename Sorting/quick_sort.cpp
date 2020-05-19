#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int first, int last)
{
    int pivot = a[first], down = first, up = last, temp;
    while (down < up)
    {
        while (a[down] <= pivot && down < last)
            down++;
        while (a[up] > pivot)
            up--;
        if (down < up)
        {
            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }
    a[first] = a[up];
    a[up] = pivot;
    return up;
}

void quick_sort(int a[], int first, int last)
{
    int pos;
    if (first > last)
        return;

    pos = partition(a, first, last);
    quick_sort(a, first, pos - 1);
    quick_sort(a, pos + 1, last);
    return;
}

int main()
{
    int size;
    cout << "Enter size : ";
    cin >> size;
    cout << endl;
    int a[size];
    cout << "Enter elements : ";
    for (int i = 0; i < size; i++)
        cin >> a[i];
    cout << endl;
    quick_sort(a, 0, size - 1);
    cout << "After Sorting : ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}