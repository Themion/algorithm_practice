#include <iostream>
#include <string>

using namespace std;

int main()
{
    //cin, cout 사용 시 필히 사용할 것
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //문자열에 크로아티아 알파벳이 몇 개 있는지 저장
    int count = 0;
    //알파벳 두 개로 나타낼 수 있는 크로아티아 알파벳 일곱 개를 미리 저장
    char pat[7][3] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
    //str : 실제 문자열
    //sch : 알파벳 두 개로 나타낼 수 있는 크로아티아 알파벳을 찾을 때 쓸 부분 문자열
    string str, sch;

    cin >> str;

    //str의 맨 앞을 지워가면서 카운트
    while (!str.empty())
    {
        //알파벳 세 개로 나타낼 수 있는 크로아티아 알파벳은 하나 뿐
        //이 알파벳이 들어있다면 알파벳 세 개를 지운다
        if (str.substr(0, 3) == "dz=") str.erase(0, 3);
        //그렇지 않다면
        else
        {
            //부분 문자열을 사용해서 두 개 짜리 알파벳을 찾는다
            sch = str.substr(0, 2);
            for (int i = 0; i < 7; i++)
            {
                //두 개 짜리 알파벳을 찾았다면 알파벳 두 개를 지운다
                if (sch == pat[i])
                {
                    str.erase(0, 2);
                    break;
                }

                //i == 6이라면 크로아티아 알파벳을 찾지 못한 것이다
                //알파벳 한 개를 지운다
                if (i == 6)
                    str.erase(0, 1);
            }
        }

        //알파벳을 몇 개를 지웠건 결국 다 같은 크로아티아 알파벳 한 개이다
        //크로아티아 알파벳을 하나 카운트한다
        count += 1;
    }

    //크로아티아 알파벳의 개수를 출력한다
    cout << count << '\n';

    return 0;
}