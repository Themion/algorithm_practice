#include <cstdio>

//탑의 c번째 원반을 start에서 end로 움직인다
void move(int c, int start, int end)
{
    //세 탑의 번호의 합은 6이므로
    //start와 end를 제외한 기둥 wp를 이렇게 계산한다
    int wp = 6 - start - end;
    
    //탑은 맨 윗부분만 움직일 수 있으므로 재귀적으로 c의 윗부분을 wp에 치워둔다
    if (c > 1) move(c - 1, start, wp);
    //c를 start에서 end로 옮긴다
    printf("%d %d\n", start, end);
    //c의 윗부분을 다시 c의 위로 옮긴다
    if (c > 1) move(c - 1, wp, end);
}

int main()
{
    //size: 하노이 탑의 높이, mul: 총 이동 횟수
    int size, mul = 1;

    //하노이 탑의 높이를 입력받은 뒤 탑을 움직일 횟수를 계산한다
    scanf("%d", &size);

    //탑을 움직일 횟수는 (2^높이)-1이다
    for (int i = 0; i < size; i++) mul *= 2;

    //탑을 움직일 횟수를 출력한다
    printf("%d\n", mul - 1);

    //탑의 맨 밑단을 움직인다
    move(size, 1, 3);

    return 0;
}