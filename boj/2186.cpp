#include <cstdio>
#include <string>

#define MAX_N 100
#define MAX_LEN 80

// map: 주어진 문자판을 저장할 공간, str: 문자판에서 찾고자 하는 문자열
char map[MAX_N][MAX_N], str[MAX_LEN + 1];
// N, M, K: 문자판의 크기와 점프 가능한 최대 칸 수
// len: 문자열의 길이, ans: 출력할 정답
// mem[y][x][cnt]: 좌표 (x, y)에서 입력받은 문자열의 뒤 cnt 길이만큼을 만드는 경우의 수
int N, M, K, len = 0, ans = 0, mem[MAX_N][MAX_N][MAX_LEN];
// 이동할 방향
int add[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// map[y][x]에서 시작하여
// str[cnt]부터 시작하는 부분 문자열을 만들 수 있는 경우의 수
int search(int y, int x, int cnt) {
    // mem[y][x][cnt]에 저장할 값을 계산할 변수
    int ret = mem[y][x][cnt];

    // 아직 해당하는 경우가 나오지 않았다면
    if (ret == -1) {
        // 경우의 수를 0으로 초기화한 뒤
        ret = 0;

        // 애초에 부분 문자열을 만들 수 없는 경우를 날리고
        if (map[y][x] != str[cnt]);
        // str을 모두 만들었다면 경우의 수는 1로 고정
        else if (cnt == len - 1) ret = 1;
        // 아직 만들어야 할 문자열이 남았다면
        else for (int i = 0; i < 4; i++) for (int j = 1; j <= K; j++) {
            // 현재 칸에서 이동 가능한 각 칸에 대해
            int y_ = y + (j * add[i][0]), x_ = x + (j * add[i][1]);
            if (y_ >= N || y_ < 0 || x_ >= M || x_ < 0) continue;
            // 해당 칸에서의 경우의 수를 ret에 저장한 뒤
            ret += search(y_, x_, cnt + 1);
        }

        // 구한 경우의 수를 mem에 저장한다
        mem[y][x][cnt] = ret;
    }

    // 경우의 수를 반환한다
    return ret;
}

int main() {
    // N, M, K를 각각 입력받고
    scanf("%d %d %d", &N, &M, &K);
    // 문자판을 입력받는다
    for (int i = 0; i < N; i++) {
        scanf("\n");
        for (int j = 0; j < M; j++) {
            scanf("%c", &map[i][j]);
            for (int k = 0; k < MAX_LEN; k++) mem[i][j][k] = -1;
        }
    }
    // 찾고자 하는 문자열을 입력받은 뒤 문자열의 길이를 구한다
    scanf("%s", str);
    for (len = 0; str[len]; len++);

    // 문자판의 각 지점에 대해 해당 지점에서 시작하는 경우의 수를 구한다
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) 
        ans += search(i, j, 0);

    // 문자열을 만들 수 있는 경우의 수를 출력한다
    printf("%d\n", ans);

    return 0;
}
