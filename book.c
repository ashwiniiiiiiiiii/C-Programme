#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    float price;
};

// Function to add a book
void addBook() {
    struct Book b;
    FILE *fp = fopen("books.dat", "ab");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", b.author);
    printf("Enter Price: ");
    scanf("%f", &b.price);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    printf("✅ Book added successfully!\n");
}

// Function to search for a book
void searchBook() {
    int id, found = 0;
    struct Book b;
    FILE *fp = fopen("books.dat", "rb");

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("\n📘 Book Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nPrice: ₹%.2f\n", b.id, b.title, b.author, b.price);
            found = 1;
            break;
        }
    }

    if (!found) printf("❌ Book not found.\n");
    fclose(fp);
}

// Function to update a book
void updateBook() {
    int id, found = 0;
    struct Book b;
    FILE *fp = fopen("books.dat", "rb+");

    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("Enter new Title: ");
            scanf(" %[^\n]", b.title);
            printf("Enter new Author: ");
            scanf(" %[^\n]", b.author);
            printf("Enter new Price: ");
            scanf("%f", &b.price);

            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            found = 1;
            printf("✅ Book updated successfully!\n");
            break;
        }
    }

    if (!found) printf("❌ Book not found.\n");
    fclose(fp);
}

// Function to delete a book
void deleteBook() {
    int id, found = 0;
    struct Book b;
    FILE *fp = fopen("books.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id != id) {
            fwrite(&b, sizeof(b), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("books.dat");
    rename("temp.dat", "books.dat");

    if (found)
        printf("✅ Book deleted successfully!\n");
    else
        printf("❌ Book not found.\n");
}

// Function to display all books
void displayBooks() {
    struct Book b;
    FILE *fp = fopen("books.dat", "rb");

    printf("\n📚 All Book Records:\n");
    printf("--------------------------------------------------\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\nPrice: ₹%.2f\n", b.id, b.title, b.author, b.price);
        printf("--------------------------------------------------\n");
    }

    fclose(fp);
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n📖 Book Record Management System\n");
        printf("1. Add Book\n2. Search Book\n3. Update Book\n4. Delete Book\n5. Display All Books\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: updateBook(); break;
            case 4: deleteBook(); break;
            case 5: displayBooks(); break;
            case 6: printf("👋 Exiting program...\n"); break;
            default: printf("⚠️ Invalid choice. Try again.\n");
        }
    } while
