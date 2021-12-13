#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 1000
#define INF 0x3f3f

// arr[i]: i번째 상자의 크기
// dp[i]: i개 상자를 넣을 수 있는 상자 중 가장 크기가 작은 상자
short arr[MAX_N], dp[MAX_N];

int main() {
    // n: 상자의 개수, l: 각 증가하는 부분 수열의 길이
    // ans: 가장 긴 증가하는 부분 수열의 길이
    short n, l, ans = 0;

    // 상자의 개수와 각 상자의 크기를 입력받은 뒤
    scanf("%hd", &n);
    for (int i = 0; i < n; i++) scanf("%hd", &arr[i]);

    // 만든 상자의 집합, 즉 증가하는 부분 수열을 초기화
    fill_n(dp, n, INF);

    // 각 상자에 대해
    for (int i = 0; i < n; i++) {
        // 여태까지 넣은 상자 중 자신보다 작으면서 가장 큰 상자를 찾고
        for (l = ans; dp[l] >= arr[i]; l--);
        // 그 상자 바로 다음 상자를 현재 상자로 대체한 뒤
        dp[++l] = arr[i];
        // 넣은 상자의 개수를 갱신
        ans += (ans == l);
    }

    // 넣을 수 있는 최대의 상자 개수를 출력
    printf("%hd\n", ans);

    return 0;
}
