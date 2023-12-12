#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float evaluateExpression(float x, char* expression);

int main() {
    char equation[100];
    printf("일차방정식을 입력하세요 (예: 2*x + 3): y = ");
    fgets(equation, sizeof(equation), stdin);

    // 개행 문자 제거
    equation[strcspn(equation, "\n")] = '\0';

    // 그래프 출력
    for (int y = 10; y >= -10; y--) {
        for (int x = -10; x <= 10; x++) {
            if (y == 0 && x == 0) {
                printf("+");  // 원점
            }
            else if (y == 0) {
                printf("-");  // x축
            }
            else if (x == 0) {
                printf("|");  // y축
            }
            else {
                float result = evaluateExpression(x, equation);
                if (result > y - 0.5 && result < y + 0.5) {
                    printf("o");  // 방정식에 해당하는 점
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}

// 주어진 x 값에 대한 식의 결과 계산
float evaluateExpression(float x, char* expression) {
    sscanf(expression, "%*[^0123456789.]%f", &x);
    return x;
}