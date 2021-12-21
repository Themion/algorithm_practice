#include <cstdio>

int main() {
    // N: 중앙 이동 알고리즘을 실행할 횟수, ans: 현재 점의 수
    int N, ans = 2;
    scanf("%d", &N);

    // 각 단계의 점의 총 개수는 가장 큰 정사각형의 한 변의 점의 개수의 제곱이다
    // 현재 단계의 한 변의 점의 개수는
    // 직전 단계의 한 변의 점의 개수에 2를 곱한 뒤 1을 뺀 값이므로
    // 이를 반복문으로 구현
    while (N--) ans += ans - 1;

    //한 변에 점이 ans개 있으므로 전체 점의 개수는 ans^2개이다
    printf("%d\n", ans * ans);

    return 0;
}
