#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define MAX_N 200000
#define _N first
#define _stat second

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 판자의 개수, L, R: 각 판자의 시작점과 끝점
    // len: 라인스위핑에 사용할 좌표의 개수, idx: 라인스위핑에 사용할 인덱스
    // ans: 가장 멀리 갔을 때의 이동 거리
    int N, L, R, len = 1, idx = 0, line, ans = 0;
    // v[i]: 라인스위핑에서 나오는 i번째 좌표와 그 상태
    pii v[MAX_N * 2];
    // 도착 가능한 모든 판자의 시작점
    queue<int> q({ 0 });

    // 각 판자의 시작점과 끝점을 입력받아 v에 pair꼴로 저장
    for (cin >> N; N--; ) {
        cin >> L >> R;
        v[idx++] = { L, 1 };
        v[idx++] = { R, -1 };
    }
    // v를 좌표순으로 정렬
    sort(v, v + idx, [](pii a, pii b) { return a._N < b._N; });

    // v의 각 성분에 대해
    for (int i = 1; i < idx; i++) {
        // 좌표가 같은 곳의 시작점/끝점 여부를 모두 더해 저장
        if (v[len - 1]._N == v[i]._N) v[len - 1]._stat += v[i]._stat;
        // 그렇지 않다면 다음 좌표를 len 위치에 끌어온 뒤 len을 1 증가
        else v[len++] = v[i];
    }

    // 이동 가능한 모든 좌표를 bfs꼴로 탐색
    while (!q.empty()) {
        // 인덱스 하나를 q에서 가져와 idx에 저장한 뒤
        idx = q.front();
        q.pop();

        // idx번째 좌표의 시작점을 L에
        // idx번째 좌표에서 시작하는 판자의 개수를 line에 저장
        L = v[idx]._N;
        line = v[idx]._stat;

        // 이후 모든 좌표에 대해
        for (int i = idx + 1; i < len && line; i++) {
            // 각 좌표에서 판자 개수의 변화량을 line에 더한 뒤
            line += v[i]._stat;
            // 이동한 좌표의 최댓값을 갱신
            ans = max(ans, v[i]._N);

            // 판자가 끝났을 때
            if (!line)
                // 점프해서 이동 가능한 모든 좌표를 탐색하여
                // 각 판자의 시작점을 q에 push
                for (R = i + 1; R < len && v[i]._N - L >= v[R]._N - v[i]._N; R++)
                    if (v[R]._stat > 0) q.push(R);
        }
    }

    // 이동 가능한 좌표의 최댓값을 출력
    cout << ans << '\n';

    return 0;
}
