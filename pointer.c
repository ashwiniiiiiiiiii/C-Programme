#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to traverse an array using pointers
void traverseArray(int *arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

// Function to swap two numbers using pointers
void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to manipulate strings dynamically using pointers
void manipulateString() {
    char *str = (char *)malloc(100 * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    printf("Original string: %s\n", str);

    // Convert to uppercase using pointer
    for (char *p = str; *p != '\0'; p++) {
        if (*p >= 'a' && *p <= 'z')
            *p -= 32;
    }

    printf("Uppercase string: %s\n", str);
    free(str);
}

// Main function
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\n🔍 Array Traversal Using Pointers\n");
    traverseArray(arr, size);

    int x = 5, y = 10;
    printf("\n🔁 Swapping Numbers Using Pointers\n");
    printf("Before swap: x = %d, y = %d\n", x, y);
    swapNumbers(&x, &y);
    printf("After swap:  x = %d, y = %d\n", x, y);

    printf("\n🧵 Dynamic String Manipulation Using Pointers\n");
    manipulateString();

    return 0;
}
