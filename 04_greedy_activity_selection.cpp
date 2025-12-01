#include <bits/stdc++.h>
using namespace std;

int main() {

    
    int start[] = {1, 3, 0, 5, 8, 5};
    int endt[]  = {2, 4, 6, 7, 9, 9};
    int n = 6;

    int last_end = endt[0];
    cout << start[0] << " " << endt[0] <<endl;

    for (int i = 1; i <= n; i++)
    {
        if (last_end < start[i])
        {
            /* code */
        }
        
    }
    

    return 0;
}
