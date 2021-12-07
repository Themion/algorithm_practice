#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAX_LEN 50

// truth[i]: i가 진실을 안다면 true
bool truth[MAX_LEN] = { false, };
// party[i][j]: i번째 파티에 j가 있었다면 true
bool party[MAX_LEN][MAX_LEN] = {{ false, }};
// graph[i][j]: i와 j가 같은 파티에 있었다면 true
bool graph[MAX_LEN][MAX_LEN] = {{ false, }};

// N: 사람의 수, M: 파티의 수
int N, M;
// bfs에 사용할 큐
queue<int> q;

int main() {
    // buf: 입력에 사용할 버퍼, len: 입력받을 배열의 길이
    int buf, len;

    scanf("%d %d", &N, &M);
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &buf); buf--;
        // buf번째 사람이 진실을 안다면 이를 truth에 표시한 뒤
        truth[buf] = true;
        // bfs를 위해 queue에 push
        q.push(buf);
    }

    // 각 파티에 대해
    for (int i = 0; i < M; i++) {
        // 같은 파티에 참여한 사람의 집합
        vector<int> v;
        scanf("%d", &len);
        // i번째 파티에 참여한 사람을 party 변수에 저장한 뒤
        for (int j = 0; j < len; j++) {
            scanf("%d", &buf); buf--;
            party[i][buf] = true;
            v.push_back(buf);
        }
        
        // 이 파티에 참여한 사람들이 서로를 만났음을 표시
        for (auto j : v) for (auto k : v) graph[j][k] = j != k;
    }

    // bfs를 통해 진실을 아는 사람을 추가한다
    while(!q.empty()) {
        // 파티에서 만난 사람들 중 진실을 모르는 사람에게 진실을 알린다
        for (int i = 0; i < N; i++) if (graph[q.front()][i] && !truth[i]) {
            truth[i] = true;
            q.push(i);
        }
        q.pop();
    }

    // 각 파티에 진실을 아는 사람이 있다면
    for (int i = M - 1; i >= 0; i--) for (int j = 0; j < N; j++) 
        if (party[i][j] && truth[j]) {
            // 참여 가능한 파티의 수를 1 줄인다
            M--;
            break;
        }

    // 과장된 이야기를 할 수 있는 파티 개수를 출력
    printf("%d\n", M);

    return 0;
}
