#include <bits/stdc++.h>
using namespace std;

int linear(vector<int>a,int key){
    for(int i=0;i<a.size();i++)
        if(a[i]==key) return i;
    return -1;
}

int sentinel(vector<int>a,int key){
    int last=a.back();
    a.back()=key;

    int i=0;
    while(a[i]!=key) i++;

    if(i==a.size()-1 && last!=key) return -1;
    return i;
}

int main(){
    int n,key;
    cin >> n >> key;

    vector<int>a(n);
    for(int&i:a) cin >> i;

    cout<<"Linear    -> "<<linear(a,key)<<"\n";
    cout<<"Sentinel  -> "<<sentinel(a,key)<<"\n";
}
