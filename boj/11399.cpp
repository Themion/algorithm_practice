#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 1000

int main() {
    // N: 사람의 수, P: 각 사람이 인출할 때 걸리는 시간, ans: 총 대기시간
    int N, P[MAX_N] = { 0, }, ans = 0;

    // 문제의 조건을 입력받은 뒤
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", P + i);

    // 총 대기시간을 최소로 하기 위해선 인출 시간이 짧은 순으로 인출해야 하므로 정렬
    sort(P, P + N);
    // 각 인원의 인출 시간과 인출할 때 기다려야 하는 사람의 수를 각각 곱해 ans에 더한다
    for (int i = 0; i < N; i++) ans += (N - i) * P[i];

    // 총 대기시간을 출력
    printf("%d\n", ans);

    return 0;
}
