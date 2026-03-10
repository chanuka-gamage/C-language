#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("A %d\n", getpid());

    // Create B
    pid_t b = fork();
    if (b == 0) {
        printf("B %d , parent %d\n", getpid(), getppid());

        pid_t e = fork();
        if (e == 0) {
            printf("E %d , parent %d\n", getpid(), getppid());
        } else {
            pid_t f = fork();
            if (f == 0) {
                printf("F %d , parent %d\n", getpid(), getppid());
            }
        }
    } else {
        // Create C
        pid_t c = fork();
        if (c == 0) {
            printf("C %d , parent %d\n", getpid(), getppid());
        } else {
            // Create D
            pid_t d = fork();
            if (d == 0) {
                printf("D %d , parent %d\n", getpid(), getppid());

                pid_t g = fork();
                if (g == 0) {
                    printf("G %d , parent %d\n", getpid(), getppid());
                } else {
                    pid_t h = fork();
                    if (h == 0) {
                        printf("H %d , parent %d\n", getpid(), getppid());
                    }
                }
            }
        }
    }

    return 0;
}