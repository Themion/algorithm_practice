#include <cstdio>

//arr[i]: i장의 카드를 살 때 필요한 금액의 최댓값
int arr[1001];

int main()
{
    //구매하고자 할 카드의 개수
    int n;
    scanf("%d", &n);

    //arr[i]값은 P(i)보다 크거나 같다
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    //arr[1]은 반드시 P(1)이다
    //arr[2]부터는 arr[i] = arr[j] + arr[i + j]로 나타낼 수 있다
    for (int i = 2; i <= n; i++) for (int j = 1; j <= i / 2; j++)
        if (arr[i] < arr[j] + arr[i - j]) arr[i] = arr[j] + arr[i - j];

    //arr[n]을 출력한다
    printf("%d\n", arr[n]);

    return 0;
}