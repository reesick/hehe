#include <bits/stdc++.h>
using namespace std;

long long calls = 0, muls = 0, adds = 0;

long long karatsuba(long long x, long long y) {
    calls++;

    if (x < 10 || y < 10) {
        muls++;
        return x * y;
    }

    int digits = max((int)log10(x)+1, (int)log10(y)+1);
    int mid = digits / 2;

    long long pow10 = pow(10, mid);

    long long a = x / pow10;
    long long b = x % pow10;
    long long c = y / pow10;
    long long d = y % pow10;

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ad_bc = karatsuba(a + b, c + d) - ac - bd;

    adds += 2;
    muls += 3;

    return ac * pow(10, 2 * mid) + ad_bc * pow(10, mid) + bd;
}

int main() {
    long long x, y;
    cin >> x >> y;

    cout << karatsuba(x,y) << "\n";
    cout << "Recursive Calls = " << calls << "\n";
    cout << "Multiplications = " << muls  << "\n";
    cout << "Additions       = " << adds  << "\n";
}
