#include <iostream>
#include <set>
#include <string>

using namespace std;

#define MAX_N 10000

// 각 테스트 케이스를 입력받아 실행
bool test_case() {
    bool ans = true;
    char buf;
    int n;
    set<string> s;
    string str[MAX_N];
    
    // 문자열의 수를 입력받은 뒤
    cin >> n;
    // 각 문자열을 배열과 map에 각각 저장
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        s.insert(str[i]);
    }

    // 각 부분 문자열이 map에 존재하는지 확인
    for (int i = 0; i < n; i++) {
        // substr(i, j)의 시간 복잡도는 O(i + j)이므로
        // 빠른 연산을 위해 새 변수를 만들어 부분 문자열을 차례로 저장
        string lookup = "";
        for (int j = 0; j < str[i].size() - 1; j++) {
            lookup += str[i][j];
            ans &= s.find(lookup) == s.end();
        }
    }
    return ans;
}

int main() {
    int t;
    // 테스트 케이스의 수를 입력받은 뒤
    cin >> t;
    // 각 테스트 케이스가 일관성 있는 테스트 케이스인지 여부를 반환
    while (t--) printf("%s\n", test_case() ? "YES" : "NO");

    return 0;
}
