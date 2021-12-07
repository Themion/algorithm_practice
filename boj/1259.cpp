#include <cstdio>

using namespace std;

char str[6];

bool test_case() {
    // idx: 문자열의 각 위치를 확인할 때 쓸 인덱스, len: 문자열의 길이
    int idx = 0, len = 0;

    // len에 문자열의 길이를 저장
    for (; str[len]; len++);
    // 계산의 편의를 위해 len에 1을 뺀다
    len--;

    // 문자열의 각 위치를 비교하여 같으면 idx를 1 올리고, 다르다면 break
    while (idx <= len / 2) {
        if (str[idx] == str[len - idx]) idx++;
        else break;
    }

    // 문자열을 마지막까지 비교했는지 확인
    return idx > len / 2;
}

int main() {
    scanf("%s", str);
    // 각 테스트 케이스에 대해
    while (str[0] != '0') {
        // 입력받은 수가 팰린드롬수라면 yes를, 아니라면 no를 출력
        printf("%s\n", test_case() ? "yes" : "no");
        scanf("%s", str);
    }

    return 0;
}
