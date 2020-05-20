#include <bits/stdc++.h>
using namespace std;

void CountSort(int A[], int size)
{
    int max_size = (*max_element(A, A + size)) + 1;
    int C[max_size];
    for (int i = 0; i < max_size; i++)
        C[i] = 0;
    for (int i = 0; i < size; i++)
        C[A[i]]++;
    cout << endl;
    int i = 0, j = 0;
    while (i < max_size)
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
            i++;
    }
}

int main()
{

    int n, i;
    cout << "Enter size : ";
    cin >> n;
    cout << endl;
    int A[n];
    cout << "Enter the elements : ";
    for (i = 0; i < n; i++)
        cin >> A[i];
    CountSort(A, n);
    cout << "After Sorting : ";
    for (i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}