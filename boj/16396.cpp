#include <cstdio>

#define MAX 10000

int main() {
    // N: 선의 개수, X, Y: 각 선의 시작점과 끝점, ans: 투사한 선의 총 길이
    int N, X, Y, sum = 0, ans = 0;
    // chk[i]: 지점 i에서 시작하는 선의 개수 + 지점 i 직전에서 끝나는 선의 개수
    short chk[MAX + 1] = { 0, };

    // 각 선에 대해
    for (scanf("%d", &N); N--; ) {
        // 선의 시작점과 끝점을 입력받고 이를 chk에 저장
        scanf("%d %d", &X, &Y);
        chk[X] += 1; chk[Y] -= 1;
    }

    // 선의 각 지점에 대해
    for (int i = 0; i <= MAX; i++) {
        // 해당 지점에서의 시작점과 끝점의 차를 sum에 더한 뒤
        sum += chk[i];
        // sum이 양수라면 아직 끝나지 않은 선이 존재하므로 ans에 1을 더한다
        ans += (sum > 0);
    }

    // 투사한 선의 총 길이를 출력
    printf("%d\n", ans);

    return 0;
}
