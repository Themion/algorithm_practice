#include <cstdio>

//A[i]: 강의실 A에 있는 학생 수
int A[1000000];

int main()
{
    //N: 강의실 수
    //B: 총감독관이 감독하는 학생 수
    //C: 부감독관 한 명이 감독하는 학생 수
    int N, B, C;
    unsigned long long ret = 0;
    
    //문제에서 주는 값을 모두 입력받은 뒤
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    //각 강의실에 대해
    for (int i = 0; i < N; i++)
    {
        //총감독관이 감독하지 못하는 학생이 있다면
        A[i] -= B;
        //필요한 부감독관 명수를 계산해 ret에 더한다
        if (A[i] > 0) ret += A[i] / C + (A[i] % C != 0);
    }

    //각 강의실에 총감독관은 반드시 존재하므로
    //부감독관 수의 총합에 강의실 수를 더한 값을 출력한다
    printf("%lld\n", ret + N);

    return 0;
}