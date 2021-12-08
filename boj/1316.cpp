#include <cstdio>

// 입력받은 단어가 그룹 단어라면 true, 아니라면 false
bool test_case() {
    // chk[i]: 각 알파벳이 이전에 등장했다면 true
    // ret: 입력된 단어가 그룹 단어라면 true
    bool chk[26] = { false, }, ret = true;
    // 단어를 글자 단위로 입력받기 위한 공간
    char buf = 0;
    // 글자를 인덱스로 바꿔 저장할 공간
    int idx = 26;

    scanf("%c", &buf);
    // 단어의 각 글자에 대해
    while (buf != '\n') {
        // 단어의 글자가 바뀌었을 때
        if (idx != buf - 'a') {
            // 글자를 인덱스로 바꾼 뒤
            idx = buf - 'a';
            // 글자가 이전에 나온 글자인지 확인한 후
            ret &= !chk[idx];
            // 현재 글자를 등장한 글자로 표시
            chk[idx] = true;
        }
        scanf("%c", &buf);
    }

    return ret;
}

int main() {
    int N, ans = 0;
    scanf("%d%*c", &N);
    //매 테스트 케이스마다 입력되는 단어가 그룹 단어인지 확인
    while (N--) ans += test_case();
    //그룹 단어의 개수를 출력
    printf("%d\n", ans);

    return 0;
}
