#include <cstdio>

#define MAX_N 50
#define MAX_M 1000

int main() {
    // vol[i][j]: i번째 곡을 연주한 직후 볼륨이 j인 경우가 있다면 true
    bool vol[MAX_N + 1][MAX_M + 1] = {{ false, }};
    // N: 연주할 곡의 수, S: 초기 볼륨, M: 최대 볼륨
    int N, S, M;
    // c_vol[i]: i번째 곡을 연주한 직후 바꿀 수 있는 볼륨의 크기
    short c_vol[MAX_N + 1] = { 0, };

    // 문제의 조건을 입력받는다
    scanf("%d %d %d", &N, &S, &M);
    for (int i = 0; i < N; i++) scanf("%hd", &c_vol[i]);

    // 0번째 곡을 연주한 직후, 즉 공연 직전 볼륨을 S로 정한다
    vol[0][S] = true;

    // i번째 곡을 연주한 직후 볼륨이 j일 가능성이 있다면
    for (int i = 0; i < N; i++) for (int j = 0; j <= M; j++) if (vol[i][j]) {
        // j +- c_vol[i]이 범위 내 볼륨이라면 해당 볼륨으로 연주할 수 있다
        if (j + c_vol[i] <= M) vol[i + 1][j + c_vol[i]] = true;
        if (j - c_vol[i] >= 0) vol[i + 1][j - c_vol[i]] = true;
    }

    // N번째 곡을 연주한 직후 가능한 최대 볼륨을 찾아 출력
    for (S = M; S >= 0 && !vol[N][S]; S--);
    printf("%d\n", S);

    return 0;
}
