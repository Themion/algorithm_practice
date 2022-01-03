#include <iostream>
#include <string>

using namespace std;

#define MAX_N 10000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N: 명령의 수, stk: 스택, len: 스택의 길이
    int N, stk[MAX_N] = { 0, }, len = 0;
    // str: 각 명령
    string str;

    // 각 명령에 대해
    for (cin >> N; N--; ) {
        // 명령을 입력받은 뒤
        cin >> str;

        // 각 명령에 맞는 연산을 실행
        if      (str == "push")     cin >> stk[len++];
        else if (str == "pop")      cout << (len ? stk[--len] : -1) << '\n';
        else if (str == "size")     cout << len << '\n';
        else if (str == "empty")    cout << (int)(len == 0) << '\n';
        else if (str == "top")      cout << (len ? stk[len - 1] : -1) << '\n';
    }

    return 0;
}
