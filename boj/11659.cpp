#include <cstdio>

// arr[i]: 입력받은 값을 처음부터 i번째 값까지 더한 값
int arr[100001] = { 0, };

int main()
{
    // size: 입력받을 배열의 크기, tc: 테스트 케이스의 수
    // s, e: 각 테스트 케이스에서 덧셈의 시작점과 끝점
    int size, tc, s, e;
    scanf("%d %d", &size, &tc);

    // 배열의 각 항목을 입력받아 이전 값과 더한다
    for (int i = 1; i <= size; i++) 
    {
        scanf("%d", &s);
        arr[i] = arr[i - 1] + s;
    }

    // 각 테스트 케이스에서
    while (tc--)
    {
        // 시작점과 끝점을 입력받아 뺄셈 한 번으로 덧셈 결과를 출력
        scanf("%d %d", &s, &e);
        printf("%d\n", arr[e] - arr[s - 1]);
    }

    return 0;
}