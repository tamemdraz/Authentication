#include <stdio.h>
#include <string.h>

#define MAX_USERS 30

struct User {
    char user[100];
    char pass[100];
};

struct User users[MAX_USERS];
int count = 0;

void registerUser() {
    if (count >= MAX_USERS) {
        printf("Can't register more users.\n");
        return;
    }

    printf("Enter a user: ");
    scanf("%s", users[count].user);

    printf("Enter a pass: ");
    scanf("%s", users[count].pass);

    count++;

    printf(" register successfully.\n");
}

int authenticateUser() {
    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < count; i++) {
        if (strcmp(username, users[i].user) == 0 && strcmp(password, users[i].pass) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int choice;
    int authenticated = 0;

    while (1) {
        printf("1. Register\n2. Login\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                authenticated = authenticateUser();
                if (authenticated) {
                    printf("Welcome, %s!\n", users[count - 1].user);
                } else {
                    printf(" failed. Please try again.\n");
                }
                break;
            case 3:
                printf("End!\n");
                return 0;
            default:
                printf("Invalid choice. try again.\n");
        }
    }

    return 0;
}
