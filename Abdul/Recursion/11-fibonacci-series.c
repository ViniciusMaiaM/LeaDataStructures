#include <stdio.h>

int mfib(int n);
int F[10];

int main(){
    for (int i = 0; i < 10; i++){
        F[i] = -1;
    }
    return 0;
}

//Memoized version
int mfib(int n){
    if (n <= 1){
        F[n] = n;
        return n;
    }

    // Check if Fibonacci of (n-2) is already computed
    if (F[n-2] == -1) {
        // If not computed, recursively calculate and store it
        F[n-2] = mfib(n-2);
    }

    // Check if Fibonacci of (n-1) is already computed
    if (F[n-1] == -1) {
        // If not computed, recursively calculate and store it
        F[n-1] = mfib(n-1);
    }

    // Combine the results of F(n-2) and F(n-1) to compute F(n)
    F[n] = F[n-2] + F[n-1];
    return F[n-2] + F[n-1];
}

// Base version
// int fib(int n){
//     if (n <= 1){
//         return n;
//     }
//     return fib(n-2) + fib(n-1);
// }

// Iterative version
// int fib(int n){
//     int f1 = 0, f2 = 1, f3;
//     if (n <= 1){
//         return n;
//     }
//     for (int i = 2; i <= n; i++){
//         f3 = f1 + f2;
//         f1 = f2;
//         f2 = f3;
//     }
//     return f3;
// }
