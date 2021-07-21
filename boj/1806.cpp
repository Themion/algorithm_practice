#include <cstdio>

#define N_MAX 100000
#define INF 0x3f3f3f3f

int main()
{
    // N: 수열의 길이, S: 최소합의 크기, arr: 수열
    int N, S, arr[N_MAX];
    // l, r: 부분수열 합을 구하기 위한 두 인덱스
    // ret: 부분합을 이루는 수열의 길이
    // sum[i]: arr의 앞 i개 성분의 합
    int l = 0, r = 1, ret = INF, sum[N_MAX + 1] = { 0, };

    // 문제 조건을 입력받는다
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", arr + i);
        sum[i + 1] = sum[i] + arr[i];
    }

    // 투 포인터를 이용해 문제 해결
    while (l < N)
    {
        // 부분합이 S 이상이라면
        if (sum[r] - sum[l] >= S) 
        {
            // 부분합 수열의 길이가 줄었다면 ret을 갱신
            if (ret > r - l && r != l) ret = r - l;
            // 부분합의 왼쪽을 가능하면 한 칸 줄인다
            if (l < N) l++;
        }
        // 부분합이 S 미만이고 오른쪽에 성분이 더 있다면
        // 오른쪽 성분도 부분합에 포함
        else if (r < N) r++;
        // 무한루프 방지
        else break;
    }
    
    // 조건을 만족하는 부분합을 찾았다면 그 길이를, 아니라면 0을 출력
    printf("%d\n", ret < INF ? ret : 0);

    return 0;
}