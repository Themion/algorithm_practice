#include <iostream>

using namespace std;

#define MIN_X -1000000000

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 선분의 개수, x, y: 각 선분의 시작점과 끝점
    // end: 선분의 끝점의 최댓값, ans: 선분의 길이의 총합
    int N, x, y, end = MIN_X, ans = 0;

    // 각 선분에 대해
    for (cin >> N; N--; ) {
        // 선분의 시작점과 끝점을 입력받고
        cin >> x >> y;
        // 시작점과 끝점을 각각 기존 선분의 끝점의 최댓값과 비교해
        // 기존에 존재하던 선분과 겹치지 않는 부분을 계산해 ans에 더한다
        ans += max(end, y) - max(x, end);
        // 선분의 끝점의 최댓값을 갱신
        end = max(end, y);
    }

    // 선분의 길이의 총합을 출력
    cout << ans << '\n';

    return 0;
}
