#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[100];
    char className[20];
    char id[20];
} Student;

Student students[MAX];
int count = 0;

void removeNewLine(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

void addStudent() {
    if (count >= MAX)
    {
        printf("Database full!\n");
        return;
    }

    printf("Enter Name: ");
    getchar();
    fgets(students[count].name, sizeof(students[count].name), stdin);
    removeNewLine(students[count].name);

    printf("Enter Class: ");
    fgets(students[count].className, sizeof(students[count].className), stdin);
    removeNewLine(students[count].className);

    printf("Enter ID: ");
    fgets(students[count].id, sizeof(students[count].id), stdin);
    removeNewLine(students[count].id);

    count++;

    printf("Student added successfully!\n");
}

void showAll() {
    printf("\n--- Student List (%d) ---\n", count);

    for (int i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Name  : %s\n", students[i].name);
        printf("Class : %s\n", students[i].className);
        printf("ID    : %s\n", students[i].id);
    }
}

void searchStudent() {
    char id[20];
    printf("Enter ID to search: ");
    scanf("%s", id);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0)
        {
            printf("\nStudent Found!\n");
            printf("Name  : %s\n", students[i].name);
            printf("Class : %s\n", students[i].className);
            printf("ID    : %s\n", students[i].id);
            return;
        }
    }

    printf("Student not found!\n");
}

void giveTC() {
    char id[20];
    printf("Enter ID for TC: ");
    scanf("%s", id);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].id, id) == 0)
        {

            for (int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;
            printf("TC given successfully (Student removed)\n");
            return;
        }
    }

    printf("Student not found!\n");
}

int main() {
    int choice;

    while (1)
    {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Give TC (Remove Student)\n");
        printf("5. Total Students\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                showAll();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                giveTC();
                break;
            case 5:
                printf("Total Students: %d\n", count);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
