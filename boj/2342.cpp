#include <cstdio>

#define INF 0x3f3f3f3f

int abs(int num) { return num >= 0 ? num : -num; }
void set_min(int& a, int b) { a = a < b ? a : b; }

// 발을 from에서 to로 옮길 때 드는 힘
int get_cost(int from, int to) {
    if (from == 0) return 2;
    else if (from == to) return 1;
    else if (abs(from - to) == 2) return 4;
    return 3;
}

int main() {
    // 3차원 배열 cost의 첫번째 인덱스
    // 원래 [0, 100010]의 범위를 가졌으나 메모리 절약을 위해 [0, 1] 범위로 압축
    bool step = true;
    // cost[i][l][r]: i % 2번째 스텝에서 왼발이 l, 오른발이 r에 있을 때 
    //                처음부터 지금까지 사용한 힘의 합
    // order: 밟아야 할 순서를 하나씩 받아 저장할 공간
    // last: 현재 스텝 이전의 스텝을 임시로 저장. 단 0일 경우 아직 스텝을 밟지 않음
    // ans: cost 배열에서 정답을 저장할 변수
    int cost[2][5][5], order, last = 0, ans = INF;

    // 명령을 하나는 반드시 입력받는다
    scanf("%d", &order);

    // cost를 INF로 초기화
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
        for (int t = 0; t < 2; t++) cost[t][i][j] = INF;
    // step이 0일 때 가능한 상태는 (0, 0) 뿐이다
    cost[0][0][0] = 0;

    // 모든 가능한 스텝에 대해
    for (step = true; order; step = !step) {
        // 고정할 발 i, 움직일 발 j에 대해 고정할 발이 목적지에 있는 게 아니라면
        for (int i = 0; i < 5; i++) if (i != order) for (int j = 0; j < 5; j++) {
            // (i, j)에서 (i, order), (j, i)에서 (order, i)로 움직일 때
            // 총 소모된 힘의 최솟값을 계산
            set_min(cost[step][order][i], cost[!step][j][i] + get_cost(j, order));
            set_min(cost[step][i][order], cost[!step][i][j] + get_cost(j, order));
        }

        // 다음 상태 초기화
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
            cost[!step][i][j] = INF;

        // 현재 스텝을 저장한 뒤 다음 스텝을 입력받는다
        last = order;
        scanf("%d", &order);
    }

    // 가장 적게 든 힘의 최솟값을 ans에 저장한 뒤 출력
    for (int i = 0; i < 5; i++) {
        set_min(ans, cost[!step][i][last]);
        set_min(ans, cost[!step][last][i]);
    }
    printf("%d\n", ans);

    return 0;
}
