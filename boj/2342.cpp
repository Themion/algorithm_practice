#include <cstdio>

// cost[i][l][r]: i % 2번째 스텝에서 왼발이 l, 오른발이 r에 있을 때 
//                처음부터 지금까지 사용한 힘의 합
int cost[2][5][5];

// 절댓값 반환
int abs(int num) { return num >= 0 ? num : -num; }
// a와 b 중 0이 아니면서 더 작은 값을 a에 할당
void set_min(int& a, int b) {
    if (a == 0) a = b;
    else if (b != 0) a = a < b ? a : b;
}
// set_min(a, b + c)를 사용할 때, b가 0인 경우 발생하는 에러를 방지하는 함수
void set_min(int& a, int b, int c) { if (b != 0) return set_min(a, b + c); }

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
    // order: 밟아야 할 순서를 하나씩 받아 저장할 공간
    // last:  현재 스텝 이전의 스텝을 임시로 저장
    //        단 0일 경우 아직 스텝을 밟지 않음
    // ans: cost 배열에서 정답을 저장할 변수
    int order, last = 0, ans = 0;

    // 명령을 하나는 반드시 입력받는다
    scanf("%d", &order);

    // step이 0일 때 가능한 상태는 (0, 0) 뿐이다
    cost[0][0][0] = -1;

    // 모든 가능한 스텝에 대해
    for (step = true; order != 0; step = !step) {
        // 현재 스텝에서 고정할 발에 대해
        for (int i = 0; i < 5; i++) {
            // 고정할 발이 옮겨야 할 위치에 있다면 continue
            if (i == order) continue;

            // 옮길 발에 대해
            for (int j = 0; j < 5; j++) {
                // 발을 옮기는 데에 드는 힘
                int cost_ = get_cost(j, order);
                // 발을 옮길 때 힘이 가장 적게 드는 곳을 찾는다
                set_min(cost[step][order][i], cost[!step][j][i], cost_);
                set_min(cost[step][i][order], cost[!step][i][j], cost_);
            }
        }

        // 다음 상태 초기화
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
            cost[!step][i][j] = 0;

        // 현재 스텝을 저장한 뒤 다음 스텝을 입력받는다
        last = order;
        scanf("%d", &order);
    }

    // 가장 적게 든 힘의 최솟값을 ans에 저장
    for (int i = 0; i < 5; i++) {
        set_min(ans, cost[!step][i][last]);
        set_min(ans, cost[!step][last][i]);
    }

    // 맨 처음 상태의 힘이 -1이었으므로 ans에 1을 더한 값을 출력
    printf("%d\n", ans + 1);

    return 0;
}