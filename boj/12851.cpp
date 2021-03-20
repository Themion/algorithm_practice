#include <cstdio>
#include <queue>

#define MAX 100000

int N, K;
int map[MAX + 1] = { 0, };
bool visit[MAX + 1] = { false, };
std::queue<int> q, vis;

int main()
{
    bool found = false;
    int time = 0, size, node;

    scanf("%d %d", &N, &K);
    // N에서 N으로 이동할 때 걸리는 연산의 수는 1이라고 가정
    map[N] = 1;
    // 시작점을 q에 push
    q.push(N);

    // N이 K보다 큰 경우 가능한 연산은 -1 뿐이므로 이를 계산한다
    if (N > K) 
    {
        time = N - K + 1;
        map[K] = 1;
    }
    // N에서 K까지 갈 수 있는 방법이 다수 존재할 때
    else while (!found)
    {
        // step을 계산하는 문제이므로 while문을 이중으로 둔다
        size = q.size();
        while (size--)
        {
            // q에서 원소를 하나 가져와 K인지 검토
            node = q.front();
            q.pop();
            if (node == K) found = true;
            // 이 원소가 K가 아닌 경우, 즉 K로 가는 과정에 위치할 경우
            // 이후 연산을 거쳐 범위 내에 있을 때
            // 또한 이전에 방문한 적이 없어 경로를 낭비하지 않을 때
            else for (auto t : {node - 1, node + 1, node * 2})
                if (0 <= t && t <= MAX && !visit[t])
                {
                    // 같은 step 안에 방문한 적이 없다면 q에 넣는다
                    if (!map[t]) 
                    {
                        q.push(t);
                        vis.push(t);
                    }
                    // 현재 노드로 이동할 수 있는 경우의 수를
                    // 직전 노드까지 이동할 수 있는 경우의 수만큼 더한다
                    map[t] += map[node];
                }
        }
        // 이번 step에 방문한 노드를 이후 step에서 방문할 경우
        // 경로\가 낭비되어 불필요한 연산이 늘어나므로 방문을 막는다
        while(!vis.empty())
        {
            visit[vis.front()] = true;
            vis.pop();
        }
        // step을 한 횟수를 증가
        time++;
    }

    // step의 수와 경우의 수를 출력
    printf("%d\n%d\n", time - 1, map[K]);

    return 0;
}