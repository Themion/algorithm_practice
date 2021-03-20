#include <cstdio>

//세 변 중 어느 변이 빗변일지 모른다
bool is_right (int a, int b, int c) {
    return (a * a + b * b == c * c) || (b * b + c * c == a * a) || (c * c + a * a == b * b);
}

int main()
{
    //세 변을 입력받을 공간
    unsigned int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    //삼각형의 세 변을 입력받았다면
    while (!(a == 0 && b == 0 && c == 0))
    {
        //직각삼각형인지 판단한 뒤 맞다면 right, 아니라면 wrong을 출력
        printf("%s\n", is_right(a, b, c) ? "right" : "wrong");
        //다시 세 변을 입력받는다
        scanf("%d %d %d", &a, &b, &c);
    }

    return 0;
}