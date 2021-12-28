#include <cstdio>

bool test_case() {
    // 괄호의 깊이가 음수가 아니라면 true, 음수라면 false
    bool ret = true;
    // 문자열을 한 글자씩 입력받을 공간
    char buf;
    // 괄호의 깊이
    int depth = 0;

    // 괄호 문자열의 각 글자에 대해
    while (scanf("%c", &buf) && buf != '\n') {
        // 괄호 문자열의 깊이를 갱신한 뒤
        (buf == '(') ? depth++ : depth--;
        // 깊이가 음수였던 적이 있는지를 ret에 저장
        ret &= (depth >= 0);
    }

    // 괄호의 깊이가 음수였던 적이 없고 현재 깊이가 0이라면 현재 문자열은 VPS이다
    // 현재 문자열이 VPS인지 여부를 반환
    return ret && !depth;
}

int main() {
    int T;
    // 테스트 케이스의 수를 입력받고 각 테스트 케이스를 실행
    for (scanf("%d%*c", &T); T--;) printf("%s\n", test_case() ? "YES" : "NO");
    return 0;
}
