#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 8

// visit[i]: 수열에 i가 사용되었다면 true, 아니라면 false
bool visit[MAX_N + 1];
// N: 사용할 자연수의 종류, M: 수열의 길이, item: 수열에 쓰일 각 수, arr: 만든 수열
int N, M, item[MAX_N], arr[MAX_N];

void backtrack(int len) {
    // len이 M라면 수열을 모두 채운 것이므로 수열을 출력한 뒤 종료
    if (len == M) {
        for (int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    // 아직 사용되지 않은 수가 있다면
    for (int i = 0; i < N; i++) if (!visit[i]) {
        // 수열에 추가한 뒤
        arr[len] = item[i];
        visit[i] = true;
        // 수열의 다음 수를 채우고
        backtrack(len + 1);
        // 수열에서 i를 제거
        visit[i] = false;
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N과 M을, 수열을 만들 수를 입력받은 뒤 정렬하고
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> item[i];
    sort(item, item + N);
    // 조건을 만족하는 수열을 모두 출력
    backtrack(0);

    return 0;
}
