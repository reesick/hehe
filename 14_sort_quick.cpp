#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&a,int low,int high){
    int pivot=a[high],i=low-1;
    for(int j=low;j<high;j++)
        if(a[j]<pivot)
            swap(a[++i],a[j]);
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(vector<int>&a,int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int&i:a)cin>>i;

    quickSort(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}
