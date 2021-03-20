#include <cstdio>
#include <map>

//배열 혹은 vector를 사용하면 메모리를 초과하므로
//map을 이용하여 메모리를 절약
std::map<long long, long long> cont;
//여러 함수에서 p와 q에 접근하므로 전역 변수로 설정
int p, q;

//map[idx]가 호출된 적이 없다면 해당 값을 채운 뒤 그 값을 반환한다
long long get(long long idx)
{
    if(cont[idx] == 0) cont[idx] = get(idx / p) + get(idx / q);
    return cont[idx];
}

int main()
{
    //수열 중 출력할 값의 인덱스를 저장
    long long n;
    //수열의 시작은 1임이 주어져 있다
    cont[0] = 1;
    //n, p, q를 입력받은 뒤 get(n)을 출력한다
    scanf("%lld %d %d", &n, &p, &q);
    printf("%lld\n", get(n));

    return 0;
}