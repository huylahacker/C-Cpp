#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int question1(float a, float b);
int question2(int n);
void question3(float *arr1, int size);
void question4(int height);
int question5(int *arr2,int n);
void question6(char* o, char* p);
int question7(int a, int *check);
int* question8(int ascii_value, int* num_digits);
int question9(int number);
int question10(int number);

int main()
{
	int key;
	while(1)
	{
	printf("============================\n");
	printf("   ***The list of jobs***\n");
	printf("	1. Question 1\n");
	printf("	2. Question 2\n");
	printf("	3. Question 3\n");
	printf("	4. Question 4\n");
	printf("	5. Question 5\n");
	printf("	6. Question 6\n");
	printf("	7. Question 7\n");
	printf("	8. Question 8\n");
	printf("	9. Question 9\n");
	printf("	10. Question 10\n");
	printf("	Press 0 to exit\n");
	printf("============================\n");
	printf("Input your choice: ");
	scanf("%d", &key);
	    
	switch(key)
	{
		case 0:
			{
				printf("Exiting the program.\n");
                return 0;
			} 
		case 1:
			{
				float a, b;
				printf("Input the first number from the keyboard:");
				scanf("%f",&a);
				printf("Input the second number from the keyboard:");
				scanf("%f",&b);
				int result1 = question1(a, b);
				if(result1 == 1)
				{
					printf("a is greater than b.");
				}
				else if(result1 == 0)
				{
					printf("a is equal b.\n");
				}
				else
				{
					printf("a is less than b.\n");
				}
				break;
			}
		case 2:
			{
				int n;
            	printf("Input the number from the keyboard:");
            	scanf("%d", &n);
            	int result2 = question2(n);
            	if (result2 == 0)
            	{
                	printf("Wrong input.");
            	}
            	else
            	{
                	printf("The product of even number from 2 to %d/2 is: %d", n, result2);
            	} 
        
            	break;
			}
		case 3:
			{
                int size;
                printf("Input number of elements: ");
                scanf("%d", &size);
                float *arr1 = (float *) malloc(size * sizeof(float));
                for(int i = 0; i < size; i++)
                {
                    printf("Element %d:",i);
                    scanf("%f",&arr1[i]);
                }
                question3(arr1, size);
                for(int i = 0; i < size; i++)
				{
					printf("%.2f ", arr1[i]);
				}
                free(arr1);
                break;
            }
        case 4:
        	{
        		int height;
        		printf("Input the height of triangle : ");
        		scanf("%d",&height);
        		question4(height);
        		break;
			}
		case 5:
			{
				int n;
				printf("Input the size of array from the keyboard:");
				scanf("%d",&n);
				int *arr2 = (int*) malloc(n * sizeof(int));
				for(int i = 0; i < n; i++)
                {
                    printf("Element %d:",i);
                    scanf("%d",&arr2[i]);
                }
                int result5 = question5(arr2, n);
                if(result5 == 0)
                {
                	printf("Error. Exit program.");
				}
				else
				{
					printf("The sum of squared of each even integer of array is: %d", result5);
				}
				free(arr2);
				break;
			}
		case 6:
			{
				char o[1000];
    			char p[100];
    			printf("Enter the long string 'o': ");
    			fgets(o, sizeof(o), stdin);
    			o[strcspn(o, "\n")] = '\0';
    			printf("Enter the short string 'p': ");
    			fgets(p, sizeof(p), stdin);
    			p[strcspn(p, "\n")] = '\0';
    			question6(o, p);
    			break;
			}
		case 7:
			{
				int n;
				printf("Input the size of array from the keyboard:");
				scanf("%d",&n);
				int *arr3 = (int*) malloc(n * sizeof(int));
				for(int i = 0; i < n; i++)
                {
                    printf("Element %d:",i);
                    scanf("%d",&arr3[i]);
                }
                
    			int count = 0;
    			int *check = (int *) calloc(n, sizeof(int));
    			for(int i = 0; i < n; i++)
    			{
    				if(arr3[i] >= 10 && arr3[i] <=99 && question7(arr3[i], check) == -1)
    				{
    					printf("%d ", arr3[i]);
    					check[count] = arr3[i];
    					count++;
					}
				}
				
				if (count == 0)
    			{
        			printf("There is no two-digit number.");
    			}
    			else if (count == 1)
    			{
        			printf(" There is only one most appearing two-digit number.");
    			}
    			else
    			{
        			printf(" There are more than one most appearing two-digit numbers.");
    			}

    			free(arr3);
				break;
			}
		case 8:
			{
				char character;
    			printf("Input a character from the keyboard: ");
    			scanf(" %c", &character);
    
    			int ascii_value = character;
    			printf("Character in ASCII is: %d\n", ascii_value);

    			int num_digits = 0;
    			int* result = question8(ascii_value, &num_digits);
    			if (result != NULL) 
				{
        			printf("Convert %d to octal: ", ascii_value);
        			for (int i = num_digits - 1; i >= 0; i--) 
					{
            			printf("%d", result[i]);
        			}
        			printf("\n");
        			free(result);
    			}
				break;
			}
		case 9:
			{
				int number;
				printf("Input the number from the keyboard: ");
				scanf("%d", &number);
				int sum = question9(number);
    			printf("Sum of all the digits forming %d: %d\n", number,sum);
    			break;
			}
		case 10:
			{
				int number;
				printf("Input the number to check: ");
				scanf("%d", &number);
				int result = question10(number);
				if(result == 0)
				{
					printf("The number is not prime.");
				}
				else
				{
					printf("The number is prime.");
				}
				break;
			}
		default:
			{
				printf("Invalid choice! Please try again.\n");
                break;
			}              
	}
	}
	return 0;
}

int question1(float a,float b)
{
	if(a > b)
	{
		return 1;
	}
	else if(a == b)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int question2(int n)
{
	int product = 1;
	if (n < 2)
    {
        return 0;
    }
	else
	{
    	int *array = (int*) malloc(n * sizeof(int));
        int index = 0;
        	for (int i = 2; i <= n/2; i++)
        	{
            	if (i % 2 == 0)
            	{
					array[index] = i;
					product = product * array[index];
                	index++;
            	}
        	}
        return product;
    }
}

void question3(float *arr1, int size)
{
	int min, index_min;
	for(int i = 0; i < size - 1; i++)
	{
		min = arr1[i];
		index_min = i;
		for(int j = i + 1; j < size; j++)
		{
			if(min > arr1[j])
			{
				min = arr1[j];
				index_min = j;
			}
		}
		float temp = arr1[i];
		arr1[i] = arr1[index_min];
		arr1[index_min] = temp;
	}
}

void question4(int height)
{
	for(int i = 0; i <= height - 1; i++)
	{
		for(int j = 0; j <= height - 1; j++)
		{
			if(i == 0 || j >= i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int question5(int *arr2, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] % 2 == 0)
        {
            sum = sum + (arr2[i] * arr2[i]);
        }
    }
    return sum;
}

void question6(char* o, char* p)
{
	int i = 0;
    int j = strlen(p) - 1;
    while (i < j) {
        char temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
    char* occurrence = strstr(o, p);
    while (occurrence != NULL) {
        int index = occurrence - o;
        strncpy(occurrence, p, strlen(p));
        i = 0;
        j = strlen(p) - 1;
        while (i < j) 
		{
            char temp = occurrence[i];
            occurrence[i] = occurrence[j];
            occurrence[j] = temp;
            i++;
            j--;
        }
        occurrence = strstr(o + index + strlen(p), p);
    }
    printf("Modified string 'o': %s\n", o);
}

int question7(int a, int *check)
{
	int n = (int) sizeof(check);
    for(int i = 0; i < n; i++)
    {
    	if(check[i] == a)
    	{
    		return 1;
		}
	}
	return -1;
}

int* question8(int ascii_value, int* num_digits) 
{
    int temp = ascii_value;
    *num_digits = 0;

    if (ascii_value == 0) {
        *num_digits = 1;
    }
    else {
        while (temp > 0) {
            temp = temp / 8;
            (*num_digits)++;
        }
    }

    int* arr8 = (int*) malloc(*num_digits * sizeof(int));
    if (arr8 == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    int index = 0;
    while (ascii_value > 0) {
        arr8[index] = ascii_value % 8;
        ascii_value = ascii_value / 8;
        index++;
    }

    return arr8;
}

int question9(int number)
{
	int sum = 0;
    while (number != 0) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }
    return sum;
}

int question10(int number)
{
	if (number < 2)
    {
        return 0;
	}
	for (int i = 2; i * i <= number; i++)
	{
	if (number % i == 0)
        {
            return 0;
        }
	}	
    return 1;
}