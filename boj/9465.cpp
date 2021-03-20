#include <cstdio>

//각 스티커의 가중치를 저장할 공간
int stkr[2][100000];
//각 단계에서 가중치의 합의 최대치를 저장한다
//pts[*][j] : j == 0일 때 스티커 없음, 1일 때 윗쪽, 2일 때 아랫쪽 스티커를 마지막으로 사용
int pts[2][3];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
    //tc: 테스트 케이스의 수, n: 스티커의 개수를 저장할 때 사용할 변수
    int tc, n;
    //pts 배열의 크기를 줄이기 위해 사용할 스위치
    bool sw;

    //테스트 케이스의 수를 입력받는다
    scanf("%d", &tc);
    //각 테스트 케이스에 대해서
    while(tc--)
    {
        //스위치를 true로 초기화시킨다
        sw = true;

        //n을 입력받은 뒤 2n개의 스티커 가중치를 입력받는다
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++) scanf("%d", &stkr[i / n][i % n]);

        //첫 번째 줄의 pts값을 저장한 뒤
        pts[0][0] = 0; pts[0][1] = stkr[0][0]; pts[0][2] = stkr[1][0];

        //두 번째 줄부터 모든 줄에 대해
        for(int i = 1; i < n; i++)
        {
            //pts값을 계속해서 갱신한다
            pts[sw][0] = max(pts[!sw][1], pts[!sw][2]);
            pts[sw][1] = max(pts[!sw][0], pts[!sw][2]) + stkr[0][i];
            pts[sw][2] = max(pts[!sw][0], pts[!sw][1]) + stkr[1][i];

            sw = !sw;
        }
        
        //마지막으로 pts값을 수정한뒤 스위치를 작동시켰으므로 !sw에 대한 값이 원하는 값이다
        //맨 마지막 줄에는 반드시 스티커가 붙어있을 것이므로 max(pts[!sw][1], pts[!sw][2])를 출력한다
        printf("%d\n", max(pts[!sw][1], pts[!sw][2]));
    }

    return 0;
}