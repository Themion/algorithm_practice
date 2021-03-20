#include <algorithm>
#include <cstdio>
#include <deque>

#define N_MAX 20

using namespace std;

// 좌표를 pair를 사용해 나타낸다
typedef pair<int, int> crd;

// N: 공간의 크기
// bulk: 상어의 크기, cnt: 상어가 현재 크기일 때 먹은 물고기의 수
int N, bulk = 2, cnt = 0;
// 공간
int place[N_MAX][N_MAX] = {{ 0, }};
// 상어가 마지막으로 물고기를 먹은 위치
crd shark;

// 주어진 좌표가 공간 안에서 가능한 좌표인지 확인
bool valid(int y, int x)
{ return (y >= 0) && (y < N) && (x >= 0) && (x < N); }

int find()
{
    // 물고기가 있는지 확인할 좌표의 집합
    // queue의 기능만 있으면 되지만 정렬을 위해 deque를 사용
    deque<crd> q;
    // time: 이동하는 데 걸린 시간, q_size: bfs에 사용할 큐
    // y, x: 상어의 현재 위치
    // yy, xx: 이동 가능한지 확인할 좌표
    int time = 0, q_size, y, x, yy, xx;
    // add: 상어가 이동 가능한 공간의 상대 좌표
    int add[4][2]  = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    // visit[y][x]: 주어진 좌표를 방문했다면 true, 아니라면 false
    bool visit[N_MAX][N_MAX] = {{ false, }};

    // 상어의 현재 위치를 q에 push한 뒤 방문했음을 표시
    q.push_back(shark);
    visit[shark.first][shark.second] = true;

    // 이동 가능한 모든 좌표에 대해
    while(!q.empty())
    {
        // 이동 가능한 좌표를 규칙에 맞게 정렬한 뒤
        sort(q.begin(), q.end());
        // bfs를 위해 현재 q의 길이를 저장
        q_size = q.size();

        // bfs 실행
        for (int i = 0; i < q_size; i++)
        {
            // 상어의 좌표를 갱신
            y = q.front().first; x = q.front().second;
            q.pop_front();

            // 이 좌표에 큰 물고기가 있다면 이 좌표로 이동할 수 없음
            if      (place[y][x] > bulk) continue;
            // 이 좌표에 먹을 수 있는 물고기가 있다면
            else if (place[y][x] != 0 && place[y][x] < bulk)
            {
                // 물고기를 먹어 배를 채운 뒤 마지막으로 식사한 좌표를 갱신
                place[y][x] = 0;
                cnt = (cnt + 1) % bulk;
                bulk += (cnt == 0);
                shark.first = y; shark.second = x;

                // 이동하는 데 걸린 시간을 반환
                return time;
            }

            // 현재 위치와 인집헌 모든 위치에 대해
            for (auto a: add) 
            {
                yy = y + a[0]; xx = x + a[1];
                // 해당 위치로 이동할 수 없다면 continue
                if (!valid(yy, xx) || visit[yy][xx]) continue;
                // 해당 위치로 이동할 수 있다면 q에 push
                else 
                {
                    visit[yy][xx] = true;
                    q.push_back(crd(yy, xx));
                }
            }
        }

        // 칸을 하나씩 이동헀으므로 time을 1 더한다
        time++;
    }

    // 먹을 수 있는 물고기가 없다면 이동하지 않는다
    return 0;
}

int main()
{
    // ret: 이동하는데 걸린 총 시간
    // temp: 이동 한 번에 걸린 시간을 별개로 저장
    int ret = 0, temp = 1;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        scanf("%d", &place[i][j]);
        // 공간을 입력받을 때 상어의 위치는 빈 공간으로 저장
        if (place[i][j] == 9)
        {
            shark = crd(i, j);
            place[i][j] = 0;
        }
    }

    // 잡아먹을 수 있는 물고기를 모두 잡아먹는다
    while (temp = find()) ret += temp;

    // 공간을 이동하는데 걸린 총 시간을 출력
    printf("%d\n", ret);

    return 0;
}