#include <cstdio>

#define MAX 10001
#define MOD 10

void swap(char &a, char &b) { char temp = a; a = b; b = temp; }

int main() {
    // 각 자리 덧셈에서 carry가 발생했는지 여부
    bool carry = false;
    // A, B: 입력받은 두 수, buf: 입력을 한 글자씩 끊어서 입력받을 공간
    char A[MAX] = { 0, }, B[MAX] = { 0, }, buf;
    // a, b: A와 B의 입출력에 사용할 인덱스, add: 각 자리 덧셈의 결과를 저장할 공간
    int a = 0, b = 0, add;

    // 두 수를 역순으로 입력받은 뒤
    while (scanf("%c", &buf) && buf != ' ') A[a++] = buf - '0';
    while (scanf("%c", &buf) && buf != '\n') B[b++] = buf - '0';
    // 역순인 수를 다시 뒤집어 저장
    for (int i = 0; i < a / 2; i++) swap(A[i], A[a - i - 1]);
    for (int i = 0; i < b / 2; i++) swap(B[i], B[b - i - 1]);

    // 수의 각 자리를 차례로 더해 A + B를 완성시킨다
    for (int i = 0; i < MAX; i++) {
        add = A[i] + B[i] + carry;
        carry = add / MOD;
        A[i] = add % MOD;
    }

    // 불필요한 자리는 모두 날린 뒤
    for (a = MAX - 1; !A[a]; a--);
    // 수를 한 자리씩 출력한다
    while (a >= 0) printf("%hhd", A[a--]);
    // 개행 문자를 출력해 출력을 종료
    printf("\n");

    return 0;
}
