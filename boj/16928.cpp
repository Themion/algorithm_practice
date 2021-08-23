#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

// visit[i]: 노드 i에 방문한 적이 있다면 true, 아니라면 false
bool visit[101] = { false, true, };
// arrived[i]:  주사위를 굴려 노드 i에 도착했을 때 
//              뱀이나 사다리에 의해 이동하게 될 노드
int arrived[101];
// v[i]: 노드 i에서 주사위를 굴려 갈 수 있는 노드
vector<int> v[101];
// bfs에 사용할 큐
queue<int> q;

void bfs()
{
    // 현재 스텝에서 도착 가능한 노드의 수
    int size = q.size();

    // 각 노드에 대해
    while (size--)
    {
        // 도착 가능한 노드를 q에서 가져온 뒤
        int n = q.front();
        q.pop();

        // n에서 이동 가능한 노드를 q에 push
        for (int i : v[n]) if (!visit[arrived[i]])
        {
            visit[i] = true;
            q.push(i);
        }
    }
}

int main()
{
    int snake, stair, s, e, step;

    // arrived[i]의 기본 값을 지정
    for (int i = 1; i <= 100; i++) arrived[i] = i;

    // 뱀 혹은 사다리의 시작점 노드는 arrived에서 대체
    scanf("%d %d", &snake, &stair);
    for (int i = 0; i < snake + stair; i++)
    {
        scanf("%d %d", &s, &e);
        arrived[s] = e;
    }

    // 각 노드에서 주사위를 굴려 이동 가능한 노드를 계산
    for (int i = 1; i < 100; i++) for (int j = 1; j <= 6 && i + j <= 100; j++)
        v[i].push_back(arrived[i + j]);

    // 게임은 반드시 1번 노드에서 시작한다
    q.push(1);

    // 100번 노드에 도착할 때까지 bfs를 실행
    for (step = 0; !visit[100]; step++) bfs();
    // 100번 노드에 도착할 때까지의 step 수를 반환
    printf("%d\n", step);

    return 0;
}