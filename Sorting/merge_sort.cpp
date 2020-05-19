#include <bits/stdc++.h>
using namespace std;

int merge(int arr[100], int first, int mid, int last)
{
    int lpt = first, upt = mid + 1, size = last - first + 1, j = 0, b[size];
    while (lpt < mid + 1 && upt < last + 1)
    {
        if (arr[lpt] < arr[upt])
        {
            b[j] = arr[lpt];
            lpt++;
            j++;
        }
        else
        {
            b[j] = arr[upt];
            upt++;
            j++;
        }
    }
    while (lpt < mid + 1)
    {
        b[j] = arr[lpt];
        lpt++;
        j++;
    }
    while (upt < last + 1)
    {
        b[j] = arr[upt];
        upt++;
        j++;
    }
    for (lpt = first, j = 0; j < size; lpt++, j++)
        arr[lpt] = b[j];

    return 1;
}

int merge_sort(int arr[100], int first, int last)
{
    int mid;
    if (first == last)
        return 1;
    else
    {
        mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
        return 1;
    }
}

int main()
{
    int arr[100], size;
    cout << "Enter array size : ";
    cin >> size;
    cout << endl;
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

/*void merge(int arr[100],int first,int mid,int last){
    int n1=mid-first+1,n2=last-mid,size=last-first+1;
    int left[n1],right[n2],i;
    for(i=first;i<n1;i++)
        left[i]=arr[i];
    for(i=mid;i<n2;i++)
        left[i]=arr[i];
    i=first;
    while(i<size){
        if(left[i]<right[i]){
            arr[i]=left[i];
            i++;
        }
        else{
            arr[i]=right[i];
            i++;
        }
    }
}
*/