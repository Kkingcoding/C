#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define XPOS 35 // �ܼ� â�� �߾��� �뷫������ ���� (�ܼ� â�� �ʺ� ���� ���� �ʿ�)
#define MAX_CONSOLE_HEIGHT 60  // �ܼ� â�� �ִ� ����

void SetConsoleSize(int consoleWidth, int consoleHeight);
void CursorView(char show);
void PrintCentered(const char* text, int width, int y);
void GotoXY(int x, int y);
void ViewGravity() {
    printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��\t\t\t\t\t\t\t\t   ��\n");
    printf("��");
    PrintCentered("�߷°��ӵ� �ùķ��̼�", 70, 2);
    GotoXY(67, 2);
    printf("��\n");
    printf("��\t\t\t\t\t\t\t\t   ��\n");
    printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n\t�߷� ���ӵ��� �Է��ϼ��� (m/s^2): ");
};

float evaluateExpression(float x, char* expression);

void GravitySimulation();
void GraphPlotting();

int main() {
    SetConsoleSize(80, 40);

    while (1) {
        

        int choice;
        printf("\n�޴��� �����ϼ��� (1 �Ǵ� 2): ");
        if (scanf("%d", &choice) == 1) {
            switch (choice) {
            case 1:
                GravitySimulation();
                break;
            case 2:
                GraphPlotting();
                break;
            default:
                printf("�߸��� �޴� �����Դϴ�. �ٽ� �����ϼ���.\n");
                break;
            }
        }
        else {
            while (getchar() != '\n');
            printf("���ڸ� �Է��ϼ���.\n");
            Sleep(1500);
            system("cls");
        }
    }

    return 0;
}

void GravitySimulation() {
    ViewGravity();

    SetConsoleSize(70, MAX_CONSOLE_HEIGHT);

    float gravity, visualScaleFactor = 0.1;
    float restitutionCoefficient; // �ݹ� ���

    while (1) {
        printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��\t\t\t\t\t\t\t\t   ��\n");
        printf("��");
        PrintCentered("�߷°��ӵ� �ùķ��̼�", 70, 2);
        GotoXY(67, 2);
        printf("��\n");
        printf("��\t\t\t\t\t\t\t\t   ��\n");
        printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\n\t�߷� ���ӵ��� �Է��ϼ��� (m/s^2): ");

        if (scanf("%f", &gravity) == 1) {
            printf("\t�ݹ� ����� �Է��ϼ��� (0.0 ~ 1.0): ");

            if (scanf(" %f", &restitutionCoefficient) == 1)
                break;

            else {
                while (getchar() != '\n');
                printf("�ùٸ� ���ڸ� �Է��ϼ���1 (0.0~1.0) \n");
                Sleep(1000);
                system("cls");
            }
        }
        else {
            while (getchar() != '\n');
            printf("���ڸ� �Է��ϼ���.\n");
            Sleep(1500);
            system("cls");
        }
    }

    system("cls");

    int height = 0; // �ʱ� ���� ���� (�ܼ� ��ܿ��� ����)
    float elapsedTime = .01; // ��� �ð� (��)

    CursorView(0); // Ŀ�� �����

    while (height < MAX_CONSOLE_HEIGHT - 2) {

        GotoXY(XPOS, height);
        printf("��");
        Sleep(elapsedTime);

        int sleepTime = (int)(100 / sqrt(gravity * elapsedTime));
        Sleep(sleepTime);

        elapsedTime += .4; // ��� �ð� ���� (ms -> s)
        height = (int)(0.5 * gravity * pow(elapsedTime, 2) * visualScaleFactor); // ���� ��� (h = 0.5 * g * t^2)

        // �浹 �� ƨ��� �κ�
        if (restitutionCoefficient > 0) {

            GotoXY(XPOS, height);
            printf("��");

            elapsedTime = 0; // �ð� �ʱ�ȭ
            gravity *= restitutionCoefficient; // �ݹ� ��� ����
        }

        system("cls");
    }

    GotoXY(XPOS, MAX_CONSOLE_HEIGHT - 1);
    printf("��\n");
    Sleep(1000); // ������ ��ġ���� 1�ʰ� ���

    printf("�߷� �ùķ��̼� ����\n");
    Sleep(1000);
    system("cls");
}

void GraphPlotting() {
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

    printf("�׷��� �׸��� ����\n");
    Sleep(1000);
    system("cls");
}

void SetConsoleSize(int consoleWidth, int consoleHeight) {
    char command[30];
    sprintf(command, "mode con: cols=%d lines=%d", consoleWidth, consoleHeight);
    system(command);
}

void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void PrintCentered(const char* text, int width, int y) {
    int padding = (width - strlen(text)) / 2;
    GotoXY(padding, y);
    printf("%s", text);
}

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// �־��� x ���� ���� ���� ��� ���
float evaluateExpression(float x, char* expression) {
    sscanf(expression, "%*[^0123456789.]%f", &x);
    return x;
}
