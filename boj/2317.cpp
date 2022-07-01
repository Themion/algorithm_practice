#include <cstdio>

#define MAX_K 1000
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

// N: 열차의 길이, K: 사자의 수
int N, K, lion[MAX_K];

int abs(int n) { return n < 0 ? -n : n; }

int check_leftover(int H, int L) {
    // 열차의 중간에 최댓값 혹은 최솟값을 넣을 경우
    int ret = abs(H - L) << 1;

    // 열차의 시작 혹은 끝에 최댓값 혹은 최솟값을 넣을 경우
    ret = MIN(ret, abs(lion[0] - H));
    ret = MIN(ret, abs(lion[K - 1] - H));

    // 세 경우를 비교한 뒤 가장 작은 값을 반환
    return ret;
}

int main () {
    // ans: 열차에서 인접한 키의 차이의 합
    // H[i]: 사람의 키의 {최솟값, 최댓값}[i]
    // L[i]: 사자의 키의 {최솟값, 최댓값}[i]
    // buf: 사람의 키를 임시로 입력받을 공간
    int ans = 0, H[2] = { 0, }, L[2] = { 0, }, buf;

    // 초기의 최솟값을 INT_MAX로, 초기의 최댓값을 0으로 초기화
    H[0] = L[0] = __INT_MAX__;

    // 열차의 길이와 사자의 수를 입력받은 뒤
    scanf("%d %d", &N, &K);

    // 사자의 키를 입력받아 그 범위를 계산
    for (int i = 0; i < K; i++) {
        scanf("%d", lion + i);
        L[0] = MIN(L[0], lion[i]);
        L[1] = MAX(L[1], lion[i]);
    }

    // 사람의 키를 입력받아 그 범위를 계산
    for (int i = K; i < N; i++) {
        scanf("%d", &buf);
        H[0] = MIN(H[0], buf);
        H[1] = MAX(H[1], buf);
    }

    // 인접한 사자끼리의 키의 차이의 합을 계산
    for (int i = 1; i < K; i++) ans += abs(lion[i] - lion[i - 1]);

    // 사람의 키의 최솟값과 최댓값이 사자의 키의 범위를 벗어난 경우
    // 사자의 배열에 사람의 키를 넣은 경우의
    // 차이의 최솟값을 계산해 ans에 더한다
    if (H[0] < L[0]) ans += check_leftover(H[0], L[0]);
    if (H[1] > L[1]) ans += check_leftover(H[1], L[1]);

    // 기차에서 인접한 앞뒤사람의 키 차이를 모두 더한 값을 출력
    printf("%d\n", ans);

    return 0;
}
