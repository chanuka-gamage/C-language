#include <stdio.h>

int main() {

    int count_even = 0, count_odd = 0;
    int total_even_summation = 0, total_odd_summation = 0;
    int highest_odd = 0, highest_even = 0;
    int n;
    char choice;

    do {
        printf("Enter the Positive Integer :");
        scanf("%d\n", &n);

        if (n > 0) {
            if (n % 2 == 0) {
                count_even++;
                total_even_summation += n;
                if (n > highest_even) {
                    highest_even = n;
                }
            } else {
                count_odd++;
                total_odd_summation += n;
                if (n > highest_odd) {
                    highest_odd = n;
                }
            }
        }

        printf("Do you want to continue: \n");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nTotal count of the even number which user has entered :%d\n", count_even);
    printf("Total Summation of the even number is:%d\n", total_even_summation);
    printf("Highest Even Number is:%d\n", highest_even);

    printf("Total count of the odd number which user has entered :%d\n", count_odd);
    printf("Total Summation of the odd number is:%d\n", total_odd_summation);
    printf("Highest Odd Number is:%d\n", highest_odd);

    return 0;
}
