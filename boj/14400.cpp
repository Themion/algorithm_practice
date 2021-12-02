#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 100000

int abs(int num) { return num < 0 ? -num : num; }

// coord[b][i]: i번째 좌표의 (b == 0 : x ? y)값
// 정렬을 위해 b를 첫번째 인덱스로 설정
int coord[2][MAX_N];

int main() {
    int n;
    long long ans = 0;

    // 평균이 아니라 중간값으로 접근해야 함

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &coord[0][i], &coord[1][i]);
    // 좌표의 x값과 y값을 각각 정렬한 뒤
    sort(coord[0], coord[0] + n);
    sort(coord[1], coord[1] + n);
    // 각 좌표값과 중간값의 차를 ans에 더한다
    for (int i = 0; i < n; i++) {
        ans += abs(coord[0][i] - coord[0][n / 2]);
        ans += abs(coord[1][i] - coord[1][n / 2]);
    }

    printf("%lld\n", ans);

    return 0;
}