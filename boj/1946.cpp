#include <cstdio>

//score[i - 1]: 서류심사 순위가 i인 지원자의 면접심사 순위
int score[100000];

int main()
{
    //t: 테스트 케이스의 수, n: 각 테스트 케이스에서 지원자의 수
    int t, n, idx, val, ret;

    //테스트 케이스의 수를 입력받은 뒤
    scanf("%d", &t);
    while(t--)
    {
        //지원자의 수를 입력받고
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            //각 지원자의 서류/면접심사 순위를 입력받아
            scanf("%d %d", &idx, &val);
            //이를 score에 저장한다
            score[idx - 1] = val;
        }

        //서류심사 1위인 지원자는 반드시 합격한다
        val = score[0]; ret = 1;
        //서류심사 순위가 높은 순부터 차례로 면접심사 순위가 가장 높은 사람은
        for (int i = 1; i < n; i++) if (val > score[i])
        {
            //채용 가능한 사람이다
            ret++;
            //면접심사 최고 순위를 갱신한다
            val = score[i];
        }

        //최대 채용자 수를 출력한다
        printf("%d\n", ret);
    }

    return 0;
}