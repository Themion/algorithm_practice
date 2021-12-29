#include <cstdio>

int main() {
    // score: 각 학생의 점수, ans: 점수의 합
    int score, ans = 0;

    // 점수를 다섯번 입력받아 각 점수와 40 중 더 큰 값을 ans에 더한다
    for (int i = 0; i < 5; i++) {
        scanf("%d", &score);
        ans += (score > 40) ? score : 40;
    }

    // ans를 5로 나눠 얻은 점수의 평균을 출력
    printf("%d\n", ans / 5);

    return 0;
}
