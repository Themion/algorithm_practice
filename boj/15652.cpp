#include <cstdio>

#define MAX_N 8

// str: 출력할 수열을 문자열 형태로 저장
char str[2 * MAX_N + 1];
// N: 사용할 자연수의 종류, M: 수열의 길이
int N, M;

void backtrack(int len, int last) {
    // len이 M * 2라면 수열을 모두 채운 것이므로 수열을 출력한 뒤 종료
    if (len == M * 2) {
        printf("%s\n", str);
        return;
    }

    // last부터 N 중 사용 가능한 수가 있다면
    for (int i = last; i <= N; i++) {
        // 수열에 추가한 뒤 수열의 다음 수를 채운다
        str[len] = i + '0';
        str[len + 1] = ' ';
        backtrack(len + 2, i);
    }
}

int main() {
    // N과 M을 입력받은 뒤 조건을 만족하는 수열을 모두 출력
    scanf("%d %d", &N, &M);
    backtrack(0, 1);
    return 0;
}
