#include <cstdio>

void test_case() {
    // R: 문자열의 반복 횟수, s: 문자열의 각
    int R, s;

    // 문자열 반복 횟수와 문자열의 첫 글자를 입력받는다
    scanf("%d %c", &R, &s);
    // 문자열의 모든 글자에 대해
    while (s != '\n') {
        // 각 글자를 R번 출력한 뒤 다음 문자를 입력받는다
        for (int i = 0; i < R; i++) printf("%c", s);
        scanf("%c", &s);
    }
    
    // 개행 문자를 출력해 출력을 종료
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) test_case();

    return 0;
}
