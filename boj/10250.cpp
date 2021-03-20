#include <cstdio>
#include <cmath>

//호텔의 구조가 주어졌을 때 n번째 손님의 방을 배정
int assign_room (int h, int w, int n) {
    //엘리베이터에서 방까지의 거리
    int dist = 1;

    //손님의 수가 호텔 층 수보다 많고 아직 호텔이 다 차지 않았을 때
    while (n > h && dist < w) {
        //h명의 손님을 거리가 dist인 방에 차레로 배정한 뒤 dist를 1씩 늘린다
        n -= h;
        dist += 1;
    }

    //n번째 손님은 높이가 대략 (n % h), 거리가 dist인 방에 묵게 된다
    return n * 100 + dist;
}

int main () {
    //tc: 테스트 케이스의 수
    //h, w: 호텔의 층 수와 각 층의 방 수, n: 손님의 수
    int tc, h, w, n;
    scanf("%d", &tc);

    //각 테스트 케이스를 입력받아 알고리즘 실행
    while (tc--) {
        scanf("%d %d %d", &h, &w, &n);
        printf("%d\n", assign_room(h, w, n));
    }
    
    return 0;
}