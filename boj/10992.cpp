#include <cstdio>

int main() {
    // 출력할 별의 최다 개수를 입력
    int N;
    scanf("%d", &N);

    // 별을 ㅅ 모양으로 출력한다
    for (int i = 1; i < N; i++) {
        // i번째 줄에 대해 N - i만큼 미리 간격을 띄운 뒤
        for (int j = i; j < N; j++) printf(" ");
        // 0번째 줄, 즉 꼭지점이 아니라면 왼쪽 변을 출력
        if (i > 1) printf("*");
        // i번째 줄에서 두 변의 간격은 2i - 1이므로 그만큼 공백을 출력
        for (int j = 3; j < 2 * i; j++) printf(" ");
        // 오른쪽 변을 출력하고 줄바꿈
        printf("*\n");
    }

    // 아랫변을 출력한 뒤 개행 문자를 출력해 출력을 종료
    for (int i = 1; i < 2 * N; i++) printf("*");
    printf("\n");

    return 0;
}
