#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int x;
	int y;
	int sum;

	printf("x=");
	scanf("%d", &x);

	printf("y=");
	scanf("%d", &y);

	sum = x + y;
	printf("x+y=%d\n",sum);

	return 0;
}