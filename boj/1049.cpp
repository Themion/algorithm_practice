#include <cstdio>

#define MAX 0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    // N: 끊어진 기타줄의 수, M: 기타줄 브랜드의 수, buf: 각 가격을 입력받을 버퍼
    // pack, one: 각 브랜드의 기타줄 팩과 낱개의 최소 가격
    // price: 기타줄 팩만 사는 경우와 낱개만 사는 경우,
    //        팩으로 6개씩 산 뒤 나머지를 낱개로 사는 경우
    // ans: price의 최솟값을 저장할 공간
    int N, M, buf, pack = MAX, one = MAX, price[3], ans = MAX;

    // 끊어진 기타줄 수와 기타줄 브랜드의 수를 입력받은 뒤
    scanf("%d %d", &N, &M);
    // 각 기타줄 브랜드에 대해
    while(M--) {
        // 기타줄 팩과 낱개의 값의 최솟값을 저장
        scanf("%d", &buf);
        pack = min(pack, buf);

        scanf("%d", &buf);
        one = min(one, buf);
    }

    // 기타줄 팩만 사는 경우와 낱개만 사는 경우,
    // 팩으로 6개씩 산 뒤 나머지를 낱개로 사는 경우를 각각 저장
    price[0] = pack * (N / 6 + (N % 6 != 0));
    price[1] = one * N;
    price[2] = pack * (N / 6) + one * (N % 6);

    // price의 최솟값을 ans에 저장한다
    for (int i = 0; i < 3; i++) ans = min(ans, price[i]);

    // 기타줄을 사는 최소 비용을 출력한다
    printf("%d\n", ans);

    return 0;
}