#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 100
#define FOR(i) for (i = 1; i <= N; i++)

void set_min(short &a, short b) { a = a < b ? a : b; }

int main() {
    // N: 인물의 수, M: 관계의 수, A, B: 그래프를 입력받을 두 노드
    // i, j, k: for문에 사용될 인덱스 변수
    // sum: 각 인물의 관계 단계수의 합, min: 관계 단계수의 합의 최솟값
    // ans: 관계 단계수의 합이 최소인 사람
    int N, M, A, B, i, j, k, sum, min = MAX_N * MAX_N, ans = -1;
    // graph[i][j]: i와 j의 관계 단계
    short graph[MAX_N + 1][MAX_N + 1];

    // 서로 모르는 사람의 관계 단계를 충분히 큰 값으로 설정
    for (int i = 1; i <= MAX_N; i++) fill_n(graph[i], MAX_N + 1, MAX_N);
    
    // 문제 조건을 입력
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d %d", &A, &B);
        // 인물의 관계를 희소행렬 꼴로 저장
        graph[A][B] = graph[B][A] = 1;
    }

    // 플로이드-와샬 공식 사용
    FOR(k) FOR(i) FOR(j)
        set_min(graph[i][j], graph[i][k] + graph[k][j]);

    // 각 인물에 대해
    FOR(i) {
        // 관계 단계수의 합을 계산한 뒤
        sum = 0;
        FOR(j) sum += graph[i][j];
        // 관계 단계수의 합이 가장 적은 사람을 갱신
        if (min > sum) {
            min = sum;
            ans = i;
        }
    }

    // 관계 단계수의 합이 가장 적은 사람을 출력
    printf("%d\n", ans);

    return 0;
}
