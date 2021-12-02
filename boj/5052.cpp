#include <cstdio>

// trie 클래스
class node {
public:
    bool is_leaf = false;
    node* next[10];

    node() { for (int i = 0; i < 10; i++) next[i] = NULL; }
    node* push (char c) {
        int i = c - '0';
        if (next[i] == NULL) next[i] = new node();
        return next[i];
    }
};

// 각 테스트 케이스를 입력받아 실행
bool test_case() {
    // 주어진 경우가 가능하다면 true, 아니라면 false
    bool ans = true;
    // 문자열을 한 글자씩 입력받기 위한 버퍼
    char buf;
    // 테스트 케이스에서 주어지는 문자열의 개수
    int n;
    // trie: 트라이를 저장할 공간, ptr: trie를 탐색하기 위한 포인터
    node trie, *ptr;

    scanf("%d\n", &n);
    // 테스트 케이스의 각 문자열에 대해
    while (n--) {
        ptr = &trie;

        // while문을 통해 문자열을 한 글자씩 탐색
        scanf("%c", &buf);
        while (buf != '\n') {
            // 입력받은 문자를 trie에 push한 뒤
            ptr = ptr->push(buf);
            // 지금까지 입력받은 부분 문자열이 이전에 입력받은 전체 문자열일 때
            // 현재 테스트 케이스는 불가능한 경우이다
            if (ptr->is_leaf) ans = false;
            scanf("%c", &buf);
        }
        // 현재 문자열이 이전에 입력받은 문자열의 부분 문자열이라면
        // ptr->next 중 NULL이 아닌 값이 존재하므로 이를 확인하면
        // 현재 테스트 케이스는 불가능한 경우이다
        for (int i = 0; i < 10; i++) if (ptr->next[i] != NULL) ans = false;
        // 문자열 입력을 마쳤으므로 현재 문자열의 끝을 표시
        ptr->is_leaf = true;
    }

    // 현재 테스트 케이스가 가능한 경우인지를 출력
    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) printf("%s\n", test_case() ? "YES" : "NO");

    return 0;
}