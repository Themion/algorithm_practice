#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 100000

// int를 절댓값과 부호로 나누어 저장
class num {
public:
    // 실제 값이 음수라면 true
    bool b = false;
    // 실제 값의 절댓값
    int i = 0;

    num() {}
    num(int i_) { b = i_ < 0; i = abs(i_); }
    // x의 절댓값
    int abs(int x) { return x < 0 ? -x : x; }
    // 클래스의 실제 값
    int val() { return b ? -i : i; }
};

// 두 num 클래스를 비교
bool operator<(num p, num q) { return p.i == q.i ? p.b : p.i < q.i; }
bool operator>(num p, num q) { return p.i == q.i ? !p.b : p.i > q.i; }
// cout용 operator
ostream &operator<<(ostream &out, num n) { out << n.val(); return out; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 연산의 개수, x: 각 연산
    int N, x;
    // 최소 힙
    priority_queue<num, vector<num>, greater<num>> q;

    // 각 연산에 대해
    for (cin >> N; N--; ) {
        // 연산을 입력받은 뒤
        cin >> x;

        // x가 0이 아니라면 해당 수를 힙에 push
        if (x != 0) q.push(num(x));
        // 아니라면 힙에서 노드를 하나 출력한 뒤 pop
        else {
            cout << (!q.empty() ? q.top() : 0) << '\n';
            if (!q.empty()) q.pop();
        }
    }

    return 0;
}
