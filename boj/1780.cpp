#include <cstdio>

#define MAX_N 2187

// 출력할 각 종이의 수
int list[3];
// 입력받은 종이
__int8_t paper[MAX_N][MAX_N];

__int8_t check(int y, int x, int len) {
    // 모든 조각이 같은 종이를 쓰는지 확인
    bool is_same = true;
    // 아홉 조각으로 나누었을 때 각 조각이 어떤 종이를 쓰는지 저장
    __int8_t chk = paper[y][x];

    // 확인하고자 하는게 1*1짜리 종이라면 해당 종이의 색을 반환
    if (!len) return paper[y][x];

    // 종이의 각 조각 종류를 알아낸 뒤 모든 조각이 같은 조각인지 계산
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) 
        is_same &= (chk == check(y + len * i, x + len * j, len / 3));

    // 모든 조각이 같은 조각이라면 사용한 종이의 개수를 8 뺀다
    if (is_same) {
        list[chk + 1] -= 8;
        return chk;
    }
    // 아니라면 아무 연산도 하지 않고 이 조각이 누더기임을 알린다
    else return 2;
}

int main() {
    // 종이의 크기
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++){
        scanf("%hhd", &paper[i][j]);
        list[paper[i][j] + 1]++;
    }

    // 종이에 쓰인 조각의 개수를 계산한다
    check(0, 0, N / 3);

    // 종이 조각의 수를 출력한다
    for (auto i : list) printf("%d\n", i);

    return 0;
}
