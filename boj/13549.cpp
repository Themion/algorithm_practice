#include <cstdio>
#include <queue>

using namespace std;

#define MAX 100000

// visit[i]: 노드 i에 방문한 적이 있다면 true, 아니라면 false
bool visit[MAX + 1] = { false, };
// 각 step에서 방문할 예정인 노드
queue<int> q;

// 한 노드에 방문했을 때 필요한 동작들
void push_q(int node)
{
    // 노드 n에서 노드 n * (2 ^ k)까지 이동하는 것은 시간이 소모되지 않음
    for (int n = node; n <= MAX; n *= 2) 
    {
        // 이미 방문한 노드를 밟았다면 이 이상 나아갈 필요가 없음
        if (visit[n]) break;
        // q에 노드를 넣은 뒤 방문했음을 표시
        q.push(n);
        visit[n] = true;
    }
}

int main()
{
    int N, K, node, step = 0, size;

    // 시작 노드와 목표 노드를 입력받은 뒤 시작 노드를 q에 push
    scanf("%d %d", &N, &K);
    push_q(N);

    // 시작 노드가 목표 노드보다 뒤에 있다면
    // 가능한 행동은 뒤로 한 칸 걷는 것 뿐이다
    if (N > K) step = N - K;
    // q가 전부 비었거나 노드 K에 방문했다면
    else while(!(q.empty() || visit[K]))
    {
        // q의 사이즈를 계산한 뒤
        size = q.size();

        // step번만에 도달할 수 있는 각 노드에 대해
        while (size--)
        {
            // 노드를 q에서 pop한 뒤
            node = q.front();
            q.pop();

            // 노드에서 앞뒤로 한 칸씩 이동한 노드를 q에 push
            for (int n : {node - 1, node + 1})
                if (n >= 0 && n <= MAX) push_q(n);
        }

        // step을 1 늘려 다음 step의 노드를 탐색
        step += 1;
    }

    printf("%d\n", step);

    return 0;
}