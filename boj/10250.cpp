#include <cstdio>

int test_case () {
    // H, W: 호텔의 층 수와 각 층의 방 수, N: 손님의 수
    // d: 엘리베이터에서 방까지의 거리
    int H, W, N, d = 1;

    // 문제의 조건을 입력받은 뒤 각 층에 사람을 한 명씩 배정
    for (scanf("%d %d %d", &H, &W, &N); N > H && d < W; d++) N -= H;
    
    // N번째 손님은 (N % H)층의 거리가 d인 방에 묵게 된다
    return N * 100 + d;
}

int main () {
    int T;
    // 테스트 케이스의 수를 입력받고 각 테스트 케이스를 실행
    for (scanf("%d", &T); T--; ) printf("%d\n", test_case());
    return 0;
}
