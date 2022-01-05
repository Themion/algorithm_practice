#include <cstdio>

int main() {
    char c;
    int sum = 0;

    // N은 입력받을 필요 없다
    scanf("%*d%*c");
    // 숫자가 공백 없이 주어지므로 주어지는 각 숫자는 한 자리 수이다
    // 모든 한 자리 수를 입력받아 sum에 그 합을 저장한 뒤 출력
    while (scanf("%c", &c) && c != '\n') sum += c - '0';
    printf("%d\n", sum);

    return 0;
}
