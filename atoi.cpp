#include<bits/stdc++.h>
using namespace std;
int my_atoi(string s){
    int result = 0;
    for(auto i = 0; i < s.length(); i++){
        result *= 10;
        result += s[i] - '0';
    }
    return result;
}

int main(){
    string s;
    cout<<"Enter num as string: ";
    cin>>s;
    cout<<my_atoi(s);
    return 0;
}