#include <cstdio>

int main() {
    // 출력할 별의 최다 개수를 입력
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        // i번째 줄에 대해 N - i만큼 미리 간격을 띄운다
        for (int j = i; j < N; j++) printf(" ");
        printf("*");
        // i - 1회만큼 ' *'를 출력한다
        for (int j = 1; j < i; j++) printf(" *");
        printf("\n");
    }

    return 0;
}
