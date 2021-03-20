#include <cstdio>

//coin[i]: i번째 동전의 가치, coin[i - 1]의 배수
int coin[10];

int main()
{
    //n: 동전 종류의 수, k: 만들고자 하는 가치
    //sum: 범위 내의 동전 중 가장 큰 것부터 써서
    //     만들 수 있는 k 이하의 가치 중 가장 큰 값
    //buf: (k - sum)원을 만들 때 필요한
    //     가용 가능한 동전 중 가장 가치가 큰 동전의 수
    //ret: sum원을 만들 때 사용한 동전의 수( = buf의 합)
    int n, k, sum = 0, buf, ret = 0;

    //동전의 종류 수와 만들 가치, 각 동전의 가치를 입력받는다
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

    //가장 큰 동전부터 차례로 써서 만든 가치가 아직 k보다 작을 때
    for (int i = n - 1; i >= 0; i--) if (sum < k)
    {
        //(k - sum)을 만드는 데에 필요한 coin[i]의 수를 구한 뒤
        buf = (k - sum) / coin[i];
        //coin[i]을 buf개 사용하여 sum값을 늘리고
        sum += buf * coin[i];
        //사용한 동전의 개수가 buf개만큼 늘었따고 표시한다
        ret += buf;
    }

    //총 사용한 동전의 수를 출력한다
    printf("%d\n", ret);

    return 0;
}