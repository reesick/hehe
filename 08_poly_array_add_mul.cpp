#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int>A(n+1),B(m+1);
    for(int i=0;i<=n;i++) cin>>A[i];
    for(int i=0;i<=m;i++) cin>>B[i];

    int mx = max(n,m);
    vector<int> add(mx+1);
    for(int i=0;i<=mx;i++) add[i] = A[i] + B[i];

    vector<int> mul(n+m+1,0);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            mul[i+j] += A[i]*B[j];

    for(int x:add) cout<<x<<" ";
    cout<<"\n";
    for(int x:mul) cout<<x<<" ";
}
