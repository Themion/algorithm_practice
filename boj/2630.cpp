#include <cstdio>

#define MAX_N 128

bool paper[MAX_N][MAX_N] = {{ false, }};
int ans[2] = {0, 0};

// 색종이 분할정복
bool dnc(int y, int x, int size) {
    // 검사하고자 하는 색종이의 크기가 1이라면
    if (size == 1)  {
        // 해당 색종이 수를 1만큼 늘리고
        ans[paper[y][x]] += 1;
        // 반드시 한 종류의 색종이만 사용하므로 true를 반환
        return true;
    }

    bool ret = true; // ret: 현재 색종이가 단색일 때만 true
    int y_, x_;      // y_, x_: 좌표를 미리 계산한 다음 사용한다

    size /= 2;       // 색종이를 네개로 나누므로 size로 절반씩 감소

    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
        // 네 조각의 왼쪽 위 귀퉁이의 좌표를 계산한 뒤
        y_ = y + i * size;
        x_ = x + j * size;
        // 네 조각이 단색인지, 또 네 조각의 색이 서로 같은지 확인
        ret &= dnc(y_, x_, size) && paper[y][x] == paper[y_][x_];
    }

    // 위의 이중 for문 결과 단색이라면 네 조각을 하나로 계산
    if (ret) ans[paper[y][x]] -= 3;

    // 이 조각이 단색인지 여부를 반환
    return ret;
}

int main() {
    int N, buf;
    scanf("%d", &N);
    // 입력값 0, 1은 bool로 형변환 시 false, true로 변환
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        scanf("%d", &(paper[i][j]));

    // 입력받은 색종이의 조합을 분할 정복으로 계산
    dnc(0, 0, N);

    // 사용된 흰 종이, 파란 종이의 수를 출력
    printf("%d\n%d\n", ans[0], ans[1]);

    return 0;
}
