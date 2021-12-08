#include <cstdio>

int main() {
    // N: 입출력에 쓸 변수, need[i]: 숫자 i가 쓰이는 횟수
    int N, need[10] = { 0, };

    // 방 번호를 입력받는다
    scanf("%d", &N);

    // 방 번호가 0이라면 0이 필요한 개수는 1개
    if (!N) need[0] = 1;

    // 방 번호의 각 자리 수가 얼마나 쓰이는지 계산
    for (; N; N /= 10) need[N % 10]++;

    // 6과 9는 서로 호환되므로 한 세트에 6이 2개, 9가 0개 들었다고 가정
    // 둘의 합이 홀수일 경우 소숫점이 버림되므로 (합 % 2)를 더해준다
    need[6] = (need[6] + need[9]) / 2 + (need[6] + need[9]) % 2;

    // 각 수 중 가장 많이 쓰이는 수가 필요 세트 양과 같다
    for (int i = 0; i < 9; i++) if (N < need[i]) N = need[i];

    // 필요 세트 양을 출력한다
    printf("%d\n", N);

    return 0;
}
