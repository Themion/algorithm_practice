#include <algorithm>
#include <cstdio>

//a: 입력받은 배열 a
//map[i]: 입력받은 배열 b에서 i가 등장한 횟수
int a[50], map[101];

int main()
{
    //n: 배열의 크기, idx: 출력값을 계산 할 때 사용할 인덱스 변수
    //ret: 입력 시에는 입력 버퍼, 출력 시에는 출력값을 저장할 공간
    int n, idx = 0, ret = 0;
    //배열의 크기를 입력받은 뒤
    scanf("%d", &n);

    //a를 입력받고
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    //b의 각 성분이 나온 횟수를 계산한다
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ret);
        map[ret]++;
    }

    //a를 정렬한 뒤 임의의 값이 들어있는 ret를 0으로 초기화한다
    std::sort(a, a + n);
    ret = 0;

    //b의 각 성분에 대해 가장 큰 값부터 차례로
    for(int i = 101; idx < n; i--) while(map[i]--)
        //a의 idx번째 성분과 곱해 ret에 더한다
        ret += a[idx++] * i;

    //ret을 출력한다
    printf("%d\n", ret);

    return 0;
}