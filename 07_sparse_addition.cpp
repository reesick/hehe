#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2;
    cin >> n1 >> n2;

    vector<array<int,3>> A(n1), B(n2), C;
    for(auto &x:A) cin >> x[0]>>x[1]>>x[2];
    for(auto &x:B) cin >> x[0]>>x[1]>>x[2];

    int i=0,j=0;
    while(i<n1 && j<n2){
        if(A[i][0]==B[j][0] && A[i][1]==B[j][1]){
            int v = A[i][2]+B[j][2];
            if(v) C.push_back({A[i][0],A[i][1],v});
            i++; j++;
        }
        else if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1]))
            C.push_back(A[i++]);
        else 
            C.push_back(B[j++]);
    }
    while(i<n1) C.push_back(A[i++]);
    while(j<n2) C.push_back(B[j++]);

    for(auto &x:C) cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
}
