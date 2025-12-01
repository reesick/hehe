#include <bits/stdc++.h>
using namespace std;

int main() {

    int start[] = {1, 3, 0, 5, 8, 5};
    int endt[]  = {2, 4, 6, 7, 9, 9};
    int n = 6;

    // First activity select karo
    int last_end = endt[0];
    cout << start[0] << " " << endt[0] << endl;

    // Now check the remaining
    for (int i = 1; i < n; i++)        // FIX #1 → < n
    {
        if (start[i] >= last_end)      // FIX #2 → >= not <
        {
            cout << start[i] << " " << endt[i] << endl;
            last_end = endt[i];
        }
    }

    return 0;
}
