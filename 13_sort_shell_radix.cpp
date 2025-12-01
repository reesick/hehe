#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>a){
    int n=a.size();
    for(int gap=n/2;gap>0;gap/=2)
        for(int i=gap;i<n;i++){
            int temp=a[i],j=i;
            while(j>=gap && a[j-gap]>temp){
                a[j]=a[j-gap];
                j-=gap;
            }
            a[j]=temp;
        }
    for(int x:a) cout<<x<<" ";
    cout<<"\n";
}

void radixSort(vector<int>a){
    int mx=*max_element(a.begin(),a.end());
    for(int exp=1;mx/exp>0;exp*=10){
        vector<int>out(a.size()),count(10,0);

        for(int x:a) count[(x/exp)%10]++;
        for(int i=1;i<10;i++) count[i]+=count[i-1];
        for(int i=a.size()-1;i>=0;i--)
            out[--count[(a[i]/exp)%10]]=a[i];

        a=out;
    }
    for(int x:a) cout<<x<<" ";
}

int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int&i:a)cin>>i;

    shellSort(a);
    radixSort(a);
}
