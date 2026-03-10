#include <stdio.h>

int fibonacci(int n) {
    int a = 0, b = 1, fib;

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

int i;
    for (i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer\n");
        return 1;
    }

    printf("Fibonacci number at position %d is: %d\n", n, fibonacci(n));
    return 0;
}