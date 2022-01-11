#include <iostream>

using namespace std;

#define MAX_N 500

int N, M;
short t[MAX_N + 1][MAX_N + 1];

// cmp3의 이름이 max일 때 ‘__comp’ cannot be used as a function 에러 발생
int cmp2(int a, int b) { return a > b ? a : b; }
int cmp3(int a, int b, int c) { return cmp2(cmp2(a, b), c); }

short search(int y, int x) {
    // ret: 실제로 비교할 테트로미노의 총합, temp: 계산식 길이를 줄이기 위한 변수
    short ret = 0, temp;

    // 세로 |자 비교
    if (y + 3 <= N)
        ret = cmp2(ret, t[y][x] + t[y + 1][x] + t[y + 2][x] + t[y + 3][x]);
    if (y + 2 <= N) {
        // 한 칸 짜리가 왼쪽에 있는 세로 L, T자 비교
        // 한 칸 짜리의 최댓값을 temp에 저장한 뒤 세 칸 짜리와 더해 비교
        temp = cmp3(t[y][x - 1], t[y + 1][x - 1], t[y + 2][x - 1]);
        ret = cmp2(ret, t[y][x] + t[y + 1][x] + t[y + 2][x] + temp);

        // 한 칸 짜리가 오른쪽에 있는 세로 L, T자 비교
        // 한 칸 짜리의 최댓값을 temp에 저장한 뒤 세 칸 짜리와 더해 비교
        temp = cmp3(t[y][x], t[y + 1][x], t[y + 2][x]);
        ret = cmp2(ret, t[y][x - 1] + t[y + 1][x - 1] + t[y + 2][x - 1] + temp);

        // 세로 S자, O자 비교
        // 세 경우에 포함되지 않는 끄트머리 두 칸끼리 비교해 더한 뒤
        // 반드시 포함되는 가운데 두 칸과 더한 값을 비교
        temp = cmp2(t[y][x], t[y + 2][x]) + cmp2(t[y][x - 1], t[y + 2][x - 1]);
        ret = cmp2(ret, t[y + 1][x] + t[y + 1][x - 1] + temp);
    }

    // 가로 |자 비교
    if (x + 3 <= M)
        ret = cmp2(ret, t[y][x] + t[y][x + 1] + t[y][x + 2] + t[y][x + 3]);
    if (x + 2 <= M) {
        // 한 칸 짜리가 위쪽에 있는 가로 L, T자 비교
        // 한 칸 짜리의 최댓값을 temp에 저장한 뒤 세 칸 짜리와 더해 비교
        temp = cmp3(t[y - 1][x], t[y - 1][x + 1], t[y - 1][x + 2]);
        ret = cmp2(ret, t[y][x] + t[y][x + 1] + t[y][x + 2] + temp);

        // 한 칸 짜리가 아래쪽에 있는 가로 L, T자 비교
        // 한 칸 짜리의 최댓값을 temp에 저장한 뒤 세 칸 짜리와 더해 비교
        temp = cmp3(t[y][x], t[y][x + 1], t[y][x + 2]);
        ret = cmp2(ret, t[y - 1][x] + t[y - 1][x + 1] + t[y - 1][x + 2] + temp);

        // 가로 S자, O자 비교
        // 세 경우에 포함되지 않는 끄트머리 두 칸끼리 비교해 더한 뒤
        // 반드시 포함되는 가운데 두 칸과 더한 값을 비교
        temp = cmp2(t[y][x], t[y][x + 2]) + cmp2(t[y - 1][x], t[y - 1][x + 2]);
        ret = cmp2(ret, t[y][x + 1] + t[y - 1][x + 1] + temp);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값
    short ans = 0;

    // 문제의 조건을 입력받은 뒤
    cin >> N >> M;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> t[i][j];

    // 칸 (i, j)를 포함하도록 놓인 테트로미노가 놓인 칸의 수의 합을 계산
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
        ans = cmp2(ans, search(i, j));

    // 계산한 합의 최댓값을 출력
    cout << ans << '\n';

    return 0;
}
