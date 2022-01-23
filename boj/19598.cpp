#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, char> pii;

#define _crd first
#define _stat second

#define MAX_N 100000

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 회의의 개수, s, e: 회의의 시작 시간과 종료 시간
    // cnt: 동시에 진행되는 회의의 개수, ans: 최소 회의실 개수
    int N, s, e, cnt = 0, ans = 0;
    pii arr[MAX_N * 2];

    // 회의의 개수를 입력받은 뒤 각 회의에 대해
    cin >> N;
    for (int i = 0; i < N; i++) {
        // 회의의 시작 시간과 종료 시간을 입력받고 각각 arr에 표시
        cin >> s >> e;
        arr[2 * i] = {s, 1};
        arr[2 * i + 1] = {e, -1};
    }
    // arr을 정렬한 뒤
    sort(arr, arr + (N *= 2));
    // 최소 회의실 어느 시점에 겹치는 회의의 최대 수이므로
    // 라인스위핑을 통해 겹치는 회의의 개수를 세어 그 최댓값을 ans에 저장
    for (int i = 0; i < N; i++) ans = max(ans, (cnt += arr[i]._stat));
    // 최소 회의실 개수를 출력
    cout << ans << '\n';

    return 0;
}
