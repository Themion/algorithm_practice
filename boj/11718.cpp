#include <cstdio>

int main() {
    char c;
    // 한 글자씩 입력받으며 모든 글자를 출력
    while ((c = getchar()) != EOF) printf("%c", c);
    return 0;
}
