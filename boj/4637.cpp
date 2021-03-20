#include <cstdio>

//인덱스가 셀프 넘버라면 false, 아니라면 true
bool selfNum[10001];

int main()
{
    //d(n)을 구할때 쓸 두 변수
    int temp, dTemp;

    //1부터 10000까지
    for (int i = 1; i <= 10000; i++)
    {
        //이 숫자가 이미 d(n)의 결과로 나왔다면 패스한다
        if (selfNum[i]) continue;

        //i에 대해 d(i)를 진행한다
        temp = i;
        dTemp = i;

        while (temp <= 10000)
        {
            while (temp > 0)
            {
                dTemp += temp % 10;
                temp /= 10;
            }

            //d(temp)의 결과가 10000 이하라면 selfNum에 셀프 넘버가 아니라고 표시한다
            if (dTemp <= 10000) selfNum[dTemp] = true;
            temp = dTemp;
        }
    }

    //셀프 넘버인 숫자를 출력한다
    for (int i = 1; i <= 10000; i++) if (!selfNum[i]) printf("%d\n", i);

    return 0;
}