#include<stdio.h>
int main()
{
	float income=0.00;
	printf("Enter your monthly income in VND:");
	scanf("%f",&income);
	if (income < 0)
	{
		printf("Input error");
	}
	else if(income <= 9000000)
	{
		printf("You will not pay");
	}
	else if(income > 9000000 && income < 15000000)
	{
		printf("You must pay %.2f VND",income-(income * 0.1));
	}
	else
	{
		printf("You must pay %.2f VND",income-(income * 0.2));
	}
	return 0;
}