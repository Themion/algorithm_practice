#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> meet;

#define MAX_N 100000

#define _start first
#define _end second

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 주어진 회의의 수, end: 가장 마지막으로 끝난 회의의 끝나는 시간
    // ans: 회의실을 사용한 회의의 수
    int N, end = -1, ans = 0;
    // 각 회의를 저장할 배열
    meet m[MAX_N];

    // 회의의 수와 각 회의를 입력받는다
    cin >> N;
    for (int i = 0; i < N; i++) cin >> m[i]._start >> m[i]._end;

    // 회의들을 끝나는 시간 순으로
    // 끝나는 시간이 같다면 시작하는 시간 순으로 정렬한다
    sort(m, m + N, [](meet a, meet b) { 
        if (a._end == b._end) return a._start < b._start;
        return a._end < b._end; 
    });

    // 정렬된 순서대로 회의 일정을 살펴본다
    // 현재 회의가 이전 회의와 겹치지 않는다면
    for (int i = 0; i < N; i++) if (end <= m[i]._start) {
        // 해당 회의를 배정한다.
        end = m[i]._end;
        // 회의실을 사용한 회의가 하나 더 늘었다
        ans++;
    }

    // 회의실을 사용한 회의의 수를 출력한다
    cout << ans << '\n';

    return 0;
}
