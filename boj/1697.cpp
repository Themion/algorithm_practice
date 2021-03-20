#include <cstdio>
#include <queue>

#define MAX 100000

int N, K;
//map[i]: 노드 i를 방문했는지 확인
bool map[MAX + 1] = { false, };
//bfs에 사용할 노드
std::queue<int> q;

int main()
{
    //2중 루프를 벗어나기 위한 트리거
    bool found = false;
    //time: 도착 노드까지 걸리는 시간, size: bfs에 사용되는 큐의 크기
    //node: 방문할 각 노드
    int time = 0, size, node;

    scanf("%d %d", &N, &K);
    map[N] = true;
    q.push(N);

    //아직 목표 노드를 찾지 못했다면
    while (!found)
    {
        //큐의 사이즈만큼 루프를 돌면서
        size = q.size();
        for (int i = 0; i < size; i++)
        {
            //큐의 각 성분이 목표 노드인지 확인한 후
            node = q.front();
            if (node == K)
            {
                //맞다면 걸린 시간을 출력한 뒤 종료
                printf("%d\n", time);
                found = true;
                break;
            }
            //1초만에 이동할 수 있는 노드를 큐에 넣어 bfs
            for (auto t : {node - 1, node + 1, node * 2})
                if (0 <= t && t <= MAX && !map[t])
                {
                    map[t] = true;
                    q.push(t);
                }
            //탐색한 노드는 큐에서 제거
            q.pop();
        }
        time++;
    }

    return 0;
}