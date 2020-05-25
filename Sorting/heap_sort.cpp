#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int size, int i){
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left < size && a[left]>a[largest])
        largest = left;
    if(right < size && a[right]>a[largest])
        largest = right;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,size,largest);
    }
}

void heap_sort(int a[], int size){
    for(int i=size/2-1;i>=0;i--)
        heapify(a,size,i);
    for(int i=size-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
    
}

int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<endl;
    int a[size];
    cout<<"Enter the elements : ";
    for(int i=0;i<size;i++)
        cin>>a[i];
    heap_sort(a,size);
    cout<<"After Sorting : ";
    for(int i=0;i<size;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
     return 0;
}