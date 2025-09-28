#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// Main menu
int main() {
    int choice, num;

    do {
        printf("\n🔁 Recursive Function Menu\n");
        printf("1. Factorial\n2. Fibonacci Series\n3. Sum of Digits\n4. Exit
