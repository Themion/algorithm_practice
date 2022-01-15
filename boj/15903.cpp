#include <cstdio>

typedef unsigned long long ull;

#define MAX_N 1000

ull heap[MAX_N + 1] = { 0, };

// 힙의 두 인덱스를 받아 값을 swap하고 두 번째 인덱스를 반환
ull swap(ull a, ull b) {
    ull temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;

    return b;
}

// 노드 parent의 두 자식 노드 중 parent를 대체할 노드의 인덱스를 반환
ull get_child(ull parent) {
    // 인덱스가 범위를 벗어나거나 자식 노드가 없다면 0을 반환
    int left = parent * 2, right = parent * 2 + 1;

    if (right > MAX_N || (!heap[left] && !heap[right])) return 0;

    if (!heap[left]) return right;
    if (!heap[right]) return left;
    return heap[left] < heap[right] ? left : right;
}

ull pop() {
    // idx, cmp: swap할 노드의 인덱스, ret: pop할 루트 노드
    ull idx = 1, cmp, ret = heap[idx];

    // 루트 노드의 값을 마지막 노드로 바꾼 뒤 마지막 노드를 제거
    heap[idx] = heap[heap[0]];
    heap[heap[0]] = 0;

    // 루트 노드가 heap에 맞는 자리를 찾을 때까지 swap
    while ((cmp = get_child(idx)) && heap[idx] > heap[cmp]) 
        idx = swap(idx, cmp);

    // heap의 크기를 1 줄인다
    heap[0] -= (heap[0] > 0);

    return ret;
}

void push(ull item) {
    int idx = ++heap[0];    // 힙의 크기를 1 늘린 뒤
    heap[idx] = item;       // 힙에 아이템을 추가하고 swap하여 위치를 지정
    while (idx > 1 && heap[idx] < heap[idx / 2]) idx = swap(idx, idx / 2);
}

int main() {
    // n: 카드의 수, m: 연산 횟수
    int n, m;
    // x, y: 힙에서 고른 두 수, ans: 카드에 쓰인 수의 합
    ull x, y, ans = 0;

    // 카드의 수와 연산 횟수를 입력받은 뒤 모든 카드에 대해
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        // 각 카드에 쓰인 수를 입력받으면서
        scanf("%lld", &x);
        // 카드를 힙에 push한 뒤
        push(x);
        // 카드에 쓰인 수의 합을 구한다
        ans += x;
    }
    // 각 연산에 대해
    while (m--) {
        // 두 카드를 힙에서 가져온 뒤
        x = pop();
        y = pop();

        // 두 카드에 쓰인 수를 x + y로 바꾸어 push
        push(x + y);
        push(x + y);
        // 이 과정에서 카드의 수의 합은 (x + y)가 (x + y + x + y)로 바뀌었으므로
        // 카드의 수의 합은 (x + y)만큼 늘었다
        ans += x + y;
    }

    // 카드에 쓰인 수의 합을 출력
    printf("%lld\n", ans);

    return 0;
}
