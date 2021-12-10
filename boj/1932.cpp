#include <iostream>

using namespace std;

#define MAX_N 500

int max(int a, int b) { return a > b ? a : b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tri[MAX_N][MAX_N + 1] = {{ 0, }}, ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 1; j <= i + 1; j++) {
        cin >> tri[i][j];
        tri[i % 2][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
    }

    for (int i = 1; i <= n; i++) ans = max(ans, tri[n - 1][i]);
    cout << ans << '\n';

    return 0;
}
