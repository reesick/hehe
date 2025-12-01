#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int>a){
    int n=a.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);

    for(int x:a) cout<<x<<" ";
    cout<<"\n";
}

void insertion(vector<int>a){
    int n=a.size();
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(int x:a) cout<<x<<" ";
}

int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int&i:a)cin>>i;

    bubble(a);
    insertion(a);
}

