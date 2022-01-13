#include <iostream>

using namespace std;

#define MAX_LEN 100

void swap(int &a, int &b) { int t = a; a = b; b = t; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 배열이 저장된 공간, !origin: 배열을 저장할 공간
    bool origin = false;
    // N, M: 배열의 크기
    // array[origin][y][x]: 배열의 (x, y) 좌표값, 공간을 둘로 나누어 번갈아 저장
    // times: 명령을 받을 횟수, order: 각 명령의 종류
    // y, x: 뒤집은 배열을 저장할 좌표, qtr: 뒤집을 각 좌표가 속한 사분면
    int N, M, array[2][MAX_LEN][MAX_LEN] = {{{ 0, }}}, times, order, y, x, qtr;

    // 배열의 초기 상태를 입력받은 뒤
    cin >> N >> M >> times;
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++)
        cin >> array[origin][y][x];

    // 각 명령에 대해
    while (times--) {
        // 명령 종류를 입력받은 뒤
        cin >> order;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            // 명령에 따라 저장할 좌표를 계산한 뒤 저장
            y = i; x = j;

            // 좌표값 정보를 지정
            if (y < N / 2) qtr = (x >= M / 2);
            else qtr = 2 + (x < M / 2);

            // 명령의 종류에 따라
            switch (order)
            {
            case 1: // 1: 상하 뒤집기
                y = N - 1 - i;
                break;
            case 2: // 2: 좌우 뒤집기
                x = M - 1 - j;
                break;
            case 3: // 3: 시계방향으로 90' 뒤집기
                y = x;
                x = N - 1 - i;
                break;
            case 4: // 4: 반시계방향으로 90' 뒤집기
                x = y;
                y = M - 1 - j;
                break;
            case 5: // 5: 시계방향으로 사분면 교체
                if (qtr % 2) y += (N / 2) * (qtr == 1 ? 1 : -1);
                else x += (M / 2) * (qtr == 0 ? 1 : -1);
                break;
            case 6: // 6: 반시계방향으로 사분면 교체
                if (qtr % 2) x += (M / 2) * (qtr == 1 ? -1 : 1);
                else y += (N / 2) * (qtr == 0 ? 1 : -1);
                break;
            }

            array[!origin][y][x] = array[origin][i][j];
        }

        // 90도 회전의 경우 배열의 크기가 변경되므로 N과 M을 바꾼다
        if (order == 3 || order == 4) swap(N, M);
        // 뒤집은 배열을 원본 배열에 덮어쓴다
        origin = !origin;
    }

    // 배열 출력
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++)
        cout << array[origin][y][x] << (x == M - 1 ? '\n' : ' ');

    return 0;
}
