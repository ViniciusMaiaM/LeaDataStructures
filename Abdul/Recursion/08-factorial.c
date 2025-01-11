#include <stdio.h>

int fact(int n);

int main (){
    int r;
    r = fact(30);
    printf("%d\n",r);
    return 0;
}

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}
