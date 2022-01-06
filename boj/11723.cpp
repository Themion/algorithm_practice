#include <iostream>

using namespace std;

// 비트마스킹의 i번째 위치
#define bit(i) (1 << i)
// 문자열에서 정수를 파싱한 뒤 비트마스킹 실행
#define x(i) bit(stoi(str.substr(i)))

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // M: 연산의 수, S: 비트마스킹으로 표현한 집합
    int M, S = 0;
    // 명령을 입력받을 공간
    string str;

    // 명령의 개수를 입력받은 뒤 getline을 위해 공백 문자를 입력받는다
    cin >> M; cin.get();
    // 각 명령에 대해
    while (M-- && getline(cin, str)) {
        // 첫 두 글자가 'a'일 경우 가능한 명령은 두 가지가 있다
        if      (str[0] == 'a') {
            // 두 번째 글자가 'l'이라면 명령은 all이므로 모든 숫자를 추가
            if (str[1] == 'l')
                for (int i = 1; i <= 20; i++) S |= bit(i);
            // 그렇지 않다면 명령은 'add'이므로 명령 내의 숫자 x를 추가
            else S |= x(4);
        } 
        // 첫 글자가 'e'라면 명령은 'empty'이므로 모든 숫자를 제거
        else if (str[0] == 'e') S = 0;
        // 첫 글자가 'r'이라면 명령은 'remove'이므로 명령 내의 숫자 x를 제거
        else if (str[0] == 'r') S &= ~x(7);
        // 첫 글자가 'c'라면 명령은 'check'이므로 명령 내의 숫자 x가 존재하는지를 출력
        else if (str[0] == 'c') {
            if (S & x(6)) cout << "1\n";
            else cout << "0\n";
        }
        // 첫 글자가 't'라면 명령은 'toggle'이므로 명령 내의 숫자 x를 추가 혹은 제거
        else if (str[0] == 't') S ^= x(7);
    }
    
    return 0;
}
