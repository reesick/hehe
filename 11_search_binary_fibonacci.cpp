#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a,int key){
    int l=0,r=a.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==key) return mid;
        if(a[mid]<key)  l=mid+1;
        else            r=mid-1;
    }
    return -1;
}

int fibonacciSearch(vector<int> a,int key){
    int n=a.size();
    int f2=0,f1=1,f=f1+f2;

    while(f<n) f2=f1,f1=f,f=f1+f2;
    int offset=-1;

    while(f>1){
        int i=min(offset+f2,n-1);

        if(a[i]<key) offset=i, f=f1, f1=f2, f2=f-f1;
        else if(a[i]>key) f=f2, f1=f1-f2, f2=f-f1;
        else return i;
    }
    if(f1 && offset+1<n && a[offset+1]==key) return offset+1;
    return -1;
}

int main(){
    int n,key;
    cin>>n>>key;

    vector<int>a(n);
    for(int&i:a)cin>>i;

    cout<<"Binary    = "<<binarySearch(a,key)<<"\n";
    cout<<"Fibonacci = "<<fibonacciSearch(a,key)<<"\n";
}
