#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int X;
    string S;
    
    int time = 0;
    bool is_time_match;
    bool is_hourglass;
    bool is_time_backward = false;

    for (cin >> N; N--;) {
        cin >> S >> X;
        
        is_time_match = X == (time + 1);
        is_hourglass = (S == "HOURGLASS");
        if (is_hourglass && !is_time_match)
            is_time_backward = !is_time_backward;

        cout << (time + 1) << ' ' << ((is_time_match && !is_hourglass) ? "YES" : "NO") << '\n';

        time = (is_time_backward ? (time + 11) : (time + 1)) % 12;
    }

    return 0;
}
