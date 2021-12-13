#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, bool> doc;

#define _pri first
#define _target second

int test_case() {
    // N: 문서의 수, M: 출력할 문서의 인덱스, buf: 각 문서의 중요도
    // rank[i]: 큐에 남아있는 중요도가 i인 문서의 수
    int N, M, buf, rank[10] = { 0, };
    // q에서 가져올 문서를 저장할 공간
    doc d;
    // 프린터의 문서 출력 큐
    queue<doc> q;

    // 문제의 조건을 입력받는다
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &buf);
        // 각 문서는 {문서의 중요도, 순서를 알고자 하는 문서 여부}로 저장
        rank[buf]++;
        q.push({buf, i == M});
    }
    // 중요도가 높은 문서부터 차례로 q에서 뽑아 검토
    for (int i = 9; i >= 0; i--) while (rank[i]) {
        d = q.front();
        q.pop();

        // 현재 문서가 순서를 알고자 하는 문서이고
        // 현재 문서의 중요도가 출력 중요도라면 답을 반환
        if (d._target && d._pri == i) return N - q.size();

        // 현재 문서의 중요도가 출력 중요도가 아니라면 q에 다시 push
        if (d._pri < i) q.push(d);
        // 그렇지 않다면 출력 중요도의 문서 수를 1 감소
        else rank[d._pri]--;
    }

    // 여기까지 도달했다면 프린터 큐의 모든 문서를 출력한 것이므로 N을 반환
    return N;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) printf("%d\n", test_case());

    return 0;
}
