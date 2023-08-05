#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100

char names[MAX_STUDENTS][50];
int ages[MAX_STUDENTS];
float gpas[MAX_STUDENTS];
int num_students = 0;

void display_students();
void add_student();
void sort_students();
void search_student(char *name);
void write_students_to_file();
void delete_student(char *name);
void delete_all_students();
void remove_spaces(char *str);

int main() {
    int choice;

    do {
    	printf("\n|=======================================================================|\n");
        printf("|                 MANAGE INFORMATION STUDENTS                         	|\n");
        printf("|=======================================================================|\n");
        printf("|       1        |Display list students                                 |\n");
        printf("|       2        |Add students list                                     |\n");
        printf("|       3        |Sort students                                         |\n");
        printf("|       4        |Search students                                       |\n");
        printf("|       5        |Write students to file                                |\n");
        printf("|       6        |Delete students                                       |\n");
        printf("|       7        |Delete all students                                   |\n");
        printf("|       8        |Exit program                                          |\n");
        printf("|=======================================================================|\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:{
            	display_students();
            	system("pause");
				system("cls");
				break;
			}
            case 2:{
            	add_student();
            	system("pause");
				system("cls");
				break;
			}
            case 3:{
            	sort_students();
            	system("pause");
				system("cls");
				break;
			}
            case 4:{
                char search_name[50];
                printf("Enter student name to search: ");
                scanf(" %[^\n]", search_name);
                search_student(search_name);
                system("pause");
				system("cls");
                break;
            }
            case 5:{
            	write_students_to_file();
            	system("pause");
				system("cls");
				break;
			}
            case 6:{
                char delete_name[50];
                printf("Enter student name to delete: ");
                scanf(" %[^\n]", delete_name);
                delete_student(delete_name);
                system("pause");
				system("cls");
                break;
            }
            case 7:{
            	delete_all_students();
            	system("pause");
				system("cls");
				break;
			}
            case 8:{
            	printf("Exiting program. Have a good day!\n");
				break;
			}
            default:{
            	printf("Invalid choice. Please try again.\n");
				break;
			}
        }
        printf("\n");
    } while (choice != 8);
	system("pause");
	system("cls");
    return 0;
}

void display_students() {
    FILE *fp;
    char name[50];
    int age;
    float gpa;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Student Information:\n");
    printf("--------------------\n");

    while (fscanf(fp, "%[^,],%d,%f\n", name, &age, &gpa) == 3) {
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("GPA: %.2f\n", gpa);
        printf("\n");
    }

    fclose(fp);
}

void add_student() {
    FILE *fp;
    char name[50];
    int age;
    float gpa;

    printf("Enter student name: ");
    scanf(" %[^\n]", name);

    // Remove extra spaces in the name
    remove_spaces(name);

    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }

    // Input validation for age
    while (1) {
        printf("Enter student age: ");
        if (scanf("%d", &age) == 1) {
            break;  // Valid input, exit the loop
        }
        printf("Invalid input for age. Please enter a valid integer.\n");
        // Clear the input buffer
        while (getchar() != '\n');
    }

    // Input validation for GPA
    while (1) {
        printf("Enter student GPA: ");
        if (scanf("%f", &gpa) == 1) {
            break;  // Valid input, exit the loop
        }
        printf("Invalid input for GPA. Please enter a valid float number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
    }

    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fp, "%s,%d,%.2f\n", name, age, gpa);
    fclose(fp);

    printf("Student added to file.\n");
}

void sort_students() {
    FILE *fp;
    int i, j;
    char temp_name[50];
    int temp_age;
    float temp_gpa;

    // Read all student information from the file
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i = 0; fscanf(fp, "%[^,],%d,%f\n", names[i], &ages[i], &gpas[i]) == 3; i++) {
        // Read the student information into arrays
    }

    fclose(fp);
    num_students = i;

    // Menu for selecting sorting criteria
    int choice;
    printf("Sorting Options:\n");
    printf("1. Sort by Name\n");
    printf("2. Sort by Age\n");
    printf("3. Sort by GPA\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Sort the students based on the selected criteria
    switch (choice) {
        case 1:
            // Sort by name
            for (i = 0; i < num_students - 1; i++) {
                for (j = 0; j < num_students - i - 1; j++) {
                    if (strcmp(names[j], names[j + 1]) > 0) {
                        // Swap student information
                        strcpy(temp_name, names[j]);
                        strcpy(names[j], names[j + 1]);
                        strcpy(names[j + 1], temp_name);

                        temp_age = ages[j];
                        ages[j] = ages[j + 1];
                        ages[j + 1] = temp_age;

                        temp_gpa = gpas[j];
                        gpas[j] = gpas[j + 1];
                        gpas[j + 1] = temp_gpa;
                    }
                }
            }
            printf("Students sorted by name.\n");
            break;
        case 2:
            // Sort by age
            for (i = 0; i < num_students - 1; i++) {
                for (j = 0; j < num_students - i - 1; j++) {
                    if (ages[j] > ages[j + 1]) {
                        // Swap student information
                        strcpy(temp_name, names[j]);
                        strcpy(names[j], names[j + 1]);
                        strcpy(names[j + 1], temp_name);

                        temp_age = ages[j];
                        ages[j] = ages[j + 1];
                        ages[j + 1] = temp_age;

                        temp_gpa = gpas[j];
                        gpas[j] = gpas[j + 1];
                        gpas[j + 1] = temp_gpa;
                    }
                }
            }
            printf("Students sorted by age.\n");
            break;
        case 3:
            // Sort by GPA
            for (i = 0; i < num_students - 1; i++) {
                for (j = 0; j < num_students - i - 1; j++) {
                    if (gpas[j] > gpas[j + 1]) {
                        // Swap student information
                        strcpy(temp_name, names[j]);
                        strcpy(names[j], names[j + 1]);
                        strcpy(names[j + 1], temp_name);

                        temp_age = ages[j];
                        ages[j] = ages[j + 1];
                        ages[j + 1] = temp_age;

                        temp_gpa = gpas[j];
                        gpas[j] = gpas[j + 1];
                        gpas[j + 1] = temp_gpa;
                    }
                }
            }
            printf("Students sorted by GPA.\n");
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

	printf("Sorted Student Information:\n");
    printf("---------------------------\n");

    for (i = 0; i < num_students; i++) {
        printf("Name: %s\n", names[i]);
        printf("Age: %d\n", ages[i]);
        printf("GPA: %.2f\n", gpas[i]);
        printf("\n");
    }
    
    // Write the sorted student information back to the file
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%d,%.2f\n", names[i], ages[i], gpas[i]);
    }

    fclose(fp);
}

void remove_spaces(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void search_student(char *name) {
    FILE *fp;
    char student_name[50];
    int age;
    float gpa;
    int found = 0;

    // Remove spaces from the input name
    remove_spaces(name);

    // Convert the input name to lowercase
    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(fp, "%[^,],%d,%f\n", student_name, &age, &gpa) == 3) {
        // Remove spaces from the stored name
        remove_spaces(student_name);

        // Convert the stored name to lowercase
        for (int i = 0; student_name[i] != '\0'; i++) {
            student_name[i] = tolower(student_name[i]);
        }

        if (strcasecmp(student_name, name) == 0) {
            printf("Student found:\n");
            printf("Name: %s\n", student_name);
            printf("Age: %d\n", age);
            printf("GPA: %.2f\n", gpa);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Student not found.\n");
        return;
    }
}

void write_students_to_file() {
    if (num_students == 0) {
        printf("No student information to write.\n");
        return;
    }

    FILE *fp;
    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%d,%.2f\n", names[i], ages[i], gpas[i]);
    }

    printf("Student information written to file successfully.\n");
    fclose(fp);
}

void delete_student(char *name) {
    FILE *original_fp, *temp_fp;
    char student_name[50];
    int age;
    float gpa;
    int found = 0;

    original_fp = fopen("students.txt", "r");
    if (original_fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    temp_fp = fopen("temp.txt", "w");
    if (temp_fp == NULL) {
        printf("Error creating temporary file.\n");
        fclose(original_fp);
        return;
    }

    while (fscanf(original_fp, "%[^,],%d,%f\n", student_name, &age, &gpa) == 3) {
        if (strcmp(student_name, name) != 0) {
            fprintf(temp_fp, "%s,%d,%.2f\n", student_name, age, gpa);
        } else {
            found = 1;
        }
    }

    fclose(original_fp);
    fclose(temp_fp);

    if (!found) {
        printf("Student not found.\n");
        remove("temp.txt");
    } else {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        printf("Student deleted.\n");
    }
}

void delete_all_students() {
    FILE *fp;

    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fclose(fp);
    num_students = 0;
    printf("All student information deleted.\n");
}