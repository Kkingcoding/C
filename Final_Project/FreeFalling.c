#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define g 9.8 
#define time 10

void free_fall();

int main()
{
	double s = 0;
	double v = 0;
	// int t = 0;
	// scanf("%d", &t);
	free_fall(s, v); //, t);

	return 0;
}

void free_fall(double s, double v) //, int t)
{
	for (int t = 1; t < time; t++) {
		
		v = g * t;
		s = 0.5 * g * t * t;
		printf("%d초 후의 순간속도 : %.2lfm/s, 낙하거리 : %.2lfm\n", t, v, s);
	}

	return 0;
}