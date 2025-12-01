#include <iostream>
using namespace std;

// Insert
void insertElement(int a[], int &n, int pos, int val){
    for(int i = n; i > pos; i--) a[i] = a[i - 1];
    a[pos] = val;
    n++;
}

// Delete
void deleteElement(int a[], int &n, int pos){
    for(int i = pos; i < n - 1; i++) a[i] = a[i + 1];
    n--;
}

// Merge
void mergeArray(int a[], int n1, int b[], int n2, int c[]){
    for(int i = 0; i < n1; i++) c[i] = a[i];
    for(int i = 0; i < n2; i++) c[n1 + i] = b[i];
}

// 2D Row-major display
void rowMajor(int a[], int r, int c){
    cout << "\nRow Major:\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout << a[i*c + j] << " ";
        cout << endl;
    }
}

// 2D Column-major display
void colMajor(int a[], int r, int c){
    cout << "\nColumn Major:\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout << a[j*r + i] << " ";
        cout << endl;
    }
}

// Print values + addresses
void showAddress(int a[], int n){
    cout << "\nValue | Address\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " -> " << (a + i) << endl;
}

int main(){
    int a[50] = {10,20,30,40,50}, n = 5;

    insertElement(a, n, 2, 99);     // INSERT at index 2
    deleteElement(a, n, 3);         // DELETE index 3

    int b[] = {7,8,9}, c[20];
    mergeArray(a,n,b,3,c);          // MERGE

    int oneD[] = {1,2,3,4,5,6};
    rowMajor(oneD,2,3);
    colMajor(oneD,2,3);

    showAddress(a, n);

    return 0;
}
