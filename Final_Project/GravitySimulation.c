#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define XPOS 35 // �ܼ� â�� �߾��� �뷫������ ���� (�ܼ� â�� �ʺ� ���� ���� �ʿ�)
#define MAX_CONSOLE_HEIGHT 60  // �ܼ� â�� �ִ� ����

void SetConsoleSize(int consoleWidth, int consoleHeight);
void CursorView(char show);
void GotoXY(int x, int y);

int main() {

    SetConsoleSize(70, MAX_CONSOLE_HEIGHT);

    float gravity, visualScaleFactor = 0.1;
    float restitutionCoefficient; // �ݹ� ���

    while (1) {
        printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��\t\t\t\t\t\t\t\t   ��\n");
        printf("��\t\t\t �߷°��ӵ� �ùķ��̼�\t\t\t   ��\n");
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

    return 0;
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

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
