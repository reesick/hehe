#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<array<int,3>> m(n), simple, fast(n);
    for(int i=0;i<n;i++) cin >> m[i][0] >> m[i][1] >> m[i][2];

    // simple
    for(auto &x:m) simple.push_back({x[1],x[0],x[2]});

    vector<int> freq(1000,0), index(1000,0);

    for(auto &x:m) freq[x[1]]++;
    for(int i=1;i<1000;i++) index[i] = index[i-1] + freq[i-1];

    for(auto &x:m) fast[index[x[1]]++] = {x[1],x[0],x[2]};

    for(auto &x:simple) cout << x[0] << " " << x[1] << " " << x[2] << "\n";
    cout<<"\n";
    for(auto &x:fast) cout << x[0] << " " << x[1] << " " << x[2] << "\n";
}
