#include <cstdio>

//chr[i]: 알파벳 cnt[i]가 후보로 주어졌다면 true, 아니라면 false
bool chr[26];
//출력할 문자열을 저장할 컨테이너
char cnt[15];
//l: 만들 암호의 길이, s: 암호 후보 문자의 수
short l, s;

//idx자의 끝이 last인 암호를 만든 뒤 나머지 암호를 완성시킨다
void decr(int idx, int last)
{
    //암호를 전부 완성시키지 못했다면
    if(idx < l)
    {
        //아직 쓰지 않은 문자열이 있을 때
        for(int i = last + 1; i < 26; i++) if(chr[i])
        {
            //각 문자를 암호의 끝에 붙인 뒤 해당 과정을 다시 시행한다
            cnt[idx] = i + 'a';
            decr(idx + 1, i);
        }
    }
    //암호 후보가 완성되었다면
    else
    {
        //a: 모음 수, b: 자음 수
        int a = 0, b = 0;
        //모음의 수와 자음의 수를 센다
        for (int i = 0; i < l; i++)
        {
            if      (cnt[i] == 'a') a++;
            else if (cnt[i] == 'e') a++;
            else if (cnt[i] == 'i') a++;
            else if (cnt[i] == 'o') a++;
            else if (cnt[i] == 'u') a++;
            else                     b++;
        }

        //모음 수와 자음 수가 충분하다면 암호 후보를 출력한다
        if ((a >= 1) && (b >= 2)) 
        {
            for (int i = 0; i < l; i++) printf("%c", cnt[i]);
            printf("\n");
        }
    }
}

int main()
{
    //입력에 사용할 버퍼
    char buf;
    //암호의 길이와 후보 문자의 수, 각 후보 문자를 입력받는다
    scanf("%hd %hd", &l, &s);
    for (int i = 0; i < s; i++)
    {
        scanf("%*c%c", &buf);
        chr[buf - 'a'] = true;
    }

    //암호 해독을 시작한다
    decr(0, -1);

    return 0;
}