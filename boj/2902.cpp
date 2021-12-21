#include <cstdio>

int main() {
    // 각 문자를 입력받을 공간
    char buf;

    // 문자를 계속해서 입력받는다
    while (scanf("%c", &buf)) {
        // 입력받은 문자가 대문자라면 해당 문자를 출력
        if ((buf >= 'A') && (buf <= 'Z')) printf("%c", buf);
        // 입력받은 문자가 개행 문자라면 루프문을 나간다
        else if (buf == '\n') break;
    }

    // 개행 문자를 출력해 출력을 종료한다
    printf("\n");

    return 0;
}
