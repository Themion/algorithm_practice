#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<string, bool> strmap;

int main() {
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // N: 집합 안의 문자열 수, M: 집합에서 찾을 문자열 수
    // ans: 집합에서 찾은 문자열의 개수
    int N, M, ans = 0;
    // 문자열을 입력받을 때 쓸 공간
    string str;
    // 문자열 집합을 저장할 공간
    strmap m;

    cin >> N >> M;
    // 문자열 N개를 입력받아 집합에 넣은 뒤
    while (N--) {
        cin >> str;
        m[str] = true;
    }
    // M개의 문자열을 각각 집합에서 찾는다
    // 문자열을 찾을 경우 ans의 값을 1 증가
    while (M--) {
        cin >> str;
        ans += m.find(str) != m.end();
    }

    cout << ans << '\n';

    return 0;
}

/* class node {
public:
    // 현재 노드가 리프 노드라면 true, 아니라면 false
    bool is_leaf = false;
    // cnt: 현재 노드까지 도달한 부분 문자열의 개수
    int cnt = 0;
    // next[c]: 현재 노드에서 문자 c에 해당하는 자식 노드의 포인터
    node* next[26];

    // 현재 노드의 자식 노드를 가리키는 포인터를 NULL로 초기화
    node() { for (int i = 0; i < 26; i++) this->next[i] = NULL; }
    // 문자 c를 현재 위치에 push
    void push(char c) {
        // c를 인덱스 i로 변환한 뒤
        int i = c - 'a';
        // c에 해당하는 자식 노드가 없다면 생성
        if (this->next[i] == NULL) this->next[i] = new node();
        // 자식 노드의 cnt값을 1 증가
        this->next[i]->cnt++;
    }
    // 현재 위치를 leaf로 지정
    void set_leaf() { is_leaf = true; }
    // 현재 위치에서 문자 c에 해당하는 자식 노드를 반환
    node* child(char c) { return this->next[c - 'a']; }
};

// trie: 트라이, ptr: 트라이 탐색에 사용할 포인터
node trie, *ptr;

// 문자열을 입력받아 그 문자열이 트라이에 있는지 여부를 반환
bool test_case() {
    // 문자열을 한 글자씩 입력받기 위한 버퍼
    char buf;

    // 문자열의 첫 글자를 입력받은 뒤
    scanf("%c", &buf);
    // 문자열이 끝나거나 포인터가 널이 될 때까지
    while (buf != '\n' && ptr != NULL) {
        // 포인터를 자식 노드로 변경
        ptr = ptr->child(buf);
        // 다음 글자를 입력받는다
        scanf("%c", &buf);
    }
    // 포인터가 널이 되었다는 것은 문자열이 트라이에 없다는 의미이므로
    // 남은 문자열을 모두 입력받는다
    while (buf != '\n') scanf("%c", &buf);

    // 트라이를 리프 노드까지 탐색했는지 여부를 반환한다
    return ptr != NULL && ptr->is_leaf;
}

int main() {
    // 문자열을 한 글자씩 입력받기 위한 버퍼
    char buf;
    int N, M, ans = 0;

    scanf("%d %d\n", &N, &M);
    // 각 문자열에 대해
    while (N--) {
        ptr = &trie;

        // 문자열의 첫 글자를 미리 입력받은 뒤
        scanf("%c", &buf);
        // 문자열이 끝나기 전까지
        while (buf != '\n') {
            // 트라이에 문자 buf를 push한 뒤
            ptr->push(buf);
            // 포인터를 한 칸 옮긴다
            ptr = ptr->child(buf);

            // 문자열의 다음 문자를 입력받는다
            scanf("%c", &buf);
        }
        ptr->set_leaf();
    }
    // M개의 문자열을 트라이에서 탐색
    while (M--) ans += test_case();

    // 트라이에서 찾은 문자열의 개수를 출력
    printf("%d\n", ans);

    return 0;
} */