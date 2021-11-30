#include <cstdio>

#define MAX_LEN 100

// 배열이 저장된 공간, !origin: 배열을 저장할 공간
bool origin = false;
// N, M: 배열의 크기
// array[origin][y][x]: 배열의 (x, y) 좌표값, 공간을 둘로 나누어 번갈아 저장
int N, M, array[2][MAX_LEN][MAX_LEN];

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 좌표값 (x, y)와 명령 종류를 입력받아 좌표값을 뒤집는다
void turn(int &y, int &x, int order) {
    // y_, x_: 뒤집은 좌표를 임시로 저장할 공간
    // qtr: 좌표값의 사분면 정보
    int y_ = y, x_ = x, qtr;

    // 좌표값 정보를 지정
    if (y < N / 2) qtr = (x >= M / 2);
    else qtr = 2 + (x < M / 2);

    // 명령의 종류에 따라
    switch (order)
    {
    case 1: // 1: 상하 뒤집기
        y_ = N - 1 - y;
        break;
    case 2: // 2: 좌우 뒤집기
        x_ = M - 1 - x;
        break;
    case 3: // 3: 시계방향으로 90' 뒤집기
        y_ = x;
        x_ = N - 1 - y;
        break;
    case 4: // 4: 반시계방향으로 90' 뒤집기
        x_ = y;
        y_ = M - 1 - x;
        break;
    case 5: // 5: 시계방향으로 사분면 교체
        if (qtr % 2) y_ += (N / 2) * (qtr == 1 ? 1 : -1);
        else x_ += (M / 2) * (qtr == 0 ? 1 : -1);
        break;
    case 6: // 6: 반시계방향으로 사분면 교체
        if (qtr % 2) x_ += (M / 2) * (qtr == 1 ? -1 : 1);
        else y_ += (N / 2) * (qtr == 0 ? 1 : -1);
        break;
    }

    y = y_;
    x = x_;
}

int main() {
    // times: 명령을 받을 횟수
    // order: 각 명령의 종류
    // y, x: 뒤집은 배열을 저장할 좌표
    int times, order, y, x;

    // 배열의 초기 상태를 입력받은 뒤
    scanf("%d %d %d", &N, &M, &times);
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++)
        scanf("%d", &array[origin][y][x]);

    // 각 명령에 대해
    while (times--) {
        // 명령 종류를 입력받은 뒤
        scanf("%d", &order);
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            // 명령에 따라 저장할 좌표를 계산한 뒤 저장
            turn(y = i, x = j, order);
            array[!origin][y][x] = array[origin][i][j];
        }

        // 90도 회전의 경우 배열의 크기가 변경되므로 N과 M을 바꾼다
        if (order == 3 || order == 4) swap(N, M);
        // 뒤집은 배열을 원본 배열에 덮어쓴다
        origin = !origin;
    }

    // 배열 출력
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) printf("%d ", array[origin][y][x]);
        printf("\n");
    }

    return 0;
}