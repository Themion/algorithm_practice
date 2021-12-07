#include <cstdio>

int test_case(int dist) {
    // 현재 공간 이동 이전에 jump만큼 공간 이동을 한 횟수
    bool flag = false;
    // times: 공간 이동을 한 횟수, jump: 공간 이동을 할 거리
    int times = 0, jump = 1;

    // 아직 목적지까지의 거리가 남아있을 때
    while (dist > 0) {
        // 거리 jump만큼 공간이동을 한 뒤
        dist -= jump;
        // 거리 jump만큼 공간 이동을 한 게 처음이라면 공간 이동 거리를 그대로 두고, 
        // 그렇지 않다면 공간 이동 거리를 1 늘린다
        jump += flag;
        // jump만큼 공간 이동을 했는지 여부를 갱신
        flag = !flag;
        // 공간 이동 횟수를 1 늘린다
        times++;
    }

    // 각 공간 이동을 적절히 재배치한 뒤 
    // 마지막 공간 이동의 거리를 적절히 재배치하면 최적해가 된다
    // 공간 이동을 한 횟수를 반환
    return times;
}

int main() {
    // T: 테스트 케이스의 수, x, y: 시작점과 끝점의 좌표
    int T, x, y;

    scanf("%d", &T);
    // 각 테스트 케이스마다
    while (T--) {
        // 시작점과 끝점을 입력받고 그 차만큼 이동할 때 걸리는 시간을 출력
        scanf("%d %d", &x, &y);
        printf("%d\n", test_case(y - x));
    }

    return 0;
}
