#include <cstdio>

int main() {
    // E, S, M: 각각 지구, 태양, 달을 나타내는 수
    // ans : 구하고자 하는 년도 저장, add : ans에 더할 가중치
    int E, S, M, ans = 0, add = 1;
    scanf("%d %d %d", &E, &S, &M);

    // 나머지 연산이 용이하게끔 수를 1씩 빼 준다
    E -= 1;
    S -= 1;
    M -= 1;

    // 지구, 태양, 달을 나타내는 수가 같은 년도는 7980년에 한 번 온다
    // 빠른 시간 안에 계산할 수 있는 범위이므로 완전 탐색 실행
    while (ans % 15 != E || ans % 28 != S || ans % 19 != M) ans++;

    // 나머지 연산을 위해 E, S, M에 1을 빼 주었으므로 ans에 1을 더한 값을 출력
    printf("%d\n", ans + 1);

    return 0;
}
