#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2000, 500, 200, 100, 50 ,20 ,10 ,5 ,2 ,1};
    int n = 10;

    int amnt;
    cout << "enter amnt : "<< endl;
    cin >> amnt;

    for (int i = 0; i < n; i++)
    {
        int count = amnt/arr[i] ;
        if (count > 0)
        {
           cout << arr[i] << " x " << count << endl;
            amnt %= arr[i];
        }
         
    }
    return 0 ;
    

}
