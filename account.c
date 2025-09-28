#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[100];
    float balance;
};

// Function to create a new account
void createAccount() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);
    printf("✅ Account created successfully!\n");
}

// Function to display account details
void viewAccount() {
    int accNo, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    printf("Enter Account Number to view: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("\n📄 Account Details:\n");
            printf("Account No: %d\nName: %s\nBalance: ₹%.2f\n", acc.accNo, acc.name, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("❌ Account not found.\n");
    fclose(fp);
}

// Function to deposit money
void depositMoney() {
    int accNo, found = 0;
    float amount;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb+");

    printf("Enter Account Number to deposit into: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter amount to deposit: ₹");
            scanf("%f", &amount);
            acc.balance += amount;

            fseek(fp, -sizeof
