#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	printf("[202304023/������/���� 11�� 12��]\n\n");

	int perfect = 0; //�ʱ�ȭ �� �ؾ� �ϴ� ���ΰ�? �� �ص� �Ǵ� ���ΰ�

	while (1) { //���ѹݺ��� ���
		
		printf("���ڸ� �Է����ּ���: ");
		scanf("%d", &perfect);

		if (perfect <= 0) 
			break; //�ڿ��� �ƴ� �� �Է��ϸ� while�� ����, ���α׷� ����

		int sum = 0; //���� sum �ݺ� �ʱ�ȭ

		for (int k = 1; k < perfect; k++) { 
			if (perfect % k == 0)
				sum += k;
		} //�ڱ� �ڽ��� ������ ����鸸 ����

		if (perfect == sum) //������ ���� ���� ���� �ڱ� �ڽ��̸� ������
			printf("���� %d(��)�� �������Դϴ�\n", perfect);
		else 
			printf("���� %d(��)�� �������� �ƴմϴ�\n", perfect);
	
	}
}