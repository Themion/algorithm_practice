#include <cstdio>

int main()
{
    //n: 팩토리얼에 곱할 각 수, nn: n의 오염을 막기 위한 변수
    //n2, n5: 각 nn의 2의 차수와 5의 차수의 합
    int n, nn, n2 = 0, n5 = 0;
    //팩토리얼을 구할 수를 입력받은 뒤
    scanf("%d", &n);

    //팩토리얼에 곱할 각 수에 대해
    while(nn = n--)
    {
        //해당 수가 2 혹은 5의 배수라면 그 차수만큼 n2혹은 n5에 값을 더해준다
        while (nn % 2 == 0) { n2++; nn /= 2; }
        while (nn % 5 == 0) { n5++; nn /= 5; }
    }

    //n2와 n5 중 더 작은 값을 출력한다
    printf("%d\n", n2 < n5 ? n2 : n5);

    return 0;
}