#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<int> arr(r*c);

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> arr[i*c + j];  // 1D simulating 2D

    int pos, val;
    cin >> pos >> val;
    arr.insert(arr.begin() + pos, val);

    int del;
    cin >> del;
    arr.erase(arr.begin() + del);

    vector<int> merged = arr;
    merged.insert(merged.end(), arr.begin(), arr.end());

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << arr[i*c + j] << " ";
        cout << "\n";
    }
}
