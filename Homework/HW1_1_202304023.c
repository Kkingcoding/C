#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	printf("**********************\n");
	printf("202304023/이은혜\n");
	printf("**********************\n");

	long long won; // 정수형 변수 선언
	
	printf("money? ");
	scanf("%lld", &won);

	long long left = won / 1000; // 콤마 왼쪽 부분
	long long right = won % 1000; // 콤마 오른쪽 부분

	printf("\n[%lld,%03lld원 결과]\n", left, right);

	long long ftt = won / 50000; // 전체/5만=5만원권
	long long tt = won % 50000 / 10000; // 나머지/1만=1만원권d
	long long ft = won % 50000 % 10000 / 5000; // 나머지의 나머지/5천=5천원권
	long long ot = won % 50000 % 10000 % 5000 / 1000; // 나머지의 나머지의 나머지/1천=1천원권 
	long long coin = won % 50000 % 10000 % 5000 % 1000; // 나머지의 나머지의 나머지의 나머지=동전

	printf("5만원권 %lld장\n", ftt);
	printf("1만원권 %lld장\n", tt);
	printf("5천원권 %lld장\n", ft);
	printf("1천원권 %lld장\n", ot);
	printf("동   전 %lld원\n", coin);

	return 0;
}