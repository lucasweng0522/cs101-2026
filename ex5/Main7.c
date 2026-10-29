#include <stdio.h>

int factorial(int n) {
    if (n == 1) return 1;  
    return n * factorial(n - 1);
}

int main() {
    int n, m;
    
   
    printf("請輸入一個正整數: ");
    scanf("%d", &n);
    
  
    m = factorial(n);
    printf("factorial %d = %d\n", n, m);
    
    return 0;
}
