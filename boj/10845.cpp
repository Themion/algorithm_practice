#include <iostream>
#include <string>

using namespace std;

#define MAX_N 10000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N: 명령의 수, que: 큐, l, r: 큐의 시작과 끝
    int N, que[MAX_N] = { 0, }, l = 0, r = 0;
    // str: 각 명령
    string str;

    // 각 명령에 대해
    for (cin >> N; N--; ) {
        // 명령을 입력받은 뒤
        cin >> str;

        // 각 명령에 맞는 연산을 실행
        if      (str == "push")     cin >> que[r++];
        else if (str == "pop")      cout << (l < r ? que[l++] : -1) << '\n';
        else if (str == "size")     cout << r - l << '\n';
        else if (str == "empty")    cout << (int)(l == r) << '\n';
        else if (str == "front")    cout << (l < r ? que[l] : -1) << '\n';
        else if (str == "back")     cout << (l < r ? que[r - 1] : -1) << '\n';
    }

    return 0;
}
