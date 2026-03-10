#include <stdio.h>

int factorialfunc() {

    int n, i;
    int fact = 1;

    printf("Enter the integer number: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("You entered a negative number.\n");
        return 0;
    }

    for(i = 1; i <= n; i++) {
        fact = fact * i;
    }

    printf("Factorial value: %d\n", fact);

    return fact;
}

int main() {

    factorialfunc();
    return 0;
}
