#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	printf("[202304023/이은혜/생일 11월 12일]\n\n");

	int perfect = 0; //초기화 꼭 해야 하는 것인가? 안 해도 되는 것인가

	while (1) { //무한반복문 사용
		
		printf("숫자를 입력해주세요: ");
		scanf("%d", &perfect);

		if (perfect <= 0) 
			break; //자연수 아닌 값 입력하면 while문 종료, 프로그램 종료

		int sum = 0; //변수 sum 반복 초기화

		for (int k = 1; k < perfect; k++) { 
			if (perfect % k == 0)
				sum += k;
		} //자기 자신을 제외한 약수들만 더함

		if (perfect == sum) //위에서 누적 더한 값이 자기 자신이면 완전수
			printf("숫자 %d(은)는 완전수입니다\n", perfect);
		else 
			printf("숫자 %d(은)는 완전수가 아닙니다\n", perfect);
	
	}
}