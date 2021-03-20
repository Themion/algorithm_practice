#include <cstdio>
#include <queue>
#include <stack>

// node[i]: i번으로 가는 최단기 경로에서,
//          start: i 직전의 수
//          cmd: start를 i로 변환할 명령어
//          visit: i가 이전에 나왔다면 true, 아니라면 false
class node
{
public:
    int start;
    char cmd;
    bool visit;
    node() {
        start = 0;
        cmd = '\0';
        visit = false;
    }
    node(int _start, char _cmd)
    {
        start = _start;
        cmd = _cmd;
        visit = true;
    }
};


void boj_9019()
{
    
    int A, B, item[4];      // item: 명령어를 통해 A를 변환시킨 모습
    char dslr[5] = "DSLR";  // D, S, L, R 네 명령어 문자
    node n[10000];          // 각 수의 변환 관계를 나타낼 그래프

    
    std::queue<int> q;  // q: bfs에 사용할 큐
    std::stack<char> s; // s: B에서 A까지 탐색을 스택으로 저장해 출력

    scanf("%d %d", &A, &B);
    q.push(A); n[A] = node(A, '\0');    // 루트 노드인 A를 q에 push
    
    while(!n[B].visit)
    {
        A = q.front(); q.pop(); // q에서 노드 하나를 가져와 DSLR 변환
        item[0] = (A * 2) % 10000;
        item[1] = (A + 9999) % 10000;
        item[2] = (A % 1000) * 10 + (A / 1000);
        item[3] = (A % 10) * 1000 + A / 10;

        // 변환한 수 중 등장하지 않은 수가 있다면 방문하고 q에 push
        for (int i = 0; i < 4; i++) if (!n[item[i]].visit)
        {
            n[item[i]] = node(A, dslr[i]);
            q.push(item[i]);
        }
    }

    // B에 도착한 이후 탐색을 통해 A -> B 경로를 스택에 저장
    while(n[B].cmd != '\0') 
    {
        s.push(n[B].cmd);
        B = n[B].start;
    }
    // 스택에 저장된 경로를 차례로 출력
    while(!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    } printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) boj_9019();

    return 0;
}