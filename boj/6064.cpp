#include <cstdio>

#define MAX_N 40000

int test_case() {
    // visit[x_]: 카잉 년도 <x_, y>를 발견했다면 true
    bool visit[MAX_N] = { false, };
    // M, N: 카잉 년도의 주기, <x, y>: 찾고자 하는 년도의 카잉 년도
    // ans: 입력받은 카잉 년도를 변환한 값
    int M, N, x, y, ans;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d %d %d", &M, &N, &x, &y);

    // 계산의 편의를 위해 x와 y에 값을 1씩 차감
    // 임의의 년도 <x_, y_>에 대해 y_ = y를 만족하는 최소의 ans를 계산
    x--; ans = --y;
    
    // 년도를 N씩 늘리며 카잉 년도 <x, y>를 만족하는 경우가 있는지 확인
    for (; !visit[x] && !visit[ans % M]; ans += N)
        visit[ans % M] = true;

    // 카잉 년도 <x, y>를 만족하는 경우가 있다면 그 년도를, 없다면 -1을 반환
    // ans를 반환할 경우, 년도의 시작이 1이고 for문에서 x를 표시한 뒤 N을 더했으므로
    // ans가 아닌 ans - N + 1을 반환해야 한다
    return visit[x] ? ans - N + 1 : -1;
}

int main() {
    int T;
    // 테스트 케이스를 입력받고 각 테스트 케이스의 정답을 출력
    for (scanf("%d", &T); T--; ) printf("%d\n", test_case());
    return 0;
}
