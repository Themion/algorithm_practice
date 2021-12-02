#include <cstdio>
#include <stack>

using namespace std;

int main() {
    // is_minus: n이 음수라면 true, 아니라면 false
    // carry: 3진법을 균형 3진법으로 바꿀 때 사용할 flag
    bool is_minus, carry = false;
    // -1, 0, 1을 각각 T, 0, 1로 맵핑하기 위한 dictionary
    char dict[4] = "T01";
    // 균형 3진법으로 전환할 수
    int n;
    // 균형 3진법의 각 digit을 저장할 공간
    stack<int> s;

    scanf("%d", &n);

    // n이 음수라면 이를 표시한 뒤 n을 일시적으로 양수로 전환
    is_minus = n < 0;
    if (is_minus) n = -n;

    // n을 균형 3진법(-1, 0, 1)로 전환
    do {
        // 3진법으로 표시한 n의 i번째 자리를 push한 뒤
        // 해당 자리가 3진법으로 2일 때, 즉 2 * 3^n을 포함할 때
        // 2 * 3^n을 3^(n - 1) - 3^n으로 바꾸어 표기한다

        // 3진법 n의 i번째 digit을 push한 뒤
        s.push(n % 3 + carry);
        // 해당 자리가 3진법으로 2거나, 이전 자리의 영향으로 2 이상이 되었는가를 계산
        carry = s.top() >= 2;
        // 만일 그렇다면 현재 자리에 3을 뺀 뒤
        // 다음 자리 digit에 1을 더해 push한다
        if (carry) s.top() -= 3;
        // 다음 자리에 대해 반복
        n /= 3;
    } while (n || carry);

    // 균형 3진법으로 바꾼 n의 각 자리에 대해 가장 큰 자리부터
    while (!s.empty()) {
        // i번째 digit을 스택에서 가져온 뒤
        n = s.top();
        s.pop();
        // n이 본래 음수였다면 보수를 취해준다
        if (is_minus) n *= -1;

        // n의 범위가 [-1, 1]이므로 
        // 배열의 범위에 맞춰 n에 1을 더한 값을 인덱스로 해
        // dict에서 맞는 문자를 가져와 출력
        printf("%c", dict[n + 1]);
    }
    // 개행문자를 출력해 출력을 마친다
    printf("\n");
    
    return 0;
}