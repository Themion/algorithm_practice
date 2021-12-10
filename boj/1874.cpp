#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define MAX_N 100000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n: 스택 수열의 길이, next: 스택에 넣을 다음 수
    // arr[i]: 스택 수열의 i번째 성분, idx: arr에 접근하기 위한 인덱스
    int n, next = 1, arr[MAX_N], idx = 0;
    // 출력하기 위한 스택의 push / pop 로그
    queue<char> log;
    // 스택 수열을 저장하기 위한 스택
    stack<int> s;

    // 문제의 조건을 입력받은 뒤
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 스택에 빼거나 넣을 수 있는 수가 존재할 때
    while (idx < n && next <= n) {
        // 스택에 idx번재 스택 수열이 등장할 때까지
        while (next <= arr[idx]) {
            // 각 자연수를 push한 뒤 로그에 표시
            s.push(next++);
            log.push('+');
        }
        // 스택에서 idx번째 스택 수열이 존재할 동안
        while (!s.empty() && (s.top() == arr[idx])) {
            // 스택에서 수열의 성분을 pop한 뒤 로그에 표시하고
            s.pop();
            log.push('-');
            // 다음 스택 수열에 대해 반복
            idx += 1;
        }
    }

    // idx가 n 이하라면 NO를 출력하고
    if (idx < n) cout << "NO\n";
    // 그렇지 않다면 로그를 순차적으로 출력한다
    else while (!log.empty()) {
        cout << log.front() << '\n';
        log.pop();
    }

    return 0;
}
