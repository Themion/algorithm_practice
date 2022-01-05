#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 1000

int main() {
    // N: 카드의 개수, card: 각 카드에 적힌 수
    // lis: 가장 긴 증가하는 부분 수열, len: lis의 길이
    int N, card, lis[MAX_N] = { 0, }, len = 0;

    // 각 수열의 성분에 대해
    for (scanf("%d", &N); N--; ) {
        // 각 수열의 성분을 입력받고
        scanf("%d", &card);
        // 증가하는 부분 수열 lis이 비었거나 card가 lis의 마지막 값보다 크다면
        // lis의 맨 뒤에 card를 추가
        if (!len || lis[len - 1] < card) lis[len++] = card;
        // 그렇지 않다면 lis에서 card보다 작은 값 중 가장 큰 값을 card로 변경
        // 부분 수열의 순서에는 영향을 미치지만 부분 수열의 길이에는 영향을 주지 않음
        else *lower_bound(lis, lis + len, card) = card;
    }

    // 가장 긴 증가하는 부분 수열의 길이를 출력
    printf("%hd\n", len);

    return 0;
}
