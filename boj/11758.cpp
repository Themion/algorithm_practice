#include <cstdio>

int main() {
    // 각 점의 x 좌표
    int x[3];
    // 각 점의 y 좌표
    int y[3];
    // 각 점을 일정 위치로 이동시킨 뒤 외적하여 벡터의 방향을 계산
    int ccw;

    for (int i = 0; i < 3; i++)
        scanf("%d %d", x + i, y + i);

    // 두 번째 점과 세 번째 점을 첫 번쨰 점을 원점으로 삼는 새로운 좌표축으로 이동
    for (int i = 1; i < 3; i++) {
        x[i] -= x[0];
        y[i] -= y[0];
    }

    // 두 벡터의 외적을 이용해 벡터의 각을 조사
    ccw = x[1] * y[2] - y[1] * x[2];
    if (ccw != 0) ccw = (ccw > 0) ? 1 : -1;

    // 외적하여 구한 정답을 출력
    printf("%d\n", ccw);
    return 0;
}
