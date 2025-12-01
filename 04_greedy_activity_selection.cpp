#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> act(n);
    for(int i = 0; i < n; i++)
        cin >> act[i].first >> act[i].second; // start, end

    sort(act.begin(), act.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    cout << act[0].first << " " << act[0].second << "\n";
    int last = act[0].second;

    for(int i = 1; i < n; i++) {
        if(act[i].first >= last) {
            cout << act[i].first << " " << act[i].second << "\n";
            last = act[i].second;
        }
    }
}
