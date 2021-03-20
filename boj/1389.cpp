#include <cstdio>
#include <queue>

//n: 노드의 수, m: 에지의 수
int n, m;
//graph[0][i]: bfs 중 i번째 노드 방문 여부
//grpah[i][j]: i와 j가 서로 아는 사이일 경우 true, 아니라면 false
bool graph[101][101] = {{ false, }};

int bfs(int start, int mid, int cnt, int& score)
{
    //bfs에 사용할 큐
    std::queue<int> q;
    //모든 노드에 대해
    for (int i = 1; i <= n; i++)
    {
        //해당 노드가 루트 노드라면 continue
        if (start == i) continue;
        //노드 i가 탐색이 가능하고 방문한 적이 없다면
        if (graph[mid][i] && !graph[0][i])
        {
            //노드를 방문한 뒤 score를 추가하고 큐에 push
            graph[0][i] = true;
            score += cnt + 1;
            q.push(i);
        }
    }

    //큐에 존재하는 모든 노드에 대해 bfs를 실행
    while(q.size())
    {
        bfs(start, q.front(), cnt + 1, score);
        q.pop();
    }

    //bfs 이후 score를 반환한다
    return score;
}

int main()
{
    //그래프를 입력할 때 사용할 버퍼
    int a, b;
    //score: 각 노드의 케빈-베이컨 점수, min: 가장 작은 score, ret: min을 가진 노드
    int score, min = 0x3f3f3f3f, ret = -1;

    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d", &a, &b);
        graph[a][b] = true;
        graph[b][a] = true;
    }

    //모든 노드에 대해
    for (int i = 1; i <= n; i++)
    {
        //방문 기록을 초기화한 뒤
        for (auto &g: graph[0]) g = false;
        //bfs 결과 score를 비교하여 min과 ret을 갱신한다
        if (min > bfs(i, i, 0, score = 0))
        {
            min = score;
            ret = i;
        }
    }

    //가장 작은 케빈-베이컨 점수를 가진 노드를 출력
    printf("%d\n", ret);

    return 0;
}