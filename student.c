#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNumber;
    char name[100];
    float marks;
};

void addStudent(struct Student students[], int *studentCount) {
    if (*studentCount < MAX_STUDENTS) {
        printf("Enter roll number: ");
        scanf("%d", &students[*studentCount].rollNumber);
        getchar(); // To consume the newline character after entering roll number
        printf("Enter student name: ");
        fgets(students[*studentCount].name, 100, stdin);
        students[*studentCount].name[strcspn(students[*studentCount].name, "\n")] = '\0'; // Remove newline character
        printf("Enter marks: ");
        scanf("%f", &students[*studentCount].marks);

        (*studentCount)++;
        printf("Student added successfully!\n");
    } else {
        printf("Cannot add more students, maximum limit reached!\n");
    }
}

void displayStudents(struct Student students[], int studentCount) {
    if (studentCount == 0) {
        printf("No students to display!\n");
        return;
    }

    printf("\n--- List of Students ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("------------------------\n");
    }
}

void modifyStudent(struct Student students[], int studentCount) {
    int rollNumber;
    printf("Enter roll number of the student to modify: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new name: ");
            getchar(); // Consume newline character
            fgets(students[i].name, 100, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline character
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student details updated successfully!\n");
            return;
        }
    }

    printf("Student with roll number %d not found!\n", rollNumber);
}

void deleteStudent(struct Student students[], int *studentCount) {
    int rollNumber;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < *studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < *studentCount - 1; j++) {
                students[j] = students[j + 1]; // Shift students
            }
            (*studentCount)--; // Decrease student count
            printf("Student deleted successfully!\n");
            return;
        }
    }

    printf("Student with roll number %d not found!\n", rollNumber);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n----- Student Management System -----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Modify Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                modifyStudent(students, studentCount);
                break;
            case 4:
                deleteStudent(students, &studentCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
