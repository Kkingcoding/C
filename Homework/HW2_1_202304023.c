#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	printf("[202304023/������]\n\n");

	float wei, hei, stan, pbiw, bmi; //�����Կ� Ű�� �Ҽ��� �Է¹���
	printf("������(kg)�� Ű(cm)�� �Է����ּ���: ");
	scanf("%f %f", &wei, &hei);

	float mhei = hei * 0.01; //Ű�� ���ͷ� ��ȯ
	stan = mhei * mhei * 21; //ǥ��ü��
	pbiw = wei / stan * 100; //ǥ��ü�ߴ�� �����

	printf("\n--------------�񸸵� ���� ���--------------\n\n");
	printf("ǥ�� ü��: %.2fkg\n", stan);
	printf("PIBW: %.2f\n", pbiw);
	printf("PIBW�� ���� ����: ");
	
	if (pbiw < 90) printf("��ü��"); //PBIW ������ ���� ��� ���
	else if (pbiw >= 90 && pbiw < 110) printf("����ü��");
	else if (pbiw >= 110 && pbiw < 120) printf("��ü��");
	else if (pbiw >= 120 && pbiw < 130) printf("�浵��");
	else if (pbiw >= 130 && pbiw < 160) printf("��������");
	else printf("����");
	printf("\n");


	bmi = wei / (mhei * mhei);

	printf("BMI: %.2f\n", bmi);
	printf("BMI�� ���� ����: ");
	
	if (bmi < 18.5) printf("��ü��\n"); //bmi������ ���� ��� ���
	else if (bmi >= 18.5 && bmi < 23) printf("����ü��");
	else if (bmi >= 23 && bmi < 25) printf("��ü��");
	else if (bmi >= 25 && bmi < 30) printf("�浵��");
	else if (bmi >= 30 && bmi < 35) printf("��������");
	else printf("����");
	printf("\n");
}