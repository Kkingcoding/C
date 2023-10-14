#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	printf("*******************************\n");
	printf("202304023/이은혜\n");
	printf("*******************************\n");

	printf("[정보입력]\n");

	int math, korean, english; // 국어, 수학, 영어 각각 점수의 변수 선언
	char edu; // 교육 이수 여부 변수 선언 y 또는 n

	printf("수학: ");
	scanf("%d", &math);

	printf("국어: ");
	scanf("%d", &korean);

	printf("영어: "); 
	scanf("%d", &english);

	printf("*프로그래밍 교육 이수(y/n): ");
	scanf(" %c", &edu); // 교육 이수 여부 사용자가 직접 입력

	float average = (math + korean + english) / 3; // 세 과목 성적 평균
	char scholarship;

	printf("\n[결    과]\n");
	printf("성적 평균:%.2f점\n", average); // 평균 점수 소수점 아래 둘째자리까지 출력
	printf("장학금 대상: ");

	scholarship = (average >= 90) && (edu == 'y') ? printf("YES") : printf("NO");
	// 교육이수 AND 90점 이상 둘 다 충족하면 YES 출력, 둘 중 하나라도 충족되지 않으면 NO 출력

	return 0;

}