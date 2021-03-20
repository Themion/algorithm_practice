#include <cstdio>

using namespace std;

int main()
{
    //N, S: IOI 문자열과 입력받을 문자열의 길이
    //ret: 가능한 IOI 문자열의 수, idx: 가능한 문자열의 시작 인덱스
    int N, S, ret = 0, idx;
    //buf: 문자를 한 문자씩 입력받음
    //cmp: IOI 문자열의 특정 인덱스에서의 문자
    char buf, cmp[2] = {'I', 'O'};
    bool chk = false;

    scanf("%d\n%d\n", &N, &S);
    N = 2 * N + 1;

    //입력받는 문자열의 각 문자에 대해
    for (int i = 0; i <= S; i++)
    {
        //문자를 입력받은 뒤
        scanf("%c", &buf);

        //이 문자가 IOI 문자열의 일부 뒤에 왔을 경우
        if (chk)
        {
            //IOI 문자열의 일부가 된다면 문자열의 길이를 늘리고
            if (buf == cmp[idx % 2]) idx++;
            //그렇지 않다면 문자열 길이를 정리한 뒤 문자열을 끝낸다
            else
            {
                chk = false;
                if (idx >= N) ret += (idx - N) / 2 + 1;
            }
        }
        //이 문자가 IOI 문자열의 시작점이 된다면
        //문자열의 시작을 표시하고 문자열의 길이를 1로 설정
        if (!chk && buf == 'I')
        {
            idx = 1;
            chk = true;
        }
    }

    printf("%d\n", ret);

    return 0;
}