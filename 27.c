#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define PI 3.14

float areaCircle();
float areaTriangle();
float areaSquare();
float areaRectangle();

int main() {
    int p2c[2]; // parent to child
    int c2p[2]; // child to parent
    pid_t pid;
    int choice;
    float area;

    pipe(p2c);
    pipe(c2p);

    pid = fork();

    // ---------- Child ----------
    if (pid == 0) {
        close(p2c[1]);
        close(c2p[0]);

        read(p2c[0], &choice, sizeof(choice));

        switch (choice) {
            case 1: area = areaCircle(); break;
            case 2: area = areaTriangle(); break;
            case 3: area = areaSquare(); break;
            case 4: area = areaRectangle(); break;
            default: area = -1;
        }

        write(c2p[1], &area, sizeof(area));
    }

    // ---------- Parent ----------
    else {
        close(p2c[0]);
        close(c2p[1]);

        printf("1.Circle  2.Triangle  3.Square  4.Rectangle\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        write(p2c[1], &choice, sizeof(choice));
        read(c2p[0], &area, sizeof(area));

        if (area < 0)
            printf("Invalid choice\n");
        else
            printf("Area = %.2f\n", area);
    }

    return 0;
}

// -------- Area Functions --------

float areaCircle() {
    float r;
    printf("Enter radius: ");
    scanf("%f", &r);
    return PI * r * r;
}

float areaTriangle() {
    float b, h;
    printf("Enter base: ");
    scanf("%f", &b);
    printf("Enter height: ");
    scanf("%f", &h);
    return 0.5 * b * h;
}

float areaSquare() {
    float a;
    printf("Enter side: ");
    scanf("%f", &a);
    return a * a;
}

float areaRectangle() {
    float l, w;
    printf("Enter length: ");
    scanf("%f", &l);
    printf("Enter width: ");
    scanf("%f", &w);
    return l * w;
}