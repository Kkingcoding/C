#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	printf("**********************\n");
	printf("202304023/������\n");
	printf("**********************\n");

	long long won; // ������ ���� ����
	
	printf("money? ");
	scanf("%lld", &won);

	long long left = won / 1000; // �޸� ���� �κ�
	long long right = won % 1000; // �޸� ������ �κ�

	printf("\n[%lld,%03lld�� ���]\n", left, right);

	long long ftt = won / 50000; // ��ü/5��=5������
	long long tt = won % 50000 / 10000; // ������/1��=1������d
	long long ft = won % 50000 % 10000 / 5000; // �������� ������/5õ=5õ����
	long long ot = won % 50000 % 10000 % 5000 / 1000; // �������� �������� ������/1õ=1õ���� 
	long long coin = won % 50000 % 10000 % 5000 % 1000; // �������� �������� �������� ������=����

	printf("5������ %lld��\n", ftt);
	printf("1������ %lld��\n", tt);
	printf("5õ���� %lld��\n", ft);
	printf("1õ���� %lld��\n", ot);
	printf("��   �� %lld��\n", coin);

	return 0;
}