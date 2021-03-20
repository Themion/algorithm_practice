#include <cstdio>
#include <queue>

// a - b의 절댓값을 계산
int abs(int a, int b) { return a > b ? a - b : b - a; }
//두 좌표 간의 맨하탄 거리를 계산
int dist(int node[][2], int a, int b) 
{ return abs(node[a][0], node[b][0]) + abs(node[a][1], node[b][1]); }

bool boj_9205()
{
    // f: q.front()를 바로 접근하지 않고 변수에 저장
    // node: 집, 편의점, 송도 페스티벌의 좌표
    int N, f, node[102][2];
    // visit[i]: i번째 노드에 방문했다면 true, 아니라면 false
    bool visit[102] = { false, };
    // bfs에 사용할 큐
    std::queue<int> q;

    scanf("%d", &N); N += 2;
    for (int i = 0; i < N; i++)
        scanf("%d %d", &(node[i][0]), &(node[i][1]));

    q.push(0); visit[0] = true; // 먼저 q에 집을 push한 뒤

    while(!q.empty())           // q에 존재하는 모든 노드에 대해
    {
        // 방문하지 않았으면서 방문 가능한 편의점을 q에 push
        f = q.front(); q.pop();
        for (int i = 0; i < N; i++)
            if (!visit[i] && dist(node, i, f) <= 1000)
            {
                // 이 떄 q에 push될 노드 중 송도페스티벌이 있다면 true를 반환
                if (i == N - 1) return true;
                q.push(i); visit[i] = true;
            }
    }

    return visit[N - 1];    // 송도페스티벌에 방문했는지를 반환 
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) printf("%s", boj_9205() ? "happy\n" : "sad\n");

    return 0;
}