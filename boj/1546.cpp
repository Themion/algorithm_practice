#include <cstdio>

int main() {
    // 답을 출력할 때 쓸 변수
    double ans = 0;
    // input: 입력받은 점수를 저장할 공간, N: 입력받을 점수의 수, M: 점수의 최댓값
    int input, N, M = 0;

    scanf("%d", &N);

    // 각 점수를 입력받은 뒤 ans에 더하고 가장 큰 점수를 M에 저장
    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        ans += input;
        if (M < input) M = input;
    }

    // ans에 100을 곱한 뒤 (M * N)만큼 나누어 새로운 평균을 출력한다
    printf("%f\n", ans * 100 / (M * N));

    return 0;
}
