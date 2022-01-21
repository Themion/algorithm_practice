#include <cstdio>

int main() {
    // 동혁이 이긴다면 true, 백준이 이긴다면 false
    bool i;
    // n: 곱셈으로 만들 수, p: 최적의 플레이로 계산한 수
    unsigned int n, p, mul[2] = { 9, 2 };
    // n을 입력받은 뒤 숫자가 입력됐다면 1부터
    while ((p = scanf("%d", &n)) != EOF) {
        // k에 9와 2를 번갈아서 곱하면서 마지막으로 곱한 수가 9인지 2인지를 i에 저장
        for (i = false; (p *= mul[i]) < n; i = !i);
        // 마지막으로 곱한 수가 9라면 백준이, 2라면 동혁이 이긴다
        printf("%s wins.\n", i ? "Donghyuk" : "Baekjoon");
    }

    return 0;
}
