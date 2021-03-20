#include <cstdio>

int main()
{
    //n, m: 끊어진 기타줄의 수와 기타줄 브랜드의 수
    //pack, one: 각 브랜드의 기타줄 팩과 낱개의 값
    //p_m, o_m: pack과 one의 최솟값
    //price: 기타줄 팩만 사는 경우와 낱개만 사는 경우,
    //       팩으로 6개씩 산 뒤 나머지를 낱개로 사는 경우를 각각 저장
    //ret: price의 최솟값을 저장할 공간
    int n, m, pack, one, p_m = 10000, o_m = 10000, price[3], ret = 100000;

    //끊어진 기타줄 수와 기타줄 브랜드의 수를 입력받은 뒤
    scanf("%d %d", &n, &m);
    //각 기타줄 브랜드에 대해
    while(m--)
    {
        //기타줄 팩과 낱개의 값을 입력받고
        scanf("%d %d", &pack, &one);

        //이 값을 최솟값과 비교해 더 작은 값을 최솟값으로 정한다
        p_m = p_m < pack ? p_m : pack;
        o_m = o_m < one ? o_m : one;
    }

    //기타줄 팩만 사는 경우와 낱개만 사는 경우,
    //팩으로 6개씩 산 뒤 나머지를 낱개로 사는 경우를 각각 저장
    price[0] = p_m * (n / 6 + (n % 6 != 0));
    price[1] = o_m * n;
    price[2] = p_m * (n / 6) + o_m * (n % 6);

    //price의 최솟값을 ret에 저장한다
    for (int i = 0; i < 3; i++)
        ret = (ret < price[i] ? ret : price[i]);

    //기타줄을 사는 최소 비용을 출력한다
    printf("%d\n", ret);

    return 0;
}