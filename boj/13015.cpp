#include <cstdio>

int main() {
    // N: 입력받을 수, space: x자에서 각 대각선 사이의 거리
    int N, space;
    scanf("%d", &N);

    // 사용의 편의를 위해 N에 1을 빼준다
    N -= 1;
    // space의 초기값을 설정해준다
    space = 2 * N - 1;

    for (int i = 0; i < N; i++) {
        // x의 왼쪽 위 부분
        // 왼쪽 선을 i칸 띄운 뒤 그리고, N - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
        // 이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 1; j < N; j++) printf("%c", i ? ' ' : '*');
        printf("*");

        // x의 위쪽 공백 부분
        // space만큼 띄워준다
        for (int j = 0; j < space; j++) printf(" ");

        // x의 오른쪽 위 부분
        // 왼쪽 선을 그리고, N - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
        // 이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
        printf("*");
        for (int j = 1; j < N; j++) printf("%c", i ? ' ' : '*');
        printf("*\n");

        // x의 위쪽 공백이 점점 줄어드므로 space를 줄어든 만큼 빼준다
        space -= 2;
    }

    // x의 한가운데 부분
    // 우선 N만큼 공백을 준다
    for (int i = 0; i < N; i++) printf(" ");

    // 왼쪽 꼭지점을 그린 뒤 N - 1칸만큼 띄우고
    // 한가운데 있는 점을 찍어준다
    // 그 후 N - 1칸만큼 띄우고 오른쪽 꼭지점을 그린다
    printf("*");
    for (int i = 1; i < N; i++) printf(" ");
    printf("*");
    for (int i = 1; i < N; i++) printf(" ");
    printf("*\n");

    for (int i = N - 1; i >= 0; i--) {
        // x의 위쪽 공백이 점점 늘어나므로 space를 늘어난 만큼 더해준다
        space += 2;

        // x의 왼쪽 아래 부분
        // 왼쪽 선을 i칸 띄운 뒤 그리고, N - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
        // 이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 1; j < N; j++) printf("%c", i ? ' ' : '*');
        printf("*");


        // x의 아래쪽 공백 부분
        // space만큼 띄워준다
        for (int j = 0; j < space; j++) printf(" ");

        // x의 오른쪽 아래 부분
        // 왼쪽 선을 그리고, N - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
        // 이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
        printf("*");
        for (int j = 1; j < N; j++) printf("%c", i ? ' ' : '*');
        printf("*\n");
    }

    return 0;
}
