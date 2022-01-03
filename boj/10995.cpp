#include <cstdio>

int main() {
    int N;

    // 도형의 높이를 입력받은 뒤
    scanf("%d", &N);
    // 각 줄마다 줄 번호에 따라 "* " 혹은 " *"을 N번씩 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%s", (i % 2) ? " *" : "* ");
        printf("\n");
    }

    return 0;
}
