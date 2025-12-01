/*
PS 1) Write a program to implement Gauss’s multiplication method.
Display the number of recursive calls, multiplications,
and additions required to implement this method.
*/

#include <iostream>
using namespace std;

int recursivecall = 0;
int multiplications = 0;
int additions = 0;

int gaussmultiply(int x, int y) {
    recursivecall++;

    // Base case (single-digit numbers)
    if (x < 10 && y < 10) {
        multiplications++;   // one multiplication
        return x * y;
    }

    // Split the numbers
    int a1 = x / 10, a0 = x % 10;
    int b1 = y / 10, b0 = y % 10;

    // Recursive calls
    int p1 = gaussmultiply(a1, b1);
    int p2 = gaussmultiply(a0, b0);
    int p3 = gaussmultiply(a1 + a0, b1 + b0);

    additions += 2; // a1 + a0, b1 + b0

    // Calculate middle term
    int mid = (p3 - p2 - p1);
    additions += 3; // p3 - p2 - p1

    // Final combination
    int result = p1 * 100 + mid * 10 + p2;

    multiplications += 2; // p1*100 and mid*10

    return result;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int result = gaussmultiply(x, y);

    cout << "\nProduct = " << result << endl;
    cout << "Recursive Calls = " << recursivecall << endl;
    cout << "Multiplications = " << multiplications << endl;
    cout << "Additions = " << additions << endl;

    return 0;
}

/*
--------------------------------------------
TIME & SPACE COMPLEXITY (STANDARD)
--------------------------------------------

Time Complexity:
T(n) = 3T(n/2) + O(1)
=> O(n^log2(3)) ≈ O(n^1.585)

Space Complexity:
O(log n)   // due to recursion depth

--------------------------------------------
*/






/*
PS 2) Write a program to implement Karatsuba’s algorithm for multiplying large integers.
Display the number of recursive calls, multiplications, and additions required to implement this method.
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int recursive = 0;
int multiplication = 0;
int addition = 0;

long long karatsuba(long long x, long long y) {
    recursive++;

    // Base case: single digit multiplication
    if (x < 10 && y < 10) {
        multiplication++;
        return x * y;
    }

    int n = max((int)to_string(x).length(), (int)to_string(y).length());
    int m = n / 2;

    long long p = pow(10, m);

    // Split numbers
    long long a1 = x / p;
    long long a0 = x % p;
    long long b1 = y / p;
    long long b0 = y % p;

    // Recursive multiplications
    long long p1 = karatsuba(a1, b1);
    long long p2 = karatsuba(a0, b0);
    long long p3 = karatsuba(a1 + a0, b1 + b0);

    addition += 2; // (a1+a0) , (b1+b0)

    // Karatsuba formula
    long long result =
        p1 * (long long)pow(10, 2 * m) +
        (p3 - p2 - p1) * p +
        p2;

    addition += 2;      // (p3 - p2 - p1)
    multiplication += 3; // p1*(10^...), mid*p, and base mul counted above

    return result;
}

int main() {
    long long x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    long long result = karatsuba(x, y);

    cout << "\nProduct = " << result << endl;
    cout << "Additions = " << addition << endl;
    cout << "Recursive Calls = " << recursive << endl;
    cout << "Multiplications = " << multiplication << endl;

    return 0;
}

/*
--------------------------------------------
TIME & SPACE COMPLEXITY (STANDARD)
--------------------------------------------

Karatsuba Time Complexity:
T(n) = 3T(n/2) + O(n)
=> O(n^log2(3))
=> O(n^1.585)     // faster than normal O(n^2)

Space Complexity:
O(log n)          // recursion depth

--------------------------------------------
*/





/*
PS:3] Write a program to implement a greedy algorithm to solve a real-world
optimization problem, such as minimizing currency notes in a digital wallet 
(coin change). Also write pseudo-code, flowchart, and time complexity analysis.
*/

#include <iostream>
#include <vector>
using namespace std;

// Greedy coin change function
void minimizeCurrencyNotes(int amount, vector<int> coins) {
    cout << "Minimum currency notes/coins:\n";

    for (int coin : coins) {
        if (amount >= coin) {
            int count = amount / coin;
            cout << coin << " x " << count << endl;
            amount %= coin;
        }
    }
}

int main() {
    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    vector<int> denominations = {2000, 500, 100, 50, 20, 10, 5, 1};

    minimizeCurrencyNotes(amount, denominations);

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY (Big-O, Θ, Ω)
-----------------------------------------------------------
Let n = number of denominations

Best Case: Ω(1)
- When amount < largest coin → loop runs but no division.

Average Case: Θ(n)
- Loop checks each denomination once.

Worst Case: O(n)
- Even if all coins are used, loop still iterates over all n coins.

SPACE COMPLEXITY:
O(1) — Only fixed variables, no extra storage.

-----------------------------------------------------------
*/



/*
PS 4) Write a program to implement a greedy algorithm to solve a real-world
optimization problem, such as maximizing non-overlapping events in a scheduler
(Activity Selection Problem). Represent the logic using pseudo-code and a 
flowchart. Analyse time complexity (Best, Average, Worst Case).
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

// Sort by finish time (ascending)
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity arr[], int n) {
    // Sort activities by finish time
    sort(arr, arr + n, compare);

    cout << "Selected Activities: ";

    int last_finish = 0;  // end time of last selected activity

    for (int i = 0; i < n; i++) {
        if (arr[i].start >= last_finish) {
            cout << "(" << arr[i].start << "," << arr[i].finish << ") ";
            last_finish = arr[i].finish;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[100];

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    activitySelection(arr, n);

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------
Let n = number of activities

Sorting Step:
- Takes O(n log n)

Selection Step:
- Single pass through array → O(n)

Worst Case:  O(n log n)
Average Case: Θ(n log n)
Best Case:    Ω(n log n) 
(Reason: sorting dominates all cases)

SPACE COMPLEXITY:
O(1)  → only fixed variables used

-----------------------------------------------------------
*/




/*
PS 5) Write a program to implement basic array operations such as insert, delete, 
and merge, while simulating a 2D array using a single-dimensional array to optimize space 
(using both Row-Major and Column-Major formats). Use pointer arithmetic to print memory 
addresses to understand how arrays are stored in memory.
*/

#include <iostream>
using namespace std;

// Row-Major mapping: index = r * totalcols + c
int rowmajor(int r, int c, int totalcols) {
    return r * totalcols + c;
}

// Column-Major mapping: index = c * totalrows + r
int colmajor(int r, int c, int totalrows) {
    return c * totalrows + r;
}

// Insert element into simulated 2D array
void insertel(int arr[], int r, int c, int totalcols, int value) {
    int index = rowmajor(r, c, totalcols);
    arr[index] = value;
}

// Delete element (replace with 0)
void deleteel(int arr[], int r, int c, int totalcols) {
    int index = rowmajor(r, c, totalcols);
    arr[index] = 0;
}

// Merge two 1D arrays
void mergeel(int A[], int sizeA, int B[], int sizeB, int result[]) {
    for (int i = 0; i < sizeA; i++) {
        result[i] = A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        result[sizeA + i] = B[i];
    }
}

int main() {
    int rows = 3, cols = 3;
    int size = rows * cols;

    int arr[size] = {0};

    // INSERT operations
    insertel(arr, 0, 0, cols, 10);
    insertel(arr, 0, 1, cols, 20);
    insertel(arr, 1, 2, cols, 30);
    insertel(arr, 2, 0, cols, 40);

    // Print using row-major
    cout << "Row-Major 2D Simulation:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = rowmajor(i, j, cols);
            cout << arr[index] << "\t";
        }
        cout << endl;
    }

    // Print memory addresses using pointer arithmetic
    cout << "\nMemory Addresses of Elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "&arr[" << i << "] = " << (arr + i) << endl;
    }

    // DELETE element
    deleteel(arr, 1, 2, cols);

    cout << "\nAfter Deletion (Row-Major Print):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = rowmajor(i, j, cols);
            cout << arr[index] << "\t";
        }
        cout << endl;
    }

    // COLUMN-MAJOR display
    cout << "\nColumn-Major Order:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = colmajor(i, j, rows);
            cout << arr[index] << "\t";
        }
        cout << endl;
    }

    // MERGE operation
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};
    int merged[6];

    mergeel(A, 3, B, 3, merged);

    cout << "\nMerged Array: ";
    for (int i = 0; i < 6; i++)
        cout << merged[i] << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Row-Major Indexing:  O(1)
Column-Major Indexing: O(1)
Insert Operation:  O(1)
Delete Operation:  O(1)
Print Memory Addresses: O(n)
Merge Operation:  O(sizeA + sizeB)
2D Simulation Print: O(rows * cols)

OVERALL:
Worst Case:  O(n)
Average Case: Θ(n)
Best Case: Ω(1)   // insert/delete/indexing only

SPACE COMPLEXITY:
O(n)  // single 1D array of n elements

-----------------------------------------------------------
*/





/*
PS 6) Write a program to implement simple transpose and fast transpose of a 
sparse matrix using the 3-tuple representation. Compare both methods based on 
their time and space efficiency to understand which one works better for 
handling large and fragmented data in real-world systems.
*/

#include <iostream>
using namespace std;

// ------------ CREATE SPARSE MATRIX (3-TUPLE) -----------------
void createSparse(int mat[10][10], int r, int c, int sparse[100][3]) {
    int k = 1; 
    sparse[0][0] = r;      // rows
    sparse[0][1] = c;      // cols

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;  // number of non-zero elements
}

// ------------ DISPLAY SPARSE MATRIX --------------------------
void displaySparse(int s[100][3]) {
    int n = s[0][2] + 1;
    for (int i = 0; i < n; i++)
        cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;
}

// ------------ SIMPLE TRANSPOSE ------------------------------
void simpleTranspose(int s[100][3], int t[100][3]) {
    int rows = s[0][0];
    int cols = s[0][1];
    int terms = s[0][2];

    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = terms;

    int k = 1;

    for (int col = 0; col < cols; col++) {    // scanning each column
        for (int i = 1; i <= terms; i++) {    // scanning all non-zero entries
            if (s[i][1] == col) {
                t[k][0] = s[i][1];
                t[k][1] = s[i][0];
                t[k][2] = s[i][2];
                k++;
            }
        }
    }
}

// ------------ FAST TRANSPOSE ------------------------------
void fastTranspose(int s[100][3], int t[100][3]) {
    int rows = s[0][0];
    int cols = s[0][1];
    int terms = s[0][2];

    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = terms;

    if (terms == 0) return;

    int rowTerms[100] = {0};
    int startPos[100];

    // Count number of values in each column
    for (int i = 1; i <= terms; i++)
        rowTerms[s[i][1]]++;

    // Find starting position of each column in result
    startPos[0] = 1;
    for (int i = 1; i < cols; i++)
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];

    // Fill fast transpose
    for (int i = 1; i <= terms; i++) {
        int col = s[i][1];
        int pos = startPos[col];

        t[pos][0] = s[i][1];
        t[pos][1] = s[i][0];
        t[pos][2] = s[i][2];

        startPos[col]++;
    }
}

// --------------------------- MAIN -------------------------------
int main() {
    int r, c, mat[10][10];
    int sparse[100][3], simple[100][3], fast[100][3];

    cout << "Enter rows and cols: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    createSparse(mat, r, c, sparse);

    cout << "\nSparse Matrix (3-tuple):\n";
    displaySparse(sparse);

    simpleTranspose(sparse, simple);
    cout << "\nSimple Transpose:\n";
    displaySparse(simple);

    fastTranspose(sparse, fast);
    cout << "\nFast Transpose:\n";
    displaySparse(fast);

    cout << "\n---------- PERFORMANCE REPORT -----------\n";
    cout << "Simple Transpose Time    : O(n * cols)\n";
    cout << "Fast Transpose Time      : O(n + cols)\n";
    cout << "Fast transpose performs better for large sparse matrices.\n";
    cout << "-----------------------------------------\n";

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Let n = number of non-zero elements
Let c = number of columns

SIMPLE TRANSPOSE:
- For each column → scan all non-zero elements
Time:
  Worst Case: O(n * c)
  Average Case: Θ(n * c)
  Best Case: Ω(n)       // when non-zero grouping is favorable

FAST TRANSPOSE:
- Count column occurrences → O(n)
- Compute starting positions → O(c)
- Place elements → O(n)

Time:
  Worst Case: O(n + c)
  Average Case: Θ(n + c)
  Best Case: Ω(c)       // even if n = 0, must process columns

SPACE COMPLEXITY:
Simple Transpose:  O(1)
Fast Transpose:    O(c)   // rowTerms[] + startPos[]

CONCLUSION:
Fast Transpose is more efficient than Simple Transpose for large, sparse and fragmented matrices.
-----------------------------------------------------------
*/



/*
PS 7) Write a program to perform addition of two sparse matrices using the 3-tuple 
representation. Analyse the time and space complexity of your program and explain 
why efficient sparse matrix addition is useful for large data sets where most values 
are zero.
*/

#include <iostream>
using namespace std;

// ---------------- CREATE SPARSE (3-TUPLE) ----------------
void createSparse(int mat[10][10], int r, int c, int sparse[100][3]) {
    int k = 1;
    sparse[0][0] = r;      // rows
    sparse[0][1] = c;      // cols

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;  // number of non-zero terms
}

// ---------------- DISPLAY SPARSE -------------------------
void displaySparse(int s[100][3]) {
    int n = s[0][2] + 1;
    for (int i = 0; i < n; i++)
        cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;
}

// ---------------- ADD SPARSE MATRICES ---------------------
void addSparse(int A[100][3], int B[100][3], int C[100][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrix size mismatch. Cannot add.\n";
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int m = A[0][2];  // non-zero in A
    int n = B[0][2];  // non-zero in B
    int i = 1, j = 1, k = 1;

    // Merge like merge-sort based on (row, col)
    while (i <= m && j <= n) {
        if (A[i][0] < B[j][0] ||
           (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {

            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] ||
                (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {

            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { // same row and column → add values
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    // Remaining entries of A
    while (i <= m) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    // Remaining entries of B
    while (j <= n) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;  // total non-zero values
}

// ---------------------------- MAIN -------------------------------
int main() {
    int r, c;
    int mat1[10][10], mat2[10][10];
    int A[100][3], B[100][3], C[100][3];

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter Matrix 1:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat1[i][j];

    cout << "Enter Matrix 2:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat2[i][j];

    createSparse(mat1, r, c, A);
    createSparse(mat2, r, c, B);

    cout << "\nSparse Matrix A (3-tuple):\n";
    displaySparse(A);

    cout << "\nSparse Matrix B (3-tuple):\n";
    displaySparse(B);

    addSparse(A, B, C);

    cout << "\nResultant Sparse Matrix C = A + B:\n";
    displaySparse(C);

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------
Let:
m = number of non-zero entries in A
n = number of non-zero entries in B

createSparse():     O(r * c)
displaySparse():    O(m)
addSparse():        O(m + n)     // merging like merge-sort

Worst Case:  O(m + n)
Average Case: Θ(m + n)
Best Case:   Ω(min(m, n))

SPACE COMPLEXITY:
Sparse matrices use:
A → O(m)
B → O(n)
C → O(m + n)
Total: O(m + n)

-----------------------------------------------------------
WHY SPARSE MATRIX ADDITION IS USEFUL?
-----------------------------------------------------------
✔ Real-world matrices (graphs, images, ML datasets) are mostly zeros  
✔ Storing only non-zero values saves huge memory  
✔ Addition is fast (only merge non-zero values)  
✔ Space improves from O(r*c) → O(non-zero)  
✔ Useful in:
   - Machine Learning  
   - Graph adjacency matrices  
   - Large scientific computations  
   - Data compression  
-----------------------------------------------------------
*/



/*
PS 8) Write a program to implement polynomial addition and multiplication 
operations using array representation.
*/

#include <iostream>
using namespace std;

// ---------------- INPUT POLYNOMIAL --------------------
void inputpoly(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        cin >> poly[i];
    }
}

// ---------------- PRINT POLYNOMIAL ---------------------
void printpoly(int poly[], int degree) {

    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            cout << poly[i] << "x^" << i;
            if (i != 0)
                cout << " + ";
        }
    }
    cout << endl;
}

// ---------------- POLYNOMIAL ADDITION -------------------
void addpoly(int p1[], int d1, int p2[], int d2, int result[]) {

    int maxd = max(d1, d2);

    for (int i = 0; i <= maxd; i++) {

        int a = (i <= d1) ? p1[i] : 0;
        int b = (i <= d2) ? p2[i] : 0;

        result[i] = a + b;
    }
}

// ---------------- POLYNOMIAL MULTIPLICATION --------------
void multipoly(int p1[], int d1, int p2[], int d2, int result[]) {

    // Initialize result
    for (int i = 0; i <= d1 + d2; i++)
        result[i] = 0;

    // Multiply each term
    for (int i = 0; i <= d1; i++) {
        for (int j = 0; j <= d2; j++) {
            result[i + j] += p1[i] * p2[j];
        }
    }
}

// ----------------------------- MAIN ------------------------------
int main() {
    int d1, d2;

    cin >> d1;
    int p1[d1 + 1];
    inputpoly(p1, d1);

    cin >> d2;
    int p2[d2 + 1];
    inputpoly(p2, d2);

    int addResult[max(d1, d2) + 1];
    int mulResult[d1 + d2 + 1];

    addpoly(p1, d1, p2, d2, addResult);
    multipoly(p1, d1, p2, d2, mulResult);

    cout << "\nAddition: ";
    printpoly(addResult, max(d1, d2));

    cout << "Multiplication: ";
    printpoly(mulResult, d1 + d2);

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Let:
d1 = degree of Polynomial 1
d2 = degree of Polynomial 2

Addition:
    Worst Case:  O(max(d1, d2))
    Average Case: Θ(max(d1, d2))
    Best Case:    Ω(max(d1, d2))

Multiplication:
    Nested loops → (d1 + 1) * (d2 + 1)
    Worst Case:   O(d1 * d2)
    Average Case: Θ(d1 * d2)
    Best Case:    Ω(d1 * d2)

SPACE COMPLEXITY:
Addition Result Array:       O(max(d1, d2))
Multiplication Result Array: O(d1 + d2)
Total Space:                 O(d1 + d2)

-----------------------------------------------------------
*/




/*
PS 9) Write a program to store a polynomial using an array of structures, where 
each structure contains a coefficient and an exponent. Perform polynomial addition 
and multiplication using this structure-based representation. Compare the efficiency 
of this approach with the previous array-based method and explain which 
representation is better and why.
*/

#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

// ------------------ DISPLAY ------------------
void display(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        cout << poly[i].coeff << "x^" << poly[i].exp;
        if (i != n - 1) cout << " + ";
    }
    cout << endl;
}

// ------------------ ADDITION ------------------
int addPoly(Term A[], int n1, Term B[], int n2, Term C[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (A[i].exp == B[j].exp) {  
            C[k].coeff = A[i].coeff + B[j].coeff;
            C[k].exp = A[i].exp;
            i++; j++; k++;
        }
        else if (A[i].exp > B[j].exp) {  
            C[k++] = A[i++];
        }
        else {  
            C[k++] = B[j++];
        }
    }

    while (i < n1) C[k++] = A[i++];
    while (j < n2) C[k++] = B[j++];

    return k; // total resulting terms
}

// ------------------ MULTIPLICATION ------------------
int multiplyPoly(Term A[], int n1, Term B[], int n2, Term C[]) {
    int k = 0;

    // multiply each term of A with each term of B
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            C[k].coeff = A[i].coeff * B[j].coeff;
            C[k].exp = A[i].exp + B[j].exp;  // ✔ exponent ADD (correct rule)
            k++;
        }
    }

    // MERGE terms with same exponent
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (C[i].exp == C[j].exp) {
                C[i].coeff += C[j].coeff;

                // remove duplicate term
                for (int m = j; m < k - 1; m++)
                    C[m] = C[m + 1];

                k--;
                j--;
            }
        }
    }

    return k;
}

// ---------------------- MAIN ------------------------
int main() {
    int n1, n2;
    Term A[50], B[50], Result[200];

    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n1;
    cout << "Enter coeff and exp:\n";
    for (int i = 0; i < n1; i++)
        cin >> A[i].coeff >> A[i].exp;

    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n2;
    cout << "Enter coeff and exp:\n";
    for (int i = 0; i < n2; i++)
        cin >> B[i].coeff >> B[i].exp;

    cout << "\nPolynomial 1: ";
    display(A, n1);

    cout << "Polynomial 2: ";
    display(B, n2);

    // ADDITION
    int addN = addPoly(A, n1, B, n2, Result);
    cout << "\nAddition Result: ";
    display(Result, addN);

    // MULTIPLICATION
    int mulN = multiplyPoly(A, n1, B, n2, Result);
    cout << "Multiplication Result: ";
    display(Result, mulN);

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Let n1 = number of terms in A
Let n2 = number of terms in B

ADDITION:
- Similar to merge of two sorted lists
Worst Case:  O(n1 + n2)
Average Case: Θ(n1 + n2)
Best Case:    Ω(n1 + n2)

MULTIPLICATION:
- Each term of A multiplied with each term of B
Worst Case:  O(n1 * n2)
Average Case: Θ(n1 * n2)
Best Case:    Ω(n1 * n2)

MERGING LIKE TERMS:
Worst Case:  O((n1*n2)^2)  (rare, only if many terms share same exponent)
Usually:     Θ(n1*n2)

SPACE COMPLEXITY:
Addition Result:       O(n1 + n2)
Multiplication Result: O(n1 * n2)
Total:                 O(n1 * n2)

-----------------------------------------------------------
COMPARISON: ARRAY METHOD (PS 8) VS STRUCT METHOD (PS 9)
-----------------------------------------------------------

ARRAY-BASED (PS 8):
✔ Uses direct indexing (index = exponent)  
✔ Very fast for addition → O(max degree)  
✔ Very fast for multiplication → O(d1 * d2)  
Wastes memory when polynomial has huge degree but few non-zero terms  
 Cannot skip zero terms; array must include all degrees  

STRUCTURE-BASED (PS 9):
✔ Stores only non-zero terms → huge memory savings  
✔ Good for sparse polynomials  
✔ Addition is efficient (merge-like)  
 More overhead per term (structure)  
 Multiplication requires merging duplicate exponents  
 Slightly slower than array indexing

-----------------------------------------------------------
WHICH IS BETTER AND WHY?
-----------------------------------------------------------

If the polynomial is **dense** (many non-zero terms):
→ **Array method is better**  
Faster addition (O(n)) and simple multiplication.

If the polynomial is **sparse** (only few non-zero terms but huge degrees):
→ **Structure-based method is better**  
Saves memory, faster because it skips zero terms.

-----------------------------------------------------------
*/



/*
PS 10) Write a menu-driven program to implement and compare different search 
techniques — Linear Search and Sentinel Search — on sorted and unsorted datasets. 
Count and display the number of comparisons made by each algorithm to evaluate 
their efficiency.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// ------------------- LINEAR SEARCH -------------------
int linearsearch(int arr[], int n, int key, int &comp) {
    comp = 0;
    for (int i = 0; i < n; i++) {
        comp++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ------------------- SENTINEL SEARCH -------------------
int sentinelsearch(int arr[], int n, int key, int &comp) {
    comp = 0;
    int last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (arr[i] != key) { 
        comp++;
        i++;
    }

    arr[n - 1] = last;  // restore original value

    if (i < n - 1 || last == key)
        return i;

    return -1;
}

// ------------------- DISPLAY ARRAY -------------------
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ------------------------- MAIN -------------------------
int main() {
    int n, key, choice;
    int arr[50], unsorted[50], sorted[50];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        unsorted[i] = arr[i];
        sorted[i] = arr[i];
    }

    sort(sorted, sorted + n);  // sorting once for sorted dataset

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Linear Search (Unsorted)\n";
        cout << "2. Linear Search (Sorted)\n";
        cout << "3. Sentinel Search (Unsorted)\n";
        cout << "4. Sentinel Search (Sorted)\n";
        cout << "5. Display Arrays\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) break;

        cout << "Enter element to search: ";
        cin >> key;

        int comp, pos;

        switch (choice) {
            case 1:
                pos = linearsearch(unsorted, n, key, comp);
                cout << "Linear Search (Unsorted): " 
                     << (pos == -1 ? "Not Found\n" : "Found\n");
                cout << "Comparisons = " << comp << endl;
                break;

            case 2:
                pos = linearsearch(sorted, n, key, comp);
                cout << "Linear Search (Sorted): " 
                     << (pos == -1 ? "Not Found\n" : "Found\n");
                cout << "Comparisons = " << comp << endl;
                break;

            case 3:
                pos = sentinelsearch(unsorted, n, key, comp);
                cout << "Sentinel Search (Unsorted): " 
                     << (pos == -1 ? "Not Found\n" : "Found\n");
                cout << "Comparisons = " << comp << endl;
                break;

            case 4:
                pos = sentinelsearch(sorted, n, key, comp);
                cout << "Sentinel Search (Sorted): " 
                     << (pos == -1 ? "Not Found\n" : "Found\n");
                cout << "Comparisons = " << comp << endl;
                break;

            case 5:
                cout << "Unsorted Array: ";
                display(unsorted, n);
                cout << "Sorted Array: ";
                display(sorted, n);
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Let n = number of elements

LINEAR SEARCH:
Best Case   : Ω(1)       (found at first position)
Average Case: Θ(n)
Worst Case  : O(n)

SENTINEL SEARCH:
Best Case   : Ω(1)
Average Case: Θ(n)
Worst Case  : O(n)
(Sentinel only reduces boundary check, not total comparisons)

SPACE COMPLEXITY:
O(1) – Only constant space is used.

-----------------------------------------------------------
EFFICIENCY COMPARISON
-----------------------------------------------------------
✔ Sentinel Search removes the condition (i < n) in the loop  
✔ One less comparison per iteration → slightly faster  
✔ Beneficial for large unsorted datasets  
✔ Linear Search and Sentinel Search both have O(n) time, but  
  Sentinel Search performs fewer operations internally.

-----------------------------------------------------------
*/


/*
PS 11) Write a menu-driven program to implement and compare different search 
techniques — Binary Search and Fibonacci Search — on sorted and unsorted datasets. 
Count and display the number of comparisons made by each algorithm to evaluate 
their efficiency.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// ------------------ BINARY SEARCH ------------------
int binarysearch(int arr[], int n, int key, int &comp) {
    comp = 0;
    int l = 0, r = n - 1;

    while (l <= r) {
        comp++;
        int mid = (l + r) / 2;

        if (arr[mid] == key) return mid;

        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// ------------------ FIBONACCI SEARCH ------------------
int fibsearch(int arr[], int n, int key, int &comp) {
    comp = 0;

    int fib2 = 0;      // (m-2)'th Fibonacci number
    int fib1 = 1;      // (m-1)'th Fibonacci number
    int fib = fib1 + fib2; // m'th Fibonacci

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        comp++;

        int i = min(offset + fib2, n - 1);

        if (arr[i] == key)
            return i;

        else if (arr[i] < key) {      // search right
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else {                         // search left
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    comp++;
    if (fib1 && arr[offset + 1] == key)
        return offset + 1;

    return -1;
}

// ---------------- DISPLAY ARRAY ------------------
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ------------------ MAIN PROGRAM ------------------
int main() {
    int n, key, choice;
    int arr[50], unsorted[50], sorted[50];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        unsorted[i] = arr[i];
        sorted[i] = arr[i];
    }

    sort(sorted, sorted + n);

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Binary Search (Sorted)\n";
        cout << "2. Binary Search (Unsorted → auto sort)\n";
        cout << "3. Fibonacci Search (Sorted)\n";
        cout << "4. Fibonacci Search (Unsorted → auto sort)\n";
        cout << "5. Display Arrays\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) break;

        cout << "Enter element to search: ";
        cin >> key;

        int comp, pos;

        switch (choice) {

        case 1:
            pos = binarysearch(sorted, n, key, comp);
            cout << "Binary Search (Sorted): "
                 << (pos == -1 ? "Not Found\n" : "Found\n");
            cout << "Comparisons = " << comp << endl;
            break;

        case 2:
            sort(unsorted, unsorted + n);
            pos = binarysearch(unsorted, n, key, comp);
            cout << "Binary Search (Unsorted → Sorted): "
                 << (pos == -1 ? "Not Found\n" : "Found\n");
            cout << "Comparisons = " << comp << endl;
            break;

        case 3:
            pos = fibsearch(sorted, n, key, comp);
            cout << "Fibonacci Search (Sorted): "
                 << (pos == -1 ? "Not Found\n" : "Found\n");
            cout << "Comparisons = " << comp << endl;
            break;

        case 4:
            sort(unsorted, unsorted + n);
            pos = fibsearch(unsorted, n, key, comp);
            cout << "Fibonacci Search (Unsorted → Sorted): "
                 << (pos == -1 ? "Not Found\n" : "Found\n");
            cout << "Comparisons = " << comp << endl;
            break;

        case 5:
            cout << "Unsorted Array: ";
            display(arr, n);
            cout << "Sorted Array: ";
            display(sorted, n);
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

BINARY SEARCH:
Best Case:    Ω(1)         // mid element is key
Average Case: Θ(log n)
Worst Case:   O(log n)

FIBONACCI SEARCH:
Best Case:    Ω(1)
Average Case: Θ(log n)
Worst Case:   O(log n)
(Note: Fibonacci search reduces mid calculations and uses fib jumps)

UNSORTED CASE:
Before searching → array must be sorted
Sorting takes O(n log n)
So total = O(n log n + log n) = O(n log n)

SPACE COMPLEXITY:
O(1) for both searches.

-----------------------------------------------------------
EFFICIENCY COMPARISON
-----------------------------------------------------------

✔ Binary Search and Fibonacci Search both take O(log n)
✔ Fibonacci Search is slightly faster on systems with low cache performance
✔ Fibonacci Search avoids division → good for older CPUs
✔ Binary Search simpler and used widely
✔ Both require sorted data

CONCLUSION:
- For large sorted arrays → **Both are efficient (log n)**  
- Fibonacci Search may perform slightly fewer comparisons  
- Binary Search is simpler and preferred in practical applications.

-----------------------------------------------------------
*/



/*
PS 12) Write a program to implement Bubble Sort and Insertion Sort to analyse 
their performance on the same input array. Track and display the time taken, 
number of swaps, and comparisons, and generate a report with the sorted output 
and performance insights.
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void myswap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int bcomp = 0, bswap = 0;
int icomp = 0, ishift = 0;

// ------------------ BUBBLE SORT ------------------
void bubblesort(int arr[], int n) {
    bcomp = bswap = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bcomp++;
            if (arr[j] > arr[j + 1]) {
                myswap(arr[j], arr[j + 1]);
                bswap++;
            }
        }
    }
}

// ------------------ INSERTION SORT ------------------
void insertionsort(int arr[], int n) {
    icomp = ishift = 0;

    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0) {
            icomp++;
            if (arr[prev] > curr) {
                arr[prev + 1] = arr[prev];
                ishift++;
                prev--;
            } else {
                break;
            }
        }
        arr[prev + 1] = curr;
    }
}

// ------------------ DISPLAY ------------------
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ------------------ MAIN ------------------
int main() {
    int arr1[] = {5, 4, 3, 2, 1};
    int arr2[] = {5, 4, 3, 2, 1};

    int n = 5;

    // BUBBLE TIME
    auto start1 = high_resolution_clock::now();
    bubblesort(arr1, n);
    auto end1 = high_resolution_clock::now();
    long long bubbleTime = duration_cast<microseconds>(end1 - start1).count();

    // INSERTION TIME
    auto start2 = high_resolution_clock::now();
    insertionsort(arr2, n);
    auto end2 = high_resolution_clock::now();
    long long insertionTime = duration_cast<microseconds>(end2 - start2).count();

    // OUTPUT
    cout << "\n=== SORTED ARRAYS ===\n";
    cout << "Bubble Sort Output: ";
    display(arr1, n);

    cout << "Insertion Sort Output: ";
    display(arr2, n);

    cout << "\n=== PERFORMANCE REPORT ===\n";

    cout << "\n-- Bubble Sort --\n";
    cout << "Comparisons : " << bcomp << endl;
    cout << "Swaps       : " << bswap << endl;
    cout << "Time Taken  : " << bubbleTime << " microseconds\n";

    cout << "\n-- Insertion Sort --\n";
    cout << "Comparisons : " << icomp << endl;
    cout << "Shifts      : " << ishift << endl;
    cout << "Time Taken  : " << insertionTime << " microseconds\n";

    cout << "\n=== PERFORMANCE INSIGHTS ===\n";
    if (bubbleTime < insertionTime)
        cout << "Bubble Sort was faster on this input.\n";
    else
        cout << "Insertion Sort was faster on this input.\n";

    cout << "Bubble Sort performs many swaps, making it slow for large arrays.\n";
    cout << "Insertion Sort is efficient for nearly-sorted or small datasets.\n";

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

BUBBLE SORT:
Best Case:    Ω(n)         (already sorted)
Average Case: Θ(n^2)
Worst Case:   O(n^2)
Space:        O(1)

INSERTION SORT:
Best Case:    Ω(n)         (already sorted)
Average Case: Θ(n^2)
Worst Case:   O(n^2)
Space:        O(1)

-----------------------------------------------------------
PERFORMANCE SUMMARY
-----------------------------------------------------------
✔ Bubble Sort has highest number of swaps → slowest  
✔ Insertion Sort has fewer data movements → faster on nearly-sorted arrays  
✔ Both are O(n²), but **Insertion Sort generally performs fewer operations**

-----------------------------------------------------------
*/



/*
PS 13) Write a program to implement Shell Sort & Radix Sort to analyse their 
performance on the same input array. Track and display the time taken, 
number of swaps, and comparisons, and generate a report with the sorted 
output and performance insights.
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// GLOBAL COUNTERS
int sh_comp = 0, sh_swap = 0;
int rd_comp = 0, rd_swap = 0;

// ------------------ SHELL SORT ------------------
void shellSort(int arr[], int n) {
    sh_comp = sh_swap = 0;

    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {

            int temp = arr[i];
            int j = i;

            while (j >= gap) {
                sh_comp++;

                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    sh_swap++;
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

// ------------------ RADIX SORT HELPERS ------------------
// Counting sort for a specific digit
void countSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
        rd_comp++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n-1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
        rd_swap++; // movement = swap-like
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// ------------------ RADIX SORT ------------------
void radixSort(int arr[], int n) {
    rd_comp = rd_swap = 0;

    int maxEl = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxEl)
            maxEl = arr[i];

    for (int exp = 1; maxEl / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// ------------------ DISPLAY ------------------
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ------------------ MAIN ------------------
int main() {
    int n = 6;
    int arr1[] = {55, 23, 11, 98, 77, 10};
    int arr2[] = {55, 23, 11, 98, 77, 10};

    // SHELL SORT TIME
    auto start1 = high_resolution_clock::now();
    shellSort(arr1, n);
    auto end1 = high_resolution_clock::now();
    long long shellTime = duration_cast<microseconds>(end1 - start1).count();

    // RADIX SORT TIME
    auto start2 = high_resolution_clock::now();
    radixSort(arr2, n);
    auto end2 = high_resolution_clock::now();
    long long radixTime = duration_cast<microseconds>(end2 - start2).count();

    // -------------------- OUTPUT --------------------
    cout << "\n=== SORTED ARRAYS ===\n";
    cout << "Shell Sort Output : ";
    display(arr1, n);

    cout << "Radix Sort Output : ";
    display(arr2, n);

    cout << "\n=== PERFORMANCE REPORT ===\n";

    cout << "\n-- Shell Sort --\n";
    cout << "Comparisons : " << sh_comp << endl;
    cout << "Swaps       : " << sh_swap << endl;
    cout << "Time Taken  : " << shellTime << " microseconds\n";

    cout << "\n-- Radix Sort --\n";
    cout << "Digit Pass Comparisons : " << rd_comp << endl;
    cout << "Movements (Swaps)      : " << rd_swap << endl;
    cout << "Time Taken             : " << radixTime << " microseconds\n";

    cout << "\n=== PERFORMANCE INSIGHTS ===\n";
    if (shellTime < radixTime)
        cout << "Shell Sort is faster on this dataset.\n";
    else
        cout << "Radix Sort is faster on this dataset.\n";

    cout << "Shell Sort reduces gap size to decrease swaps.\n";
    cout << "Radix Sort is non-comparative and good for integers.\n";

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

SHELL SORT:
Best Case:    Ω(n log n)
Average Case: Θ(n^(3/2))
Worst Case:   O(n^2)
Space:        O(1)

RADIX SORT:
Best Case:    Ω(nk)
Average Case: Θ(nk)
Worst Case:   O(nk)
(where k = number of digits)
Space:        O(n + k)

-----------------------------------------------------------
PERFORMANCE SUMMARY
-----------------------------------------------------------

✔ Shell Sort:
   - Comparison-based  
   - Faster than Insertion Sort  
   - Good for medium-size datasets  
   - Swap count decreases due to gap-based shifting  

✔ Radix Sort:
   - Non-comparison sort  
   - Works best for integers  
   - Very fast when number of digits (k) is small  

✔ On large integers or many digits → Shell may outperform Radix  
✔ On big datasets with small integer range → Radix wins  

-----------------------------------------------------------
*/



/*
PS 14) Write a program to implement Quick Sort. Track and display the time 
taken, number of swaps, and comparisons, and generate a report with the sorted 
output and performance insights.
*/

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long comparisons = 0;
long long swapsCount = 0;

// ----------------- SWAP FUNCTION -----------------
void mySwap(int &a, int &b) {
    swapsCount++;
    int temp = a;
    a = b;
    b = temp;
}

// ----------------- PARTITION FUNCTION -----------------
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];     // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            mySwap(arr[i], arr[j]);
        }
    }

    mySwap(arr[i + 1], arr[high]);
    return i + 1;
}

// ----------------- QUICK SORT -----------------
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// ----------------- MAIN PROGRAM -----------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto startTime = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto endTime = high_resolution_clock::now();

    long long timeTaken = duration_cast<microseconds>(endTime - startTime).count();

    // ----------------- OUTPUT -----------------
    cout << "\nSorted Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    cout << "\n--------- PERFORMANCE REPORT ----------\n";
    cout << "Total Comparisons : " << comparisons << endl;
    cout << "Total Swaps       : " << swapsCount << endl;
    cout << "Time Taken        : " << timeTaken << " microseconds\n";
    cout << "----------------------------------------\n";

    cout << "\n--------- PERFORMANCE INSIGHTS ---------\n";
    cout << "• Quick Sort is efficient for large datasets.\n";
    cout << "• Pivot choice affects performance significantly.\n";
    cout << "• Worst-case occurs when array is already sorted (pivot = last element).\n";
    cout << "• Performs fewer swaps compared to Bubble/Insertion Sort.\n";
    cout << "----------------------------------------\n";

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Let n = number of elements.

BEST CASE (balanced partition):
    Ω(n log n)

AVERAGE CASE:
    Θ(n log n)

WORST CASE (already sorted or reverse-sorted):
    O(n^2)

SPACE COMPLEXITY:
    O(log n)   (recursive stack time)

-----------------------------------------------------------
WHY QUICK SORT IS FAST?
-----------------------------------------------------------
✔ Divide-and-conquer strategy  
✔ Good cache performance  
✔ Very few swaps compared to Bubble or Insertion sort  
✔ Commonly used in system libraries (like C++ sort with modifications)

-----------------------------------------------------------
*/



/*
PS 15) Write a program to perform addition of polynomials using singly linked list.
Each term should have a coefficient and power, and the result should be stored
as another linked list.
*/

#include <iostream>
using namespace std;

// ---------------- NODE STRUCTURE ----------------
class Node {
public:
    int coeff;
    int pow;
    Node *next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = nullptr;
    }
};

// ---------------- POLYNOMIAL CLASS ----------------
class Polynomial {
public:
    Node *front;

    Polynomial() {
        front = nullptr;
    }

    // Insert term at end
    void insertTerm(int coeff, int pow) {
        Node *temp = new Node(coeff, pow);

        if (front == nullptr) {
            front = temp;
            return;
        }

        Node *curr = front;
        while (curr->next != nullptr)
            curr = curr->next;

        curr->next = temp;
    }

    // Display polynomial
    void display() {
        Node *curr = front;

        while (curr != nullptr) {
            cout << curr->coeff << "x^" << curr->pow;
            if (curr->next != nullptr)
                cout << " + ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// ---------------- ADD TWO POLYNOMIALS ----------------
Polynomial addPoly(Polynomial &p1, Polynomial &p2) {
    Polynomial result;

    Node *a = p1.front;
    Node *b = p2.front;

    while (a != nullptr && b != nullptr) {

        if (a->pow == b->pow) {
            result.insertTerm(a->coeff + b->coeff, a->pow);
            a = a->next;
            b = b->next;
        }
        else if (a->pow > b->pow) {
            result.insertTerm(a->coeff, a->pow);
            a = a->next;
        }
        else {
            result.insertTerm(b->coeff, b->pow);
            b = b->next;
        }
    }

    // Remaining terms from p1
    while (a != nullptr) {
        result.insertTerm(a->coeff, a->pow);
        a = a->next;
    }

    // Remaining terms from p2
    while (b != nullptr) {
        result.insertTerm(b->coeff, b->pow);
        b = b->next;
    }

    return result;
}

// --------------------------- MAIN ----------------------------
int main() {
    Polynomial p1, p2;

    int n1, n2, c, p;

    cout << "Enter number of terms for Polynomial 1: ";
    cin >> n1;

    cout << "Enter coefficient and power (c p): \n";
    for (int i = 0; i < n1; i++) {
        cin >> c >> p;
        p1.insertTerm(c, p);
    }

    cout << "Enter number of terms for Polynomial 2: ";
    cin >> n2;

    cout << "Enter coefficient and power (c p): \n";
    for (int i = 0; i < n2; i++) {
        cin >> c >> p;
        p2.insertTerm(c, p);
    }

    cout << "\nPolynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    Polynomial result = addPoly(p1, p2);

    cout << "\nResultant Polynomial: ";
    result.display();

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Let m = number of terms in Polynomial 1
Let n = number of terms in Polynomial 2

INSERT TERM:
    O(1) when list is empty
    O(k) for inserting at end (traversal)

DISPLAY:
    O(n)

ADDITION:
    Similar to merge of two sorted lists

Best Case:    Ω(min(m, n))
Average Case: Θ(m + n)
Worst Case:   O(m + n)

SPACE COMPLEXITY:
    O(m + n)   (result polynomial)

-----------------------------------------------------------
WHY LINKED LIST FOR POLYNOMIALS?
-----------------------------------------------------------
✔ Dynamic number of terms  
✔ Easy to insert terms in sorted power order  
✔ No need for large arrays for large powers  
✔ Efficient merging like merge-sort

-----------------------------------------------------------
*/



/*
PS 16) Write a program to implement a Generalized Linked List (GLL). 
Each node should represent either:
    - An atom (simple data value), or
    - A sublist (linked to another GLL)

Implement creation of GLL using recursion and display it in proper nested format.
*/

#include <iostream>
using namespace std;

class GLL {
public:
    int tag;        // 0 = atom, 1 = sublist
    int data;       // used only when tag = 0
    GLL *down;      // pointer to sublist
    GLL *next;      // pointer to next element in same list

    GLL() {
        tag = 0;
        data = 0;
        down = nullptr;
        next = nullptr;
    }
};

// ------------------------ CREATE GLL ------------------------
GLL* createGLL() {
    GLL *front = nullptr, *rear = nullptr;

    cout << "Enter number of elements in this list: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter tag (0 = atom, 1 = sublist): ";
        int t;
        cin >> t;

        GLL *temp = new GLL();
        temp->tag = t;

        if (t == 0) {
            cout << "Enter atom value: ";
            cin >> temp->data;
        }
        else {
            cout << "Creating sublist...\n";
            temp->down = createGLL();
        }

        if (front == nullptr)
            front = temp;
        else
            rear->next = temp;

        rear = temp;
    }

    return front;
}

// ------------------------ DISPLAY GLL ------------------------
void display(GLL *front) {

    cout << "(";

    GLL *curr = front;

    while (curr != nullptr) {

        if (curr->tag == 0) {
            cout << curr->data;
        }
        else {
            display(curr->down);
        }

        if (curr->next != nullptr)
            cout << ", ";

        curr = curr->next;
    }

    cout << ")";
}

// ------------------------ MAIN PROGRAM ------------------------
int main() {
    cout << "Create Generalized Linked List\n";

    GLL *g = createGLL();

    cout << "\nGLL: ";
    display(g);
    cout << endl;

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Let N = total number of nodes (including all nested sublists)

Creation:
    Every node is visited once.
    Time: O(N)
    Space: O(N) due to recursive calls and node storage.

Display:
    Same as creation — traverses entire structure.
    Time: O(N)
    Space: O(N) from recursion depth.

-----------------------------------------------------------
WHY GLL IS USEFUL?
-----------------------------------------------------------
✔ Represents hierarchical or nested data structures  
✔ Useful in parsing expressions (LISP lists, arithmetic expressions)  
✔ Flexible — supports atoms + sublists  
✔ Dynamic memory allocation  

-----------------------------------------------------------
*/


/*
PS 17) Write a program to implement a singly linked list and perform the following 
operations:
 - Insert at beginning
 - Insert at end
 - Insert at specific position
 - Delete from beginning
 - Delete from end
 - Delete from specific position
 - Search for an element
 - Display the linked list
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *front;

    LinkedList() {
        front = nullptr;
    }

    // ---------------- INSERT AT BEGIN ----------------
    void insertAtBegin(int val) {
        Node *temp = new Node(val);
        temp->next = front;
        front = temp;
        cout << "Inserted at begin\n";
    }

    // ---------------- INSERT AT END ----------------
    void insertAtEnd(int val) {
        Node *temp = new Node(val);

        if (front == nullptr) {
            front = temp;
            cout << "Inserted at end\n";
            return;
        }

        Node *curr = front;
        while (curr->next != nullptr)
            curr = curr->next;

        curr->next = temp;
        cout << "Inserted at end\n";
    }

    // ---------------- INSERT AT POSITION ----------------
    void insertAtPos(int val, int pos) {
        if (pos == 1) {
            insertAtBegin(val);
            return;
        }

        Node *temp = new Node(val);
        Node *curr = front;

        for (int i = 1; i < pos - 1 && curr != nullptr; i++)
            curr = curr->next;

        if (curr == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        temp->next = curr->next;
        curr->next = temp;
        cout << "Inserted at position " << pos << endl;
    }

    // ---------------- DELETE FROM BEGIN ----------------
    void deleteBegin() {
        if (front == nullptr) return;

        Node *temp = front;
        front = front->next;
        delete temp;
        cout << "Deleted from begin\n";
    }

    // ---------------- DELETE FROM END ----------------
    void deleteEnd() {
        if (front == nullptr) return;

        if (front->next == nullptr) {
            delete front;
            front = nullptr;
            cout << "Deleted from end\n";
            return;
        }

        Node *curr = front;
        while (curr->next->next != nullptr)
            curr = curr->next;

        delete curr->next;
        curr->next = nullptr;
        cout << "Deleted from end\n";
    }

    // ---------------- DELETE FROM POSITION ----------------
    void deleteAtPos(int pos) {
        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node *curr = front;

        for (int i = 1; i < pos - 1 && curr != nullptr; i++)
            curr = curr->next;

        if (curr == nullptr || curr->next == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << "Deleted from position " << pos << endl;
    }

    // ---------------- SEARCH ----------------
    bool search(int key) {
        Node *curr = front;

        while (curr != nullptr) {
            if (curr->data == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    // ---------------- DISPLAY ----------------
    void display() {
        Node *curr = front;

        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// ------------------------- MAIN -------------------------
int main() {
    LinkedList L;

    // Sample demonstration
    L.insertAtBegin(10);
    L.insertAtEnd(20);
    L.insertAtEnd(30);
    L.insertAtPos(15, 2);

    cout << "List: ";
    L.display();   // 10 15 20 30

    L.deleteBegin();
    L.deleteEnd();
    L.deleteAtPos(2);

    cout << "After deletion: ";
    L.display();   // 15

    cout << (L.search(15) ? "Found\n" : "Not Found\n");

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Insert at beginning:     O(1)
Insert at end:           O(n)
Insert at position:      O(n)

Delete from beginning:   O(1)
Delete from end:         O(n)
Delete from position:    O(n)

Search an element:       O(n)
Display list:            O(n)

SPACE COMPLEXITY:
O(n) → because list stores n nodes

-----------------------------------------------------------
WHY LINKED LIST?
-----------------------------------------------------------
✔ Dynamic memory allocation  
✔ Fast insertion & deletion at beginning  
✔ No shifting like arrays  
✔ Efficient for frequent updates  

-----------------------------------------------------------
*/



/*
PS 18) Write a program to implement a linked-list-based Music Playlist Manager.
Your program should allow:
 - Add a new song
 - Delete the current song
 - Move to next song
 - Move to previous song
 - Display entire playlist with current song highlighted

Also explain why linked list is better than array for this application 
(dynamic size, fast insertion/deletion).
*/

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node *next;
    Node *prev;

    Node(string val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Playlist {
public:
    Node *front;
    Node *current;

    Playlist() {
        front = nullptr;
        current = nullptr;
    }

    // ---------------- ADD SONG ----------------
    void addSong(string x) {
        Node *temp = new Node(x);

        if (front == nullptr) {
            front = current = temp;
            return;
        }

        Node *cur = front;
        while (cur->next != nullptr)
            cur = cur->next;

        cur->next = temp;
        temp->prev = cur;
    }

    // ---------------- DELETE CURRENT SONG ----------------
    void deleteSong() {
        if (current == nullptr) return;

        Node *temp = current;

        // Move current pointer
        if (current->next != nullptr)
            current = current->next;
        else
            current = current->prev;

        // Fix links
        if (temp == front)
            front = temp->next;

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
    }

    // ---------------- NEXT SONG ----------------
    void nextSong() {
        if (current != nullptr && current->next != nullptr)
            current = current->next;
    }

    // ---------------- PREVIOUS SONG (BUG FIXED) ----------------
    void prevSong() {
        if (current != nullptr && current->prev != nullptr)
            current = current->prev;       //  (You had current->next)
    }

    // ---------------- DISPLAY PLAYLIST ----------------
    void display() {
        Node *t = front;
        while (t != nullptr) {
            if (t == current)
                cout << "[ " << t->data << " ] ";   // highlight current song
            else
                cout << t->data << " ";

            t = t->next;
        }
        cout << "\n";
    }
};

// ------------------------- MAIN -------------------------
int main() {
    Playlist p;

    p.addSong("Song A");
    p.addSong("Song B");
    p.addSong("Song C");
    p.addSong("Song D");

    cout << "Initial Playlist:\n";
    p.display();

    p.nextSong();
    cout << "\nAfter moving to next song:\n";
    p.display();

    p.nextSong();
    p.deleteSong();
    cout << "\nAfter deleting current song:\n";
    p.display();

    p.prevSong();
    cout << "\nAfter moving to previous song:\n";
    p.display();

    return 0;
}

/*
-----------------------------------------------------------
WHY LINKED LIST IS BETTER THAN ARRAY FOR PLAYLIST?
-----------------------------------------------------------

1) **Dynamic Size**
   - Linked list grows/shrinks freely.
   - No need to predefine playlist size.
   - Array has fixed capacity.

2) **Fast Insertion**
   - In linked list, adding a song takes O(1) at end.
   - In array, insertion needs shifting → O(n).

3) **Fast Deletion**
   - Deleting current song in linked list → O(1)
   - Array requires shifting all elements → O(n)

4) **Easy Navigation (Next/Prev)**
   - Doubly linked list supports next/previous songs naturally.
   - Arrays require index management.

 **Conclusion**:  
A playlist changes dynamically (add/remove songs anytime).  
Hence, **Linked List is the perfect data structure**.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Add Song (end):     O(n)
Delete Song:        O(1)
Next Song:          O(1)
Previous Song:      O(1)
Display Playlist:   O(n)

Space Complexity:   O(n)

-----------------------------------------------------------
*/




/*
PS 19) Write a program to implement a Doubly Linked List (DLL). Your program 
should support the following operations:

 - Insert a node at the beginning, at the end, and at any given position
 - Delete a node from the beginning, from the end, and from any given position
 - Display the list in forward and reverse order
 - Search for an element in the list

Also analyse how DLL helps in easier forward–backward navigation compared to a 
singly linked list.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLL {
public:
    Node* front;

    DoublyLL() {
        front = NULL;
    }

    // Insert at beginning
    void insertatbegin(int val) {
        Node* temp = new Node(val);

        if (front == NULL) {
            front = temp;
            return;
        }

        temp->next = front;
        front->prev = temp;
        front = temp;
    }

    // Insert at end
    void insertatend(int val) {
        Node* temp = new Node(val);

        if (front == NULL) {
            front = temp;
            return;
        }

        Node* curr = front;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = temp;
        temp->prev = curr;
    }

    // Insert at position
    void insertpos(int val, int pos) {
        if (pos == 1) {
            insertatbegin(val);
            return;
        }

        Node* temp = new Node(val);
        Node* curr = front;

        for (int i = 1; i < pos - 1 && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL)
            return;

        temp->next = curr->next;
        temp->prev = curr;

        if (curr->next != NULL)
            curr->next->prev = temp;

        curr->next = temp;
    }

    // Delete from beginning
    void deletebegin() {
        if (front == NULL)
            return;

        Node* temp = front;

        if (front->next == NULL) {
            front = NULL;
        }
        else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete from end
    void deleteend() {
        if (front == NULL)
            return;

        if (front->next == NULL) {
            delete front;
            front = NULL;
            return;
        }

        Node* curr = front;
        while (curr->next != NULL)
            curr = curr->next;

        curr->prev->next = NULL;
        delete curr;
    }

    // Delete from position
    void deletepos(int pos) {
        if (pos == 1) {
            deletebegin();
            return;
        }

        Node* curr = front;
        for (int i = 1; i < pos && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL)
            return;

        if (curr->prev != NULL)
            curr->prev->next = curr->next;

        if (curr->next != NULL)
            curr->next->prev = curr->prev;

        delete curr;
    }

    // Search
    bool search(int key) {
        Node* curr = front;
        while (curr != NULL) {
            if (curr->data == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    // Display forward
    void displayforward() {
        Node* curr = front;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Display reverse
    void displayreverse() {
        if (front == NULL)
            return;

        Node* curr = front;
        while (curr->next != NULL)
            curr = curr->next;

        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
};

// ------------------------- MAIN -------------------------
int main() {
    DoublyLL L;

    L.insertatbegin(10);
    L.insertatend(20);
    L.insertatend(30);
    L.insertpos(15, 2);

    L.displayforward();
    L.displayreverse();

    L.deletebegin();
    L.deleteend();
    L.deletepos(2);

    L.displayforward();

    cout << (L.search(20) ? "Found" : "Not Found");

    return 0;
}

/*
-----------------------------------------------------------
DLL NAVIGATION ADVANTAGE (CLEAN)
-----------------------------------------------------------

A Doubly Linked List has two pointers per node:
    next → move forward
    prev → move backward

Forward movement takes:      O(1)
Backward movement takes:     O(1)

In a Singly Linked List:
    Only a next pointer exists.
    Moving backward requires full traversal from head, which is O(n).

Therefore:
A Doubly Linked List allows efficient two-way traversal which is useful in 
applications like playlist navigation, browser history, undo/redo systems.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Insert at beginning:  O(1)
Insert at end:        O(n)
Insert at position:   O(n)

Delete at beginning:  O(1)
Delete at end:        O(n)
Delete at position:   O(n)

Search:               O(n)
Display forward:      O(n)
Display reverse:      O(n)

Space Complexity:     O(n)
-----------------------------------------------------------
*/



/*
PS 20) Write a program to implement a Circular Linked List (CLL). 
Your program should support:
 - Insert a node at the beginning
 - Insert a node at the end
 - Delete a node from the beginning
 - Delete a node from the end
 - Traverse and display all elements
 - Search for an element in the CLL
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class CircularLL {
public:
    Node* front;

    CircularLL() {
        front = NULL;
    }

    // Insert at beginning
    void insertbegin(int x) {
        Node* temp = new Node(x);

        if (front == NULL) {
            front = temp;
            temp->next = temp;   // Circular connection
            return;
        }

        Node* curr = front;
        while (curr->next != front)
            curr = curr->next;

        temp->next = front;
        curr->next = temp;
        front = temp;
    }

    // Insert at end
    void insertend(int x) {
        Node* temp = new Node(x);

        if (front == NULL) {
            front = temp;
            temp->next = temp;
            return;
        }

        Node* curr = front;
        while (curr->next != front)
            curr = curr->next;

        curr->next = temp;
        temp->next = front;
    }

    // Delete from beginning
    void deletefront() {
        if (front == NULL)
            return;

        // Only one node
        if (front->next == front) {
            delete front;
            front = NULL;
            return;
        }

        Node* curr = front;
        while (curr->next != front)
            curr = curr->next;

        Node* temp = front;
        front = front->next;
        curr->next = front;
        delete temp;
    }

    // Delete from end
    void deleteend() {
        if (front == NULL)
            return;

        // Only one node
        if (front->next == front) {
            delete front;
            front = NULL;
            return;
        }

        Node* curr = front;

        while (curr->next->next != front)
            curr = curr->next;

        Node* temp = curr->next;
        curr->next = front;
        delete temp;
    }

    // Search for a value
    bool search(int key) {
        if (front == NULL)
            return false;

        Node* curr = front;

        do {
            if (curr->data == key)
                return true;
            curr = curr->next;
        } while (curr != front);

        return false;
    }

    // Display full circular list
    void display() {
        if (front == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = front;

        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != front);

        cout << endl;
    }
};

// ------------------- MAIN -------------------
int main() {
    CircularLL L;

    L.insertbegin(10);
    L.insertend(20);
    L.insertend(30);
    L.insertbegin(5);

    L.display();   // 5 10 20 30

    L.deletefront();
    L.deleteend();

    L.display();   // 10 20

    cout << (L.search(20) ? "Found" : "Not Found");

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY ANALYSIS
-----------------------------------------------------------

Insert at beginning:       O(n) (need to find last node)
Insert at end:             O(n)
Delete from beginning:     O(n)
Delete from end:           O(n)
Search:                    O(n)
Display:                   O(n)

Space Complexity:          O(n)

-----------------------------------------------------------
NOTES ABOUT CIRCULAR LINKED LIST
-----------------------------------------------------------

1. Last node always points back to the first node.
2. Good for applications like:
   round-robin scheduling, repeat playlists, multiplayer games, token passing.

3. Traversal does not stop at NULL; it continues until the pointer returns to 
   the front node.

4. Insertions and deletions are efficient and structure is easy to maintain.

-----------------------------------------------------------
*/




/*
PS 21) Write a program to convert an Infix expression to Postfix expression.
It must correctly handle:
 - Parentheses
 - Multi-digit operands
 - Operator precedence
 - Invalid input (unbalanced parentheses, invalid characters)
*/

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

// Operator precedence
int prec(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

// Check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {

        if (exp[i] == ' ')
            continue;

        // CASE 1: Multi-digit operand
        if (isalnum(exp[i])) {
            while (i < exp.length() && isalnum(exp[i])) {
                result += exp[i];
                i++;
            }
            result += ' ';
            i--;
        }

        // CASE 2: Opening bracket
        else if (exp[i] == '(') {
            s.push(exp[i]);
        }

        // CASE 3: Closing bracket
        else if (exp[i] == ')') {

            bool foundOpening = false;

            while (!s.empty() && s.top() != '(') {
                result += s.top();
                result += ' ';
                s.pop();
            }

            if (!s.empty() && s.top() == '(') {
                foundOpening = true;
                s.pop();
            }

            if (!foundOpening)
                return "Error: Unbalanced parentheses";
        }

        // CASE 4: Operator
        else if (isOperator(exp[i])) {

            while (!s.empty() && prec(s.top()) >= prec(exp[i])) {
                result += s.top();
                result += ' ';
                s.pop();
            }

            s.push(exp[i]);
        }

        // CASE 5: Invalid character
        else {
            return "Error: Invalid character in expression";
        }
    }

    // Pop remaining operators
    while (!s.empty()) {

        if (s.top() == '(')
            return "Error: Unbalanced parentheses";

        result += s.top();
        result += ' ';
        s.pop();
    }

    return result;
}

int main() {
    string exp;
    cout << "Enter Infix Expression: ";
    getline(cin, exp);

    string postfix = infixToPostfix(exp);
    cout << "Postfix: " << postfix << endl;

    return 0;
}

/*
----------------------------------------------------
TIME & SPACE COMPLEXITY
----------------------------------------------------

Time Complexity:  O(n)
 - Each character of the infix expression is scanned once.
 - Every operator is pushed and popped from the stack at most once.

Space Complexity: O(n)
 - Stack may store all operators.
 - Output postfix expression also takes O(n) space.

----------------------------------------------------
*/



/*
PS 22) Write a program to convert an Infix expression into a Prefix expression.
It must handle:
 - Multi-digit operands
 - Parentheses
 - Operator precedence
 - Invalid characters
 - Unbalanced parentheses
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Operator precedence
int prec(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

// Reverse a string and swap parentheses
string reverseAndSwap(string exp) {
    string rev = "";
    for (int i = exp.length()-1; i >= 0; i--) {
        if (exp[i] == '(') rev += ')';
        else if (exp[i] == ')') rev += '(';
        else rev += exp[i];
    }
    return rev;
}

// Convert infix to postfix (reused for prefix conversion)
string infixToPostfix(string exp) {
    stack<char> s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {

        if (exp[i] == ' ')
            continue;

        // Multi-digit operand
        if (isalnum(exp[i])) {
            while (i < exp.length() && isalnum(exp[i])) {
                result += exp[i];
                i++;
            }
            result += ' ';
            i--;
        }

        else if (exp[i] == '(')
            s.push(exp[i]);

        else if (exp[i] == ')') {
            bool found = false;

            while (!s.empty() && s.top() != '(') {
                result += s.top();
                result += ' ';
                s.pop();
            }

            if (!s.empty() && s.top() == '(') {
                found = true;
                s.pop();
            }

            if (!found)
                return "Error: Unbalanced parentheses";
        }

        else if (isOperator(exp[i])) {
            while (!s.empty() && prec(s.top()) >= prec(exp[i])) {
                result += s.top();
                result += ' ';
                s.pop();
            }
            s.push(exp[i]);
        }

        else {
            return "Error: Invalid character found";
        }
    }

    while (!s.empty()) {
        if (s.top() == '(')
            return "Error: Unbalanced parentheses";

        result += s.top();
        result += ' ';
        s.pop();
    }

    return result;
}

// Convert infix to prefix
string infixToPrefix(string exp) {
    // Step 1: Reverse and swap parentheses
    string rev = reverseAndSwap(exp);

    // Step 2: Convert reversed infix to postfix
    string postfix = infixToPostfix(rev);

    if (postfix.rfind("Error", 0) == 0)    // starts with "Error"
        return postfix;

    // Step 3: Reverse postfix to get prefix
    string prefix = "";
    for (int i = postfix.length()-1; i >= 0; i--)
        prefix += postfix[i];

    return prefix;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    getline(cin, exp);

    string prefix = infixToPrefix(exp);
    cout << "Prefix: " << prefix << endl;

    return 0;
}

/*
------------------------------------------------------------
TIME & SPACE COMPLEXITY
------------------------------------------------------------

Time Complexity:  O(n)
 - Reverse scan: O(n)
 - Infix to Postfix conversion: O(n)
 - Reverse postfix: O(n)

Space Complexity: O(n)
 - Stack holds operators
 - Result string stores prefix expression

------------------------------------------------------------
*/



/*
PS 23) Write a program to Evaluate Postfix Expression.
Program should handle:
 - Multi-digit operands
 - Basic operators: + - * /
*/

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {

        if (exp[i] == ' ')
            continue;

        // Multi-digit number
        if (isdigit(exp[i])) {
            int num = 0;
            while (i < exp.length() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            s.push(num);
            i--;
        }

        // Operator
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (exp[i]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    cout << "Result = " << evaluatePostfix(exp) << endl;

    return 0;
}

/*
-----------------------------------------------
TIME & SPACE COMPLEXITY
-----------------------------------------------
Time Complexity:   O(n)
 - Scans the expression once
 - Each operand/operator processed in constant time

Space Complexity:  O(n)
 - Stack stores operands
-----------------------------------------------
*/


/*
PS 24: Write a program to implement Tower of Hanoi using Recursion.
Move n disks from source rod to destination rod using auxiliary rod.
*/

#include <iostream>
using namespace std;

// A = Source, B = Auxiliary, C = Destination
void tower(int n, char A, char B, char C) {

    if (n <= 0)        // corrected base case
        return;

    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << '\n';
        return;
    }

    // Move n-1 disks from A → B
    tower(n - 1, A, C, B);

    // Move the nth disk from A → C
    cout << "Move disk " << n << " from " << A << " to " << C << '\n';

    // Move n-1 disks from B → C
    tower(n - 1, B, A, C);
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "No moves for n <= 0.\n";
        return 0;
    }

    cout << "Tower of Hanoi moves for " << n << " disks:\n";
    tower(n, 'A', 'B', 'C');   // source A → destination C using B

    return 0;
}

/*
----------------------------------------------------------
TIME & SPACE COMPLEXITY
----------------------------------------------------------

Time Complexity:  O(2^n)
 - Tower of Hanoi makes 2^n - 1 moves
 - Recurrence: T(n) = 2*T(n-1) + 1

Space Complexity: O(n)
 - Due to recursion stack depth n

----------------------------------------------------------
*/



/*
PS 25) Write a program to implement Tower of Hanoi using an explicit stack
       (i.e., simulate recursion without using the recursive function).
*/

#include <iostream>
using namespace std;

struct Frame {
    int n;
    char from, to, aux;
    bool firstCall;   // to simulate recursive steps
};

class Stack {
public:
    Frame s[100];
    int top;

    Stack() { top = -1; }

    void push(Frame f) { s[++top] = f; }
    Frame pop() { return s[top--]; }
    bool empty() { return top == -1; }
};

void towerOfHanoi(int n, char from, char to, char aux) {
    Stack st;

    // push initial frame
    st.push({n, from, to, aux, false});

    while (!st.empty()) {
        Frame f = st.pop();

        if (f.n == 1) {
            cout << "Move disk 1 from " << f.from << " to " << f.to << endl;
            continue;
        }

        if (!f.firstCall) {
            // Simulate recursion:
            // hanoi(n, from, to, aux)

            // Step 3: move n disk (will print after others)
            st.push({f.n, f.from, f.to, f.aux, true});

            // Step 2: hanoi(n-1, aux, to, from)
            st.push({f.n - 1, f.aux, f.to, f.from, false});

            // Step 1: hanoi(n-1, from, aux, to)
            st.push({f.n - 1, f.from, f.aux, f.to, false});
        }
        else {
            // This is equivalent to the "print" step in recursion
            cout << "Move disk " << f.n << " from " << f.from << " to " << f.to << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}


/*
------------------------------------------------------------
TIME & SPACE COMPLEXITY
------------------------------------------------------------

Time Complexity:  O(2^n)
 - Same number of moves as recursive version

Space Complexity: O(n)
 - Explicit stack stores at most n frames

------------------------------------------------------------
*/


/*
PS 26) Write a program to implement Factorial using Recursion.
*/

#include <iostream>
using namespace std;

long long factorial(int n) {

    if (n < 0) 
        return -1;       // invalid input

    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long result = factorial(n);

    if (result == -1)
        cout << "Factorial is not defined for negative numbers.\n";
    else
        cout << "Factorial of " << n << " = " << result << endl;

    return 0;
}

/*
--------------------------------------------------------
TIME & SPACE COMPLEXITY
--------------------------------------------------------
Time Complexity:   O(n)
 - Each recursive call reduces n by 1

Space Complexity:  O(n)
 - Due to recursion stack depth

--------------------------------------------------------
*/


/*
PS 27: Implement Factorial using Explicit Stack (non-recursive).
Use a manual stack to simulate recursive calls.
*/

#include <iostream>
using namespace std;

class Stack {
public:
    int arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

long long factorial_iterative_stack(int n) {
    if (n < 0) return -1;  // invalid input
    if (n == 0 || n == 1) return 1;

    Stack st;

    // Simulate recursive calls: push n, n-1, ..., 2
    while (n > 1) {
        st.push(n);
        n--;
    }

    long long result = 1;

    // Pop all values and multiply (simulating unwinding)
    while (!st.isEmpty()) {
        result *= st.pop();
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long ans = factorial_iterative_stack(n);

    if (ans == -1)
        cout << "Factorial is not defined for negative numbers.\n";
    else
        cout << "Factorial of " << n << " = " << ans << endl;

    return 0;
}

/*
--------------------------------------------------------
TIME & SPACE COMPLEXITY
--------------------------------------------------------
Time Complexity:   O(n)
 - One push per number from n down to 2
 - One pop per number

Space Complexity:  O(n)
 - Manual stack stores up to (n−1) values

--------------------------------------------------------
*/




/*
PS 28) Write a program to implement a Linear Queue using an array.
Operations:
 - Enqueue (Insert)
 - Dequeue (Delete)
 - Peek (Front element)
 - Display all elements
Handle:
 - Overflow
 - Underflow
*/

#include <iostream>
using namespace std;

class LinearQueue {
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    LinearQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~LinearQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
        } else {
            arr[++rear] = value;
            cout << "Inserted\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
        } else {
            cout << "Removed: " << arr[front] << "\n";
            front++;

            // Reset (important for linear queue)
            if (isEmpty()) {
                front = 0;
                rear = -1;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    LinearQueue q(size);

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid Option\n";
        }
    }

    return 0;
}

/*
---------------------------------------------------------
TIME & SPACE COMPLEXITY
---------------------------------------------------------

Enqueue:   O(1)
Dequeue:   O(1)
Peek:      O(1)
Display:   O(n)

Space Complexity:  O(n) 
 - Array of size n

---------------------------------------------------------
*/


/*
PS 29) Write a program to implement a Circular Queue using an array.
Operations:
 - Enqueue
 - Dequeue
 - Peek
 - Display
Also compare how Circular Queue avoids limitations of Linear Queue.
*/

#include <iostream>
using namespace std;

class CircularQueue {
    int front;
    int rear;
    int capacity;
    int* arr;

public:
    CircularQueue(int size) {
        front = -1;
        rear = -1;
        capacity = size;
        arr = new int[size];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == (rear + 1) % capacity);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        cout << "Inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear) { 
            front = rear = -1; 
        }
        else {
            front = (front + 1) % capacity;
        }

        cout << "Removed\n";
    }

    void peek() {
        if (isEmpty())
            cout << "Queue is empty\n";
        else
            cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the Circular Queue: ";
    cin >> size;

    CircularQueue cq(size);

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            cq.enqueue(val);
        }
        else if (choice == 2) {
            cq.dequeue();
        }
        else if (choice == 3) {
            cq.peek();
        }
        else if (choice == 4) {
            cq.display();
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}

/*
------------------------------------------------------------
CIRCULAR QUEUE vs LINEAR QUEUE (Comparison)
------------------------------------------------------------

Linear Queue Limitation:
 - After several enqueues and dequeues,
   front moves ahead and FREE spaces at the beginning
   cannot be reused.
 - It gives FALSE OVERFLOW even if space is available.
   Example:
       [ _ _ x x x ]  front=2, rear=4 → full
       But indices 0 and 1 are empty.

Circular Queue Advantage:
 - Uses modulo (%) to wrap around.
 - Space is reused.
 - No false overflow.
 - Utilizes full array capacity.

------------------------------------------------------------
TIME & SPACE COMPLEXITY
------------------------------------------------------------
Enqueue:   O(1)
Dequeue:   O(1)
Peek:      O(1)
Display:   O(n)

Space Complexity: O(n) for array

------------------------------------------------------------
*/



/*
PS 30: Write a program to implement a Queue using a singly linked list.
Operations:
 - Enqueue
 - Dequeue
 - Display
Explain how linked list avoids overflow issues seen in array implementation.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedQueue {
    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* temp = new Node(value);

        if (isEmpty()) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }

        cout << "Inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr)  // queue becomes empty
            rear = nullptr;

        delete temp;
        cout << "Removed\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedQueue q;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.display();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid option\n";
        }
    }

    return 0;
}

/*
----------------------------------------------------------
WHY LINKED LIST QUEUE AVOIDS OVERFLOW (Compared to Array)
----------------------------------------------------------

Array-based queue:
 - Has a fixed size (capacity).
 - Can overflow even if only a few elements are present but positioned badly
   (linear queue problem).
 - Memory is wasted if queue is not circular.

Linked List-based queue:
 - Dynamic size → grows as long as memory is available.
 - No fixed capacity → no overflow unless system RAM is full.
 - Enqueue and Dequeue do not require shifting elements.
 - Perfect for unpredictable or large data input.

----------------------------------------------------------
TIME & SPACE COMPLEXITY
----------------------------------------------------------

Enqueue:   O(1)
Dequeue:   O(1)
Display:   O(n)

Space Complexity: O(n)  (stores n nodes)

----------------------------------------------------------
*/



/*
PS  31: Write a program to implement a Priority Queue using linked list.
Each element has a value and a priority.
The element with the HIGHEST priority (smallest priority number) is deleted first.
Operations:
 - Insert
 - Delete highest priority
 - Display
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    // Insert based on priority (smaller number = higher priority)
    void insert(int val, int pr) {
        Node* temp = new Node(val, pr);

        if (front == nullptr || pr < front->priority) {
            temp->next = front;
            front = temp;
        }
        else {
            Node* curr = front;
            while (curr->next != nullptr && curr->next->priority <= pr)
                curr = curr->next;

            temp->next = curr->next;
            curr->next = temp;
        }

        cout << "Inserted\n";
    }

    // Remove highest priority element
    void remove() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        cout << "Deleted\n";
    }

    // Display queue elements
    void display() {
        if (front == nullptr) {
            cout << "Priority Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Priority Queue (value, priority): ";
        while (temp != nullptr) {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert\n";
        cout << "2. Delete Highest Priority\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int val, pr;
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter priority (smaller = higher priority): ";
            cin >> pr;
            pq.insert(val, pr);
        }
        else if (choice == 2) {
            pq.remove();
        }
        else if (choice == 3) {
            pq.display();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid option\n";
        }
    }

    return 0;
}

/*
------------------------------------------------------------
TIME & SPACE COMPLEXITY
------------------------------------------------------------

Insert:
 - Worst Case: O(n)   (find correct position)
Delete:
 - O(1)   (delete from front)
Display:
 - O(n)

Space Complexity:
 - O(n) (linked list stores n nodes)

------------------------------------------------------------
WHY LINKED LIST IS GOOD FOR PRIORITY QUEUE?
------------------------------------------------------------
 - No overflow like arrays (unless memory is full).
 - Insertions maintain priority order automatically.
 - Deleting highest priority is O(1) because it is always at the front.
 - Flexible & dynamic size (better for unpredictable workloads).

------------------------------------------------------------
*/



/*
PS 32) Write a program to implement a Double-Ended Queue (Deque)
using a singly linked list.

Operations:
 - Insert Front
 - Insert Rear
 - Delete Front
 - Delete Rear
 - Display
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Insert at front
    void insertFront(int val) {
        Node* temp = new Node(val);

        if (isEmpty()) {
            front = rear = temp;
        }
        else {
            temp->next = front;
            front = temp;
        }

        cout << "Inserted at front\n";
    }

    // Insert at rear
    void insertRear(int val) {
        Node* temp = new Node(val);

        if (isEmpty()) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }

        cout << "Inserted at rear\n";
    }

    // Delete from front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow (Deque is empty)\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        cout << "Deleted from front\n";
    }

    // Delete from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow (Deque is empty)\n";
            return;
        }

        if (front == rear) {  // Only one node
            delete front;
            front = rear = nullptr;
        }
        else {
            Node* curr = front;

            while (curr->next != rear) {
                curr = curr->next;
            }

            delete rear;
            rear = curr;
            rear->next = nullptr;
        }

        cout << "Deleted from rear\n";
    }

    // Display Deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    while (true) {
        cout << "\nMENU\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            dq.insertFront(val);
        }
        else if (choice == 2) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            dq.insertRear(val);
        }
        else if (choice == 3) {
            dq.deleteFront();
        }
        else if (choice == 4) {
            dq.deleteRear();
        }
        else if (choice == 5) {
            dq.display();
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid option\n";
        }
    }

    return 0;
}

/*
-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------
Insert Front      : O(1)
Insert Rear       : O(1)
Delete Front      : O(1)
Delete Rear       : O(n)   (requires traversal)
Display           : O(n)

Space Complexity  : O(n) (linked list stores n nodes)

-----------------------------------------------------------
NOTES:
 - Singly Linked List allows O(1) insertion at both ends.
 - Deleting from rear requires traversal (O(n)).
 - Doubly Linked List can make deleteRear O(1) too.

-----------------------------------------------------------
*/



/*
PS 33: Write a program to simulate a Queue-based system such as:
Printer Spooling, Ticket Counter, or Traffic Management.
Use a queue to model real-world waiting-line behaviour and 
display how requests are processed in order.
*/

#include <iostream>
using namespace std;

class Node {
public:
    string filename;
    Node* next;

    Node(string name) {
        filename = name;
        next = nullptr;
    }
};

class PrintQueue {
    Node* front;
    Node* rear;

public:
    PrintQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Add job
    void addJob(string name) {
        Node* temp = new Node(name);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }

        cout << "Job added to queue.\n";
    }

    // Process job (FIFO order)
    void processJob() {
        if (isEmpty()) {
            cout << "No pending print jobs.\n";
            return;
        }

        Node* temp = front;
        cout << "Processing: " << temp->filename << endl;

        front = front->next;
        if (front == nullptr)
            rear = nullptr;   // queue becomes empty

        delete temp;
    }

    // Display all waiting jobs
    void display() {
        if (isEmpty()) {
            cout << "No jobs in the queue.\n";
            return;
        }

        cout << "Pending Jobs: ";
        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->filename << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PrintQueue pq;

    while (true) {
        cout << "\n--- PRINTER SPOOLING SYSTEM ---\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Job\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter document name: ";
            cin >> name;
            pq.addJob(name);
        }
        else if (choice == 2) {
            pq.processJob();
        }
        else if (choice == 3) {
            pq.display();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}

/*
------------------------------------------------------------
REAL-WORLD BEHAVIOUR (WHY QUEUE?)
------------------------------------------------------------
 - Printing requests arrive one after another (FIFO).
 - First file added must be printed first.
 - Queue models fair waiting lines (ticket counter, traffic, etc.)

------------------------------------------------------------
TIME & SPACE COMPLEXITY
------------------------------------------------------------
Add Job      : O(1)
Process Job  : O(1)
Display      : O(n)

Space Complexity: O(n)
 - Stores each job in a linked list node.

------------------------------------------------------------
*/