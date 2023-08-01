#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char* question1(char names[4][20],char classes[4][20],float scores[4]);
float* question2(float perimeter,float area);
float question3(float radius);

int main()
{
	char choice;
	while(1){
		printf("	=== Menu ===\n");
		printf("Press a to choose question 1:\n");
		printf("Press b to choose question 2:\n");
		printf("Press c to choose question 3:\n");
		printf("Press q to quit program\n");
		printf("*****************************\n");
		printf("Input your choice: ");
		scanf(" %c",&choice);
		
		switch(choice){
			case 'a':{
				char names[4][20], classes[4][20];
				float scores[4];
				char* data = question1(names, classes, scores);
				if(data == 0)
				{
					printf("File error!\n");
				}
    			for (int i = 0; i < 4; i++) {
        			printf("%s - %s - %.2f\n", names[i], classes[i], scores[i]);
    			}
    			free(data);
				break;
			}
			case 'b':{
				float perimeter, area;
				printf("Input the perimeter from the keyboard: ");
				scanf("%f",&perimeter);
				printf("Input the area from the keyboard: ");
				scanf("%f",&area);
				float* result = question2(perimeter, area);
				if(result == 0)
				{
					printf("Your output invalid.");
				}
				else
				{
					printf("The length of the rectangle is: %.2f\n", result[0]);
    				printf("The width of the rectangle is: %.2f\n", result[1]);
				}
    			free(result);
				break;
			}
			case 'c':{
				float radius;
    			printf("Enter the radius of the circle: ");
    			scanf("%f", &radius);
				float result = question3(radius);
				if(result == 0)
				{
					printf("Input wrong.\n");
				}
				else
				{
					printf("Area = %.2f\n", result);
				}
				break;
			}
			case 'q':{
				printf("Exit program. Have a good day!");
				return 0;
			}
			default:
			{
				printf("Invalid choice! Please try again.\n");
                break;
			}    
	}
}
}

char* question1(char names[4][20],char classes[4][20],float scores[4]){
	char *data = (char*) malloc (4 * sizeof(char));
	FILE *f;
    f = fopen("data_WS5.txt", "r");
    if (f == NULL) {
        return 0;
    }
    char format[20] = "%[^-] - %[^-] - %f\n";

    for (int i = 0; i < 4; i++) {
        fscanf(f, format, names[i], classes[i], &scores[i]);
    }
    fclose(f);
    return data;
}

float* question2(float perimeter,float area){
	float* result = (float*) malloc(2 * sizeof(float));
	if(perimeter <= 0 || area <= 0)
	{
		return 0;
	}
	else
	{
		result[0] = (perimeter + sqrt(perimeter * perimeter - 16.0 * area)) / 4.0;
    	result[1] = area / result[0];
	}
    return result;
}

float question3(float radius){
	float area;
	if(radius <= 0)
	{
		return 0;
	}
	else
	{
		area = 3.1415 * radius * radius;
		return area;
	}	
}