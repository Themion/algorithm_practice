#include <cstdio>

#define MAX_N 1000

double test_case() {
    // score[i]: i번째 학생의 점수
    char score[MAX_N];
    // mean: 점수의 평균, ans: 평균을 넘는 학생의 비율
    double mean = 0, ans = 0;
    // 학생의 수
    int N;

    scanf("%d", &N);

    // 각 학생의 점수를 입력받은 뒤 mean에 그 합을 저장
    for (int i = 0; i < N; i++) {
        scanf("%hhd", score + i);
        mean += score[i];
    }

    // 점수의 평균을 구한 뒤 평균을 넘는 학생의 수를 ans에 저장
    mean /= N;
    for (int i = 0; i < N; i++) ans += score[i] > mean;

    // 구한 학생의 수를 퍼센티지로 변환해 반환
    return ans * 100.0 / (double)N;
}

int main() {
    int C;

    // 테스트 케이스의 수를 입력받아 각 테스트 케이스를 실행
    scanf("%d", &C);
    while (C--) printf("%.3f%%\n", test_case());

    return 0;
}
