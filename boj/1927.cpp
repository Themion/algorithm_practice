#include <cstdio>

#define MAX 100000

unsigned int heap[MAX + 1] = { 0, };

//힙의 두 인덱스를 받아 값을 swap하고 두 번쨰 인덱스를 반환
unsigned int swap(unsigned int a, unsigned int b)
{
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;

    return b;
}

//노드 parent의 두 자식 노드 중 parent를 대체할 노드의 인덱스를 반환
unsigned int get_child(unsigned int parent)
{
    int left = parent * 2, right = parent * 2 + 1;

    //인덱스가 범위를 벗어나거나 자식 노드가 없다면 0을 반환
    if (right > MAX) return 0;
    if (!heap[left] && !heap[right]) return 0;

    if (!heap[left]) return right;
    if (!heap[right]) return left;
    return heap[left] < heap[right] ? left : right;
}

unsigned int pop()
{
    //idx, cmp: swap할 노드의 인덱스
    //ret: pop할 루트 노드
    int idx = 1, cmp, ret = heap[idx];
    //루트 노드의 값을 마지막 노드로 바꾼 뒤 마지막 노드를 제거
    heap[idx] = heap[heap[0]];
    heap[heap[0]] = 0;

    //루트 노드가 heap에 맞는 자리를 찾을 때까지 swap
    while((cmp = get_child(idx)) != 0 && heap[idx] > heap[cmp]) 
        idx = swap(idx, cmp);

    //heap의 크기를 1 줄인다
    if (heap[0] > 0) heap[0] -= 1;

    return ret;
}

void push(unsigned int item)
{
    int idx = ++heap[0];    //힙의 크기를 1 늘린 뒤
    heap[idx] = item;       //힙에 아이템을 추가하고 swap하여 위치를 지정
    while (idx > 1 && heap[idx] < heap[idx / 2]) idx = swap(idx, idx / 2);
}

int main()
{
    int cnt, num;                   //cnt: 명령의 수, num: 명령
    heap[0] = 0;                    //heap[0]을 힙의 길이로 사용
    scanf("%d", &cnt);

    //각 명령에 대해
    while(cnt--)
    {
        scanf("%d", &num);          //명령을 입력받은 뒤
        if (num) push(num);         //명령이 push라면 push를
        else printf("%d\n", pop()); //명령이 pop이라면 pop을 실행
    }

    return 0;
}