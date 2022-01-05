#include <cstdio>

int main() {
    // 단어를 한 글자씩 입력받을 공간
    char c;
    // 입력받은 문자의 개수
    int i = 0;

    // 글자의 모든 문자를 입력받은 뒤
    while (scanf("%c", &c) && c != '\n') {
        // 문자를 출력하고
        printf("%c", c);
        // 입력받은 문자의 개수가 10의 배수일 때 줄바꿈을 출력
        if (!(++i % 10)) printf("\n");
    }
    return 0;
}
