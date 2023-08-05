#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

float question_1(float a, float b, float c);
int check_perfect_square(int number);
int question_2(int number);
int check_prime(int n);
int question_3(int *array, int n);
char* question_4(int n);

int main(){
	int choice;
	while(1){
		printf("	===MENU===\n");
        printf("Press 1 to do question 1\n");
        printf("Press 2 to do question 2\n");
        printf("Press 3 to do question 3\n");
        printf("Press 4 to do question 4\n");
        printf("Press 5 to exit program\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        
        switch(choice){
        	case 1:{
        		float a, b, c;
        		printf("Input three slides from the keyboard: ");
        		scanf("%f %f %f", &a, &b, &c);
        		float result = question_1(a, b, c);
        		if(result == -1){
        			printf("The data is invalid.\n");
				}
				else{
					printf("The area of triangle with three slide %.2f, %.2f, %.2f is: %.2f\n", a, b, c, result);
				}
				break;
			}
			case 2:{
				int number;
				printf("Input the number from the keyboard: ");
				scanf("%d", &number);
				//check__perfect_square(number);
				int result = question_2(number);
				if(result == 0){
					printf("n is not sum of two perfect squares.\n");
				}
				else{
					printf("n is sum of two perfect squares.\n");
				}
				break;
			}
			case 3:{
				int n;
				printf("Input the size of the array from the keyboard: ");
				scanf("%d", &n);
				int *array = (int *) malloc(n * sizeof(int));
				for(int i = 0; i < n; i++)
				{
					printf("Element %d:", i);
					scanf("%d",&array[i]);
				}
				int result = question_3(array, n);
				printf("The max prime number in an array is: %d\n", result);
				break;
			}
			case 4:{
				int n;
				printf("Input the number of characters you want to random: ");
				scanf("%d",&n);
				char *result = question_4(n);
				printf("The characters random is: ");
				for(int i = 0; i < n; i++)
				{
					printf("%c ",result[i]);
				}
				printf("\n");
				break;
			}
			case 5:{
				printf("Exiting the program. Have a good day!\n");
				return 0;
			}
			default :{
				printf("Invalid choice! Please try again.\n");
				break;
			}
		}
	}
}

float question_1(float a, float b, float c){
	float area;
	if((a + b > c) || (a + c > b) || (b + c > a)){
		return -1;
	}
	else{
		float p = (a + b + c) / 2.0;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
		return area;
	}
}

int check_perfect_square(int number){
	if(number > 0)
	{
		for(int i = 0; i <= number; i++)
	{
		if(pow(i,2) == number)
		{
			return 1;
		}
	}
	}
	return 0;
}

int question_2(int number){
	for(int i = 0; i * i <= number; i++){
		int flag = number - i * i;
		if(check_perfect_square(flag)){	
					return 1;
				}
			}	
	return 0;
}

int check_prime(int n){
	if(n < 2){
		return 0;
	}
	
	for (int i = 2; i <= sqrt(n); i++)
    {
    	if (n % i == 0)
            return 0;
	}
	return 1;
}

int question_3(int *array, int n){
	int max = 0;
	for(int i = 0; i < n; i++){
		if(check_prime(array[i]) && array[i]> max)
		{
			max = array[i];
		}
	}
	return max;
}

char* question_4(int n){
	srand(time(NULL));
	char *p = (char *) malloc (n * sizeof(char));
	for (int i = 0; i < n; i++)
    {
        int random_value = rand() % (122 - 97 + 1) + 97;
        p[i] = (char) random_value;
    }
    return p;
}