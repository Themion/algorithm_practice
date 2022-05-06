#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pii;

#define MAX_N 1000
#define MAX_P 26
#define _y first
#define _x second

template <typename T>
class array2d {
public:
    // 어떤 타입의 2차원 배열
    T arr[MAX_N][MAX_N] = {{ 0, }};
    // 정수로 접근한 경우 1차원 배열을, pair로 접근한 경우 해당 항을 반환
    T* operator[](int i) { return arr[i]; }
    T& operator[](pii p) { return arr[p._y][p._x]; }
};

// M, N: 지도의 세로 및 가로 크기
int M, N;
// 지도의 정보
array2d<char> field;
// 지도의 각 위치를 플레이어가 방문했는지 bitmask꼴로 저장
array2d<int> visit;
// 각 플레이어가 보스가 있는 장소까지 최단시간 안에 이동하기 위한 큐
queue<pii> q[MAX_P];

// 지점 p가 지도 내의 이동할 수 있는 길인지 여부를 반환
bool valid(pii p) { 
    return 0 <= p._y && p._y < M && 0 <= p._x && p._x < N && field[p] != 'X';
}
// 어떤 수를 bitmask 형식으로 변경
int bit(int num) { return 1 << num; }
// 플레이어의 아이디를 정수꼴로 변경
int id(char c) { return c - 'a'; }
// 두 좌표를 더한 좌표를 반환
pii operator+(pii a, pii b) { return { a._y + b._y, a._x + b._x }; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 사용자의 아이디를 입력받을 공간
    char c;
    // P: 플레이어의 수, HP: 보스의 현재 체력
    // dps: 각 플레이어의 dps, dmg: 각 플레이어가 가한 총 데미지
    // ans: 보스에 데미지를 가한 플레이어의 수
    int P, HP, dps[MAX_P] = { 0, }, dmg[MAX_P] = { 0, }, ans = 0;
    // crd: 어떤 좌표를 저장할 공간, boss: 보스가 있는 곳의 좌표
    // add[i]: {상, 하, 좌, 우}[i] 방향으로의 변위
    pii crd, boss, add[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    // 문제의 조건을 입력받은 뒤
    cin >> M >> N >> P;
    for (int i = 0; i < M; i++) cin >> field[i];
    for (int i = 0; i < P; i++) cin >> c >> dps[id(c)];
    cin >> HP;

    // 보스와 각 플레이어의 초기 좌표를 저장
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
        // 각 좌표와 그 좌표의 값을 저장한 뒤
        crd = {i, j};
        c = field[crd];

        // 해당 좌표의 값이 플레이어라면
        if ('a' <= c && c <= 'z') {
            // 플레이어의 좌표를 q에 push한 뒤
            q[id(c)].push(crd);
            // visit에 플레이어의 초기 좌표를 표시
            visit[crd] = bit(id(field[i][j]));
        }
        // 해당 좌표의 값이 보스라면 보스가 있는 곳의 좌표를 갱신
        else if (c == 'B') boss = crd;
    }

    // 보스의 체력이 남아있는 동안 각 플레이어에 대해
    while (HP > 0) for (int i = 0; i < MAX_P; i++) {
        // 플레이어가 보스가 있는 곳에 도착했을 때
        if (visit[boss] & bit(i)) {
            // 보스의 체력을 현재 플레이어의 dps만큼 줄인 뒤
            HP -= dps[i];
            // 현재 플레이어가 가한 데미지를 dps만큼 늘린다
            dmg[i] += dps[i];
        }
        // 그렇지 않다면 플레이어가 있을 수 있는 모든 좌표에 대해
        else for (int _ = q[i].size(); _--;) {
            // 현재 좌표를 crd에 저장하고
            crd = q[i].front();
            q[i].pop();

            // crd에서 상하좌우 네 방향으로 한 칸씩 이동한 위치에 대해
            // 해당 칸이 지도 내의 위치이고 이동한 적 없는 공간일 때
            for (auto a : add) if (valid(crd + a) && !(visit[crd + a] & bit(i))) {
                // 해당 칸을 q에 push하고
                q[i].push(crd + a);
                // 플레이어가 해당 위치로 이동했다고 간주
                visit[crd + a] |= bit(i);
            }
        }
    }
    // 보스가 사망했을 때 보스에게 데미지를 준 플레이어의 수를 계산해 출력
    for (int i = 0; i < MAX_P; i++) ans += (dmg[i] > 0);
    cout << ans << '\n';

    return 0;
}
