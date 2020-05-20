#include<bits/stdc++.h>
using namespace std;

void ShellSort(int a[], int size){
    int gap,key,j;
    for(gap=size/2;gap>=1;gap/=2){
        for(int i=gap;i<size;i++){
            key=a[i];
            j=i-gap; 
            while(j>=0 && key<a[j]){
                a[j+gap]=a[j];
                j-=gap;
            }
            a[j+gap]=key;
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<endl;
    int a[size];
    cout<<"Enter the elements : ";
    for (int i = 0; i < size; i++)
        cin>>a[i];
    ShellSort(a,size);
    cout<<"After Sorting : ";
    for (int i = 0; i < size; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}