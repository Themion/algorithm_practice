#include <cstdio>
#include <queue>

using namespace std;

int main() {
    // N: 수열의 길이, K: 점프 거리
    int N, K, idx = 0;
    // 순열을 저장할 큐
    queue<int> q;

    // 문제의 조건을 입력받은 뒤 수열의 각 성분을 설정
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) q.push(i);

    // 출력 형식을 맞춘다
    printf("<");

    while (q.size()) {
        // 제거할 성분을 찾을 때까지 push와 pop을 반복한 뒤
        for (int i = 1; i < K; i++) {
            q.push(q.front());
            q.pop();
        }
        // 제거할 성분을 출력한 뒤 제거
        printf("%d", q.front());
        q.pop();
        // 출력 형식을 맞춘다
        printf("%s", q.size() ? ", " : ">\n");
    }

    return 0;
}
