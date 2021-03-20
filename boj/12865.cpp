#include <cstdio>

// a와 b를 비교해 더 작은 쪽을 a에 저장
void cmp(int &a, int b) { if (a < b) a = b; }

// 가방 안에 무게 1, 가치 0의 물건을 무한정 집어넣을 수 있다고 가정
int main()
{
    int N, K;
    // weight, value: 각 물건의 무게와 가치
    // val[w]: 가방에 무게가 w만큼 차 있을 때 가질 수 있는 가장 큰 가치
    int weight, value, val[100001] = { 0, };
    
    scanf("%d %d", &N, &K);

    // 물건을 입력받을 때마다 가치를 갱신
    for (int i = 0; i < N; i++) 
    {
        // 물건을 입력받은 뒤
        scanf("%d %d", &weight, &value);
        // 
        for (int w = K; w >= weight; w--)
            cmp(val[w], val[w - weight] + value);
    }

    printf("%d\n", val[K]);

    return 0;
}