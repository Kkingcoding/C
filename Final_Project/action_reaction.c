#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    double mass;     // 질량
    double velocity; // 속도
} Object;

// 함수 원형 선언
int willCollide(const Object* objA, const Object* obB2);
void calculateFinalVelocities(Object* objA, Object* objB);

int main() {
    Object objA, objB;

    printf("┌──────┐ ┌──────┐\n");
    // 두 직사각형의 중앙 (A와 B 표시)
    printf("│   A  │ │   B  │\n");
    // 두 직사각형의 하단
    printf("└──────┘ └──────┘\n");

    printf("물체 A의 질량과 속도를 입력하세요 (예: 10 -5): ");
    scanf("%lf %lf", &objA.mass, &objA.velocity);

    printf("물체 B의 질량과 속도를 입력하세요 (예: 20 10): ");
    scanf("%lf %lf", &objB.mass, &objB.velocity);

    if (willCollide(&objA, &objB)) {
        calculateFinalVelocities(&objA, &objB);
        printf("충돌 후 A 물체의 속도: %.2f\n", objA.velocity);
        printf("충돌 후 B 물체의 속도: %.2f\n", objB.velocity);
    }
    else {
        printf("두 물체는 충돌하지 않습니다.\n");
    }

    return 0;
}

int willCollide(const Object* objA, const Object* objB) {
    // 같은 방향으로 움직이면서 뒤에 있는 물체가 더 느리게 움직이는 경우, 충돌하지 않음
    if ( objB - objA >= 0 )
        return 0; // 충돌하지 않음
    return 1; // 그 외의 경우에는 충돌
}

void calculateFinalVelocities(Object* objA, Object* objB) {
    double v1_final = ((objA->mass - objB->mass) / (objA->mass + objB->mass)) * objA->velocity +
        ((2 * objB->mass) / (objA->mass + objB->mass)) * objB->velocity;
    double v2_final = ((2 * objA->mass) / (objA->mass + objB->mass)) * objA->velocity +
        ((objB->mass - objA->mass) / (objA->mass + objB->mass)) * objB->velocity;

    objA->velocity = v1_final;
    objB->velocity = v2_final;
}
