#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	printf("*******************************\n");
	printf("202304023/������\n");
	printf("*******************************\n");

	printf("[�����Է�]\n");

	int math, korean, english; // ����, ����, ���� ���� ������ ���� ����
	char edu; // ���� �̼� ���� ���� ���� y �Ǵ� n

	printf("����: ");
	scanf("%d", &math);

	printf("����: ");
	scanf("%d", &korean);

	printf("����: "); 
	scanf("%d", &english);

	printf("*���α׷��� ���� �̼�(y/n): ");
	scanf(" %c", &edu); // ���� �̼� ���� ����ڰ� ���� �Է�

	float average = (math + korean + english) / 3; // �� ���� ���� ���
	char scholarship;

	printf("\n[��    ��]\n");
	printf("���� ���:%.2f��\n", average); // ��� ���� �Ҽ��� �Ʒ� ��°�ڸ����� ���
	printf("���б� ���: ");

	scholarship = (average >= 90) && (edu == 'y') ? printf("YES") : printf("NO");
	// �����̼� AND 90�� �̻� �� �� �����ϸ� YES ���, �� �� �ϳ��� �������� ������ NO ���

	return 0;

}