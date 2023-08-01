#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int* generateFibonacci(int n);
void extractFirstName(const char* fullName, char* firstName);
void sortNames(char* nameArray[], int size);

int main()
{
    char choice;
    int n;
    int size;
    while (1) 
    {
        printf("MENU:\n");
        printf("Press 'a' to generate a Fibonacci sequence\n");
        printf("Press 'b' to sort an array of names\n");
        printf("Press 'q' to exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) 
        {
            case 'a':
                printf("Enter the number from the keyboard: ");
                scanf("%d", &n);
                
                int* fibSequence = generateFibonacci(n);
                printf("Fibonacci sequence: ");
                for (int i = 0; i < n; i++) 
                {
                    printf("%d ", fibSequence[i]);
                }
                free(fibSequence);
                printf("\n");
                break;
                
            case 'b':
                printf("Enter the number of names: ");
                scanf("%d", &size);
                char** nameArray = (char**)malloc(size * sizeof(char*));
                getchar();
                for (int i = 0; i < size; i++) 
                {
                    nameArray[i] = (char*)malloc(100 * sizeof(char));
                    printf("Enter name %d: ", i + 1);
                    fgets(nameArray[i], 100, stdin);
                    nameArray[i][strcspn(nameArray[i], "\n")] = '\0'; 
                }

                sortNames(nameArray, size);

                printf("After sort names:\n");
                for (int i = 0; i < size; i++) 
                {
                    printf("%s\n", nameArray[i]);
                }

                for (int i = 0; i < size; i++) 
                {
                    free(nameArray[i]);
                }
                free(nameArray);
                break;
            
            case 'q':
                printf("Exiting the program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

int* generateFibonacci(int n) 
{
    int* fibSequence = (int*)malloc(n * sizeof(int));
    fibSequence[0] = 1;
    fibSequence[1] = 1;
  
    for (int i = 2; i < n; i++) 
    {
        fibSequence[i] = fibSequence[i - 1] + fibSequence[i - 2];
    }
  
    return fibSequence;
}

void extractFirstName(const char*full_name,char*first_name) {
	int i;
	const char* lastSpace = strrchr(full_name, ' ');
    int  startIndex = lastSpace - full_name + 1;
    i=0;
    while (full_name[startIndex + i] != '\0') 
	    {first_name[i] = full_name[startIndex + i];
	    i++;}
    first_name[i] = '\0';
}

void sortNames(char* nameArray[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            char firstName1[100];
            char firstName2[100];

            extractFirstName(nameArray[j], firstName1);
            extractFirstName(nameArray[j + 1], firstName2);

            for (int k = 0; firstName1[k]; k++) 
            {
                firstName1[k] = tolower(firstName1[k]);
            }
            for (int k = 0; firstName2[k]; k++) 
            {
                firstName2[k] = tolower(firstName2[k]);
            }

            if (strcmp(firstName1, firstName2) > 0) 
            {
                char temp[100];
                strcpy(temp, nameArray[j]);
                strcpy(nameArray[j], nameArray[j + 1]);
                strcpy(nameArray[j + 1], temp);
            }
        }
    }
}