#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> coord;
typedef pair<coord, int> dust;

#define MAX_R 50
#define _y first
#define _x second
#define _coord first
#define _amount second

// R, C: 방의 크기, T: 공기청정기를 가동시킬 시간, room: 방의 각 칸의 미세먼지
// cleaner: 공기청정기 하단의 y좌표
int R, C, T, room[MAX_R][MAX_R], cleaner;
short add[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

coord operator+(coord c, int i) { return { c._y + add[i][0], c._x + add[i][1] }; }

// c가 방 안 좌표이면서 공기청정기 좌표가 아닌 경우에만 true
bool valid(coord c) {
    return c._y >= 0 && c._y < R && c._x >= 0 && c._x < C &&
        room[c._y][c._x] != -1;
}

// 공기청정기를 작동시켜 공기를 흡입
void activate_cleaner() {
    // 공기청정기 상단
    // 하단의 y좌표을 상단의 좌표로 변경
    for (int y = --cleaner - 1; y > 0; y--)     // 상단 순환의 왼쪽
        room[y][0] = room[y - 1][0];
    for (int x = 0; x < C - 1; x++)             // 상단 순환의 위쪽
        room[0][x] = room[0][x + 1];
    for (int y = 0; y < cleaner; y++)           // 상단 순환의 오른쪽
        room[y][C - 1] = room[y + 1][C - 1];
    for (int x = C - 1; x > 1; x--)             // 상단 순환의 아랫쪽
        room[cleaner][x] = room[cleaner][x - 1];
    room[cleaner][1] = 0;   //공기청정기에서 나온 공기는 미세먼지가 없다

    // 공기청정기 하단
    // 상단의 y좌표을 하단의 좌표로 변경
    for (int y = ++cleaner + 1; y < R - 1; y++) // 하단 순환의 왼쪽
        room[y][0] = room[y + 1][0];
    for (int x = 0; x < C - 1; x++)             // 하단 순환의 아랫쪽
        room[R - 1][x] = room[R - 1][x + 1];
    for (int y = R - 1; y > cleaner; y--)       // 하단 순환의 오른쪽
        room[y][C - 1] = room[y - 1][C - 1];
    for (int x = C - 1; x > 1; x--)             // 하단 순환의 위쪽
        room[cleaner][x] = room[cleaner][x - 1];
    room[cleaner][1] = 0;   //공기청정기에서 나온 공기는 미세먼지가 없다
}

// 미세먼지 확산
void spread_dust() {
    coord c;
    // q.front()를 저장할 공간
    dust d;
    // bfs에 사용할 q
    queue<dust> q;

    // 방 안의 모든 좌표에 대해
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        // 미세먼지의 양이 5 미만이라면 미세먼지가 확산되지 않음
        if (room[i][j] < 5) continue;
        // 미세먼지가 확산될 양
        int amount = room[i][j] / 5;

        // 미세먼지가 있는 좌표의 주변 좌표에 대해
        for (int dir = 0; dir < 4; dir++) {
            // 주변 좌표를 계산한 뒤 계산 결과가 valid하지 않다면 continue
            c = coord(i, j) + dir;
            if (!valid(c)) continue;
            // 확산될 양만큼 미세먼지를 줄인 뒤 q에 push
            room[i][j] -= amount;
            q.push({ c, amount });
        }
    }

    // q에 들어간 미세먼지를 room에 배치
    while (!q.empty()) {
        d = q.front();
        q.pop();

        room[d._coord._y][d._coord._x] += d._amount;
    }
}

int main() {
    // T초 후의 미세먼지의 총량
    int ans = 0;

    // 문제의 조건을 입력받으며 공기청정기 하단의 좌표를 저장
    scanf("%d %d %d", &R, &C, &T);
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        scanf("%d", &room[i][j]);
        if (room[i][j] == -1) cleaner = i;
    }

    // T회만큼 미세먼지의 확산과 공기청정기 가동을 반복
    while (T--) {
        spread_dust();
        activate_cleaner();
    }

    // 모든 칸에 존재하는 미세먼지의 수를 모두 더해 출력
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        // 공기청정기가 있는 좌표는 건너뛴다
        if (room[i][j] == -1) continue; 
        ans += room[i][j];
    }
    printf("%d\n", ans);

    return 0;
}
