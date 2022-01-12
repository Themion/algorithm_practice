#include <cstdio>

#define MAX_M 13
#define MAX_N 50
#define INF 0x3f3f3f3f
#define FOR(i, a, b) for (int i = a; i < b; i++)

// 좌표 { y, x }
struct p { int y = 0, x = 0; };

// dist[h][c]: h번째 치킨집과 c번째 집의 치킨 거리
char dist[MAX_M][2 * MAX_N];
// N: 도시의 크기, M: 남길 치킨집의 개수, h: 집의 수, c: 치킨집의 수
// arr: 남길 치킨집의 각 인덱스, ans: 도시의 치킨 거리의 최솟값
int N, M, h, c, arr[MAX_M], ans = INF;

int abs(int n) { return n < 0 ? -n : n; }
int min(int a, int b) { return a < b ? a : b; }

void backtrack(int len, int idx) {
    // d: 각 집의 최소 치킨 거리, sum: 도시의 치킨 거리
    int d, sum = 0;

    // 남길 치킨집이 정해졌다면
    if (len == M) {
        // 각 집에 대해
        FOR(i, 0, h) {
            // 치킨 거리를 INF로 초기화한 뒤 최소 치킨 거리를 계산
            d = INF;
            FOR(j, 0, len) d = min(d, dist[arr[j]][i]);
            // 현재 집의 치킨 거리를 sum에 더한다
            sum += d;
        }
        // 도시의 최소 치킨 거리를 sum과 비교해 갱신
        ans = min(ans, sum);
        return;
    }

    // 아직 남겨야 할 치킨집이 존재한다면
    FOR(i, idx, c) {
        // len번째로 남길 치킨집을 i번째 치킨집으로 정한 뒤 다음 치킨집을 선정
        arr[len] = i;
        backtrack(len + 1, i + 1);
    }
}

int main() {
    // 각 좌표의 정보를 입력받을 공간
    int buf;
    // home[h]: h번째 집의 좌표, chik[c]: c번째 치킨집의 좌표
    p home[2 * MAX_N], chik[MAX_M];

    // 도시의 크기와 남길 치킨집의 개수를 입력받은 뒤
    scanf("%d %d", &N, &M);
    // 각 좌표에 대해
    FOR(y, 0, N) FOR(x, 0, N) {
        // 해당 좌표의 정보를 입력받고 
        scanf("%d", &buf);
        // 해당 좌표가 집 혹은 치킨집이라면 각각 home, chik에 저장
        if (buf == 1) home[h++] = { y, x };
        if (buf == 2) chik[c++] = { y, x };
    }

    // 각 치킨집과 집의 치킨 거리를 dist에 저장
    FOR(i, 0, c) FOR(j, 0, h)
        dist[i][j] = abs(chik[i].y - home[j].y) + abs(chik[i].x - home[j].x);

    // 남겨야 할 치킨집을 계산한 뒤
    backtrack(0, 0);

    // M개의 치킨집을 남겼을 때의 최소 치킨 거리를 출력
    printf("%d\n", ans);

    return 0;
}
