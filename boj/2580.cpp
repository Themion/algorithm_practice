#include <cstdio>

// row[i][j]: i번째 행에 j가 들어있다면 true, 아니라면 false
// col[i][j]: i번째 열에 j가 들어있다면 true, 아니라면 false
// blk[i][j][k]: [i][j]번째 3*3짜리 블록에 k가 들어있다면 true, 아니라면 false
bool row[9][10], col[9][10], blk[3][3][10];
// 스도쿠 판을 저장할 공간
int sudoku[9][9];

bool valid(int y, int x, int i) {
    return !row[y][i] && !col[x][i] && !blk[y / 3][x / 3][i];
}

//칸 (x, y)에 val을 넣거나 빼고 이를 표시
void set(int x, int y, int val, bool b_set) {
    sudoku[x][y] = b_set ? val : 0;
    row[x][val] = col[y][val] = blk[x / 3][y / 3][val] = b_set;
}

bool fill(int idx) {
    // 모든 값에 가능한 값이 들어갔다면 true를 반환한다
    if (idx == 81) return true;
    // 현재 확인한 칸에 값이 이미 있다면 다음 칸으로 넘어간다
    else if (sudoku[idx / 9][idx % 9] != 0) return fill(idx + 1);

    // x, y: 현재 칸의 좌표
    int y = idx / 9, x = idx % 9;

    // 칸 (x, y)의 가능한 모든 값 i에 대해
    for (int i = 1; i <= 9; i++ ) if (valid(y, x, i)) {
        // i를 해당 칸에 넣은 뒤 이를 표시하고
        set(y, x, i, true);
        // 해당 경우가 답이 될 수 있다면 true를 반환한다
        if (fill(idx + 1)) return true;
        // 그렇지 않다면 i를 제거한 뒤 이를 표시한다
        else set(y, x, i, false);
    }

    // 가능한 경우가 하나도 없다면 false를 반환한다
    return false;
}

int main() {
    // flag: 입력된 경우가 가능하다면 true, 아니라면 false
    bool flag = true;
    // buf: 입력에 사용할 공간
    int buf;

    // 스도쿠의 각 칸에 대해
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
        // 해당 칸의 값을 입력한 뒤
        scanf("%d", &buf);
        // 해당 값이 스도쿠의 규칙에 어긋나는 값이라면 false를 반환
        if (!valid(i, j, buf)) flag = false;
        // 그렇지 않다면 현재 칸이 해당된 행, 열, 블록에 val이 등장했음을 표시한다
        else if (buf) set(i, j, buf, true);
    }

    // 만일 주어진 스도쿠 판에 맞게 모든 값을 입력했다면
    // 스도쿠 판을 양식에 맞게 출력한다
    if (flag && fill(0)) for (int i = 0; i < 9; i++)  for (int j = 0; j < 9; j++)
        printf("%d%c", sudoku[i][j], (i < 8 ? ' ' : '\n'));
    // 그렇지 않다면 -1을 출력한다
    else printf("-1\n");

    return 0;
}
