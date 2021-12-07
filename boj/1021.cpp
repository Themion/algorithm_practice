#include <cstdio>
#include <queue>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main() {
    // N: 큐의 원소 개수, M: 1번 연산을 실행할 횟수
    // buf: 큐에서 제거할 각 원소, k: 2번 연산의 실행 횟수
    // ans: 주어진 경우에서 2번 연산, 혹은 3번 연산을 실행할 최소 횟수
    int N, M, buf, k, ans = 0;
    queue<int> q;
    scanf("%d %d", &N, &M);

    // 큐에 원소를 1부터 N까지 채워넣는다
    for (int i = 1; i <= N; i++) q.push(i);

    // 각 1번 연산에 대해
    while (M--) {
        // 2번 연산의 횟수 초기화
        k = 0;
        scanf("%d", &buf);

        // 제거할 원소를 찾을 때까지 2번 연산을 k번 반복
        while (q.front() != buf) {
            q.push(q.front());
            q.pop();
            k++;
        }
        // 1번 연산 실행
        q.pop();
        // 2번 연산을 k번 실행하는 것은 3번 연산을 N - k번 실행하는 것과 같으므로
        // 2번 연산과 3번 연산 중 횟수가 더 적은 연산을 실행한 것으로 간주한다
        ans += min(k, N - k);
        N--;
    }

    // 2번 연산과 3번 연산을 한 최소 횟수를 출력
    printf("%d\n", ans);

    return 0;
}
