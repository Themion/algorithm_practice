#include <cstdio>

#define MAX 26

int main() {
    // 단어를 한 글자씩 입력받기 위한 공간
    char c;
    // ans[i]: i + 'a'가 처음 나온 인덱스
    int ans[MAX];

    // ans를 전부 -1로 초기화한 뒤
    for (int i = 0; i < MAX; i++) ans[i] = -1;
    // 단어의 각 글자가 아직 나오지 않았다면 ans에 나온 위치를 표시
    for (int i = 0; scanf("%c", &c) && c != '\n'; i++) 
        if (ans[c - 'a'] == -1) ans[c - 'a'] = i;
    // 각 글자가 나온 위치를 출력
    for (int i = 0; i < MAX; i++) printf("%d%c", ans[i], i == MAX - 1 ? '\n' : ' ');

    return 0;
}
