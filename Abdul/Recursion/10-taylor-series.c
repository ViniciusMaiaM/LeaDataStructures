#include <stdio.h>

// Function to compute e^x using the Taylor series
// x: the exponent
// n: the number of terms in the Taylor series
double e(int x, int n);

int main(){
    printf("%lf \n", e(1, 100));
    return 0;
}

double e(int x, int n) {
    // Static variables to store intermediate results across recursive calls
    static double p = 1; // p represents x^i (power of x), initialized to 1 (x^0)
    static double f = 1; // f represents i! (factorial), initialized to 1 (0!)

    double r;

    if (n == 0) {
        return 1;
    }

    r = e(x, n - 1);

    // Update power and factorial for the current term
    p *= x;  // Multiply p by x to get x^n
    f *= n;  // Multiply f by n to get n!

    // Return the sum of the previous terms and the current term (p / f)
    return r + p / f;
}

// Using Horner's method
// double e(int x, int n){
//     static double s;
//     if(n == 0){
//         return 1;
//     }
//     s = 1+x*s/n;
//     return e(x, n - 1);
// }

// Iterative approach
// double e(int x, int n){
//     double s=1;
//     double num=1;
//     double den=1;

//     int i;
//     for(i=1;i<=n;i++){
//         num*=x;
//         den*=i;
//         s+=num/den;
//     }

//     return s;
// }