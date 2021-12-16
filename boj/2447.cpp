#include <cstdio>

#define MAX_N 2187

// 정답을 bool 형태로 바꾸어 저장
bool ans[MAX_N][MAX_N] = { {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };

// 프랙탈 형태를 만들 함수
void fractal(int N) {
    // 한 변의 길이가 1일 때 프랙탈화는 수동으로 가능
    if (N == 1) return;

    // 프랙탈 형태로 만들 형태를 먼저 만든 뒤
    fractal(N / 3);

    // 프랙탈화 시킬 아홉 칸에서 첫 칸과 다섯번째 칸 외의 모든 칸에 대해
    for (int i = 0; i < 3 * N; i += N) for (int j = 0; j < 3 * N; j += N)
        if ((i || j) && (i != N || j != N))
            // 첫번째 칸의 내용을 복사
            for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) 
                ans[y + i][x + j] = ans[y][x];
}

int main() {
    // 만들 프랙탈의 깊이
    int N;

    // 깊이를 입력받은 뒤 재귀적으로 프랙탈 생성
    scanf("%d", &N);
    fractal(N / 3);

    // 프랙탈 출력
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) printf("%c", ans[y][x] ? '*' : ' ');
        printf("\n");
    }

    return 0;
}
