#include <cstdio>

int main() {
    //출력에 사용할 수를 입력받는다
    int N;

    scanf("%d", &N);
    //각 줄마다
    for (int i = 0; i < N; i++) {
        // 줄 넘버만큼 별을 출력
        for (int j = 0; j <= i; j++) printf("*");
        printf("\n");
    }

    return 0;
}
