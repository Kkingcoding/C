#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 5

int main() {

	printf("[202304023/������/2002.11.12]\n\n");
	printf("������ �Է����ּ���.\n");

	int scores[size];
	int sum = 0;

	for (int i = 0; i < size; i++) {
		scanf("%d", &scores[i]); //�迭 ũ�⸸ŭ �Է� ����
		sum += scores[i]; //�Է� ���� �������� ����
	}

	int max = scores[0];

	for (int i = 0; i < size; i++) {

		if (scores[i] > max)
			max = scores[i]; // �ִ�
	}

	int min = scores[0];

	for (int i = 0; i < size; i++) {

		if (scores[i] < min)
			min = scores[i]; //�ּڰ�
	}

	printf("\n-���-\n");
	printf("���: %.2f��\n", (float)sum / size);
	printf("�ִ밪: %d��\n", max);
	printf("�ּҰ�: %d��\n", min);

}

