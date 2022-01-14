#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 1000
#define MAX_M 100

// 각 사람이 들은 종소리의 시점과 횟수
class person {
public:
    bool bell[MAX_N] = { false, };
    char times = 0;
    // 정렬을 위한 비교 연산자
    bool operator<(person p) { return this->times < p.times; }
};

int main() {
    // N: 종소리를 들은 사람, M: 종소리가 울린 횟수
    // ans: 주어진 경우가 가능하면 true, 아니라면 false
    int N, M, ans = true;
    // p: 각 사람이 들은 종소리를 기록할 공간
    person p[MAX_N];

    // 문제의 조건을 입력받으면서 각 사람이 몇번의 종소리를 들었는지 계산
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        scanf("%d", &(p[i].bell[j]));
        p[i].times += p[i].bell[j];
    }

    // 종소리를 들은 횟수에 대해 정렬
    sort(p, p + N);

    // 정렬된 종소리 집합 중 이전 값에서 들은 종소리를 현재 값에서 듣지 못했다면
    // 주어진 경우는 불가능한 경우이다
    for (int i = 1; i < N * ans; i++) for (int j = 0; j < M * ans; j++)
        if (p[i].bell[j] < p[i - 1].bell[j]) ans = false;

    // 주어진 경우가 가능한지 여부를 출력
    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
