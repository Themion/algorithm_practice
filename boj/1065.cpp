#include <cstdio>

int main()
{
    // input: 한수의 개수를 계산할 범위, ans: 범위 내의 한수의 개수
    int input, ans = 99;
    scanf("%d", &input);

    // 한 자리 수는 길이 1짜리 수열이고, 두 자리 수는 길이 2짜리 수열이다
    // 길이가 2 이하인 수열은 각 수의 차가 일정하므로 반드시 한수이다
    if (input < 99) ans = input;

    // 범위의 끝이 세 자리 수 이상이라면
    // 완전 탐색을 통해 범위 안의 수가 한수인지 판정
    else for (int i = 100; i <= input; i++) 
        if ((i / 100 - (i / 10) % 10) == ((i / 10) % 10) - i % 10) 
            ans += 1;

    //한수의 개수를 출력
    printf("%d\n", ans);

    return 0;
}
