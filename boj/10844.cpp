#include <cstdio>

#define MAX_N 100
#define MOD 1000000000

int main() {
    // N: 자릿수를 저장할 공간
    // stair[i][j]: i + 1자리 수 중 마지막 숫자가 j로 끝나는 계단 수의 개수
    // ans: N자리 계단수의 개수를 저장할 공간
    int N, stair[MAX_N][10] = {{ 0, }}, ans = 0;
    // 자릿수를 입력받는다
    scanf("%d", &N);

    // 0이 아닌 한 자리 수는 모두 계단수이다
    for (int i = 1; i <= 9; i++) stair[0][i] = 1;
    // i + 1자리의 계단수의 개수를 i자리 계단수의 경우의 수를 이용해 계산
    for (int i = 1; i < N; i++) {
        // 1의 자리가 0 혹은 9인 경우 10의 자리는 한 가지 경우로 고정됨
        stair[i][0] = stair[i - 1][1];
        stair[i][9] = stair[i - 1][8];
        // 1의 자리가 1 <= j <= 8이라면 10의 자리는 j - 1 혹은 j + 1이다
        for (int j = 1; j <= 8; j++) 
            stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1]) % MOD;
    }

    // ans에 N자리 계단수의 개수를 모두 더해 MOD로 나눈 값을 출력한다
    for (int i = 0; i < 10; i++) ans = (ans + stair[N - 1][i]) % MOD;
    printf("%d\n", ans);

    return 0;
}
