#include <cstdio>

// 배열로 구현하기 힘들어 클래스로 트리 구조를 재현함
class node
{
public:
    int val = 0;
    node *left = nullptr, *right = nullptr;

    // 서브 트리의 루트 노드에서 실행시키면 규칙에 맞추어 push된다
    void push(int val_)
    {
        // 루트 노드의 값이 0이라면 루트 노드가 단말 노드이므로
        // 루트 노드의 값을 val_로 치환
        if (val == 0) 
        {
            val = val_;
            left = new node();
            right = new node();
        }
        // 루트 노드와 push할 값을 비교해 왼쪽/오른쪽 서브 트리에 push한다
        else
        {
            node *child = val > val_ ? left : right;
            child->push(val_);
        }
    }
    // 후위 순회
    void print()
    {
        // 값이 0인 노드는 단말 노드이며 값을 출력할 필요가 없으므로 return
        if (val == 0) return;
        
        left->print();
        right->print();
        printf("%d\n", val);
    }
};

int main()
{
    // push할 값을 잠시 저장할 버퍼
    int buf;
    // 전체 트리의 루트 노드
    node* tree = new node();

    // 입력받는 순서, 즉 전위 순회대로 push하면
    // 그대로 트리의 원래 모양대로 만들 수 있다
    while (scanf("%d", &buf) == 1) tree->push(buf);
    // 후위 순회를 하며 출력
    tree->print();

    return 0;
}