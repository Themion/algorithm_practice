#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

// q에서 원소를 하나 가져온 뒤 pop
int get() {
    int ret = q.top();
    q.pop();
    return ret;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 체인의 개수, len: 체인의 길이, ans: 열고 닫아야 할 최소한의 고리의 수
    int N, len, ans = 0;

    // 체인의 개수를 입력받은 뒤
    cin >> N;
    for (int i = 0; i < N; i++) {
        // 각 체인의 길이를 입력받아 우선순위 큐에 push
        cin >> len;
        q.push(len);
    }

    // 열고 닫을 고리를 가져올 체인을 우선순위 큐에서 가져온 뒤
    len = get();
    // 조건을 만족할 때까지
    while (ans < q.size()) {
        // 현재 체인을 모두 열어도 남은 모든 체인을 연결하지 못한다면
        if (ans + len < q.size()) {
            // 우선 남은 체인을 모두 연 뒤 다음 체인과 비교
            ans += len;
            len = get();
        }
        // 현재 체인으로 모든 체인을 연결할 수 있다면
        // 고리는 총 (체인의 실제 개수 - 1)개가 필요하다
        else ans = q.size();
    }

    // 열고 닫아야할 최소한의 고리 수를 출력
    cout << ans << '\n';

    return 0;
}
