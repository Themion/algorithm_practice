#include <cstdio>

// a: 입력받은 배열, sum[i]: i에서 끝나는 가장 큰 증가 부분수열
int a[1000], sum[1000];

int main()
{
    int n, ans = 0;
    // 배열을 입력받는다
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // 배열의 각 성분에 대해
    for (int i = 0; i < n; i++)
    {
        // 부분수열은 항상 a[i]에서 끝나므로 sum[i]의 최솟값은 a[i]이다
        sum[i] = a[i];
        
        // i 이전 성분에 대해
        for (int j = 0; j < i; j++)
            // j에서 끝나는 부분수열 중 a[i]를 더할 수 있는 부분수열이 있다면
            // 그렇게 한다
            if ((sum[i] <= sum[j] + a[i]) && (a[i] > a[j]))
                sum[i] = sum[j] + a[i];
        // ans 갱신
        if (ans < sum[i]) ans = sum[i];
    }

    // ans를 출력한다
    printf("%hd\n", ans);

    return 0;
}