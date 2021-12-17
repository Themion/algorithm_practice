#include <cstdio>

int main() {
    // 출력할 별의 최다 개수를 입력
    int N;

    scanf("%d", &N);
    // N개의 별을 N줄 출력한다
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("*");
        printf("\n");
    }

    return 0;
}
