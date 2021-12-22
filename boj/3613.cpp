#include <cstdio>

bool is_small(char c) { return c >= 'a' && c <= 'z'; }
bool is_big(char c) { return c >= 'A' && c <= 'Z'; }
bool is_valid(char c) { return is_small(c) || is_big(c) || c == '_'; }

int main() {
    // camelCase, snake_case: 입력받은 변수명이 각 형식과 닮은 부분이 있다면 true
    bool camelCase = false, snake_case = false;
    // c: 변수명을 글자 단위로 입력받을 공간, ans: 변수명을 변환해 저장할 공간
    char c, ans[200] = "";
    // i: ans에 접근하기 위한 인덱스
    int i = 0;

    // 변수명의 각 글자에 대해
    while (scanf("%c", &c) && is_valid(c) && !(camelCase && snake_case)) {
        // 소문자는 양쪽 모두에 포함되므로 ans에 그대로 저장
        if (is_small(c)) ans[i++] = c;
        // 첫 글자 이외의 부분에 대문자가 들어왔다면
        else if (is_big(c) && i) {
            // camelCase한 부분을 발견했으므로 이를 표시한 뒤
            camelCase = true;
            // 입력받은 대문자를 밑줄 + 소문자로 변경해 저장
            ans[i++] = '_';
            ans[i++] = c - 'A' + 'a';
        }
        // 첫 글자 이외의 부분에 밑줄이 들어왔다면
        else if (c == '_' && i) {
            // snake_case한 부분을 발견했으므로 이를 표시한 뒤
            snake_case = true;
            // 다음 글자를 입력받아
            scanf("%c", &c);
            // 해당 글자가 소문자라면 대문자로 변경해 저장
            if (is_small(c)) ans[i++] = c - 'a' + 'A';
            // 그렇지 않다면 에러를 표시하기 위해 camelCase를 true로 변경
            else camelCase = true;
        }
        // 이 이외의 모든 입력은 부적절한 변수명을 뜻하므로 에러를 표시
        else camelCase = snake_case = true;
    }

    // 변수명에 에러가 발생하지 않았다면 변환한 변수명을, 아니라면 "Error!"를 출력
    printf("%s\n", !(camelCase && snake_case) ? ans : "Error!");

    return 0;
}
