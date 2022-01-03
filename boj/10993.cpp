#include <cstdio>

#define MAX_HEIGHT 1 << 10 - 1

// 출력할 프랙탈을 저장할 공간
bool pattern[MAX_HEIGHT][2 * MAX_HEIGHT - 1];

int main() {
    // N: 프랙탈 횟수
    // height, width: 배열에서 실제로 쓰일 높이와 너비
    // h, w, x, y: 배열에 그릴 삼각형의 높이, 너비와 왼쪽 꼭지점의 좌표
    int N, height = 1, width = 1, h, w, y = 0, x = 0;
    scanf("%d", &N);

    // 입력받은 프랙탈 횟수에 맞춰 프랙탈 도형의 높이와 너비를 정한다
    for (int i = 1; i < N; i++) height = 2 * height + 1;
    width = (2 * height) - 1;

    // 처음에 그릴 삼각형이 정삼각형인지 역삼각형인지에 따라
    // 왼쪽 꼭지점의 y좌표가 달라진다
    if (N % 2) y = height - 1;
    // 처음에 그릴 삼각형의 높이는 height이다
    h = height;

    for (int k = N; k > 0; k--) {
        // 삼각형의 밑변의 길이는 높이 * 2에 1을 뺀 값이고
        // 배열의 크기가 n일 때 최대 인덱스는 n - 1이므로
        // 편의상 width에 1을 더 빼준다
        w = 2 * h - 2;

        // 각 높이 좌표 부분에 대해
        for (int i = 0; i < h; i++) {
            // 윗변 부분에 선을 그어준다
            pattern[y][x + i] =  pattern[y][x + w - i] = true;

            // k가 홀수일 때는 정삼각형을, 짝수일 때는 역삼각형을 그린다
            pattern[y + (k % 2 ? -i : i)][x + i] = true;
            pattern[y + (k % 2 ? -i : i)][x + w - i] = true;
        }

        // 이 다음에 그릴 삼각형에 맞춰 x, y, h값을 바꾼다
        // k가 홀수일 때는 다음번에 역삼각형을, 짝수일 때는 정삼각형을 그린다
        x += w / 4 + 1;
        h /= 2;
        y += (k % 2 ? -h : h);
    }

    //  프랙탈을 완성했다면 프랙탈을 출력한다
    for (int i = 0; i < height; i++) {
        // 백준 문제에선 추가적인 공백 출력을 금지했으므로
        // for문에서 잉여 공백을 걸러낼 때 w를 이용한다
        w = (N % 2) ? (width + 1) / 2 + i : width - i;

        for (int j = 0; j < w; j++) printf("%c", pattern[i][j] ? '*' : ' ');
        printf("\n");
    }

    return 0;
}
