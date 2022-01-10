#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 100000

int abs(int num) { return num < 0 ? -num : num; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n: 고객의 수, coord[b][i]: i번째 고객의 집의 좌표의 (b ? y : x)값
    int n, coord[2][MAX_N];
    // 점포와 고객의 거리합의 최솟값
    long long ans = 0;

    // 문제의 조건을 입력받는다
    cin >> n;
    for (int i = 0; i < n; i++) cin >> coord[0][i] >> coord[1][i];

    // 좌표의 x값과 y값의 중간값을 각각 구한 뒤
    nth_element(coord[0], coord[0] + n / 2, coord[0] + n);
    nth_element(coord[1], coord[1] + n / 2, coord[1] + n);

    // 각 좌표값과 중간값의 차를 ans에 더해 거리합의 최솟값을 구한다
    for (int i = 0; i < n; i++) {
        ans += abs(coord[0][i] - coord[0][n / 2]);
        ans += abs(coord[1][i] - coord[1][n / 2]);
    }

    // 거리합의 최솟값을 출력
    cout << ans << '\n';

    return 0;
}
