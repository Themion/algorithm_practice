#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int N, M;
bool table[100][100] = {{ false, }};

int bfs()
{
    //add[i][j]: 이웃한 좌표를 계산할 때 사용
    int add[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    //y, x: 이웃한 좌표
    //cnt: 노드를 이동한 횟수, size: bfs 시 각 단계별 큐의 크기
    int y, x, cnt = 0, size;

    //bfs 시 방문할 노드를 저장할 큐
    queue<std::pair<int, int>> q;
    //방문할 노드의 좌표
    pair<int, int> p;

    //시작점을 먼저 push한다
    q.push(pair<int, int>(0, 0));

    //큐에 노드가 존재할 동안
    while (!q.empty())
    {
        //이동한 노드 수를 1 늘린 뒤
        cnt += 1;
        //큐의 크기를 측정
        size = q.size();

        //큐의 각 노드에 대해
        for (int i = 0; i < size; i++)
        {
            //큐의 front를 p에 저장한 뒤 q에서 pop
            p = q.front();
            q.pop();

            //해당 노드가 목적지라면 노드 이동 횟수를 반환
            if (p.first == N - 1 && p.second == M - 1) return cnt;

            //해당 노드와 이웃한 노드에 대해
            for (auto a : add)
            {
                //이웃한 노드의 좌표를 계산한 뒤 그 좌표가 valid한지 판정
                y = p.first + a[0]; x = p.second + a[1];
                if (y < 0 || y >= N || x < 0 || x >= M) continue;
                //이웃한 노드로 이동이 가능하다면 해당 노드를 queue에 push
                else if (table[y][x])
                {
                    table[y][x] = false;
                    q.push(pair<int, int>(y, x));
                }
            }
        }
    }

    //답을 찾지 못한 경우에는 무한을 반환
    return 0x3f3f3f3f;
}

int main()
{
    char buf;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("\n");
        for (int j = 0; j < M; j++)
        {
            scanf("%c", &buf);
            table[i][j] = buf == '1';
        }
    }

    table[0][0] = false;
    printf("%d\n", bfs());

    return 0;
}