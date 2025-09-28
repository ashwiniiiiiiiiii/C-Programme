#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char str[]) {
    int len = strlen(str);
    printf("Reversed String: ");
    for (int i = len - 1; i >= 0; i--)
        putchar(str[i]);
    printf("\n");
}

// Function to check if a string is a palindrome
void checkPalindrome(char str[]) {
    int len = strlen(str);
    int isPalindrome = 1;

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("✅ The string is a palindrome.\n");
    else
        printf("❌ The string is not a palindrome.\n");
}

// Function to concatenate two strings
void concatenateStrings(char str1[], char str2[]) {
    char result[200];
    strcpy(result, str1);
    strcat(result, str2);
    printf("Concatenated String: %s\n", result);
}

// Function to count words in a string
void countWords(char str[]) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i]; i++) {
        if (isspace(str[i]))
            inWord = 0;
        else if (!inWord) {
            inWord = 1;
            count++;
        }
    }

    printf("Word Count: %d\n", count);
}

// Main menu
int main
