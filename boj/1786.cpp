#include <iostream>
#include <string>
#include <vector>

using namespace std;

// T, P: 문제에서 주어진 두 문자열
string T, P;
// fail: KMP에서 사용하는 실패함수
vector<int> fail;

void make_fail() {
    // 실패함수에 접근할 인덱스
    int idx;
    // 실패함수의 배열 크기를 미리 P의 크기로 설정
    fail = vector<int>(P.size(), 0);

    // P의 각 위치에 대해
    for (int i = 1; i < P.size(); i++) {
        // 실패함수를 탐색을 i부터 실행
        idx = i;
        // 접두사가 같은 지점을 발견할 때까지 idx를 이동
        while (idx && (P[i] != P[fail[idx - 1]])) idx = fail[idx - 1];
        // 접두사가 같은 지점을 발견했다면 i번째 문자의 실패함수를 갱신
        if (idx) fail[i] = fail[idx - 1] + 1;
    }
}

vector<int> KMP() {
    // P에 접근하기 위한 인덱스
    int idx = 0;
    // T에서 등장하는 P의 위치의 집합
    vector<int> ret;

    // T의 모든 위치에 대해
    for (int i = 0; i < T.size(); i++) {
        // T의 현재 위치와 일치하는 접두사를 찾는다
        while (idx > 0 && T[i] != P[idx]) idx = fail[idx - 1];

        // T에서 일치하는 접두사를 찾았다면
        if (T[i] == P[idx])  {
            // 인덱스가 1부터 시작하므로
            // 접두사가 P와 일치할 경우 ret에 P의 시작위치인 i - idx + 1을 push
            if (idx == P.size() - 1) ret.emplace_back(i - idx + 1);
            // 접두사가 P와 일치한다면 실패함수로 접두사의 크기를 변경
            // 그렇지 않다면 idx에 1을 증가시켜 접두사를 확장
            idx = (idx == P.size() - 1) ? fail[idx] : idx + 1;
        }
    }

    return ret;
}

int main() {
    //cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    // P에 접근하기 위한 인덱스
    int idx = 0;
    // T에서 P의 위치의 집합
    vector<int> v;

    // T와 P를 입력받는다
    getline(cin, T);
    getline(cin, P);

    // 실패함수 생성 후 KMP 알고리즘 실행
    make_fail();
    v = KMP();

    // T에서 P를 찾은 횟수와 각 시작점을 출력
    cout << v.size() << '\n';
    for (int i : v) cout << i << '\n';

    return 0;
}
