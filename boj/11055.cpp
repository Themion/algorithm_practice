#include <cstdio>

#define MAX_N 1000

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // sum[i]: i에서 끝나는 가장 큰 증가 부분 수열, ans: 각 부분 수열의 합의 최댓값
    int sum[MAX_N] = { 0, }, ans = 0;
    // N: 수열의 길이, A: 수열의 각 성분
    short N, A[MAX_N] = { 0, };

    // 수열의 크기를 입력받은 뒤 수열의 각 성분에 대해
    scanf("%hd", &N);
    for (int i = 0; i < N; i++) {
        // 수열의 i번째 성분을 입력받은 뒤
        scanf("%hd", A + i);
        // i에서 끝나는 부분 수열에는 { A[i] } 또한 포함하므로
        // sum[i]에 A[i]를 넣어 최솟값을 설정
        sum[i] = A[i];
        
        // j < i이고 A[j] < A[i]인 j에서 끝나는 증가 부분 수열 중 가장 큰 부분 수열에
        // A[i]를 추가해 i번째 성분에서 끝나는 가장 큰 부분 수열을 만든다
        for (int j = 0; j < i; j++) if (A[j] < A[i])
            sum[i] = max(sum[i], sum[j] + (int)A[i]);

        // 부분 수열의 합의 최댓값을 ans에 저장
        ans = max(ans, sum[i]);
    }

    // ans를 출력한다
    printf("%d\n", ans);

    return 0;
}
