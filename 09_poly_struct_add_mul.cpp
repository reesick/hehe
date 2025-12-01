#include <bits/stdc++.h>
using namespace std;

struct Term{ int c,p; };

int main(){
    int n,m;
    cin >> n >> m;

    vector<Term>A(n), B(m), ADD, MULT;

    for(auto &x:A) cin>>x.c>>x.p;
    for(auto &x:B) cin>>x.c>>x.p;

    int i=0,j=0;
    while(i<n && j<m){
        if(A[i].p == B[j].p) ADD.push_back({A[i].c+B[j].c, A[i].p}), i++, j++;
        else if(A[i].p > B[j].p) ADD.push_back(A[i++]);
        else ADD.push_back(B[j++]);
    }
    while(i<n) ADD.push_back(A[i++]);
    while(j<m) ADD.push_back(B[j++]);

    for(auto &x:A)
        for(auto &y:B)
            MULT.push_back({x.c*y.c, x.p+y.p});

    for(auto &x:ADD)  cout<<x.c<<"x^"<<x.p<<" ";
    cout<<"\n";
    for(auto &x:MULT) cout<<x.c<<"x^"<<x.p<<" ";
}
