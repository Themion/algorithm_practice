#include <cstdio>

// cnt[i]: 숫자 i가 나온 횟수
int cnt[10];

int main() {
    // 입력을 문자열로 생각하여 버퍼에 한 글자씩 입력받는다
    char buf;

    scanf("%c", &buf);
    // 문자열의 각 문자에 대해
    while (buf != '\n') {
        // 해당 문자열의 등장 횟수를 1 늘린다
        cnt[buf - '0']++;
        scanf("%c", &buf);
    }

    // 배열을 역순으로 출력
    for (int i = 9; i >= 0; i--) while (cnt[i]--) printf("%d", i);
    printf("\n");

    return 0;
}
