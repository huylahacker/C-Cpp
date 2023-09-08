Tam giác số nguyên tố 
--1. casting type and print correct format 
int a,b;
scanf("%d",&a);
scanf("%d",&b);
// a = 3, b = 4 
float c = a * 1.0/b; // output: 0.75 float / int = float
float e = (float) a /b; // output: 0.75 float / int = float 
float d = a / b; // output: 0  int / int = int 
printf("%f",c) // output: 0.750000
printf("%.4f",c) // output: 0.7500

----
float a,b;
scanf("%f",&a);
scanf("%f",&b);
-----
double a,b;
scanf("%lf",&a);
scanf("%lf",&b);
--2. input n element into arr integer
// input n 
int n;
scanf("%d",&n);

// declear array 
int arr[n];

 // input each element 
for(int i = 0; i < n;i++){
   
    scanf("%d", arr[i]);
}
--2.1 if else condition 
if(){
    printf("");
}else{
    printf("");
}
--2.2 for if else 
for(int i = 0; i < n;i++){
    if(){
    printf("");
}else{
    printf("");
}
}
--2.3 convert base number from base 2 
// Function to convert binary to decimal
long long binaryToDecimal(long long binary) {
    long long decimal = 0;
    long long base = 1;
    
    while (binary > 0) {
        long long lastDigit = binary % 10;
        decimal += lastDigit * base;
        base *= 2;
        binary /= 10;
    }
    
    return decimal;
}

// Function to convert binary to octal
void binaryToOctal(long long binary) {
    long long decimal = binaryToDecimal(binary);
    printf("Octal representation: %llo\n", decimal);
}

// Function to convert binary to hexadecimal
void binaryToHexadecimal(long long binary) {
    long long decimal = binaryToDecimal(binary);
    printf("Hexadecimal representation: %llx\n", decimal);
}
--2.4 convert base number from base 10
// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32];
    int index = 0;
    
    if (decimal == 0) {
        printf("Binary representation: 0\n");
        return;
    }
    
    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }
    
    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert decimal to octal
void decimalToOctal(int decimal) {
    int octal[32];
    int index = 0;
    
    if (decimal == 0) {
        printf("Octal representation: 0\n");
        return;
    }
    
    while (decimal > 0) {
        octal[index] = decimal % 8;
        decimal /= 8;
        index++;
    }
    
    printf("Octal representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n");
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hexadecimal[32];
    int index = 0;
    
    if (decimal == 0) {
        printf("Hexadecimal representation: 0\n");
        return;
    }
    
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index] = remainder + '0';
        } else {
            hexadecimal[index] = remainder - 10 + 'A';
        }
        decimal /= 16;
        index++;
    }
    
    printf("Hexadecimal representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

//Function to convert hexadecimal to decimal 
void hexadecimalToDecimal
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
     
    printf("%d", dec);
--2.5 Function to calculate the factorial of a non-negative integer n
// Function to calculate the factorial of a non-negative integer n
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
--3.1 sum of n elements with condition x (x == 1 : sum of old ele || x == 0: sum of even ele || x == -1: sum of all ele ) in array  
int sum(int n,int arr[], int x){
    int sum = 0;
    if(x == -1){
    for(int i = 0; i < n; i++){
        sum+= arr[i];
    }
    return sum;
    }
    else{
    for(int i = 0; i < n; i++){
        if( arr[i] % 2 == x){

        }
    }
    }
}
--3.2 function to count even number or old number in array 
void countEvenAndOdd(int arr[], int size, int *evenCount, int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            (*evenCount)++;
        } else {
            (*oddCount)++;
        }
    }
}
--3.3 product of all even number in array 
int productOfEvenNumbers(int arr[], int size) {
    int product = 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            product *= arr[i];
        }
    }

    return product;
}
--3.4 sum of digits 
// 123 -> 6 
int sumOfDigits(int number) {
    int sum = 0;

    while (number != 0) {
        int digit = number % 10; // Extract the last digit
        sum += digit;
        number /= 10; // Remove the last digit from the number
    }

    return sum;
}
--3.5 Size of int array 
size_t n = sizeof(a) / sizeof(int);

--4.  sort ascending integer array ( sap xep tang dan )
int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
void sortAscending(int arr[], int size){
    qsort(arr,size,sizeof(int),cmp);
}
--4.1  sort decending integer array ( sap xep giam dan )
int cmp(const void* a,const void* b){
    return *(int*)b - *(int*)a;
}
void sortDecending(int arr[], int size){
    qsort(arr,size,sizeof(int),cmp);
}
--5. Print Pattern Form (Ve hinh)
for(int i = 0; i < soHang;i++){
    for(int i = 0; i < soCot;i++){
        if(moiLienHeCotHangDeInRa){

        }else{
            printf(" ");
        }
    }
    printf("\n");
}
--5.1
// Function to print right triangle pattern
void printRightTriangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
--5.2
// Function to print left triangle pattern
void printLeftTriangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
--5.3 inverted triangle 
void printInvertedRightTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
--5.4  Function to print a rectangular shape filled with character '*'

// Function to print a rectangular shape filled with character '*'
void printRectangle(int a, int b) {
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == 1 || i == a || j == 1 || j == b) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

--5.5 in ra hinh thoi 
// Function to print a diamond pattern of stars with height 'n'
void printDiamond(int n) {
    if (n % 2 == 0) {
        printf("The height of the diamond should be an odd number.\n");
        return;
    }

    // Upper half of the diamond
    for (int i = 1; i <= n; i += 2) {
        int spaceCount = (n - i) / 2;
        int starCount = i;
        
        // Print leading spaces
        for (int j = 1; j <= spaceCount; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= starCount; j++) {
            printf("*");
        }

        printf("\n");
    }

    // Lower half of the diamond
    for (int i = n - 2; i >= 1; i -= 2) {
        int spaceCount = (n - i) / 2;
        int starCount = i;
        
        // Print leading spaces
        for (int j = 1; j <= spaceCount; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= starCount; j++) {
            printf("*");
        }

        printf("\n");
    }
}
--5.6  Function to print a half pyramid pattern with height 'n'
// Function to print a half pyramid pattern with height 'n'
void printHalfPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
--5.7  Function to print a half pyramid pattern with height 'n' with palindrome 
// Function to print a half pyramid pattern with height 'n'
void shapingWords(int n) {
    char ch = 'A';
    int i,j;
    if(n > 0) {
        for(i=1;i<=n;i++) {
            for(j=1;j<=i-1;j++) printf("%c",ch+j-1);
            printf("%c",ch+i-1);
            for(j=i-1;j>=1;j--)printf("%c",ch+j-1);
        if(i != n) printf("\n");
    }
    }
}
--6. remove ele with position p in array 
void removeElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position. Cannot remove element.\n");
        return;
    }

    // Shift elements to the left starting from the position to be removed
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement the size of the array
    (*size)--;
}
--6.1 add ele with position p in array 
void addElement(int arr[], int *size, int position, int element) {
    if (position < 0 || position > *size) {
        printf("Invalid position. Cannot add element.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Add the new element at the specified position
    arr[position] = element;

    // Increment the size of the array
    (*size)++;
}
--7. find the index of the first pair with a given sum in the collection 
void findPairWithSum(int arr[], int size, int targetSum, int *index1, int *index2) {
    *index1 = -1; // Initialize indices to -1 in case no pair is found.
    *index2 = -1;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                *index1 = i;
                *index2 = j;
                return; // Found the first pair, exit the function.
            }
        }
    }
}
--7.1 find Pairs With Frequency And Divisibility
 #include <stdio.h>

// Function to find each pair (frequency, divisibility) of elements in the array
void findPairsWithFrequencyAndDivisibility(int arr[], int size, int k) {
    // Initialize a hash table to store frequency information
    int hashTable[100] = {0}; // Assuming array elements are between 0 and 99

    // Calculate the frequency of each element in the array
    for (int i = 0; i < size; i++) {
        hashTable[arr[i]]++;
    }

    // Find and print each pair (frequency, divisibility) for the elements in the array
    printf("Element : Frequency : Divisibility (by %d)\n", k);
    for (int i = 0; i < size; i++) {
        if (hashTable[arr[i]] > 0) {
            printf("%d : %d : %s\n", arr[i], hashTable[arr[i]], (arr[i] % k == 0) ? "Yes" : "No");
            hashTable[arr[i]] = 0; // Mark the element as visited
        }
    }
}



--8. swap the places of the first largest and smallest even number with each other in array 
[1,2,3,5,1,8] -> [1,8,3,5,1,2]
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void swapFirstLargestAndSmallestEven(int arr[], int size) {
    int largestEvenIndex = -1;
    int smallestEvenIndex = -1;

    // Find the indices of the first largest and smallest even numbers
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            if (largestEvenIndex == -1 || arr[i] > arr[largestEvenIndex]) {
                largestEvenIndex = i;
            }
            if (smallestEvenIndex == -1 || arr[i] < arr[smallestEvenIndex]) {
                smallestEvenIndex = i;
            }
        }
    }

    if (largestEvenIndex != -1 && smallestEvenIndex != -1) {
        // Swap the positions of the first largest and smallest even numbers
        swap(&arr[largestEvenIndex], &arr[smallestEvenIndex]);
    }
}
--8.1 sum Of Squared Even Integers

int sumOfSquaredEvenIntegers(int* arr, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum += (arr[i] * arr[i]); // Square of the even integer
        }
    }

    return sum;
}
--8.2 Function to find the two-digit number(s) that appear the most in the array

void findMostFrequentNDigitNumbers(int arr[], int size,int n) {
    int frequency[100] = {0}; // Assuming integers are between 0 and 99
    int maxFrequency = 0;

    // Calculate the frequency of each number in the array
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
        if (frequency[arr[i]] > maxFrequency) {
            maxFrequency = frequency[arr[i]];
        }
    }

    // Print the numbers with the highest frequency (n-digit numbers)
    printf("N-digit number(s) that appear the most: ");
    for (int i = 0; i < 100; i++) {
        if (frequency[i] == maxFrequency && i >= pow(10,n-1) && i <= (pow(10,n)-1)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
--8.3 Function to check if all elements of the array are odd numbers
// Function to check if all elements of the array are odd numbers
int isOddArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            return 0; // Element is even, array is not all odd
        }
    }
    return 1; // All elements are odd
}
--8.4 Function to print odd numbers at odd positions in ascending order

void printOddNumbersAtOddPositions(int arr[], int size) {
    for (int i = 1; i < size; i += 2) {
        if (arr[i] % 2 != 0) {
            printf("%d", arr[i]);
            int nextIndex = i + 2;
            if (nextIndex < size && arr[nextIndex] % 2 != 0) {
                printf("\n");
            }
        }
    }
}
--8.5 // Function to find the number with n digits that appears the most
// 123 1 23 123
void findMostFrequentNDigitNumber(int arr[], int size, int n) {
    int count[pow(10,n)] = {0}; // An array to count occurrences of n-digit numbers (up to 999)
    
    // Count occurrences of n-digit numbers
    for (int i = 0; i < size; i++) {
        if (arr[i] >= pow(10,n-1) && arr[i] <= pow(10,n) -1) {
            count[arr[i]]++;
        }
    }
    
    // Find the most frequent three-digit number
    int maxCount = 0;
    int mostFrequentNumber = -1;
    for (int i = pow(10,n-1); i <= pow(10,n) -1; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequentNumber = i;
        }
    }
    
    // Print the result
    if (mostFrequentNumber != -1) {
        printf("The most frequent three-digit number is: %d\n", mostFrequentNumber);
    } else {
        printf("No three-digit number.\n");
    }
}

// Function to compare two integers (used for sorting)
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
--9. form input string with maxsize 100 character 
char str[100];
fgets(str,sizeof(str),stdin);
int len = strlen(str);
if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove the newline character
}

--9.1 convert uppercase letter with condition x (x == 1: convert at index old || x == 0 : convert at index even || x == -1: convert all)
#include <ctype.h> // For the toupper() function
// Function to convert the character at the old index (x == 1)
void  convertAtIndexOld(char alphabet[]) {
   for (int i = 1; i < 26; i += 2) {
        alphabet[i] = toupper(alphabet[i]);
    }
}

// Function to convert characters at even indices (x == 0) 
void convertAtIndexEven(char alphabet[]) {
    for (int i = 0; i < 26; i += 2) {
        alphabet[i] = toupper(alphabet[i]);
    }
}

// Function to convert all uppercase letters (x == -1)
void convertAll(char alphabet[]) {
    for (int i = 0; i < 26; i++) {
        alphabet[i] = toupper(alphabet[i]);
    }
}
--9.2 convert N First Letters To Uppercase
#include <ctype.h> // For toupper() function

void convertNFirstLettersToUppercase(char *str, int n) {
    int i = 0;

    while (str[i] != '\0') {
        // Skip non-alphabetic characters
        while (str[i] != '\0' && !isalpha(str[i])) {
            i++;
        }

        // Convert the first 'n' letters of the word to uppercase
        for (int j = 0; j < n && str[i] != '\0' && isalpha(str[i]); j++) {
            str[i] = toupper(str[i]);
            i++;
        }

        // Skip to the end of the current word
        while (str[i] != '\0' && isalpha(str[i])) {
            i++;
        }
    }
}
--9.3 count Words Ending With String
int countWordsEndingWithString(char *inputString, char *endingString) {
    int count = 0;
    int inputLen = strlen(inputString);
    int endingLen = strlen(endingString);

    for (int i = 0; i < inputLen; i++) {
        // Skip leading spaces
        while (i < inputLen && inputString[i] == ' ') {
            i++;
        }

        // Find the end of the current word
        int j = i;
        while (j < inputLen && inputString[j] != ' ') {
            j++;
        }

        // Check if the current word ends with the given string
        if (j - i >= endingLen && strcmp(inputString + j - endingLen, endingString) == 0) {
            count++;
        }

        i = j; // Move to the next word
    }

    return count;
}
--9.4 count Words Starting With Prefix
int countWordsStartingWithPrefix(char *inputString, char *prefix) {
    int count = 0;
    int inputLen = strlen(inputString);
    int prefixLen = strlen(prefix);

    for (int i = 0; i < inputLen; i++) {
        // Skip leading spaces
        while (i < inputLen && isspace(inputString[i])) {
            i++;
        }

        // Find the end of the current word
        int j = i;
        while (j < inputLen && !isspace(inputString[j])) {
            j++;
        }

        // Check if the current word starts with the given prefix
        if (j - i >= prefixLen && strncmp(inputString + i, prefix, prefixLen) == 0) {
            count++;
        }

        i = j; // Move to the next word
    }

    return count;
}
--9.5  Function to convert uppercase vowels and lowercase consonants in a string
#include <ctype.h>

// Function to convert uppercase vowels and lowercase consonants in a string
void convertVowelsToUppercaseAndConsonantsToLowercase(char *str) {
    while (*str != '\0') {
        if (isalpha(*str)) {
            // Check if the character is a vowel
            if (*str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U' ||
                *str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
                *str = toupper(*str); // Convert vowel to uppercase
            } else {
                *str = tolower(*str); // Convert consonant to lowercase
            }
        }
        str++;
    }
}
--9.6 reverse a string
#include <string.h>
#include <stdlib.h> // For dynamic memory allocation

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
--9.7 find and replace occurrences of 'p' with its reversed version in 'o'
// ab uio io 
// uio 
// ab oiu io 
void findAndReplace(char* o, const char* p) {
    int oLen = strlen(o);
    int pLen = strlen(p);
    char* reversedP = (char*)malloc((pLen + 1) * sizeof(char));

    strcpy(reversedP, p);
    reverseString(reversedP);

    for (int i = 0; i <= oLen - pLen; i++) {
        if (strncmp(o + i, p, pLen) == 0) {
            strncpy(o + i, reversedP, pLen);
            i += pLen - 1; // Skip to the next position after replacing
        }
    }

    free(reversedP);
}
--9.8  count occurrences of 'p' with its original version in 'o'

int countOccurrences(char* o, const char* p) {
    int oLen = strlen(o);
    int pLen = strlen(p);

    int count = 0;
    for (int i = 0; i <= oLen - pLen; i++) {
        if (strncmp(o + i, p, pLen) == 0) {
            count++;
        }
    }

    return count;
}
--9.9 // Function to display the binary representation of a string 's' of length 'n'
void printBinaryRepresentation(const char* s, int n) {
    for (int i = 0; i < n; i++) {
        unsigned char ch = s[i];
        for (int j = 7; j >= 0; j--) {
            int bit = (ch >> j) & 1;
            printf("%d", bit);
        }
        printf(" ");
    }
    printf("\n");
}
--9.10
// Function to display the hexadecimal representation and integer value of a character
void printHexAndInteger(char c) {
    printf("%02X %d\n", c, c);
}
--9.11
// Function to find and display the first two pairs of frequency_of_character and the_character
void findFirstTwoPairs(const char* str) {
    int frequency[256] = {0}; // Assuming ASCII character set

    // Count the frequency of each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        frequency[(unsigned char)str[i]]++;
    }

    // Print the first two pairs in the order of character entry
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (frequency[(unsigned char)str[i]] > 0) {
            printf("%d_%c\n", frequency[(unsigned char)str[i]], str[i]);
            frequency[(unsigned char)str[i]] = 0;
            count++;
        }

        if (count == 2) {
            break; // Stop after finding the first two pairs
        }
    }
}
--9.12
// Function to find and replace the first occurrence of 's2' with 's3' in 's1'
void findAndReplace(char* s1, const char* s2, const char* s3) {
    char* found = strstr(s1, s2);

    if (found != NULL) {
        // Calculate the length of the parts before and after the first occurrence of 's2'
        int beforeLen = found - s1;
        int afterLen = strlen(s1) - (beforeLen + strlen(s2));

        // Construct the resultant string with 's3' replacing the first occurrence of 's2'
        char result[100];
        strncpy(result, s1, beforeLen);
        result[beforeLen] = '\0';
        strcat(result, s3);
        strcat(result, found + strlen(s2));
        
        // Copy the resultant string back to 's1'
        strcpy(s1, result);
    }
}
-9.13 Function to capitalize the first letter of each word in a string

#include <ctype.h>

// Function to capitalize the first letter of each word in a string
void capitalizeFirstLetter(char *s) {
    int capitalizeNext = 1; // A flag to indicate whether the next character should be capitalized

    while (*s) {
        if (isalpha(*s)) {
            if (capitalizeNext) {
                *s = toupper(*s); // Capitalize the first letter of the word
                capitalizeNext = 0; // Set the flag to lowercase the rest of the word
            } else {
                *s = tolower(*s); // Lowercase the rest of the word
            }
        } else {
            // If the current character is not an alphabetic character, set the flag to capitalize the next character
            capitalizeNext = 1;
        }

        s++;
    }
}
--9.14 sort string theo alphabe 
#include<stdlib.h>
#include<string.h>
#include<ctype.h> // uppercase lowsercase 
int cmp(const void* a,const void* b){
    return *(char*)a - *(char*)b;
}
void sortAscending(char arr[], int size){
    qsort(arr,size,sizeof(char),cmp);
}
--9.15 check digit 
isdigit('3'); // ctype.h
--9.16 char to string 
char c = '1';
char str1[2] = {c , '\0'};
char str2[5] = "";
strcpy(str2,str1);

--11. print square of each even number in array 
void printSquaresOfEvenNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            int square = arr[i] * arr[i];
            printf("%d\n", square); // have new line (can remove and add space )
        }
    }
}
--9.15 string to int 
#include <stdlib.h>
char* c = "1";// chuyen string -> int 
int val = atoi(c); // atoi = ASCII TO Int
--9.16 sum of number in string 
int sum = 0;

   
    for (int i = 1; i <= strlen(str); i++) {
        if (isdigit((char)str[i])) {
            char c = str[i];
char str1[2] = {c , '\0'};
char str2[5] = "";
strcpy(str2,str1);
int val = atoi(str2); // atoi = ASCII TO Int
            sum += val;
        }
    }
    printf("sum: %d", sum);
--12. check number a is power of n and can get a exponent ( so mu )
int isPowerOfN(int a, int n, int *exponent) {
    if (n <= 1 || a == 0) {
        return 0; // Numbers that are powers of 0 or 1 do not exist.
    }

    int power = 1;
    *exponent = 0;

    while (power < a) {
        power *= n;
        (*exponent)++;
    }

    if (power == a) {
        return 1; // If a is a power of n, return true.
    }
    return 0; // If a is not a power of n, return false.
} 
--13. check number is  perfect 
int isPerfectNumber(int number) {
    if (number <= 0) {
        return 0; // Perfect numbers are positive integers.
    }

    int sum = 0;

    // Find the sum of proper divisors
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    // Check if the number is equal to the sum of its proper divisors
    if (sum == number) {
        return 1; // If it's a perfect number, return true.
    }

    return 0; // If it's not a perfect number, return false.
}
--13.1  Function to check if a number is a prime number ( so nguyen to)

// Function to check if a number is a prime number
int isPrime(int number) {
    if (number <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0; // Number is divisible by i, so it is not prime
        }
    }

    return 1; // Number is prime
}

--13.2  Function to check if a number is a palindrome ( chuoi doi xung )

int isPalindrome(int number) {
    int originalNumber = number;
    int reversedNumber = 0;

    while (number > 0) {
        int digit = number % 10; // Extract the last digit
        reversedNumber = reversedNumber * 10 + digit; // Build the reversed number
        number /= 10; // Remove the last digit from the number
    }

    return (originalNumber == reversedNumber);
}

--14. remove all characters not alphabe 
#include <ctype.h> // For isalpha() function
void removeNonAlphabetCharacters(char *str) {
    if (str == NULL) {
        return; // Handle null pointer input (optional)
    }

    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[j] = str[i]; // Move the alphabet character to its proper position.
            j++;
        }
    }
    str[j] = '\0'; // Null-terminate the string after the last alphabet character.
}

--15. 
