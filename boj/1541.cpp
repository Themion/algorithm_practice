#include <cstdio>

int main()
{
    // 수식을 한 글자씩 입력받아 계산
    char c;
    // 수식을 -를 기준으로 쪼개면
    // 수식에서 -가 나오기 이전 수를 모두 더한 값에서
    // -가 나온 이후 수를 모두 빼면 원하는 결과가 나온다
    // (a + b) - (c + d + e) - (f + g)
    bool minus_check = false;
    // ret: 정답을 저장할 공간
    // temp: 문자열에서 각 수를 추출해 temp에 저장
    int ret = 0, temp = 0;

    while (true)
    {
        // 수식의 각 글자를 입력받은 뒤
        scanf("%c", &c);

        // 입력받은 글자가 숫자일 경우 temp 뒤에 붙인다
        if (c >= '0' && c <= '9') temp = temp * 10 + (c - '0');
        // 입력받은 숫자가 +, 혹은 -라면
        else
        {
            // -가 이미 나왔다면 temp를 ret에서 빼고
            // 그렇지 않다면            ret에 더한다
            ret += temp * (1 - 2 * minus_check);
            temp = 0;

            // 입력받은 글자가 -라면 -가 나왔음을 표시한다
            if (c == '-') minus_check = true;
            // 개행문자를 입력받았다면 수식이 끝났으므로 루프를 빠져나간다
            else if (c == '\n') break;
        }
        
    }

    //계산한 결과를 출력한다
    printf("%d\n", ret);

    return 0;
}