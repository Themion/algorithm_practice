#include <cstdio>

//  비트마스트 형태:
//      문자 x를 1 << (x - 'a') 형태로 표시하면
//      문자 x가 존재함은 x번째 비트가 1로, 존재하지 않음은 0으로 표시됨
//      따라서 모든 문자에 대해 위의 연산을 행한 뒤 모두 합하면
//      그 값은 각 비트에 해당하는 문자가 존재하는지를
//      변수 하나로 표기한 값이 된다

int main()
{
    // N: 문자열의 개수, M: 쿼리의 개수, o: 쿼리의 종류
    int N, M, o;
    // cnt: 각 쿼리 당 기억한 문자열의 수, bitmask: 현재 기억한 문자
    // item: 각 문자열이 가진 문자를 비트마스크 형태로 표시
    int cnt, bitmask = (1 << 26) - 1, item[10000] = { 0, };
    // x: 쿼리의 문자, buf: 문자열을 입력받을 공간
    char x, buf[1001] = { 0, };

    // 문자열과 쿼리의 수를 입력받는다
    scanf("%d %d", &N, &M);
    
    // 각 문자열에 대해
    for (int it = 0; it < N; it++)
    {
        //문자열을 입력받은 뒤
        scanf("%s", buf);
        
        // 문자열이 가진 모든 문자를 비트마스크 형태로 표기해 저장
        for (int i = 0; buf[i] != '\0'; i++) 
            item[it] |= 1 << (buf[i] - 'a');
    }

    // 각 쿼리에 대해
    for (int it = 0; it < M; it++)
    {
        // 쿼리를 입력받은 뒤
        scanf("%d %c", &o, &x);
        // 입력받은 쿼리의 실행 결과를 비트마스크 형태로 저장
        bitmask += (1 << (x - 'a')) * (o % 2 ? -1 : 1);

        // 각 문자열에 대해
        cnt = 0;
        for (int i = 0; i < N; i++) 
            // 비트 연산으로 문자열의 모든 문자를 기억하는지 계산
            cnt += (bitmask & item[i]) == item[i];

        // 기억하는 문자열의 수를 출력
        printf("%d\n", cnt);
    }

    return 0;
}