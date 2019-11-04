#include <iostream>


// IN: index of Fibonacci sequence
// OUT: Fibonacci number at index
int fibonacci(int n) {
    int a = 0;
    int b = 1;
    
    if (n == 0) return a;
    if (n == 1) return b;

    int c;
    for (int i = 2; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
