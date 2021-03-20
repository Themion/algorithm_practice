#include <cstdio>
#include <queue>

// 토마토가 담긴 칸의 좌표
class Coord
{
public:
    int h, n, m;
    Coord() { h = n = m = 0; }
    Coord(int h, int n, int m) 
    {
        this->h = h;
        this->n = n;
        this->m = m;
    }

    // 좌표 간의 덧셈
    Coord operator+(Coord other)
    {
        Coord ret;

        ret.h = this->h + other.h;
        ret.n = this->n + other.n;
        ret.m = this->m + other.m;

        return ret;
    }
};

// total: 익은 토마토가 들어있거나 비어있는 칸의 개수
// time: bfs를 마치기까지 걸린 시간
int total = 0, time = -1;
int M, N, H;            // 토마토를 담을 상자와 그 사이즈
short box[100][100][100] = {{{ false, }}};
std::queue<Coord> q;    // bfs에 이용할 큐

bool out_of_boundary (Coord c)
{
    if (c.h < 0 || c.h >= H) return true;
    if (c.n < 0 || c.n >= N) return true;
    if (c.m < 0 || c.m >= M) return true;
    return false;
}

void bfs()
{
    // 좌표에서 인접한 칸을 구할 때 사용할 값
    Coord add[6] = {
        Coord(0, 0, -1), Coord(0, 0, 1),
        Coord(0, -1, 0), Coord(0, 1, 0),
        Coord(-1, 0, 0), Coord(1, 0, 0)
    }, t;

    // 인접 칸에 영향을 미칠 수 있는 토마토가 존재한다면
    while(!q.empty())
    {
        // 현재 시간에서 큐의 사이즈를 저장한 뒤
        int size = q.size();
        // 큐의 각 원소에 대해
        for (int i = 0; i < size; i++)
        {
            // 인접 칸의 토마토를 익힐 수 있다면 익힌 칸을 q에 push
            for (auto a : add)
            {
                t = q.front() + a;
                if (out_of_boundary(t)) continue;
                if (box[t.h][t.n][t.m] == 0)
                {
                    box[t.h][t.n][t.m] = 1;
                    total++;
                    q.push(t);
                }
            }
            // 모든 인접 칸에 영향을 미쳤다면 q에서 pop
            q.pop();
        }
        // 시간이 1 지났으므로 이를 표시
        time++;
    }
}

int main()
{
    //상자의 크기와 각 칸의 상태를 입력받은 뒤
    scanf("%d %d %d", &M, &N, &H);
    for (int h = 0; h < H; h++) for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++)
        {
            scanf("%hd", &box[h][n][m]);
            // 익은 토마토가 있는 칸을 q에 push
            if (box[h][n][m] == 1) q.push(Coord(h, n, m));
            // 익은 토마토, 혹은 빈 칸의 수를 저장
            if (box[h][n][m] != 0) total++;
        }

    bfs();

    printf("%d\n", (total == H * N * M) ? time : -1);

    return 0;
}