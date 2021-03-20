#include <cstdio>
#include <queue>
#include <vector>

// truth[i]: i가 진실을 안다면 true
bool truth[50] = { false, };
// party[i][j]: i번째 파티에 j가 있었다면 true
bool party[50][50] = {{ false, }};
// graph[i][j]: i와 j가 같은 파티에 있었다면 true
bool graph[50][50] = {{ false, }};

int N, M;
// bfs에 사용할 큐
std::queue<int> q;

int main()
{
    // buf: 입력 변환에 사용할 버퍼
    // num: 각 파티 당 인원수 / bfs에서 q.front()
    int buf, num;
    scanf("%d %d", &N, &M);
    
    // 진실을 알고 있는 사람을 각각 입력받는다
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &buf); buf--;
        truth[buf] = true;
        q.push(buf);
    }

    // 각 파티에 대해
    for (int i = 0; i < M; i++)
    {
        // 같은 파티에 참여한 사람의 집합
        std::vector<int> v;
        scanf("%d", &num);
        // i번째 파티에 참여한 사람을 party 변수에 저장한 뒤
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &buf); buf--;
            party[i][buf] = true;
            v.push_back(buf);
        }
        
        // 이 파티에 참여한 사람들이 서로 만난 적 있음을 표시
        for (auto j: v) for (auto k: v) graph[j][k] = j != k;
    }

    // bfs
    while(!q.empty())
    {
        num = q.front();
        q.pop();

        // 파티에서 만난 사람들 중 탐색하지 않은 사람이 있다면 탐색
        for (int i = 0; i < N; i++) if (graph[num][i] && !truth[i])
        {
            truth[i] = true;
            q.push(i);
        }
    }

    // 파티 중 진실을 아는 사람, 혹은 진실을 전해들은 사람이 있다면
    for (int i = M - 1; i >= 0; i--) for (int j = 0; j < N; j++) 
        if (party[i][j] && truth[j])
        {
            // 참여 가능한 파티의 수를 1 줄인다
            M--;
            break;
        }

    // 참여 가능한 파티의 개수를 출력
    printf("%d\n", M);

    return 0;
}