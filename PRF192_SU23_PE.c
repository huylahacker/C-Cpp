#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float *tShirtBill(int num_Tshirts);
int convertHexaToDec(char* hex);
char *generatePassword(int n);

int main(){
	int choice;
	while(1) {
		printf("|=============================================================================================|\n");
        printf("|Press 1 to calculate total cost and discount when a customer purchases a number of T-shirts  |\n");
        printf("|Press 2 to convert a hex number into decimal value                                           |\n");
        printf("|Press 3 to radom password                                                                    |\n");
        printf("|=============================================================================================|\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1:{
        		int num_Tshirts;
    			printf("Enter the number of T-shirts: ");
    			scanf("%d", &num_Tshirts);

    			float *result = tShirtBill(num_Tshirts);
    			printf("Bill: %.2f, Discount: %.2f, Total cost: %.2f\n", result[0], result[1], result[2]);

    			free(result);
    			printf("\n");
				break;
			}
			case 2:{
				char hex[10];
                printf("Input the hexadecimal number: ");
                scanf("%s", hex);
				int result = convertHexaToDec(hex);
				if(result == -1){
					printf("%s is invalid hex number.", hex);
				} else{
					printf("%s hex in decimal value: %d", hex, result);
				}
				printf("\n");
				break;
			}
			case 3:{
				int n;
    			printf("Enter the password length: ");
    			scanf("%d", &n);
    			char *result = generatePassword(n);
    			if (result == NULL) {
        			printf("Invalid password length. Password length should be between 8 and 10 characters.\n");
    			} else {
        		for(int i = 0; i < n; i++) {
            		printf("%c", result[i]);
        		}
    			}
    			
    			free(result);
    			printf("\n");
				break;
			}
			default :{
				printf("Invalid choice! Please try again.\n");
				printf("\n");
				break;
			}
	}
    
}
}

float *tShirtBill(int num_Tshirts) {
    int unit_cost;
    float discount = 0;
    float Total_cost;
    float Bill;
    float *p = (float *) malloc(num_Tshirts * sizeof(float));

    if (num_Tshirts <= 3) {
        unit_cost = 10;
        p[0] = unit_cost * num_Tshirts;
    } else if (num_Tshirts >= 4 && num_Tshirts <= 7) {
        unit_cost = 8;
        p[0] = (3 * 10) + ((num_Tshirts - 3)) * unit_cost;
    } else if (num_Tshirts >= 7) {
        unit_cost = 6;
        p[0] = (3 * 10) + (4 * 8) + (num_Tshirts - 7) * unit_cost;
    }

    if (p[0] >= 400) {
        discount = p[0] * 0.1;
    }
		p[2] = p[0] - discount;
    return p;
}

int convertHexaToDec(char* hex){
	int dec = 0;
    int length = strlen(hex);
    
    for (int i = 0; i < length; i++) {
        int digitValue;
        
        if (hex[i] >= '0' && hex[i] <= '9') {
            digitValue = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digitValue = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digitValue = hex[i] - 'a' + 10;
        } else {
            return -1;  
        }
        
        dec = dec * 16 + digitValue;
    }
    
    return dec;
}

char *generatePassword(int n) {
    if (n < 8 || n > 10) {
        return NULL;
    }
    
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$^&*?";
    int length = strlen(characters);
    
    srand(time(NULL));
    char *password = (char *) malloc((n + 1) * sizeof(char));
    if (password == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        password[i] = characters[rand() % length];
    }
    
    password[n] = '\0';
    
    return password;
}
