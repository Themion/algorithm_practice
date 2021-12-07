#include <iostream>
#include <set>
#include <string>

using namespace std;

#define MAX_LEN 50

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 정렬할 단어의 개수
    int N;
    // s[i]: 길이가 i인 단어의 집합
    set<string> s[MAX_LEN + 1];
    // 단어를 입력받을 공간
    string str;

    // 단어의 개수를 입력받은 뒤
    cin >> N;
    // 단어를 길이에 따라 나누어 저장한다
    while (N--) {
        cin >> str;
        s[str.size()].insert(str);
    }

    // 단어를 길이순 -> 사전순으로 출력
    for (N = 0; N <= MAX_LEN; N++) for (auto it : s[N]) 
        cout << it << '\n';

    return 0;
}
