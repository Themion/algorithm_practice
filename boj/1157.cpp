#include <cstdio>

#define MAX_LEN 1'000'000

// 단어를 저장할 공간
char str[MAX_LEN];
// times[i]: i번째 알파벳의 등장 횟수
int times[26];

int main() {
    // idx: 단어의 각 글자를 인덱스로 바꾼 값
    // most: 가장 많이 등장한 알파벳의 인덱스
    int idx, most = 0;

    // 단어를 입력받은 뒤
    scanf("%s", str);
    // 단어의 각 글자에 대해
    for (int i = 0; str[i]; i++) {
        // 글자를 알파벳의 순서에 맞는 인덱스로 변경
        idx = str[i] - ((str[i] >= 'a') && (str[i] <= 'z') ? 'a' : 'A');
        // 각 알파벳의 등장 횟수와 가장 많이 등장한 알파벳을 차례로 갱신
        times[idx] += 1;
        if (times[most] < times[idx]) most = idx;
    }

    // most만큼 등장한 알파벳이 most 외에 있다면 most를 ?로 갱신
    for (int i = 0; i < 26; i++)
        if (i != most && times[i] == times[most]) {
            most = '?' - 'A';
            break;
        }

    // 가장 많이 나온 알파벳을 출력
    printf("%c\n", most + 'A');

    return 0;
}
