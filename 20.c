#include <stdio.h>

/* Function declarations */
void studentInfo();
void grade();
void scholarshipEligibility();

int main() {
    int choice;

    printf("Choose a statistic to calculate:\n");
    printf("1. Student Information\n");
    printf("2. Grade Calculation\n");
    printf("3. Scholarship Eligibility\n");
    printf("Enter your choice (1 to 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            studentInfo();
            break;

        case 2:
            grade();
            break;

        case 3:
            scholarshipEligibility();
            break;

        default:
            printf("Invalid choice! Please enter 1 to 3 only\n");
    }

    return 0;
}

/* Function to display student information */
void studentInfo() {
    char name[50];
    int roll;
    char phone[15];
    char email[50];

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Phone Number: ");
    scanf("%s", phone);

    printf("Enter Email Address:\n");
    scanf("%s", email);

    printf("Student Name: %s\n", name);
    printf("Roll Number: %d\n", roll);
    printf("Phone Number: %s\n", phone);
    printf("Email Address: %s\n", email);
}

/* Function to calculate grade */
void grade() {
    int sub1, sub2, sub3, total;
    float average;
    char grade;

    printf("Enter marks for Subject 1: ");
    scanf("%d", &sub1);

    printf("Enter marks for Subject 2: ");
    scanf("%d", &sub2);

    printf("Enter marks for Subject 3: ");
    scanf("%d", &sub3);

    total = sub1 + sub2 + sub3;
    average = total / 3.0;

    if (average >= 90)
        grade = 'A';
    else if (average >= 80)
        grade = 'B';
    else if (average >= 70)
        grade = 'C';
    else if (average >= 60)
        grade = 'D';
    else
        grade = 'F';

    printf("Total Marks = %d\n", total);
    printf("Average Marks = %.2f\n", average);
    printf("Grade = %c\n", grade);
}

/* Function to check scholarship eligibility */
void scholarshipEligibility() {
    long income;

    printf("Enter annual family income: ");
    scanf("%ld", &income);

    if (income <= 1000000)
        printf("Student is Eligible for Scholarship\n");
    else
        printf("Student is Not Eligible for Scholarship\n");
}
