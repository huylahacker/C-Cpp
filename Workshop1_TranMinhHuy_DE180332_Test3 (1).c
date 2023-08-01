#include <stdio.h>
float power(float x, float number);
int main()
{
	float x, number, sum = 1.0;
    printf("Input x from the keyboard: ");
    scanf("%f", &x);
    printf("Input a number from the keyboard: ");
    scanf("%f", &number);
    for(int i = 1; i <= number; i++)
    {
    	sum = sum + (power(-1,i) * power(x,i)) / i;
	}
	printf("Result: %.3f",sum);
}
float power(float x, float number)
{
	float result = 1.0;
	if (number < 0) {
        return 0;
    } else {
        for (int i = 0; i < number; i++) {
            result *= x;
        }
		return result;
    }
}
 
