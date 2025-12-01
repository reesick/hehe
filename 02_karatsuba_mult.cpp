#include <bits/stdc++.h>
using namespace std;

long long calls = 0, muls = 0, adds = 0;

long long karatsuba(long long x, long long y) {

    calls++; // ← Every recursive call counts

    // BASE CASE (single digit multiplication)
    if (x < 10 || y < 10) {
        muls++;                 // Only 1 multiplication performed
        return x * y;
    }

    // Number of digits
    int digits = max((int)log10(x) + 1, (int)log10(y) + 1);
    int m = digits / 2;

    long long p = pow(10, m);

    // Splitting numbers
    long long a = x / p;
    long long b = x % p;
    long long c = y / p;
    long long d = y % p;

    // 3 Recursive multiplications (core of Karatsuba)
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long z  = karatsuba(a + b, c + d);

    // ad + bc extraction
    long long ad_bc = z - ac - bd;
    adds += 2;   // (z - ac - bd) ← 2 additions here

    // Final result combination
    long long result = ac * pow(10, 2 * m) + ad_bc * pow(10, m) + bd;
    adds += 2;   // 2 final additions in formula

    return result;
}

int main() {
    long long x, y;
    cin >> x >> y;

    cout << "\nResult = " << karatsuba(x, y) << endl;
    cout << "\n📌 Recursive Calls = " << calls << endl;
    cout << "📌 Multiplications = " << muls  << endl;
    cout << "📌 Additions       = " << adds  << endl;
}
