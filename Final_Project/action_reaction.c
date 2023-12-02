#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    double mass;     // ����
    double velocity; // �ӵ�
} Object;

// �Լ� ���� ����
int willCollide(const Object* objA, const Object* obB2);
void calculateFinalVelocities(Object* objA, Object* objB);

int main() {
    Object objA, objB;

    printf("���������������� ����������������\n");
    // �� ���簢���� �߾� (A�� B ǥ��)
    printf("��   A  �� ��   B  ��\n");
    // �� ���簢���� �ϴ�
    printf("���������������� ����������������\n");

    printf("��ü A�� ������ �ӵ��� �Է��ϼ��� (��: 10 -5): ");
    scanf("%lf %lf", &objA.mass, &objA.velocity);

    printf("��ü B�� ������ �ӵ��� �Է��ϼ��� (��: 20 10): ");
    scanf("%lf %lf", &objB.mass, &objB.velocity);

    if (willCollide(&objA, &objB)) {
        calculateFinalVelocities(&objA, &objB);
        printf("�浹 �� A ��ü�� �ӵ�: %.2f\n", objA.velocity);
        printf("�浹 �� B ��ü�� �ӵ�: %.2f\n", objB.velocity);
    }
    else {
        printf("�� ��ü�� �浹���� �ʽ��ϴ�.\n");
    }

    return 0;
}

int willCollide(const Object* objA, const Object* objB) {
    // ���� �������� �����̸鼭 �ڿ� �ִ� ��ü�� �� ������ �����̴� ���, �浹���� ����
    if ( objB - objA >= 0 )
        return 0; // �浹���� ����
    return 1; // �� ���� ��쿡�� �浹
}

void calculateFinalVelocities(Object* objA, Object* objB) {
    double v1_final = ((objA->mass - objB->mass) / (objA->mass + objB->mass)) * objA->velocity +
        ((2 * objB->mass) / (objA->mass + objB->mass)) * objB->velocity;
    double v2_final = ((2 * objA->mass) / (objA->mass + objB->mass)) * objA->velocity +
        ((objB->mass - objA->mass) / (objA->mass + objB->mass)) * objB->velocity;

    objA->velocity = v1_final;
    objB->velocity = v2_final;
}
