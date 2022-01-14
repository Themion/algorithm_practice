#include <cstdio>

#define MAX_LEN 22

int main() {
    // n이 음수라면 true, 아니라면 false
    bool is_minus, carry = false;
    // -1, 0, 1을 각각 T, 0, 1로 맵핑하기 위한 dictionary
    char dict[4] = "T01";
    // n: 균형 3진법으로 전환할 수
    // arr: 균형 3진법의 각 digit을 저장할 공간, len: arr의 길이
    int n, arr[MAX_LEN] = { 0, }, len = 0;

    // 균형 3진법으로 바꿀 수를 때입력받은 뒤
    scanf("%d", &n);

    // n이 음수라면 이를 표시한 뒤 n을 일시적으로 양수로 전환
    is_minus = n < 0;
    if (is_minus) n = -n;

    // n을 균형 3진법(-1, 0, 1)로 전환
    do {
        // 3진법으로 표시한 n의 i번째 자리를 push한 뒤
        // 해당 자리가 3진법으로 2일 , 즉 2 * 3^n을 포함할 때
        // 2 * 3^n을 3^(n - 1) - 3^n으로 바꾸어 표기한다

        // 3진법 n의 i번째 digit을 push한 뒤
        arr[len] += n % 3;
        // 해당 자리가 3진법으로 2거나, 이전 자리의 영향으로 2 이상이라면
        if (arr[len++] >= 2) {
            // 현재 자리에 3을 뺀 뒤 다음 자리 digit에 1을 더한다
            arr[len - 1] -= 3;
            arr[len]++;
        }
        // 다음 자리에 대해 반복
    } while ((n /= 3) || carry);

    // 균형 3진법으로 바꾼 n의 각 자리에 대해 가장 큰 자리부터 해당하는 문자로 출력
    while (len--) printf("%c", dict[(is_minus ? -arr[len] : arr[len]) + 1]);
    // 개행문자를 출력해 출력을 마친다
    printf("\n");
    
    return 0;
}