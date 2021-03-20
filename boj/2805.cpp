#include <cstdio>

//n: 나무의 수, m: 원하는 나무토막의 총 길이
int n, m;
//wood[i]: i번째 나무
int wood[1000000];

//나무를 높이 mid만큼 자른 뒤 얻은 나무토막의 총 길이
long long cut_wood(int mid)
{
    long long sum = 0;
    for (auto w : wood) sum += (w > mid) ? (w - mid) : 0;
    return sum;
}

int main()
{
    //min, max: 이진 탐색에 필요한 범위
    int min = 1, mid, max = 1;
    //나무토막의 길이의 합을 저장할 공간
    long long tmp;
    scanf("%d %lld", &n, &m);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", wood + i);
        //절단기의 최대 높이를 나무의 최대 높이로 제한
        max = max > wood[i] ? max : wood[i]; 
    }
    mid = (min + max) / 2;

    //최적의 절단기 높이를 이분 탐색을 이용해 찾는다
    while (min < max)
    {
        tmp = cut_wood(mid);

        if (tmp >= m)   min = mid + 1;
        else            max = mid - 1;

        mid = (min + max) / 2;
    }

    //이렇게 구한 절단기 높이가 간혹 정답의 범위에서 벗어날 때가 있으므로
    //높이가 정답의 범위 안에 들 때까지 높이를 줄인다
    while (cut_wood(mid) < m) mid--;

    printf("%lld\n", mid);
    return 0;
}