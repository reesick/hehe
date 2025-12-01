#include <bits/stdc++.h>
using namespace std;

long long calls = 0, muls = 0, adds = 0;

long long karatsuba(long long x, long long y) {
    calls++;
    if (x<10 && y <10 )
    {muls++;
        return x*y;
    }

    int n = max((int)log10(x)+1,(int)log10(y)+1);
    int m = n/2;
    long long pwr = pow(10,m);

    long long a = x /pwr ;
    long long b = x %pwr ;
    long long c = y /pwr ;
    long long d = y %pwr ;

    long long ac = karatsuba(a,c);
    long long bd = karatsuba(b,d);
    long long z = karatsuba(a+b, c+d);

    long long mid = z- ac -bd;
    adds+=2;

    long long ad_bc = ac * pow(10,2*m) + bd + mid * pow(10,m) ;

    adds+=2;

    return ad_bc;

    
}

int main() {
    long long x, y;
    cin >> x >> y;

    cout << "\nResult = " << karatsuba(x,y) << endl;
    cout << "Recursive Calls = " << calls << endl;
    cout << "Multiplications = " << muls  << endl;
    cout << "Additions       = " << adds  << endl;
}
