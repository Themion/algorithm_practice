#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 50000

int min(int a, int b) {return a < b ? a : b; }

int main() {
    // visit[i]: 노드 i를 방문한 적이 있다면 true, 아니라면 false
    bool visit[MAX_N + 1] = { 0, };
    // n: 목표 노드, k: q의 front를 저장할 공간
    int n, k, time = 0, len = 1;
    // bfs에 사용할 큐
    queue<unsigned short> q;

    // 목표 노드를 입력받은 뒤
    scanf("%d", &n);

    // bfs를 위한 가상의 시작 노드를 push
    q.push(0);

    // 합이 n인 제곱수의 집합을 찾을 때까지
    while(!q.empty() && !visit[n]) {
        if (!--len) {
            len = q.size();
            time++;
        }

        // q에서 노드를 하나 가져와 k에 저장한 뒤
        k = q.front();
        q.pop();
        
        // k에 각 제곱수 i * i를 더한 값에 대해
        for (int i = 1; i * i + k <= n; i++) if (!visit[i * i + k]) {
            // 현재 수는 k에 제곱수를 하나 더한 값이므로
            // 합이 현재 수인 제곱수의 최소 개수 cnt[i * i + k]는 cnt[k] + 1이다
            visit[i * i + k] = true;
            // bfs를 위해 현재 수를 q에 push
            q.push(i * i + k);
        }
    }

    // 합이 n인 제곱수의 최소 개수를 출력
    printf("%d\n", time);

    return 0;
}
