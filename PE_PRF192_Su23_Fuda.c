#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float calculateTaxiBill(int distance) {
    float totalCost;
    int unitCost;

    if (distance <= 5) {
        unitCost = 100;
    } else if (distance <= 15) {
        unitCost = 100 + (distance - 5) * 10;
    } else if (distance <= 25) {
        unitCost = 100 + 10 * 10 + (distance - 15) * 8;
    } else {
        unitCost = 100 + 10 * 10 + 10 * 8 + (distance - 25) * 5;
    }

    totalCost = distance * unitCost;

    if (totalCost > 200) {
        totalCost *= 0.9; // Apply 10% discount
    }

    return totalCost;
}

char* convertOctalToBinary(const char* octal) {
    int len = strlen(octal);

    for (int i = 0; i < len; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            return NULL;
        }
    }

    int octalNum = atoi(octal);
    int binaryLen = len * 3 + 1; 
    char* binary = malloc(binaryLen);
    binary[binaryLen - 1] = '\0';

    for (int i = binaryLen - 2; i >= 0; i--) {
        binary[i] = (octalNum % 2) + '0';
        octalNum /= 2;
    }

    return binary;
}

int checkPasswordQuality(const char* password) {
    int length = strlen(password);
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    if (length < 8) {
        return 0; 
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpperCase = 1;
        } else if (islower(password[i])) {
            hasLowerCase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSpecialChar = 1;
        }
    }

    int quality = hasUpperCase + hasLowerCase + hasDigit + hasSpecialChar;

    return quality;
}

int main() {
    int choice;
    int distance;
    char octal[100];
    char password[100];

    do {
        printf("Menu:\n");
        printf("1. Calculate Taxi Fare\n");
        printf("2. Convert Octal to Binary\n");
        printf("3. Check Password Quality\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the distance in kilometers: ");
                scanf("%d", &distance);
                float totalCost = calculateTaxiBill(distance);
                printf("Total cost: %.2f$\n", totalCost);
                break;
            case 2:
                printf("Enter an octal number: ");
                scanf("%s", octal);
                char* binary = convertOctalToBinary(octal);
                if (binary != NULL) {
                    printf("Binary representation: %s\n", binary);
                    free(binary);
                } else {
                    printf("Invalid octal number.\n");
                }
                break;
            case 3:
                printf("Enter a password: ");
                scanf("%s", password);
                int pwQuality = checkPasswordQuality(password);
                printf("Password quality: %d\n", pwQuality);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}
