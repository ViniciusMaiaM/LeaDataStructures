#include <stdio.h>

int func (int n);

int main(){
    int a = 5;

    printf("%d", fun(a));

    return 0;
}

int func (int n){
    Static int x =0; // static variables in recursion
    if(n>0){
        x++
        return fun(n-1)+ x ;
    }
    return 0;
}

// int x = 0; // global variable in recursion
// int func (int n){
//  if(n>0){
//      x++
//      return fun(n-1)+ x ;
//  }
// return 0;
// }
// main(){
//  int a = 5;
//  printf("%d", fun(a));
// }