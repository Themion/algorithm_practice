#include <cstdio>

int test_case(char buf) {
    // cnt: 문자를 바꾼 횟수, depth: 괄호의 깊이
    int cnt = 0, depth = 0;
    // 문자열의 각 문자에 대해
    do {
        // 깊이가 0일 때 닫는 괄호를 입력받았다면
        if (!depth && buf == '}') {
            // 괄호를 여는 괄호로 바꾼다
            buf = '{';
            cnt++;
        }
        // 입력받은 괄호에 따라 깊이를 1 늘리거나 줄인다
        depth += buf == '{' ? 1 : -1;
    } while (scanf("%c", &buf) && buf != '\n');

    // 괄호가 다 닫히지 않았을 때 맨 뒤 여는 괄호부터 차례로 닫는 괄호로 바꾼다
    for (; depth > 0; depth -= 2) cnt++;

    // 문자열을 바꾼 횟수를 반환한다
    return cnt;
}

int main() {
    // 문자열을 입력받을 공간
    char buf = '\0';
    // 각 테스트 케이스의 번호를 출력할 때 쓸 변수
    int cnt = 1;

    // 모든 테스트 케이스의 문자 교체 횟수를 계산하여 출력
    while (scanf("%c", &buf) && buf != '-')
        printf("%d. %d\n", cnt++, test_case(buf));

    return 0;
}
