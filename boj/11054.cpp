#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 1000

// S: 부분 수열을 구할 수열, lis: 가장 긴 부분 증가/감소 수열
// len[i]: S[i]에서 끝나는 증가/부분 수열의 길이
short S[MAX_N], lis[MAX_N], len[MAX_N][2];

int max(int a, int b) { return a > b ? a : b; }

// i 직전 성분까지 가장 긴 (b ? 감소 : 증가) 부분 수열을 구했을 때
// i번 성분을 추가하여 lis를 갱신
void LIS(int i, bool b) {
    // 직전 성분까지의 길이를 가져온 뒤
    len[i][b] = len[b ? i + 1 : i - 1][b];
    // S[i]가 lis의 마지막 값보다 크다면 lis의 맨 뒤에 S[i]를 추가
    // 그렇지 않다면 lis에서 S[i]보다 작은 값 중 가장 큰 값을 S[i]로 변경
    if (lis[len[i][b] - 1] < S[i]) lis[len[i][b]++] = S[i];
    else *lower_bound(lis, lis + len[i][b], S[i]) = S[i];
}

int main() {
    // N: 수열의 길이, ans: 바이토닉 수열의 길이
    short N, ans = 0;

    // 수열의 길이와 각 수열의 성분을 입력받은 뒤
    scanf("%hd", &N);
    for (int i = 0; i < N; i++) scanf("%hd", S + i);

    // 부분 수열의 첫 길이를 1로 초기화
    len[0][0] = len[N - 1][1] = 1;

    // 증가하는 부분 수열을 { S[0] }으로 초기화
    lis[0] = S[0];
    // 1번째 성분부터 모든 성분에 대해 LIS 진행
    for (int i = 1; i < N; i++) LIS(i, 0);

    // lis를 초기화한 뒤 증가하는 부분 수열을 { S[N - 1] }으로 초기화
    fill_n(lis, N, 0);
    lis[0] = S[N - 1];
    // N - 2번째 성분부터 모든 성분에 대해 역순으로 LIS 진행
    for (int i = N - 2; i >= 0; i--) LIS(i, 1);
    
    // i에서 끝나는 부분 증가 수열과 i에서 시작하는 부분 감소 수열의
    // 길이의 합의 최댓값을 ans에 저장
    for (int i = 0; i < N; i++) ans = max(ans, len[i][0] + len[i][1]);

    // 두 부분 수열이 S[i]를 공통으로 포함하므로 ans - 1을 반환
    printf("%hd\n", ans - 1);

    return 0;
}
