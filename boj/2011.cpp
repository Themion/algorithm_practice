#include <cstdio>

//dcd[i]: i부터 size까지의 부분 암호의 경우의 수, size: 암호의 길이
int dcd[5001], size = 0;
//암호를 문자열로 저장
char str[5001];

//idx부터 size까지의 경우의 수를 구한다
int decode(int idx)
{
    //암호가 0으로 시작된다면 경우의 수는 0이다
    if      (str[idx] == '0') dcd[idx] = 0;
    //암호가 한 자리 뿐이라면 경우의 수는 1이다
    else if (idx == size - 1) dcd[idx] = 1;
    else if (dcd[idx] == -1) 
    {
        //tmp: 암호의 맨 앞 두 자리를 int 타입으로 저장
        //ret: 암호를 해독할 때 사용할 변수
        int tmp, ret;

        //맨 앞 글자를 뺀 암호의 경우의 수를 구한다
        ret = decode(idx + 1);
        //만일 암호가 한 자리가 아니라면
        if(idx < size - 1)
        {
            //암호의 맨 앞 두 자리를 정수로 타입캐스팅한 뒤
            tmp = (str[idx] - '0') * 10 + (str[idx + 1] - '0');
            //tmp가 10 이상 26 이하라면 맨 앞 두 글자를 뺀 암호의 경우의 수를 더한다
            if ((tmp >= 10) && (tmp <= 26)) ret += decode(idx + 2);
        }

        //ret가 경우의 수이므로 이를 dcd에 저장한다
        dcd[idx] = ret % 1000000;
    }
    
    //암호의 경우의 수를 반환한다
    return dcd[idx];
}

int main()
{
    //암호를 입력받은 뒤
    scanf("%s", str);

    //암호의 경우의 수를 -1로 초기화한다
    while(str[size] != '\0') dcd[size++] = -1;
    //실질적으로 쓰이지 않는 부분이지만 알고리즘에서 요구하므로
    //암호의 자리수가 0자리일 때의 경우의 수를 저장한다
    dcd[size] = 1;

    //암호를 해독하여 출력한다
    printf("%d\n", decode(0));

    return 0;
}