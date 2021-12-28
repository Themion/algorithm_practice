#include <cstdio>

#define MAX 10

int main() {
    // T: 테스트 케이스의 수, n: 각 테스트 케이스를 저장할 공간
    // ans[i]: i를 1, 2, 3의 합으로 나타낼 수 있는 경우의 수
    int T, n, ans[MAX + 1] = {0, 1, 2, 4};
    
    // 4부터 가능한 모든 경우에 대해 경우의 수를 계산
    for (int i = 4; i <= MAX; i++)
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];

    // 각 테스트 케이스마다 n을 나타낼 수 있는 경우의 수를 출력
    for (scanf("%d", &T); T--; ) {
        scanf("%d", n);
        printf("%d\n", ans[n]);
    }

    return 0;
}
