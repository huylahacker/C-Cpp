#include <stdio.h>

int check(int number); //a function to check whether a number is prime
int calculate(int number); //a function to calculate n! = 1*2*3…*n
int locate(float point_x, float point_y, float center_x, float center_y, float radius); //a function to check the relative position between a point and a circle where the circle has a center at (2, 3)

int main()
{
    int number;
    printf("Input a number from the keyboard:");
    scanf("%d", &number);

    int prime = check(number);
    if (prime == 0)
    {
        printf("The number is not prime so can not print list primes from 2 to %d.\n", number);
    }
    else
    {
        printf("List of prime numbers from 2 to %d:\n", number);
        for (int j = 2; j <= number; j++)
        {
            if (check(j))
            {
                printf("%d ", j);
            }
        }
    }

    int factorial = calculate(number);
    if (factorial == 0)
    {
        printf("\nWrong input.");
    }
    else if (factorial == 1)
    {
        printf("\n%d! = 1", number);
    }
    else
    {
        printf("\n%d! = %d", number, factorial);
    }
    
    float point_x, point_y;
    float center_x = 2.0, center_y = 3.0, radius = 5.0;
    printf("\nEnter the coordinates of the point (x, y): ");
    scanf("%f %f", &point_x, &point_y);    
	
    int position = locate(point_x, point_y, center_x, center_y, radius);
    if (position == 1)
    {
        printf("The point (%.2f,%.2f) is outside of the circle", point_x, point_y);
    }
    else if (position == 0)
    {
        printf("The point (%.2f,%.2f) is on of the circle", point_x, point_y);
    }
    else
    {
        printf("The point (%.2f,%.2f) is inside of the circle", point_x, point_y);
    }
	
    return 0;
}

int check(int number)
{
    if (number < 2)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i <= number / 2; i++)
        {
            if (number % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int calculate(int number)
{
    int factorial = 1;
    if (number < 0)
    {
        factorial = 0;
    }
    else if (number > 0)
    {
        for (int k = 1; k <= number; k++)
        {
            factorial *= k;
        }
    }
    return factorial;
}

int locate(float point_x, float point_y, float center_x, float center_y, float radius)
{
    float distance_squared = (point_x - center_x) * (point_x - center_x) + (point_y - center_y) * (point_y - center_y);
    if (distance_squared > radius * radius)
    {
        return 1;
    }
    else if (distance_squared == radius * radius)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}