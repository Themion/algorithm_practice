#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX_N 1000

void test_case() {
    // N: 단어의 개수, ord[i]: i번째 암호문의 복호문에서의 위치
    int N, ord[MAX_N] = { 0, };
    // str: 암호 순서를 계산할 때 사용할 변수, code: 암호문
    string str, code[MAX_N];
    // m[i]: i번째 암호 예제
    unordered_map<string, int> m;

    // 단어의 개수를 입력받은 뒤
    cin >> N;
    // 암호 예제의 각 단어 순서를 저장한 뒤
    for (int i = 0; i < N; i++) {
        cin >> str;
        m[str] = i;
    }
    // 복호 예제를 이용해 암호문 -> 복호문 순서를 저장
    for (int i = 0; i < N; i++) {
        cin >> str;
        ord[i] = m[str];
    };
    // 암호문을 복호문 순서로 저장한 뒤 순서대로 출력
    for (int i = 0; i < N; i++) cin >> code[ord[i]];
    for (int i = 0; i < N; i++) cout << code[i] << (i < N - 1 ? ' ' : '\n');
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    // 테스트 케이스의 수를 입력받고 각 테스트 케이스를 실행
    for (cin >> T; T--; ) test_case();
    return 0;
}
