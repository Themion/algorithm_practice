#include <iostream>

using namespace std;

#define MAX_N 100000

// heap: 최대 힙, len: 힙의 크기
int heap[MAX_N] = { 0, }, len;

void swap(int &a, int &b) { int temp = a; a = b; b = temp; }
// i의 부모 노드의 인덱스
int prev(int i) { return (i - 1) / 2; }
// i의 두 자식 노드 중 더 큰 노드의 인덱스
int next(int i) { return 2 * i + (heap[2 * i + 1] > heap[2 * i + 2] ? 1 : 2); }

// x를 heap에 push
void push(int x) {
    // x를 저장할 인덱스
    int i = len++;
    // 힙의 마지막에 x를 push한 뒤
    heap[i] = x;
    // 부모 노드가 자신보다 클 때까지 부모 노드와 현재 노드를 swap
    for (int j = prev(i); i && heap[i] > heap[j]; i = j, j = prev(i))
        swap(heap[i], heap[j]);
}

int pop() {
    // i: heap의 노드를 swap하기 위한 인덱스, ret: pop한 노드의 값
    int i = 0, ret = heap[i];

    // 루트 노드와 마지막 노드를 swap한 뒤 마지막 노드를 0으로 설정해 pop
    swap(heap[i], heap[len ? --len : len]);
    heap[len] = 0;

    // 자식 노드가 자신보다 작을 때까지 자식 노드 중 더 큰 노드와 현재 노드를 swap
    for (int j = next(i); j < len && heap[i] < heap[j]; i = j, j = next(i))
        swap(heap[i], heap[j]);

    return ret;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 연산의 개수, x: 각 연산
    int N, x;

    // 각 연산에 대해
    for (cin >> N; N--; ) {
        // 연산을 입력받은 뒤
        cin >> x;

        // x가 0보다 크다면 해당 수를 힙에 push
        if (x) push(x);
        // 아니라면 힙에서 노드를 하나 pop한 뒤 출력
        else cout << pop() << '\n';
    }

    return 0;
}
