#include <cstdio>

int min(int a, int b) { return a < b ? a : b; }

int main(){
    // N: 문제의 개수, L: 역량, K: 풀 수 있는 문제 수
    // sub1: 쉬운 문제의 난이도, sub2: 어려운 문제의 난이도, ans: 총점
    int N, L, K, sub1, sub2, ans = 0;
    // solve[i]: { 못 푼 문제, 쉬운 문제, 어려운 문제 }[i]를 푼 개수
    // score[i]: { 못 푼 문제, 쉬운 문제, 어려운 문제 }[i]의 점수
    short solve[3] = { 0, }, score[3] = { 0, 100, 140 };

    // 문제의 조건을 입력받으면서 각 문제에 대해
    for (scanf(" %d %d %d", &N, &L, &K); N--; ) {
        // 각 문제를 역량별로 분류해 문제수를 저장
        scanf("%d %d", &sub1, &sub2);
        solve[(sub2 <= L) + (sub1 <= L)]++;
    }

    // 각 분류에 대해 얻는 점수가 큰 순으로 문제를 푼다
    for (int i = 2; i; i--) {
        L = min(K, solve[i]);
        ans += L * score[i];
        K -= L;
    }

    // 문제를 풀어서 얻은 총점을 출력
    printf("%d\n", ans);

    return 0;
}
