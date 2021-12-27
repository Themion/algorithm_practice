#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> node;
typedef priority_queue<node, vector<node>, greater<node>> min_queue;
typedef priority_queue<node> max_queue;

#define _val first
#define _ord second

bool operator<(node a, node b) { return a._val < b._val; }
bool operator>(node a, node b) { return a._val > b._val; }
bool operator<=(node a, node b) { return a._val <= b._val; }
bool operator>=(node a, node b) { return a._val >= b._val; }
bool operator==(node a, node b) { return a._val == b._val; }
bool operator!=(node a, node b) { return a._val != b._val; }

#define MAX_K 1000000

min_queue min_heap;
max_queue max_heap;

void test_case() {
    // valid[i]: i번째 명령으로 입력받은 수가 힙 안에 존재하는지 여부
    bool valid[MAX_K] = { 0, };
    // 연산의 문자 부분
    char c;
    // k: 연산의 수, num: 각 연산의 정수 부분, len: 힙의 길이
    int k, num, len = 0;

    // 연산의 수를 입력받고
    cin >> k;

    // 힙을 초기화한 뒤
    min_heap = min_queue();
    max_heap = max_queue();

    // 각 연산에 대해
    for (int i = 0; i < k; i++) {
        // 연산을 입력받은 뒤
        cin >> c >> num;
        
        // 연산이 push 연산이라면
        if (c == 'I') {
            // 최소 힙과 최대 힙에 i번째 명령으로 num을 push한 뒤
            min_heap.push({num, i});
            max_heap.push({num, i});
            // i번째 명령으로 입력받은 수가 큐에 존재함을 표시
            len += (valid[i] = true);
        }
        // 연산이 pop 연산이라면
        else {
            // 힙의 길이가 0일 때
            if (!len) {
                // 최소 힙과 최대 힙을 초기화하고 continue
                min_heap = min_queue();
                max_heap = max_queue();
                continue;
            }

            // 힙의 길이를 1 줄인 뒤
            len--;
            // 최대 힙에서 pop해야 할 경우
            if (num == 1) {
                // 최대 힙 안에서 유효하지 않은 원소를 모두 pop
                while (!max_heap.empty() && !valid[max_heap.top()._ord])
                    max_heap.pop();
                // 최대 힙이 비지 않았다면
                if (!max_heap.empty()) {
                    // 최대 힙의 top이 유효하지 않음을 표시한 뒤 pop
                    valid[max_heap.top()._ord] = false;
                    max_heap.pop();
                }
            }
            else {
                // 최소 힙 안에서 유효하지 않은 원소를 모두 pop
                while (!min_heap.empty() && !valid[min_heap.top()._ord])
                    min_heap.pop();
                // 최소 힙이 비지 않았다면
                if (!min_heap.empty()) {
                    // 최소 힙의 top이 유효하지 않음을 표시한 뒤 pop
                    valid[min_heap.top()._ord] = false;
                    min_heap.pop();
                }
            }
        }
    }

    // 두 힙의 유효하지 않은 원소를 모두 pop한 뒤
    while (!max_heap.empty() && !valid[max_heap.top()._ord]) max_heap.pop();
    while (!min_heap.empty() && !valid[min_heap.top()._ord]) min_heap.pop();

    // 힙의 길이가 0이라면 EMPTY를
    // 그렇지 않다면 힙 안의 최댓값과 최솟값을 출력
    if (!len) cout << "EMPTY\n";
    else cout << max_heap.top()._val << ' ' << min_heap.top()._val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    // 테스트 케이스의 수를 입력받아 각 테스트 케이스를 진행
    for (cin >> T; T--; ) test_case();
    return 0;
}
