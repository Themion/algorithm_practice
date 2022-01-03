#include <cstdio>

int main() {
    int N;

    // 도형의 높이를 입력받은 뒤
    scanf("%d", &N);
    // '*'과 ' '을 번갈아 출력
    for (int i = 0; i < N * 2; i++) {
        for (int j = 0; j < N; j++) printf("%c", ((i + j) % 2) ? ' ' : '*');
        // 문자를 N개 출력할 때마다 줄바꿈을 출력
        printf("\n");
    }

    return 0;
}
