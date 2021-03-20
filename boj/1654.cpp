#include <cstdio>

//cable[i]: i번째로 주어진 랜선의 길이
unsigned int k, n, cable[10000];

//길이 mid짜리 랜선 토막의 수
unsigned int cable_cut(unsigned long long mid)
{
    unsigned int sum = 0;
    for (int i = 0; i < k; i++) sum += cable[i] / mid;
    return sum;
}

int main()
{
    //cnt: 랜선 토막의 수
    //min, mid, max: 이분 탐색에 쓰이는 범위
    unsigned long long cnt = 0, min, mid, max;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) 
    {
        scanf("%lld", cable + i);
        cnt += cable[i];
    }

    //랜선 토막의 길이는 1보다 짧지 않다
    min = 1;
    //랜선을 토막낸 뒤 자투리의 길이의 합이 랜선 토막의 길이보다 길 수도 있다
    max = cnt / n;
    mid = (min + max) / 2;

    //최적의 랜선 토막의 길이를 이분 탐색을 이용해 찾는다
    while (min != max)
    {
        cnt = cable_cut(mid);

        if (cnt >= n)   min = mid + 1;
        else            max = mid - 1;
        mid = (min + max) / 2;
    }

    //이렇게 구한 랜선 토막의 길이가 간혹 정답의 범위에서 벗어날 때가 있으므로
    //토막의 길이가 정답의 범위 안에 들 때까지 토막의 길이를 줄인다
    while (cable_cut(mid) < n) mid--;

    //최적의 토막 길이를 출력한다
    printf("%lld\n", mid);

    return 0;
}