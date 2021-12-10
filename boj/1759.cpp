#include <cstdio>

#define MAX_C 15

// chr[i]: 알파벳 i가 후보로 주어졌다면 true, 아니라면 false
bool chr[26];
// 출력할 문자열을 저장할 컨테이너
char str[MAX_C];
// L: 만들 암호의 길이, C: 암호 후보 문자의 수
short L, C;

// 길이가 len이고 마지막으로 알파벳 last를 사용한 암호를 만든 뒤
// 나머지 암호를 완성시킨다
void backtrack(int len, int last) {
    // 암호를 전부 완성시키지 못했다면
    if (len < L) {
        // 아직 쓰지 않은 문자열이 있을 때
        for (int i = last + 1; i < 26; i++) if (chr[i]) {
            // 각 문자를 암호의 끝에 붙인 뒤 해당 과정을 다시 시행한다
            str[len] = i + 'a';
            backtrack(len + 1, i);
        }
    }
    // 암호 후보가 완성되었다면
    else {
        // a: 모음 수, b: 자음 수
        int a = 0, b = 0;
        // 모음의 수와 자음의 수를 센다
        for (int i = 0; i < L; i++) switch (str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': a++; break;
            default: b++;
        }

        // 모음 수 혹은 자음 수가 부족하다면 함수를 종료한다
        if ((a < 1) || (b < 2)) return;
        // 암호 후보를 출력한다
        for (int i = 0; i < L; i++) printf("%c", str[i]);
        printf("\n");
    }
}

int main() {
    // 입력에 사용할 버퍼
    char buf;
    // 암호의 길이와 후보 문자의 수, 각 후보 문자를 입력받는다
    scanf("%hd %hd", &L, &C);
    for (int i = 0; i < C; i++) {
        scanf("%*c%c", &buf);
        chr[buf - 'a'] = true;
    }

    // 백트래킹을 이용해 암호 해독을 시작한다
    backtrack(0, -1);

    return 0;
}