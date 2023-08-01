/*Method 1*/   
/*int number;
    printf("Input a number from the keyboard: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Input error");
    }
    else
    {
        while (number % 2 == 0)
        {
            number = number / 2;
        }

        if (number == 1)
        {
            printf("The number is a power of 2");
        }
        else
        {
            printf("The number is not a power of 2");
        }
    }*/
/*Method 2*/
#include <stdio.h>

int main()
{
    int number, check = 1;
    printf("Input a number from the keyboard: ");
    scanf("%d", &number);

    while(check < number)
    {
        check = check * 2;
    }

    if (check == number)
    {
        printf("The number is a power of 2");
    }
    else
    {
        printf("The number is not a power of 2");
    }

    return 0;
}
