#include <cstdio>

int abs(int n) { return n < 0 ? - n : n; }

bool test_case() {
    // N: 디스크의 수, buf: 각 디스크가 검은색이라면 1, 아니라면 0
    // diff: 검은 디스크의 좌표 중 홀수 좌표의 개수와 짝수 좌표의 개수의 차
    int N, buf, diff = 0;

    // 디스크의 개수와 각 디스크를 입력받으며
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &buf);
        // 홀수 좌표와 짝수 좌표의 디스크의 개수의 차를 diff에 저장
        if (buf) diff += (i % 2 ? 1 : -1);
    }

    // N이 홀수인 경우에는 각 디스크의 좌표의 홀/짝 여부는 바뀔 수 있으므로
    // N이 홀수인 경우에는 반드시 true
    // N이 짝수이고 diff가 1 이하라면 모든 검은 디스크를 한 곳으로 모을 수 있음이 자명
    // 즉 N이 홀수거나 diff가 1 이하라면
    // 주어진 테스트 케이스는 흰색과 검은색 디스크들을 분리해 낼 수 있다
    return N % 2 || abs(diff) <= 1;
}

int main() {
    int T;
    // 테스트 케이스의 수를 입력받아 각 테스트 케이스의 정답을 출력
    for (scanf("%d", &T); T--; ) printf("%s\n", test_case() ? "YES" : "NO");
    return 0;
}
