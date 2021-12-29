#include <cstdio>

#define MAX_N 100

// 그림을 저장할 공간
char image[MAX_N][MAX_N + 1];
// N: 그림의 한 변의 길이, add: 좌표의 상하좌우 좌표를 계산할 때 사용할 값
int N, add[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

// 좌표 (x, y)가 포함되며 값이 from인 구역을 순회하며 값을 to로 바꾼다
bool dfs(int y, int x, char from, char to) {
    // 좌표 (x, y)와 인접한 좌표를 계산할 때 사용할 변수
    int y_, x_;

    // 현재 좌표의 값을 to로 바꾼 뒤
    image[y][x] = to;
    // 현재 좌표와 인접한 좌표에 대해
    for (auto a : add) {
        // 좌표값을 계산한 뒤
        y_ = y + a[0]; x_ = x + a[1];
        // 좌표가 valid하지 않다면 continue
        if (y_ < 0 || y_ >= N || x_ < 0 || x_ >= N) continue;
        // 해당 좌표의 값이 from이라면 dfs를 통해 방문
        else if (image[y_][x_] == from) dfs(y_, x_, from, to);
    }

    // 편의를 위해 true를 반환
    return true;
}

int main() {
    // RGB: 색약이 아닌 사람이 봤을 때 구역의 수, ab: 색약인 사람이 봤을 때 구역의 수 
    int RGB = 0, ab = 0;

    // 문제의 조건을 입력받은 뒤
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%s", image[i]);

    // 구역을 계산하며 RGB 이미지를 적녹 색약에 맞게 a, b로 바꿔준다 
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        if (image[i][j] == 'R' || image[i][j] == 'G' || image[i][j] == 'B')
            RGB += dfs(i, j, image[i][j], (image[i][j] == 'B') ? 'b' : 'a');

    // 구역을 계산하며 확인한 좌표를 0으로 초기화
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        if (image[i][j] == 'a' || image[i][j] == 'b')
            ab += dfs(i, j, image[i][j], 0);

    printf("%d %d\n", RGB, ab);

    return 0;
}
