#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float evaluateExpression(float x, char* expression);

int main() {
    char equation[100];
    printf("������������ �Է��ϼ��� (��: 2*x + 3): y = ");
    fgets(equation, sizeof(equation), stdin);

    // ���� ���� ����
    equation[strcspn(equation, "\n")] = '\0';

    // �׷��� ���
    for (int y = 10; y >= -10; y--) {
        for (int x = -10; x <= 10; x++) {
            if (y == 0 && x == 0) {
                printf("+");  // ����
            }
            else if (y == 0) {
                printf("-");  // x��
            }
            else if (x == 0) {
                printf("|");  // y��
            }
            else {
                float result = evaluateExpression(x, equation);
                if (result > y - 0.5 && result < y + 0.5) {
                    printf("o");  // �����Ŀ� �ش��ϴ� ��
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

// �־��� x ���� ���� ���� ��� ���
float evaluateExpression(float x, char* expression) {
    sscanf(expression, "%*[^0123456789.]%f", &x);
    return x;
}