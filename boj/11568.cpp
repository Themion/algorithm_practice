#include <cstdio>

void set_max(int &a, int b) { a = a > b ? a : b; }
void set_min(int &a, int b) { a = (a > b || a == 0) ? b : a; }

int main()
{
    int N, max = 0;
    // card[i]: i번째 카드
    // max-of_len[i]: 길이가 i인 부분수열에서 가장 큰 값
    int card[1000], max_of_len[1000] = { 0, };

    // 카드의 목록을 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", card + i);

    // 각 카드와 길이가 서로 다른 증가 부분수열에 대해
    for (int i = 0; i < N; i++) for (int l = max; l >= 0; l--)
        // 부분수열의 마지막 값이 현재 카드보다 작다면
        if (card[i] > max_of_len[l])
        {
            // 부분수열의 맨 뒤에 현재 카드를 더한 뒤 
            // 맨 끝 값이 더 작은 부분수열을 저장
            set_min(max_of_len[l + 1], card[i]);
            // 부분수열의 최대 길이를 갱신
            set_max(max, l + 1);
        }
    
    // 부분수열의 최대 길이를 출력
    printf("%d\n", max);

    return 0;
}