#include <cstdio>

#define MAX_B 20
#define MAX_P 100

// 각 다리, 혹은 다리와 다리 사이의 지점
// time: 이동하는 데에 걸리는/남은 시간
// moving: 이동 가능한 최대 인원/이동중인 인원
// pending: 0/이동 대기중인 인원
struct Bridge { public: int time = 0, moving = 0, pending = 0; };

int min(int a, int b) { return a < b ? a : b; }

int test_case(int B, int P){
    int time = 0, group;
    Bridge bridge[MAX_B], place[MAX_B + 1];
    
    for (int i = 0; i < B; i++) 
        scanf("%d %d", &(bridge[i].moving), &(bridge[i].time));

    // 모든 인원을 첫 지점에 대기시킨다
    place[0].pending = P;

    // 모든 인원이 이동할 때까지
    while (place[B].pending < P) {
        // 시간을 1씩 소모하며 각 다리/지점의 상황을 변화시킨다
        time++;

        // 각 다리에 대해 역순으로 순회
        for (int b = B - 1; b >= 0; b--) {
            // 다리를 건너는 그룹이 없을 때
            if (!place[b].time && place[b].pending) {
                // 건널 수 있는 사람의 최대치를 계산
                group = min(place[b].pending, bridge[b].moving);
                // 최대한 많이 사람을 pending에서 moving으로 보낸다
                place[b].pending -= group;
                place[b].moving = group;
                // 이동에 걸리는 시간을 초기화
                place[b].time = bridge[b].time;
            }
            // 이동에 걸리는 시간 계산
            if (place[b].time) place[b].time -= 1;
            if (!place[b].time && place[b].moving) {
                // 이동을 마친 인원을 다음 지역의 pending으로 보낸 뒤
                place[b + 1].pending += place[b].moving;
                // 이동을 마친 지점의 moving을 비운다
                place[b].moving = 0;
            }
        }
    }

    // 모든 인원
    return time;
}

int main() {
    int B, P;
    // while문을 이용해 각 테스트 케이스를 실행
    scanf("%d %d", &B, &P);
    while (B != 0 && P != 0) {
        printf("%d\n", test_case(-B, P));
        scanf("%d %d", &B, &P);
    }

    return 0;
}