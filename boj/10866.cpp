#include <iostream>
#include <string>

using namespace std;

typedef int idx;

#define MAX_N 10000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N: 명령의 수, deq: 덱, f, b: 덱의 front와 back
    int N, deq[MAX_N * 2] = { 0, }, f = MAX_N, b = MAX_N;
    // str: 각 명령
    string str;

    // 각 명령에 대해
    for (cin >> N; N--; ) {
        // 명령을 입력받은 뒤
        cin >> str;

        // 각 명령에 맞는 연산을 실행
        if      (str == "push_front")   cin >> deq[--f];
        else if (str == "push_back")    cin >> deq[b++];
        else if (str == "pop_front")    cout << (f < b ? deq[f++] : -1) << '\n';
        else if (str == "pop_back")     cout << (f < b ? deq[--b] : -1) << '\n';
        else if (str == "size")         cout << b - f << '\n';
        else if (str == "empty")        cout << (int)(f == b) << '\n';
        else if (str == "front")        cout << (f < b ? deq[f] : -1) << '\n';
        else if (str == "back")         cout << (f < b ? deq[b - 1] : -1) << '\n';
    }

    return 0;
}
