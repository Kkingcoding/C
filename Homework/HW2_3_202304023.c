#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 5

int main() {

	printf("[202304023/이은혜/2002.11.12]\n\n");
	printf("점수를 입력해주세요.\n");

	int scores[size];
	int sum = 0;

	for (int i = 0; i < size; i++) {
		scanf("%d", &scores[i]); //배열 크기만큼 입력 받음
		sum += scores[i]; //입력 받은 점수들의 총합
	}

	int max = scores[0];

	for (int i = 0; i < size; i++) {

		if (scores[i] > max)
			max = scores[i]; // 최댓값
	}

	int min = scores[0];

	for (int i = 0; i < size; i++) {

		if (scores[i] < min)
			min = scores[i]; //최솟값
	}

	printf("\n-결과-\n");
	printf("평균: %.2f점\n", (float)sum / size);
	printf("최대값: %d점\n", max);
	printf("최소값: %d점\n", min);

}

