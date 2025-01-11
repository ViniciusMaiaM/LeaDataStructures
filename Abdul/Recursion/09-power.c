#include <stdio.h>

int power(int a, int b);

int main(){
    int r;

    r = power(2, 10);
    printf("%d\n", r);

    return 0;
}

// Optimized recursive power function using exponentiation by squaring
int power(int a, int b) {
    if (b == 0) return 1;

    // Recursive case for even exponent:
    // If b is even, we reduce the problem size by halving b and squaring a
    if (b % 2 == 0) {
        return power(a * a, b / 2); // Square the base and halve the exponent
    }

    // Recursive case for odd exponent:
    // If b is odd, we subtract 1 from b (making it even),
    // square the base, and multiply by the original base once
    return a * power(a * a, (b - 1) / 2);
}


// Base version
// int power(int a, int b){
//     if(b == 0) return 1;
//     return a * power(a, b - 1);
// }