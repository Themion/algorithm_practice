#include <cstdio>

int main() {
    // 출력에 사용할 수를 입력받는다
    int N;

    scanf("%d", &N);
    // 각 줄마다 별을 하나부터 N까지 출력
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) printf("*");
        printf("\n");
    }

    // 각 줄마다 별을 N - 1부터 하나까지 출력
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) printf("*");
        printf("\n");
    }

    return 0;
}
