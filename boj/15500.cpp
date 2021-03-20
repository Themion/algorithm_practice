#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int position[12345 + 1];
stack<int> poll[3];
vector<pair<int, int>> move_log;

// start 기둥의 맨 위 판을 dest 기둥으로 이동시키는 함수
void move_plate(int start, int dest)
{
    // dest 기둥에 start 기둥의 맨 위 판을 복제하여 추가한 뒤
    poll[dest].push(poll[start].top());
    // 판이 속한 기둥을 갱신하고
    position[poll[start].top()] = dest;
    // start 기둥에서 맨 위 판을 제거한다
    poll[start].pop();

    // 판 이동 로그를 추가
    move_log.push_back({start, dest});
}

// target 기둥을 2번 기둥으로 옮기는 함수
void move_plates(int target)
{
    // pos: target 판이 속한 기둥, save: target 판 위의 모든 판을 옮길 기둥
    int pos = position[target], save = pos == 0 ? 1 : 0;
    if (pos == 2) return;   // 판이 속한 기둥이 2번 기둥이라면 return

    // target 위의 모든 판을 save 기둥으로 옮긴 뒤
    while (poll[pos].top() != target) move_plate(pos, save);
    // pos에서 판 하나, 즉 target을 2번 기둥으로 옮긴다
    move_plate(pos, 2);
}

int main()
{
    int buf, N;
    scanf("%d", &N);
    
    // 0번 기둥에 판을 차례로 넣는다
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &buf);
        poll[0].push(buf);
    }

    // N번 판부터 1번 판까지 모든 판을 2번 기둥으로 옮긴다
    for (int i = N; i > 0; i--) move_plates(i);

    // log의 길이와 각 로그를 출력
    printf("%d\n", move_log.size());
    for (auto l: move_log) printf("%d %d\n", l.first + 1, l.second + 1);

    return 0;
}