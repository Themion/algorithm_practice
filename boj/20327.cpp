#include <cstdio>

#define MAX_N 7
#define pow(i) (1 << i)

// N: 배열의 크기, R: 명령의 개수, k: 각 명령, l: 명령의 실행 단위
int N, R, k, l;
// arr[b % 2]: 배열을 b번 돌린 결과
short arr[2][pow(MAX_N)][pow(MAX_N)];

void step(bool b, int y, int x) {
    // y_, x_: k와 l에 따라 배열의 y + i, x + j를 돌린 후의 위치
    int y_ = y, x_ = x;

    // 배열을 돌린 뒤의 위치를 각각 계산한 뒤 이동
    for (int i = 0; i < l; i++) for (int j = 0; j < l; j++) {
        if      (k == 1) {
            y_ = y + (l - 1) - i;
            x_ = x + j;
        }
        else if (k == 2) {
            y_ = y + i;
            x_ = x + (l - 1) - j;
        }
        else if (k == 3) {
            y_ = y + j;
            x_ = x + (l - 1) - i;
        }
        else if (k == 4) {
            y_ = y + (l - 1) - j;
            x_ = x + i;
        }
        else if (k == 5) {
            y_ = (N - l) - y + i;
            x_ = x + j;
        }
        else if (k == 6) {
            y_ = y + i;
            x_ = (N - l) - x + j;
        }
        else if (k == 7) {
            y_ = x + i;
            x_ = (N - l) - y + j;
        }
        else if (k == 8) {
            y_ = (N - l) - x + i;
            x_ = y + j;
        }

        // 배열을 돌린 결과를 다른 곳에 저장
        arr[!b][y_][x_] = arr[b][y + i][x + j];
    }
}

int main() {
    // 문제의 조건을 각각 입력받은 뒤
    scanf("%d %d", &N, &R);
    // N은 2 ^ N 꼴로 변경
    N = pow(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        scanf("%hd", arr[0][i] + j);

    // 각 명령에 대해
    for (int r = 0; r < R; r++) {
        // 명령과 수행 단위를 입력받은 뒤
        scanf("%d %d", &k, &l);
        // l은 2 ^ l 꼴로 변경
        l = pow(l);
        // 각 단위를 차례차례 이동
        for (int i = 0; i < N; i += l) for (int j = 0; j < N; j += l) 
            step(r % 2, i, j);
    }
    
    // 배열을 돌린 결과를 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%hd ", arr[R % 2][i][j]);
        printf("\n");
    }

    return 0;
}
