#include<bits/stdc++.h>
using namespace std;

void insert_heap(int a[], int index){
    int ele=a[index],i=index;
    while(i>=1 && ele>a[i/2]){
        a[i]=a[i/2];
        i/=2;
    }
    a[i]=ele;
}

int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<endl;
    int a[size];
    cout<<"Enter the heap elements : ";
    for(int i=0;i<size;i++)
        cin>>a[i];
    cout<<endl;
    for(int i=2;i<size;i++)
        insert_heap(a,i);
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}