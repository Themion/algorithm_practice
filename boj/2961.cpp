#include <cstdio>

#define INF 0x3f3f3f3f

// 재료의 수
int N;
// 각 재료의 신맛과 쓴맛 지수
int taste[10][2];

int abs(int num) { return num > 0 ? num : -num; }
int min(int a, int b) { return a < b ? a : b; }

// 요리의 신맛 지수와 쓴맛 지수가 각각 sour, bit일 때 idx번째 재료를 사용
int brute_force(int idx, int sour, int bit) {
    // 요리한 직후의 신맛과 쓴맛의 차
    int ret;

    // 신맛 지수는 기존 신맛 지수에 곱하고 쓴맛 지수는 기존 쓴맛 지수에 더한다
    sour *= taste[idx][0];
    bit += taste[idx][1];

    // 현재 요리의 신맛 지수와 쓴맛 지수의 차를 구한 뒤
    ret = abs(sour - bit);
    // 현재 요리에서 다른 재료를 추가했을 때 신맛 지수와 쓴맛 지수의 차가 줄어든다면
    // 줄어든 차를 ret에 저장한다
    for (int i = idx + 1; i < N; i++) ret = min(ret, brute_force(i, sour, bit));

    //신맛 지수와 쓴맛 지수의 차를 반환한다
    return ret;
}

int main() {
    //물의 신맛 지수와 쓴맛 지수의 차를 큰 값으로 지정한다
    int ans = INF, temp;

    // 재료의 수와 각 재료의 신맛/쓴맛 지수를 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", taste[i], taste[i] + 1);

    // 재료의 개수가 10개를 넘지 않으므로
    // 브루트포스 알고리즘을 이용해도 충분히 빠른 시간 안에 풀 수 있다
    for (int i = 0; i < N; i++) ans = min(ans, brute_force(i, 1, 0));

    // 요리하여 신맛 지수와 쓴맛 지수의 차가 최소인 값을 출력한다
    printf("%d\n", ans);

    return 0;
}
