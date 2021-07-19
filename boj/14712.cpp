#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> coord;

#define _y first
#define _x second

// 블럭을 입력받을 공간
bool plate[25][25];
// 공간의 크기
int N, M;

// 좌표 c를 오른쪽 아래 꼭지점으로 하는 2*2 블록이 있는지 반환
bool is_square(coord c) { return (c._y > 0 && c._x > 0 && plate[c._y - 1][c._x] && plate[c._y][c._x - 1] && plate[c._y - 1][c._x - 1]); }
// 좌표 c의 바로 오른쪽, 혹은 아랫줄 첫번째 좌표를 반환
coord next(coord c) { return {c._y + (c._x + 1 == M), (c._x + 1) % M}; }

// 현재 plate에서 좌표 c에 대해 백트래킹 실행
int backtrack(coord c)
{
    // 백트래킹 시 얻을 수 있는 가능한 경우의 수
    int ret = 0;

    // 모든 좌표에 값을 채운 경우, 이 경우는 가능한 경우이므로 1을 반환
    if (c._y == N) return 1;

    // 현재 좌표에 블록이 있을 때 2*2 블록이 만들어지지 않는다면 다음 좌표에 대해 백트래킹
    plate[c._y][c._x] = true;
    if (!is_square(c)) ret += backtrack(next(c));

    // 현재 좌표에 블록이 없을 때 2*2 블록은 반드시 존재하지 않으므로
    // 다음 좌표에 대해 백트래킹
    plate[c._y][c._x] = false;
    ret += backtrack(next(c));

    return ret;
}

int main()
{
    // 공간의 크기를 입력받은 뒤
    scanf("%d %d", &N, &M);
    // 백트래킹으로 블럭을 채워넣을 수 있는 경우의 수를 구한다
    printf("%d\n", backtrack({0, 0}));

    return 0;
}