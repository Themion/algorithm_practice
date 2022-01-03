#include <cstdio>

int main() {
    // N, ans: ans에 N부터 1까지 모두 곱한 값을 저장
    int N, ans = 1;

    // N!을 계산해 ans에 저장한 뒤 출력
    for (scanf("%d", &N); N; ) ans *= N--;
    printf("%d\n", ans);

    return 0;
}
