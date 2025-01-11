#include <stdio.h>

int sum(int n);

int main (){
    int r;
    r = sum(30);
    printf("%d\n",r);
    return 0;
}

int sum(int n){
    if (n == 0) {
        return 0;
    }
    return sum(n-1) + n;
}
