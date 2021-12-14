#include <cstdio>
#include <queue>

using namespace std;

int main() {
    // 덱의 초기 카드 수
    int N;
    // 덱
    queue<int> q;

    // 덱의 크기를 입력받은 뒤 q에 덱의 각 카드를 push
    scanf("%d", &N);
    for (int i = 0; i < N; i++) q.push(i + 1);

    // 카드가 한 장 남을 때까지
    while (q.size() > 1) {
        // 맨 위 카드를 버리고
        q.pop();
        // 맨 위 카드를 맨 아래로 이동
        q.push(q.front());
        q.pop();
    }

    // 한 장 남은 카드를 출력
    printf("%d\n", q.front());

    return 0;
}
