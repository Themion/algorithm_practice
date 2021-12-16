#include <cstdio>

#define MAX_N 100
#define MAX_LEN 15
#define MOD 100

// 조합의 결과를 저장
bool visit[MAX_N + 1][MAX_N + 1];
char C[MAX_N + 1][MAX_N + 1][MAX_LEN];

// 매우 긴 두 수를 string 형태로 저장해 더한다
void set(char c[MAX_LEN], char a[MAX_N], char b[MAX_N]) {
    // 두 성분을 더했을 때 발생한 carry
    bool carry;
    // 두 수의 각 성분을 더한 값
    int add_ = 0;

    // 두 수의 각 자리를 더해 그 결과를 ret에 차례로 저장
    for (int i = MAX_LEN - 1; i >= 0; i--) {
        add_ = a[i] + b[i] + carry;
        c[i] = add_ % MOD;
        carry = add_ / MOD;
    }
}

char* get_C(int n, int r) {
    // 조합의 특성상 nCr은 nC(n-r)와 같다
    if (r > n - r) return get_C(n, n - r);

    // nCr을 아직 구하지 않았다면
    if (!visit[n][r]) {
        // nC0은 항상 1
        if (r == 0) C[n][r][MAX_LEN - 1] = 1;
        // nCr = (n-1)C(r-1) + (n-1)Cr
        else set(C[n][r], get_C(n - 1, r - 1), get_C(n - 1, r));

        // nCr을 구했음을 표시
        visit[n][r] = true;
    }

    // nCr을 구했으므로 재귀를 위해 nCr의 좌표를 반환
    return C[n][r];
}

int main() {
    int n, m, idx = 0;
    scanf("%d %d", &n, &m);

    // 조합의 특성상 nCr은 nC(n-r)와 같다
    get_C(n, m = (m < n - m) ? m : n - m);

    // 배열의 빈 공간은 건너뛴 다음
    for (; !C[n][m][idx]; idx++);
    // 첫 자리는 빈 공간을 공백을 넣어 출력하고
    printf("%hhd", C[n][m][idx++]);
    // 나머지 자리는 빈 공간을 0을 넣어 출력
    for (; idx < MAX_LEN; idx++) printf("%02hhd", C[n][m][idx]);
    printf("\n");

    return 0;
}
