#include <bits/stdc++.h>
using namespace std;
int main()
{
    void binary_search(vector<int>);
    int size, item;
    vector<int> v;
    cout << "Enter the size : ";
    cin >> size;
    cout << endl;
    cout << "Enter the data : ";
    while (size--)
    {
        cin >> item;
        v.push_back(item);
    }
    binary_search(v);
    return 0;
}
void binary_search(vector<int> v)
{
    int ele,first=0,last=v.size()-1,mid=last/2;
    cout << "Enter element to be searched : ";
    cin >> ele;
    cout << endl;
    while(first<v.size()){
        mid=(first+last)/2;
        if(ele==v.at(mid)){
            cout<<"Item found at index "<<mid+1<<endl;
            return;
        }
        else if(ele<v.at(mid))
            last=mid-1;
        else if(ele>v.at(mid))
            first=mid+1;
    }
    cout<<"Element not found"<<endl;
}