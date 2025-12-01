#include <bits/stdc++.h>
using namespace std;
long long calls , muls ,adds;

long long gauss(long long a , long long b){
    
    calls++;


    if (b == 1)
    {   
        muls++;
        return a;

    }

    long long half = gauss(a,b/2);
    adds++;
    if(b%2 == 0){
        
        muls++;
        return half + half;
    }
    else{
       
        adds++;
        muls++;
        return half + half + a;
    }

}

int main() {
    long long a, b;
    cin >> a >> b;

    cout << gauss(a, b) << "\n";
    cout << "Recursive Calls = " << calls << "\n";
    cout << "Multiplications = " << muls  << "\n";
    cout << "Additions       = " << adds  << "\n";
}