#include <cstdio>

// 각 테스트 케이스마다 실행
bool test_case()
{
    // 번호판을 입력받을 공간
    char plate[9];
    // str: 첫번째 부분(문자 부분)의 가치
    // num: 두번쨰 부분(숫자 부분)의 가치
    int str = 0, num = 0;

    // 번호판을 입력받는다
    scanf("%s", plate);

    // 문자 부분의 가치를 계산
    for (int i = 0; i < 3; i++)
    {
        str *= 26;
        str += plate[i] - 'A';
    }
    // 숫자 부분의 가치를 계산
    for (int i = 4; i < 8; i++)
    {
        num *= 10;
        num += plate[i] - '0';
    }

    // 두 가치의 차가 100 미만이면 true, 아니라면 false를 반환한다
    return (str - num <= 100) && (num - str <= 100);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    // 각 테스트 케이스에 대해 nice 혹은 not nice를 출력
    while (tc--) printf("%s\n", test_case() ? "nice" : "not nice");

    return 0;
}