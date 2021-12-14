#include <cstdio>

#define MAX_LEN 5000
#define MOD 1000000

int main() {
    // 암호
    char str[MAX_LEN + 1] = { 0, };
    // dcd[i]: 앞 i자리를 해독할 수 있는 경우의 수
    int dcd[MAX_LEN + 1] = { 0, }, i, temp = 0;

    // 암호를 입력받는다
    scanf("%s", str);

    // 첫 글자를 해독하는 경우의 수를 계산
    temp = str[0] - '0';
    dcd[0] = temp != 0;

    // 암호의 두 번째 글자부터 각 글자에 대해
    for (i = 1; str[i]; i++) {
        // 마지막 두 글자를 숫자로 변경
        temp = (temp % 10) * 10 + (str[i] - '0');
        // 현재 글자가 0이 아니라면 이전 글자까지 해독한 경우의 수를 가져옴
        dcd[i] = str[i] != '0' ? dcd[i - 1] : 0;
        // 마지막 두 글자가 한 글자로 해독될 수 있다면
        // 두 글자 이전까지 해독한 결과를 더함
        if (temp >= 10 && temp <= 26) dcd[i] += (i >= 2) ? dcd[i - 2] : 1;
        // 값이 범위를 넘어갈 수 있으므로 특정 값으로 나눈 나머지를 저장
        dcd[i] %= MOD;
    }

    // 전체 암호를 해독한 경우의 수를 출력
    printf("%d\n", dcd[i - 1]);

    return 0;
}
