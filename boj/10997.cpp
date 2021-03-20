#include <cstdio>

//소용돌이 모양 2차원 배열의 실제 높이
int size;
//2차원 배열을 저장할 공간
bool plate[401][399];

int main()
{
    scanf("%d", &size);
    
	//해당 수가 1이라면 *만을 출력
    //그렇지 않다면 plate에 소용돌이 모양 그림을 그린다
	if (size == 1) { printf("*\n"); return 0; }

    //배열의 실제 크기를 정해준다
    size = 4 * size - 1;

    //소용돌이 모양을 그릴 시작점의 좌표
    int x = size - 3, y = 1;

    //소용돌이 모양의 모든 시작점은 오른쪽 맨 위의 바로 아랫줄이며
    //소용돌이 모양의 모든 끝은 x좌표가 입력받은 수 size에 대해 2  size - 1이다

    //소용돌이 모양을 모두 그릴 때까지 시행
    while (x != (size - 1) / 2)
    {
        //지우고자 하는 칸이 유효한 동시에 그 왼쪽 칸을 건드리지 않았다면
        while ((x > 0) && (!plate[y][x - 1]))
        {
            //해당 칸을 지우고
            plate[y][x] = true;
            //다음 칸을 확인
            x -= 1;
        }
        x += 1;
        //지우고자 하는 칸이 유효한 동시에 그 아랫쪽 칸을 건드리지 않았다면
        while ((y < size - 1) && (!plate[y + 1][x]))
        {
            //해당 칸을 지우고
            plate[y][x] = true;
            //다음 칸을 확인
            y += 1;
        }
        y -= 1;
        //지우고자 하는 칸이 유효한 동시에 그 오른쪽 칸을 건드리지 않았다면
        while ((x < size - 3) && (!plate[y][x + 1]))
        {
            //해당 칸을 지우고
            plate[y][x] = true;
            //다음 칸을 확인
            x += 1;
        }
        x -= 1;
        //지우고자 하는 칸이 유효한 동시에 그 윗쪽 칸을 건드리지 않았다면
        while ((y > 0) && (!plate[y - 1][x]))
        {
            //해당 칸을 지우고
            plate[y][x] = true;
            //다음 칸을 확인
            y -= 1;
        }
        y += 1;
    }

    //배열의 크기가 [size][size - 2]이므로 for문 역시 이에 맞춘다
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 2; j++)
        {
            if (!plate[i][j]) printf("*");
            else if (i != 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}