#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.rbegin(), coins.rend());

    for (int c : coins) {
        if (amount >= c) {
            int count = amount / c;
            cout << c << " × " << count << "\n";
            amount %= c;
        }
    }
}
