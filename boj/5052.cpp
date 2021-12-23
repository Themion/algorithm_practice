#include <iostream>

using namespace std;

#define MAX_N 10000
#define MAX_LEN 10
#define ALP 10

// 트라이의 각 노드
struct node {
    // child[i]: i에 해당하는 자식이 존재한다면 그 자식의 인덱스, 아니라면 0
    int child[ALP] = { 0, };
    // 현재 노드가 리프 노드라면 true, 아니라면 false
    bool is_leaf = false;
};

bool test_case() {
    // 주어진 테스트 케이스가 일관성이 있는 목록이라면 true, 아니라면 false
    bool ret = true;
    // 문자열을 한 글자씩 입력받을 공간
    char c;
    // n: 전화번호의 개수
    // i: 트라이에 접근하기 위한 인덱스, len: 트라이에 존재하는 노드 수
    int n, i, len = 0;
    // trie[i]: i번째로 push된 노드의 상태
    node trie[MAX_N * MAX_LEN];

    // 전화번호의 개수를 입력받은 뒤 개행 문자를 입력받아 에러 방지
    cin >> n;
    cin.get();

    // 각 전화번호에 대해
    while (n--) {
        // 루트 노드에서부터 차례로 push
        i = 0;
        // 전화번호의 각 글자에 대해
        while ((c = cin.get()) != '\n') {
            // 현재 테스트 케이스가 일관성이 없다면 continue
            if (!ret) continue;

            // 현재 글자에 해당하는 자식 노드가 없다면 자식 노드를 새로 생성
            if (!trie[i].child[c - '0']) trie[i].child[c - '0'] = ++len;
            // 현재 글자에 해당하는 자식 노드로 이동한 뒤
            i = trie[i].child[c - '0'];
            // 이전에 현재 전화번호의 부분 문자열이 입력된 적 있다면
            // 현재 테스트 케이스는 일관성이 없음
            ret &= !(trie[i].is_leaf);
        }
        // 전화번호 입력을 마쳤으므로 리프 노드를 설정
        trie[i].is_leaf = true;
        // 현재 노드에 자식 노드가 존재하면
        // 현재 전화번호를 부분 문자열로 삼는 전화번호가 존재하므로
        // 현재 테스트 케이스는 일관성이 없음
        for (int j = 0; j < ALP; j++) ret &= !(trie[i].child[j]);
    }

    // 입력받은 테스트 케이스가 일관성 있는 목록인지 여부를 반환
    return ret;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // 테스트 케이스의 수를 입력받은 뒤
    // 각 테스트 케이스가 일관성 있는 목록인지 여부를 출력
    for (cin >> t; t--; ) cout << (test_case() ? "YES" : "NO") << '\n';

    return 0;
}
