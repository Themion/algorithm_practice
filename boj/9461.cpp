#include <cstdio>

//수열을 저장할 공간
long long arr[100] = {1, 1, 1, 2, 2};

int main()
{
    //tc: 테스트 케이스의 수, input: 수를 입력받을 공간
    //max: 현재 구한 수열 중 가장 큰 수의 인덱스
    int tc, input, max = 4;

    //테스트 케이스를 입력받는다
    scanf("%d", &tc);

    //각 테스트 케이스마다
    while (tc--)
    {
        //출력할 수의 인덱스를 입력받은 뒤
        scanf("%d", &input);
        //해당 인덱스가 비어있다면 그 인덱스까지 모두 채운 다음
        while (max < input) arr[max++] = arr[max - 1] + arr[max - 5];
        //해당 인덱스의 수를 출력한다
        printf("%lld\n", arr[input - 1]);
    }

    return 0;
}