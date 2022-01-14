#include <iostream>

using namespace std;

#define MAX_H 256
#define INF 0x3f3f3f3f

int abs(int n) { return n < 0 ? -n : n; }
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // M, N: 집터의 크기, low, high: 집터의 최소 / 최대 높이
    // height: 땅고르기 후의 집터의 높이
    short M, N, low = MAX_H, high = 0, height;
    // B: 인벤토리 안에 든 블록의 개수
    // dig, put: 땅을 고르기 위해 파거나 놓은 블록의 수
    // ground[i]: 높이 i인 좌표의 수, ans: 최소 땅고르기 비용
    int B, dig, put, ground[MAX_H + 1] = { 0, }, ans = INF;

    // 문제의 조건을 입력받으며 ground와 low, high를 완성시킨다
    cin >> M >> N >> B;
    for (int i = 0; i < N * M; i++) {
        cin >> height;
        ground[height]++;
        low = min(low, height);
        high = max(high, height);
    }

    // 땅을 높이 h로 고르는 비용을 계산
    for (int h = low; h <= high; h++) {
        // dig와 put을 0으로 초기화
        dig = put = 0;
        // 각 좌표의 높이를 h로 만들 때 필요한 작업과 그 횟수를 계산
        for (int i = low; i <= high; i++)
            (i > h ? dig : put) += abs(i - h) * ground[i];

        // 가진 블록을 모두 사용해도 높이를 h로 맞출 수 없다면 continue
        if (dig + B < put) continue;
        // 가진 모든 블록을 내려놓을 필요는 없으므로 최소한의 블록만 내려놓게끔 한다
        put = min(put, dig + B);

        // 땅고르기를 하는 시간이 기존 시간과 같거나 작을 때 시간과 높이를 갱신
        if (ans >= 2 * dig + put) {
            ans = 2 * dig + put;
            height = h;
        }
    }

    // 땅고르기를 할 최소 시간과 이 떄의 높이를 출력
    cout << ans << ' ' << height << '\n';

    return 0;
}
