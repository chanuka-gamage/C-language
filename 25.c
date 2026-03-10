#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int p2c[2];   // Parent to Child
    int c2p[2];   // Child to Parent
    pid_t pid;
    int n;
    long long fact = 1;

    // Create pipes
    pipe(p2c);
    pipe(c2p);

    // Create child process
    pid = fork();

    // Parent Process
    if (pid > 0) {
        close(p2c[0]); // Close read end of parent-to-child
        close(c2p[1]); // Close write end of child-to-parent

        printf("Enter an integer number: ");
        scanf("%d", &n);

        // Send n to child
        write(p2c[1], &n, sizeof(n));
        close(p2c[1]);

        // Receive factorial from child
        read(c2p[0], &fact, sizeof(fact));
        close(c2p[0]);

        printf("\n------ Parent Process Output ------\n");
        printf("Factorial of %d is: %lld\n", n, fact);
    }

    // Child Process
    else {
        close(p2c[1]); // Close write end of parent-to-child
        close(c2p[0]); // Close read end of child-to-parent

        // Receive n from parent
        read(p2c[0], &n, sizeof(n));
        close(p2c[0]);

        // Calculate factorial
		int i;
        for (i = 1; i <= n; i++) {
            fact *= i;
        }

        // Send factorial to parent
        write(c2p[1], &fact, sizeof(fact));
        close(c2p[1]);
    }

    return 0;
}