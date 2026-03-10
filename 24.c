#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pd[2];
    int num;
    pid_t pid;

    // Create pipe
    pipe(pd);

    // Create child process
    pid = fork();

    // Child Process: get input
    if (pid == 0) {
        close(pd[0]); // close read end

        printf("Enter the integer number: ");
        scanf("%d", &num);

        write(pd[1], &num, sizeof(num));
        close(pd[1]);
    }

    // Parent Process: check palindrome
    else {
        close(pd[1]); // close write end

        read(pd[0], &num, sizeof(num));
        close(pd[0]);

        int original = num, reverse = 0, remainder;

        while (num != 0) {
            remainder = num % 10;
            reverse = reverse * 10 + remainder;
            num = num / 10;
        }

        printf("\n--------- Parent Process Output ----------\n");
        if (original == reverse)
            printf("%d is a Palindrome number.\n", original);
        else
            printf("%d is NOT a Palindrome number.\n", original);
    }

    return 0;
}