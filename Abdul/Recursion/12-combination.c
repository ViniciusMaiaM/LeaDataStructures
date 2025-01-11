#include <stdio.h>

int fact(int n);
int nCr(int n, int r);
int NCR(int n, int r);

int main() {
    printf("%d", NCR(5, 1));
    return 0;
}

int fact(int n){
    if(n == 0){
        return 1;
    }
    return n * fact(n - 1);
}

// Function to calculate nCr using the factorial formula
// nCr = n! / (r! * (n - r)!)
int nCr(int n, int r){
    int num, den;

    // Calculate n! (numerator)
    num = fact(n);
    // Calculate r! and (n-r)! (denominator)
    den = fact(r) * fact(n - r);

    // Return the result of nCr = n! / (r! * (n - r)!)
    return num / den;
}

// Function to calculate nCr using Pascal's Triangle (recursive approach)
// nCr = NCR(n-1, r-1) + NCR(n-1, r)
int NCR(int n, int r){
    if(r == 0 || r == n){
        return 1;
    }
    // Recursive case: use Pascal's Triangle formula
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}
