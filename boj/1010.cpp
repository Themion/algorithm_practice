#include <cstdio>

#define MAX_N 30
#define FOR(i, a, b) for(i = a; i < b; i++)

// tri[N][K]: 파스칼의 삼각형을 이용해 NCK를 계산
int tri[MAX_N + 1][MAX_N + 1];

int main() {
    // T: 테스트 케이스의 수
    // N, M: 각각 서쪽, 동쪽의 사이트의 개수
    int T, N, M, n, k;
    
    FOR(n, 0, MAX_N) {
        // 이전 값을 탐색할 수 없는 nC0은 하드 코딩으로 초기화
        tri[n][0] = 1;
        // nCk = (n - 1)C(k - 1) + (N - 1)Ck
        FOR(k, 1, n) tri[n][k] = tri[n - 1][k - 1] + tri[n - 1][k];
    }

    scanf("%d", &T);
    while(T--) {
        //컴비네이션을 구할 N과 M을 입력받은 뒤
        scanf("%d %d", &N, &M);
        //해당 테스트 케이스의 컴비네이선을 출력한다
        printf("%d\n", tri[M][N]);
    }

    return 0;
}