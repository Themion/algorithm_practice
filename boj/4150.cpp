#include <cstdio>

#define MAX_LEN 500
#define MOD 100

// 매우 긴 두 수를 string 형태로 저장해 더한다
void add(char c[MAX_LEN], char a[MAX_LEN], char b[MAX_LEN]) {
    // 두 성분을 더했을 때 발생한 carry
    bool carry = false;
    // 두 수의 각 성분을 더한 값
    char add_ = 0;

    // 두 수의 각 자리를 더해 그 결과를 c에 차례로 저장
    for (int i = MAX_LEN - 1; i >= 0; i--) {
        add_ = a[i] + b[i] + carry;
        c[i] = add_ % MOD;
        carry = add_ / MOD;
    }
}

int main() {
    // 피보나치 수를 3개의 1차원 배열에 두 자리씩 나누어 저장한다
    char arr[3][MAX_LEN];
    // N: 구하고자 하는 피보나치 수의 순서, idx: arr을 출력할 때 사용할 인덱스
    int N, idx = 0;

    scanf("%d", &N);

    // 첫 두 개의 피보나치 수는 1임이 자명하다
    arr[1][MAX_LEN - 1] = arr[2][MAX_LEN - 1] = 1;
    // 세 번째 피보나치 수부터 차례로 계산
    for (int i = 3; i <= N; i++)
        add(arr[i % 3], arr[(i - 2) % 3], arr[(i - 1) % 3]);

    // 배열의 빈 공간은 건너뛴 다음
    for (; !arr[N % 3][idx]; idx++);
    // 첫 자리는 빈 공간을 공백을 넣어서, 나머지 자리는 0을 넣어서 출력
    printf("%hhd", arr[N % 3][idx++]);
    for (; idx < MAX_LEN; idx++) printf("%02hhd", arr[N % 3][idx]);

    printf("\n");

    return 0;
}
