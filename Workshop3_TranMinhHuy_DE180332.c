#include<stdio.h>
#include<stdlib.h>

float calculate_waitress(float rate,float hours);
int *generate_square_numbers(int number);
void swap_element(int *arr, int k);

int main()
{
	
	//Calculate the total pay of a waitress
	float rate, hours;
	printf("Input the rate of pay: ");
	scanf("%f",&rate);
	printf("Input the number of hours: ");
	scanf("%f",&hours);
	float total_pay = calculate_waitress(rate, hours);
	printf("The total pay is: %.2f\n",total_pay);
	
	//Generate an array containing square numbers
	int number;
	printf("Input the number from the keyboard: ");
	scanf("%d",&number);
	int *array_square_numbers = generate_square_numbers(number);
	printf("Array containing square numbers\n");
	for(int i = 1; i <= number; i++)
	{
		printf("%d \n", array_square_numbers[i]);
	}
	
	//Array are swapped
	int k, n;
	int *arr = (int *) malloc(n * sizeof(int));
	printf("Input the size of the array: ");
	scanf("%d", &n);
	printf("Input k from the keyboard: ");
	scanf("%d", &k);
	for(int i = 0; i < n; i++)
	{
		printf("Element %d:",i);
		scanf("%d",&arr[i]);
	}
	swap_element(arr, k);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
}

float calculate_waitress(float rate,float hours)
{
	float total_pay;
	if(hours <= 40.0)
	{
		total_pay = rate * hours;
	}
	else
	{
		total_pay = (rate * 40) + (rate * 2 * (hours - 40));
	}
	return total_pay;
}

int *generate_square_numbers(int number)
{
	int *square_numbers = (int *) malloc(number * sizeof(int));
	
	if(number < 0)
	{
		return 0;
	}
	else
	{
		for(int i = 1; i <= number; i++)
		{
			square_numbers[i] = i * i ;
		}
		return square_numbers;
	}	
}

void swap_element(int *arr, int k)
{
	int temp = arr[k];
	arr[k] = arr[k + 1];
	arr[k + 1] = temp;
}