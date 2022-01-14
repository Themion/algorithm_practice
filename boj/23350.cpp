#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> container;
typedef queue<container> que;
typedef stack<container> stk;

#define MAX_M 100
#define _prior first
#define _weight second

// cnt_prior[i]: 우선순위가 인 컨테이너의 수
int ans = 0, cnt_prior[MAX_M + 1];
// unsorted_q, q:   정렬되지 않은 컨테이너의 배열을 unsorted_q에 차례로 입력하여
//                  주어진 방식으로 정렬하여 q에 push
que unsorted_q, q;
// s: 적재된 컨테이너의 배열을 저장
// s_: s에서 빼낸 컨테이너를 임시로 저장할 공간
stk s, s_;

// 컨테이너 cont를 to에 push
template <typename T>
void push(container cont, T &to) {
    to.push(cont);
    ans += cont._weight;
}
// 큐 from에서 컨테이너 하나를 to에 push
template <typename T>
void move(que &from, T &to) {
    push(from.front(), to);
    from.pop();
}
// 스택 from에서 컨테이너 하나를 to에 push
template <typename T>
void move(stk &from, T &to) {
    push(from.top(), to);
    from.pop();
}

int main() {
    // N: 컨테이너의 개수, M: 컨테이너의 우선순위 종류의 수
    int N, M, idx = MAX_M;
    container cont;
    scanf("%d %d", &N, &M);

    // 컨테이너를 차례로 입력받아 unsorted_q에 저장
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &(cont._prior), &(cont._weight));
        unsorted_q.push(cont);

        // 해당 우선순위를 가진 컨테이너의 수를 1 증가
        cnt_prior[cont._prior]++;
    }

    // unsorted_q에서 우선순위가 최대인 컨테이너를 발견하면 q에 push
    // 발견하지 못한다면 발견할 때까지 unsorted_q에 다시 push하며 순회
    while (!unsorted_q.empty()) {
        // 남은 우선순위 중 최댓값을 탐색하여 idx에 저장
        while (idx > 0 && !cnt_prior[idx]) idx--;
        // 우선순위가 idx인 컨테이너를 찾을 때까지 순회
        while (unsorted_q.front()._prior != idx) move(unsorted_q, unsorted_q);

        // 우선순위가 idx인 컨테이너를 q에 push
        q.push(unsorted_q.front());
        unsorted_q.pop();

        // 우선순위가 idx인 컨테이너의 수를 1 감소
        cnt_prior[idx]--;
    }

    // s에 컨테이너가 없을 때를 대비하여 알고리즘에 영향을 주지 않는 값을 push
    s.push({0, 0});

    // q 안에 있는 모든 컨테이너에 대해
    while(!q.empty()) {
        // 우선순위가 같으면서 무게가 더 작은 컨테이너가 적재되어 있을 때
        // 그러한 컨테이너를 s_에 이동시킨 뒤
        while ( q.front()._prior == s.top()._prior && 
                q.front()._weight > s.top()._weight )
            move(s, s_);

        // 컨테이너를 s로 옮긴 후
        move(q, s);
        
        // s_에 있던 컨테이너를 다시 s에 push
        while (!s_.empty()) move(s_, s);
    }

    // 컨테이너를 이동시킬 때 든 비용을 출력
    printf("%d\n", ans);

    return 0;
}
