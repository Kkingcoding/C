#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	printf("[202304023/이은혜]\n\n");

	float wei, hei, stan, pbiw, bmi; //몸무게와 키는 소수로 입력받음
	printf("몸무게(kg)와 키(cm)를 입력해주세요: ");
	scanf("%f %f", &wei, &hei);

	float mhei = hei * 0.01; //키는 미터로 변환
	stan = mhei * mhei * 21; //표준체중
	pbiw = wei / stan * 100; //표준체중대비 백분율

	printf("\n--------------비만도 판정 결과--------------\n\n");
	printf("표준 체중: %.2fkg\n", stan);
	printf("PIBW: %.2f\n", pbiw);
	printf("PIBW에 대한 판정: ");
	
	if (pbiw < 90) printf("저체중"); //PBIW 범위에 따른 결과 출력
	else if (pbiw >= 90 && pbiw < 110) printf("정상체중");
	else if (pbiw >= 110 && pbiw < 120) printf("과체중");
	else if (pbiw >= 120 && pbiw < 130) printf("경도비만");
	else if (pbiw >= 130 && pbiw < 160) printf("중정도비만");
	else printf("고도비만");
	printf("\n");


	bmi = wei / (mhei * mhei);

	printf("BMI: %.2f\n", bmi);
	printf("BMI에 대한 판정: ");
	
	if (bmi < 18.5) printf("저체중\n"); //bmi범위에 따른 결과 출력
	else if (bmi >= 18.5 && bmi < 23) printf("정상체중");
	else if (bmi >= 23 && bmi < 25) printf("과체중");
	else if (bmi >= 25 && bmi < 30) printf("경도비만");
	else if (bmi >= 30 && bmi < 35) printf("중정도비만");
	else printf("고도비만");
	printf("\n");
}