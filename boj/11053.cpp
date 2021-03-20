#include <cstdio>

//a: 주어진 수열, cnt[i]: 0부터 i - 1까지 중 가장 긴 증가하는 부분수열
short a[1000], cnt[1000];

int main()
{
    //n: 수열의 길이, ret: 출력할 값을 저장할 공간
    short n, ret = 0;

    //수열의 크기와 각 성분을 입력받는다
    scanf("%hd", &n);
    for (int i = 0; i < n; i++) scanf("%hd", &a[i]);

    //cnt[0] = 0임은 자명하므로
    //수열의 두 번째 성분부터 그 성분 이전의 성분들로 구성된 부분 수열에 대해
    for (int i = 1; i < n; i++)
    {
        //알려진 부분 수열 중 길이가 cnt[i]보다 크거나 같고
        //a[i]보다 작은 성분으로 끝나는 부분 수열이 있다면
        //cnt[i]를 해당 수열의 길이 + 1로 갱신한다
        for (int j = 0; j < i; j++)
            if((cnt[i] <= cnt[j]) && (a[i] > a[j])) cnt[i] = cnt[j] + 1;

        //cnt[i]가 현재 나온 모든 값들 중 가장 크다면 출력할 값을 갱신한다
        if(ret < cnt[i]) ret = cnt[i];
    }

    //cnt[i]는 a[i - 1]까지를 고려한 값이므로 ret에 1을 더한 값을 출력한다
    printf("%hd\n", ret + 1);

    return 0;
}