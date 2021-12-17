#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> coord;

#define MAX_N 25
#define _y first
#define _x second

// N: 단지 부지의 크기, map: 단지 배치도
// add: 현재 노드와 인접한 노드의 인덱스 계산에 사용
int N, map[MAX_N][MAX_N], add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// v: 각 단지의 크기를 저장할 배열
vector<int> v;

bool valid(coord c) 
{ return (c._y >= 0 && c._y < N && c._x >= 0 && c._x < N && map[c._y][c._x]); }
coord operator+(coord c, int a[2]) { return {c._y + a[0], c._x + a[1]}; }

// c가 포함된 그래프를 탐색
void dfs(coord c, bool is_root) {
    // c의 인접한 노드를 저장할 공간
    coord c_;

    // c가 루트 노드라면 v에 단지내 집의 수를 저장할 공간을 생성
    if (is_root) v.push_back(0);

    // c를 비운 뒤 단지내 집의 수를 1 늘린다
    map[c._y][c._x] = 0;
    v.back()++;

    // c에 인접한 노드에 대해 dfs 실행
    for (auto a : add) if (valid(c_ = c + a)) dfs(c_, false);
}

int main() {
    // 그래프를 입력받기 위해 사용할 변수
    char buf;
    // 문제의 조건을 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("\n");
        for (int j = 0; j < N; j++) {
            // 문자열의 각 성분을 int로 바꾸어 저장
            scanf("%c", &buf);
            map[i][j] = buf - '0';
        }
    }

    // 부지 탐색 중 건물을 발견했다면 그 건물을 bfs
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (map[i][j]) 
        dfs({i, j}, true);

    // 단지 크기를 오름차순으로 정렬
    sort(v.begin(), v.end());

    // 단지의 수를 출력한 뒤 단지 크기를 오름차순으로 출력
    printf("%d\n", v.size());
    for (auto i : v) printf("%d\n", i);

    return 0;
}
