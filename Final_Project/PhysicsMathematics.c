#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "functions.h"
#include "physics.h"
#include "graph.h"

#define X_CENTER 35 // 콘솔 창의 중앙을 대략적으로 가정 (콘솔 창의 너비에 따라 조정 필요)
#define GRAVITY_CONSOLE_HEIGHT 60  // 콘솔 창의 최대 높이
#define MAIN_WIDTH 70
#define MAIN_HEIGHT 40

float Velocity = 0; // 공의 초기속도는 0
float visualScaleFactor = 0.1; // 화면에 실제 공이 떨어지는 떨어지는 듯한 속도를 구현하기 위해 배율 조절

void MainMenu() {
    // 0번째 줄
    printf("┌───────────────────────────────────────────────────────────────────┐\n");
    // 1번째 줄 
    printf("│");
    GotoXY(68, 1);
    printf("│\n");
    // 2번째 줄
    printf("│");
    PrintCentered("Welcome to", MAIN_WIDTH, 2);
    GotoXY(MAIN_WIDTH - 2, 2);
    printf("│\n");
    // 3번째 줄
    printf("│");
    GotoXY(MAIN_WIDTH - 2, 3);
    printf("│\n");
    // 4번째 줄
    printf("│");
    PrintCentered("★ Physics & Mathematics Elxploration ★", MAIN_WIDTH, 4);
    GotoXY(MAIN_WIDTH - 2, 4);
    printf("│\n");
    // 5번째 줄
    printf("│");
    GotoXY(68, 5);
    printf("│\n");
    // 6번째 줄       
    printf("│\t\t\t  1. 중력 시뮬레이션");
    GotoXY(68, 6);
    printf("│\n");
    // 7번째 줄
    printf("│\t\t\t  2. 그래프 그리기");
    GotoXY(68, 7);
    printf("│\n");
    // 8번째 줄
    printf("│\t\t\t  0. 프로그램 종료");
    GotoXY(68, 8);
    printf("│\n");
    // 9번째 줄
    printf("│");
    GotoXY(68, 9);
    printf("│\n");
    //10번째 줄
    printf("└───────────────────────────────────────────────────────────────────┘\n");
};
void ExceptionHandling(int line);

int main() {
    SetConsoleSize(MAIN_WIDTH, MAIN_HEIGHT);
    int choice = -1;

    do {
        MainMenu();

        PrintCentered("메뉴를 선택하세요: ", MAIN_WIDTH, 12);
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            break;
        case 1:
            PhysicsEngine();
            break;
        case 2:
            GraphPlotting();
            break;
        default:
            ExceptionHandling(15); //잘못된 메뉴 선택 예외 처리
            break;
        }
    } while (choice != 0);

    PrintCentered("이용해 주셔서 감사합니다.\n", MAIN_WIDTH, 14);
    return 0;
}

void PhysicsEngine() {

    SetConsoleSize(70, GRAVITY_CONSOLE_HEIGHT);

    float gravity = 1;
    float restitution = 0; // 반발 계수

    while (1) { // 사용자가 데이터 입력
        ViewPhysicsMain();

        if (scanf("%f", &gravity) == 1) {
            printf("\t반발 계수를 입력하세요 (0.0 ~ 1.0): ");

            if (scanf("%f", &restitution) == 1 && restitution >= 0.0 && restitution <= 1.0) {
                break;
            }
            else {
                while (getchar() != '\n');
                ExceptionHandling(15);
                Sleep(1000);
                system("cls");
            }
        }
        else {
            while (getchar() != '\n');
            ExceptionHandling(15);
            Sleep(1500);
            system("cls");
        }
    }

    system("cls");

    int height = 0; // 초기 높이 설정 (콘솔 상단에서 시작)
    float elapsedTime = .01; // 경과 시간 (초)

    CursorView(0); // 커서 숨기기

    SimulateGravity(gravity);
    SimulateBouncing(gravity, restitution);

}

void ViewPhysicsMain() {
    printf("┌───────────────────────────────────────────────────────────────────┐\n");

    printf("│");
    GotoXY(MAIN_WIDTH - 2, 1);
    printf("│\n");

    printf("│");
    PrintCentered("중력가속도 시뮬레이션", MAIN_WIDTH, 2);
    GotoXY(MAIN_WIDTH - 2, 2);
    printf("│\n");

    printf("│");
    GotoXY(MAIN_WIDTH - 2, 3);
    printf("│\n");
    printf("└───────────────────────────────────────────────────────────────────┘\n");
    printf("\n\t중력 가속도를 입력하세요 (m/s^2): ");
}

void SimulateGravity(float gravity) {
    int height = 0;
    float elapsedTime = 0.4; // 초기 경과 시간 (ms -> s)
    
    while (height < GRAVITY_CONSOLE_HEIGHT - 2) {
        GotoXY(X_CENTER, height);
        printf("●");
        Sleep((int)(100 / sqrtf(gravity * elapsedTime))); // 공이 떨어지면서 공의 출력 시간 줄어듦

        Velocity += gravity * elapsedTime; // 속도 갱신
        height = (int)(0.5 * gravity * powf(elapsedTime, 2) * visualScaleFactor); // 공의 높이 공식 = 0.5 * (중력가속도) * (경과 시간) ^ 2

        system("cls");
        elapsedTime += 0.4; // 경과 시간 증가
    }
}

void SimulateBouncing(float gravity, float restitution) {
    int height = GRAVITY_CONSOLE_HEIGHT - 2;
    float elapsedTime = 1.0; // 초기 경과 시간 (ms -> s)
    
    do {
        GotoXY(X_CENTER, height - 3);
        printf("●");
        Sleep((int)(100 * pow(elapsedTime,2) / sqrtf(gravity))); // 공이 올라가면서 공의 출력 시간 줄어듦

        Velocity += gravity * elapsedTime; // 속도 갱신
        height = (int)(height - Velocity * elapsedTime + 0.5 * gravity * powf(elapsedTime, 2) * visualScaleFactor); // 공의 높이 공식 = 초기 높이 - (초기 속도 * 경과 시간) + 0.5 * (중력가속도) * (경과 시간) ^ 2
        
        if (height >= GRAVITY_CONSOLE_HEIGHT - 2) {
            // 바닥에 닿으면 반발
            Velocity *= -restitution; // (반발 직후 속도) = (땅에 닿기 직전 속도) * (반발계수) 
            elapsedTime = 0;
        }

        system("cls");
        elapsedTime += 0.4; // 경과 시간 증가
    } while (height < GRAVITY_CONSOLE_HEIGHT - 3);
    Sleep(1000);
}


void GraphPlotting() {
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
                float result = Equation(x, equation);
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

    printf("그래프 그리기 종료\n");
    Sleep(1000);
    system("cls");
}

// 주어진 x 값에 대한 식의 결과 계산
float Equation(float x, char* expression) {
    sscanf(expression, "%*[^0123456789.]%f", &x);
    return x;
}

void ExceptionHandling(int line) {
    PrintCentered("┌--------------------------┐\n", 70, line);
    PrintCentered("│     다시 입력해주세요    │\n", MAIN_WIDTH, line + 1);
    PrintCentered("└--------------------------┘\n", MAIN_WIDTH, line + 2);
    Sleep(1500);
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
    int textLength = strlen(text);
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

