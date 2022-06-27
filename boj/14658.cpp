#include <cstdio>

#define MAX_K 100

// N, M: 별똥별이 떨어지는 공간의 크기, L: 정사각형 트램펄린의 한 변의 길이
// K: 별똥별의 수, sum: 트램펄린이 튕겨내는 별똥별의 갯수, max: sum의 최댓값 
int N, M, L, K, max, sum;
// star: 각 별이 떨어지는 좌표
struct Star { int x, y; } star[MAX_K];

// 트램펄린이 가로로 i번째 별이 떨어지는 곳,
// 세로로 j번째 별이 떨어지는 곳에서부터 시작할 때
// k번째 별을 튕겨낼 수 있는지를 반환
bool valid(int i, int j, int k) {
    return (star[k].x >= star[i].x) && (star[k].x <= (star[i].x + L))
        && (star[k].y >= star[j].y) && (star[k].y <= (star[j].y + L));
}

int main() {
    // 문제의 조건을 입력받은 뒤
    scanf("%d %d %d %d", &N, &M, &L, &K);
    for (int i = 0; i < K; i++) scanf("%d %d", &star[i].x, &star[i].y);

    // i번째 별의 x좌표와 j번째 별의 y좌표에 대해
    // 트램펄린의 왼쪽 모서리를 좌표 (x, y)에 두었을 때
    for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
        // 트램펄린이 튕겨내는 별똥별의 수를 초기화한 뒤
        sum = 0;
        // 해당 상태의 트램펄린이 튕겨내는 별똥별의 개수를 계산하고
        for (int k = 0; k < K; k++) sum += valid(i, j, k);
        // sum을 max와 비교해 갱신
        if (max < sum) max = sum;
    }

    // 최대로 별똥별을 튕겨낼 때 지면에 떨어진 별똥별의 수를 출력
    printf("%d\n", K - max);

    return 0;
}
