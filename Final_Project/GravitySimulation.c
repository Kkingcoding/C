#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define XPOS 35 // 콘솔 창의 중앙을 대략적으로 가정 (콘솔 창의 너비에 따라 조정 필요)
#define MAX_CONSOLE_HEIGHT 60  // 콘솔 창의 최대 높이

void SetConsoleSize(int consoleWidth, int consoleHeight);
void CursorView(char show);
void GotoXY(int x, int y);

int main() {

    SetConsoleSize(70, MAX_CONSOLE_HEIGHT);

    float gravity, visualScaleFactor = 0.1;
    float restitutionCoefficient; // 반발 계수

    while (1) {
        printf("┌──────────────────────────────────────────────────────────────────┐\n");
        printf("│\t\t\t\t\t\t\t\t   │\n");
        printf("│\t\t\t 중력가속도 시뮬레이션\t\t\t   │\n");
        printf("│\t\t\t\t\t\t\t\t   │\n");
        printf("└──────────────────────────────────────────────────────────────────┘\n");
        printf("\n\t중력 가속도를 입력하세요 (m/s^2): ");
        
        if (scanf("%f", &gravity) == 1) {
            printf("\t반발 계수를 입력하세요 (0.0 ~ 1.0): ");

            if (scanf(" %f", &restitutionCoefficient) == 1)
                break;
            
            else {
                while (getchar() != '\n');
                printf("올바른 숫자를 입력하세요1 (0.0~1.0) \n");
                Sleep(1000);
                system("cls");
            }
        }
        else {
            while (getchar() != '\n');
            printf("숫자를 입력하세요.\n");
            Sleep(1500);
            system("cls");
        }
    }

    system("cls");

    int height = 0; // 초기 높이 설정 (콘솔 상단에서 시작)
    float elapsedTime = .01; // 경과 시간 (초)

    CursorView(0); // 커서 숨기기

    while (height < MAX_CONSOLE_HEIGHT - 2) {

        GotoXY(XPOS, height);
        printf("●");
        Sleep(elapsedTime);

        int sleepTime = (int)(100 / sqrt(gravity * elapsedTime));
        Sleep(sleepTime);

        elapsedTime += .4; // 경과 시간 증가 (ms -> s)
        height = (int)(0.5 * gravity * pow(elapsedTime, 2) * visualScaleFactor); // 높이 계산 (h = 0.5 * g * t^2)

        // 충돌 후 튕기는 부분
        if (restitutionCoefficient > 0) {

            GotoXY(XPOS, height);
            printf("●"); 

            elapsedTime = 0; // 시간 초기화
            gravity *= restitutionCoefficient; // 반발 계수 적용
        }

        system("cls");
    }

    GotoXY(XPOS, MAX_CONSOLE_HEIGHT - 1);
    printf("●\n");
    Sleep(1000); // 마지막 위치에서 1초간 대기

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
