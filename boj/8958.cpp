#include <cstdio>

int test_case() {
    // 문자열을 한 글자씩 입력받을 버퍼
    char buf;
    // add: 가중치, sum: 가중치의 총합
    int add = 1, sum = 0;

    // 문자열의 각 문자에 대해
    while (scanf("%c", &buf) && buf != '\n') {
        // 현재 문자가 'O'라면 sum에 가중치를 더하고 가중치를 1 증가
        if (buf == 'O') sum += add++;
        // 그렇지 않다면 가중치를 0으로 초기화
        else add = 1;
    }

    // 정답을 반환
    return sum;
}

int main() {
    int T;
    // 테스트 케이스를 입력받아 각 테스트 케이스 실행
    for (scanf("%d%*c", &T); T--; ) printf("%d\n", test_case());

    return 0;
}
