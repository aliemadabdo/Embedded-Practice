/*
 ============================================================================
 Name        : quiz_questions.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */





/* the quiz link with codes
 *
 * https://docs.google.com/forms/d/e/
1FAIpQLSe3Lkdf0BuqHsEdn2GbEVgOlId2gAVuobuHkEgS8UDdeqh8SA/
?viewscore=AE0zAgDYux5jMyLeS5MdCcApy1TU30h6MUgzih7nJvB-
sZt8FtRaTbvPVbYvqsEBCxnTxmw

 */




#include <stdio.h>

int dicimalToBin(int dicimal){
	int bin[32];
	int i = 0;
	while(dicimal != 0){
		bin[i] = dicimal % 2;
		dicimal /= 2;
		i++;
	}
	return bin[3];
}


int main(void) {

	int num;
	scanf("%d",&num);

	printf("result : %d",dicimalToBin(num));
	return 0;
}


/*
write c program
0 of 0 points
Q2
*
Captionless Image
#include <stdio.h>

void swap(int a[],int b[],int len);

int main(void) {

	int a[20] = {1,2,3,4,5,6};
	int b[20] = {1,2,3,4,5,6,7,8};

	int len = sizeof(a)/sizeof(int);
	swap(a,b,len);

	return 0;
}

void swap(int a[],int b[],int len){

	int temp;
	for(int i=0; i<len; i++){
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
		printf("%d",a[i]);
	}
}
Feedback
#define MAX_SIZE 100 // Maximum array size
// Function declarations
void inputArray(int arr[], int size);
void printArray(int arr[], int size);
void swapArray(int sourceArr[], int destArr[]);

int main()
{
int sourceArr[MAX_SIZE];
int destArr[MAX_SIZE];
int size1,size2;


// Input array size
printf("Enter size of array1: ");
fflush(stdin);fflush(stdout);
scanf("%d", &size1);

printf("Enter size of array2: ");
fflush(stdin);fflush(stdout);
scanf("%d", &size2);

// Input elements of destination array
printf("Enter %d elements in source array: ", size1);
fflush(stdin);fflush(stdout);
inputArray(sourceArr, size1);

// Input element of destination array
printf("Enter %d elements in destination array: ", size2);
fflush(stdin);fflush(stdout);
inputArray(destArr, size2);


/*
* Print elements of both arrays before swapping

printf("\n\nSource array before swapping: ");
printArray(sourceArr, size1);

printf("\nDestination array before swapping: ");
printArray(destArr, size2);


/* Swap elements of both arrays.
swapArray(sourceArr, destArr);


/*
* Print elements of both arrays after swapping

printf("\n\nSource array after swapping: ");
printArray(sourceArr, size2);

printf("\nDestination array after swapping: ");
printArray(destArr, size1);


return 0;
}

void inputArray(int arr[], int size)
{
int i;
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
}

void printArray(int arr[], int size)
{
int i;
// Print elements of array one by one
for(i=0;i<size;i++)
{
printf("%d ",arr[i]);
}
}
void swapArray(int sourceArr[], int destArr[])
{
int i;
for(i=0;i<MAX_SIZE;i++)
{
//write any swapping technique
sourceArr[i] ^= destArr[i];
destArr[i] ^= sourceArr[i];
sourceArr[i] ^= destArr[i];


}
}
Q1)Write a C program takes string from the user and check if it the same USERNAME or not.
*
#include <stdio.h>
#include <string.h>


int main(void) {

	char text[50];

	printf("\n\n\n enter username: ");
	fflush(stdout);
	gets(text);

	if(!(strcmp(text,"USERNAME")))
		printf("TRUE");
	else
		printf("FALSE");


	return 0;
}
Feedback
int compare(char a[], char b[]);

int main()
{
char a[100]="marwa goda";
char b[100];


printf("please enter your user name\n");
fflush(stdin);fflush(stdout);
gets(b);

if (compare(a, b) == 1)
printf("correct user\n");
else
printf("wrong user\n");

return 0;
}

int compare(char a[], char b[])
{
int i = 0;
while (a[i] == b[i])
{
if (a[i] == '\0' || b[i] == '\0') break;
i++;
}

if (a[i] == '\0' && b[i] == '\0') return 1;
else
return 0;
}
Q4)
*
Captionless Image
#include <stdio.h>

unsigned int strToInt(char arr[]){

	unsigned int output = 0;
	int i = -1;

	while(arr[++i] != '\0'){
		output = output * 10 + (arr[i] - 48);
	}
	return output;
}

int main(void) {
	char number[] = "135466";

	printf("%u \n",strToInt(number));

	return 0;
}
Q7
*
Captionless Image
#include <stdio.h>

float check_root(float root, float num){

	do{
		num /= root;
		if (num == 0.0)
			break;
	}
	while(num != 1.0);

	if (num == 1.0)
		return 0;
	else
		return 1;
}
int main(void) {

	float root = 3, num = 27;

	printf("%f ==> %f",num, check_root(root, num));

	return 0;
}
Q3)
*
Captionless Image
#include <stdio.h>


int main(void) {

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	scanf("%d ", arr);
	int len = sizeof(arr) / sizeof(int);

	for(int i = 0; i<len; i++){
		printf("%d",arr[len - i - 1]);

		if (i != len - 1)
			printf(",");
	}

	return 0;
}
Feedback
void inp_array(int arr[],int size);
void reverse_array(int arr[],int size);
void print_array(int arr[],int size);
int main()
{
int arr[10];
int size;

printf("enter size of array");
fflush(stdin);fflush(stdout);
scanf("%d",&size);

printf("enter %d element of array",size);
fflush(stdin);fflush(stdout);
inp_array(arr,size);

printf("element before reverse\n");
print_array(arr,size);

reverse_array(arr,size);

printf("\nelement after reverse \n");
print_array(arr,size);

}
void inp_array(int arr[],int size)
{
int i;
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
}
void print_array(int arr[],int size)
{
int i;

for(i=0;i<size;i++)
{
printf(" %d",arr[i]);
}
}
void reverse_array(int arr[],int size)
{
int i,j,temp;
for(i=0,j=size-1;i<=j;i++,j--)
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;

}

}
Q5)
*
Captionless Image
#include <stdio.h>


int main(void) {

	int num, pos;

	printf("enter a number: ");
	fflush(stdout);
	scanf("%d", &num);

	printf("enter a the bit position: ");
	fflush(stdout);
	scanf("%d", &pos);

	num = num & ~(1<<pos);
	printf("result = %d",num);
	return 0;
}
Feedback
#include "stdio.h"
int main()
{
int num, n,new_num;

/* Input number from user
printf("Enter any number: ");
fflush(stdin);fflush(stdout);
scanf("%d", &num);

/* Input bit number you want to clear
printf("Enter nth bit to clear (0-31): ");
fflush(stdin);fflush(stdout);
scanf("%d", &n);

/*
* Left shifts 1 to n times
* Perform complement of above
* finally perform bitwise AND with num and result of above

new_num =num & (~(1 << n));

printf("Bit cleared successfully.\n\n");
printf("Number before clearing %d bit: %d (in decimal)\n", n, num);
printf("Number after clearing %d bit: %d (in decimal)\n", n, new_num);

return 0;
}
Q8
*
Captionless Image
#include <stdio.h>

int check_last_occur(int arr[], int len, int element){
	int pos = 0;
	for(int i=0; i<len; i++){
		if (element == arr[i])
			pos = i;
	}

	if (pos == 0)
		return -1;
	else
		return pos;
}
int main(void) {

	int arr[] = {1, 2, 3, 4, 5, 6, 4, 5, 6, 4, 5, 6, 4, 5, 6, 4, 5, 6};
	int len = sizeof(arr) / sizeof(int);
	int element = 5;

	printf("result = %d",check_last_occur(arr, len, element));
	return 0;
}
Feedback
#include "stdio.h"
void find_lastindex(int arr[],int num);
int main()
{
int arr[10]={10,20,5,8,9,20,5,45,90,10};
int x;
printf("enter your search number ");
fflush(stdin);fflush(stdout);
scanf("%d",&x);
find_lastindex(arr,x);
}
void find_lastindex(int arr[],int num)
{
int i,k=-1;// initialize k=-1 if number not found return -1
for(i=0;i<10;i++)
{
if(num==arr[i])
k=i;
else
continue;

}
printf("index=%d",k);
}
Q6)
*
Captionless Image

#include <stdio.h>

int dicimalToBin(int dicimal){
	int bin[32];
	int i = 0;
	while(dicimal != 0){
		bin[i] = dicimal % 2;
		dicimal /= 2;
		i++;
	}
	return bin[3];
}


int main(void) {

	int num;
	scanf("%d",&num);

	printf("result : %d",dicimalToBin(num));
	return 0;
}
Feedback
int main()
{
int n, c, k;
printf("Enter an integer in decimal number system\n");
fflush(stdin);fflush(stdout);
scanf("%d", &n);

printf("%d in binary number system is:\n", n);

for (c = 31; c >= 0; c--)
{
k = n >> c;

if (k & 1)
printf("1");
else
printf("0");
}

printf("\n");
k=n>>3;
if(k&1)
printf(" 4th least significant bit is 1");
else
printf("4th least significant bit is 0");
return 0;
}
 */

