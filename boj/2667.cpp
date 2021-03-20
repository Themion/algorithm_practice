#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

//N: 단지 부지의 크기, map: 단지 배치도
int N, map[25][25] = {{ 0, }};
//v: 각 단지의 크기를 저장할 배열
vector<int> v;

//단지 하나의 크기를 bfs로 탐색
void bfs(int y, int x)
{
    //현재 노드와 인접한 노드의 인덱스 계산에 사용
    int add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, yy, xx;
    //bfs로 탐색할 노드를 저장할 큐
    queue<pair<int, int>> q;

    //단지가 존재하므로 최소 크기인 1을 push
    v.push_back(1);

    //단지의 루트 노드를 큐에 넣고 탐색
    q.push(pair<int, int>(y, x));
    map[y][x] = 0;

    //아직 탐색할 노드가 존재한다면
    while (!q.empty())
    {
        //해당 노드의 이웃 노드에 대해
        for (auto a : add)
        {
            //인덱스를 계산한 뒤 valid하지 않다면 continue
            yy = q.front().first + a[0]; 
            xx = q.front().second + a[1];
            if (yy < 0 || yy >= N || xx < 0 || xx >= N) continue;
            //이웃 노드가 탐색 가능한 노드라면
            else if (map[yy][xx]) 
            {
                //탐색한 노드 수를 1 늘리고 q에 넣은 뒤 탐색
                v.back()++;
                q.push(pair<int, int>(yy, xx));
                map[yy][xx] = 0;
            }
        }

        //완전히 탐색한 노드는 pop하여 제거
        q.pop();
    }
}

int main()
{
    char buf;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("\n");
        for (int j = 0; j < N; j++)
        {
            scanf("%c", &buf);
            map[i][j] = buf - '0';
        }
    }
    
    //부지 탐색 중 건물을 발견했다면 그 건물을 bfs
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        if (map[i][j]) bfs(i, j);

    //단지 크기를 오름차순으로 정렬
    sort(v.begin(), v.end());

    //단지의 수를 출력한 뒤 단지 크기를 오름차순으로 출력
    printf("%d\n", v.size());
    for (auto i : v) printf("%d\n", i);

    return 0;
}