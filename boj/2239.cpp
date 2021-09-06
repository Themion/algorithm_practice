#include <cstdio>

// row[][i], col[][i], blk[][][i]: 
//      주어진 인덱스로 참조하는 행, 열, 3*3에 i가 있다면 true, 아니라면 false 
bool row[9][10], col[9][10], blk[3][3][10];
// 스도쿠를 플레이하는 판
int sudoku[9][9];

// set(y, x, val, b_set): 좌표 (y, x)에 val값을 b_set이라면 설정, 아니라면 제거
void set(int y, int x, int val, bool b_set)
{
    if (!val) return;
    
    sudoku[y][x] = b_set ? val : 0;
	row[y][val] = b_set;
	col[x][val] = b_set;
	blk[y / 3][x / 3][val] = b_set;
}

// 백트래킹을 이용해 주어진 인덱스에서 맞는 값을 할당
bool backtrack(int idx)
{
    // 모든 값에 할당을 성공했다면 true를 반환
    if (idx >= 81) return true;
    // 현재 인덱스에 이미 값이 있다면 다음 값을 할당
    else if (sudoku[idx / 9][idx % 9]) return backtrack(idx + 1);

    // 1차원 좌표 idx를 2차원 좌표 (y, x)로 변경
    int y = idx / 9, x = idx % 9;
    
    // 1부터 9 중 할당 가능한 값이 있다면
    for (int i = 1; i <= 9; i++) 
        if (!row[y][i] && !col[x][i] && !blk[y / 3][x / 3][i])
        {
            // 해당 값을 할당한 뒤
			set(y, x, i, true);
            // 그 값을 포함한 경우가 정답이라면 true를 반환
			if (backtrack(idx + 1)) return true;
            // 아니라면 해당 값을 제거
			else set(y, x, i, false);
        }
    
    // 할당에 실패했으므로 false를 반환
    return false;
}

int main()
{
    // 한 글자씩 입력받아 배열에 입력한다
    char buf;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%c", &buf);
            set(i, j, buf - '0', true);
        }
        scanf("%*c");
    }

    // 맨 처음 값부터 차례로 할당
    backtrack(0);

    // 반드시 할당에 성공하는 경우만 주어지므로 정답을 출력
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) printf("%d", sudoku[i][j]);
        printf("\n");
    }

    return 0;
}