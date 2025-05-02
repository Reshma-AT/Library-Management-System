#include <stdio.h>
struct Book {
    int id;
    char title[100];
    char author[100];
    int day, month, year;
};

struct Book library[100];
int count = 0;
void addBook() {
    printf("\n========== Add a New Book ==========\n");

    printf("Enter Book ID          : ");
    scanf("%d", &library[count].id);
    getchar(); // Clear newline

    printf("Enter Book Title       : ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Book Author      : ");
    scanf(" %[^\n]", library[count].author);

    printf("Enter Date of Issuance (DD MM YYYY): ");
    scanf("%d %d %d", &library[count].day, &library[count].month, &library[count].year);

    count++;
    printf("\nBook added successfully!\n");
}
void displayBooks() {
    printf("\n========== Library Book List ==========\n");

    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("ID            : %d\n", library[i].id);
        printf("Title         : %s\n", library[i].title);
        printf("Author        : %s\n", library[i].author);
        printf("Issued Date   : %02d-%02d-%04d\n",
               library[i].day, library[i].month, library[i].year);
    }
}

void searchBook() {
    int id;
    printf("\n========== Search for a Book ==========\n");
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID            : %d\n", library[i].id);
            printf("Title         : %s\n", library[i].title);
            printf("Author        : %s\n", library[i].author);
            printf("Issued Date   : %02d-%02d-%04d\n",
                   library[i].day, library[i].month, library[i].year);
            return;
        }
    }

    printf("Sorry, no book found with ID %d.\n", id);
}

int main() {
    int choice;

    printf("========================================\n");
    printf("  Welcome to the Library Management App\n");
    printf("========================================\n");

    while (1) {
        printf("\n------------ Menu ------------\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book by ID\n");
        printf("4. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nThank you for using the Library Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 to 4.\n");
        }
    }

    return 0;
}
