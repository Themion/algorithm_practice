#include <cstdio>
#include <queue>

using namespace std;

#define MAX 1000001

// step[i]: N에서 1로 만들 때 i바로 이전 순서의 수
int step[MAX + 1] = { 0, 1, };
// bfs에 사용할 큐
queue<int> q;

int main()
{
    // 1로 만들 수
    int N;
    scanf("%d", &N);

    // 1에서부터 역순으로 탐색
    q.push(1);

    // bfs
    while(!q.empty() && !step[N])
    {
        int node = q.front();
        q.pop();

        // 현재 수의 3배수, 2배수, 다음 수를 탐색하여 큐에 넣는다
        if (3 * node <= MAX && !step[3 * node]) 
        {
            step[3 * node] = node;
            q.push(3 * node);
        }

        if (2 * node <= MAX && !step[2 * node]) 
        {
            step[2 * node] = node;
            q.push(2 * node);
        }

        if (node + 1 <= MAX && !step[node + 1]) 
        {
            step[node + 1] = node;
            q.push(node + 1);
        }
    }

    // 탐색이 완료된 후에는 큐를 비운다
    while (!q.empty()) q.pop();

    // N에서 1까지 가는 경로를 q에 순서대로 push
    q.push(N);
    while (N > 1)
    {
        N = step[N];
        q.push(N);
    }

    // 경로의 길이와 경로를 출력
    printf("%d\n", q.size() - 1);
    while (!q.empty())
    {
        printf("%d%c", q.front(), q.size() > 1 ? ' ' : '\n');
        q.pop();
    }

    return 0;
}