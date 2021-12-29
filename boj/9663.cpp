#include <cstdio>

#define MAX_N 15

// col[i]: i열에 퀸이 있다면 true, 아니라면 false
// yx[i]: y = x꼴 대각선에 대해 판정
//        x축, y축 인덱스의 합이 i인 퀸이 있다면 true
// y_x[i]: y = -x꼴 대각선에 대해 판정
//         좌표의 x값을 반전시킨 뒤
//         x축, y축 인덱스의 합이 i인 퀸이 있다면 true
bool col[MAX_N], yx[2 * MAX_N - 1], y_x[2 * MAX_N - 1];
// 조건에 맞게 퀸을 놓는 경우의 수
int ans = 0;
// 체스판의 한 변의 길이
short n;

int abs(int a, int b) { return (a > b ? a - b : b - a); }

// y행 x열에 퀸을 놓을 수 있다면 true, 아니라면 false
bool check(int y, int x) {
    return !col[x] && !yx[x + y] && !y_x[y + (n - 1 - x)];
}

// 퀸을 y개 놓았을 때 가능한 퀸의 배치를 계산한다
void set(int y) {
    // 퀸을 n개 모두 놓았다면 가능한 경우의 수를 하나 늘린다
    if (y == n) ans++;
    // 그렇지 않다면 y번째 행에서 퀸을 놓을 수 있는 모든 경우에 대해
    else for (int x = 0; x < n; x++) if (check(y, x)) {
        // 퀸을 놓은 뒤
        col[x] = yx[y + x] = y_x[y + (n - 1 - x)] = true;
        // 이 이후 퀸을 놓을 수 있는 경우를 세고
        set(y + 1);
        // 놓은 퀸을 제거
        col[x] = yx[y + x] = y_x[y + (n - 1 - x)] = false;
    }
    return;
}

int main() {
    // 체스판의 크기를 입력받은 뒤
    scanf("%hd", &n);

    // 배치 가능한 퀸의 수를 세어 출력한다
    set(0);
    printf("%d\n", ans);

    return 0;
}
