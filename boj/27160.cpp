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
    bool ans = false;

    string fruit;
    unordered_map<string, int> m;

    for (cin >> N; N--;) {
        cin >> fruit >> X;
        m[fruit] += X;
    }

    for (auto val : m) ans |= val.second == 5;
    cout << (ans ? "YES" : "NO") << "\n";

    return 0;
}
