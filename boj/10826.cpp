#include <cstdio>

#define SIZE 1045
#define MOD 100

// arr[n % 3]: n번쨰 피보나치 수
char arr[3][SIZE];

// ab에 a + b를 저장
void fib(char a[], char b[], char ab[]) {
    // 두 성분을 더했을 때 발생한 carry
    bool carry = false;
    // 두 수의 각 성분을 더한 값
    int add;

    // 두 수의 각 자리를 더해 그 결과를 ab에 차례로 저장
    for (int i = SIZE - 1; i >= 0; i--) {
        add = a[i] + b[i] + carry;
        carry = add / MOD;
        ab[i] = add % MOD;
    }
}

int main() {
    // n: 구하고자 하는 피보나치 수의 순서, idx: 피보나치 수의 출력에 사용할 인덱스
    int n, idx = 0;

    // n을 입력받은 뒤
    scanf("%d", &n);
    // 1번째 피보나치 수를 arr[1]에 저장
    arr[1][SIZE - 1] = 1;
    // 2번째부터 n번째까지 피보나치 수를 각각 더해 계산
    for (int i = 2; i <= n; i++)
        fib(arr[(i - 2) % 3], arr[(i - 1) % 3], arr[i % 3]);

    // 배열의 빈 공간은 건너뛴 다음
    for (; idx < SIZE - 1 && !arr[n % 3][idx]; idx++);
    // 첫 자리는 빈 공간을 공백을 넣어서, 나머지 자리는 0을 넣어서 출력
    printf("%hhd", arr[n % 3][idx++]);
    for (; idx < SIZE; idx++) printf("%02hhd", arr[n % 3][idx]);
    // 개행 문자를 출력해 출력을 종료
    printf("\n");

    return 0;
}
