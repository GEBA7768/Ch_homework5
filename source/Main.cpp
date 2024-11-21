#include<stdio.h>
#include<stdlib.h>

void cubeByReference(int& nPtr);

int main()//P13
{
	int number = 5;
	printf("The original value of number is %d", number);

	cubeByReference(number);

	printf("\nThe new value of number is %d\n", number);
	system("pause");
	return 0;
}

void cubeByReference(int& nPtr)
{
	nPtr = nPtr * nPtr * nPtr;
}