#include <cstdio>

int main()
{
    //E, S, M: 각각 지구, 태양, 달을 나타내는 수
    //ret : 구하고자 하는 년도 저장, add : ret에 더할 가중치
	int E, S, M, ret = 0, add = 1;
	scanf("%d %d %d", &E, &S, &M);

    //범위에 맞게 수를 1씩 빼 준다
	E -= 1; S -= 1; M -= 1;
    
    //지구 년도로 나머지가 E일 때까지 add만큼 더한다
    while(ret % 15 != E) ret += add;
    //지구 년도 나머지를 보존하기 위해 add에 15를 곱한다
    add *= 15;
    //태양 년도로 나머지가 S일 때까지 add만큼 더한다
    while(ret % 28 != S) ret += add;
    //태양 년도 나머지를 보존하기 위해 add에 28을 곱한다
    add *= 28;
    //달 년도로 나머지가 M일 때까지 add만큼 더한다
    while(ret % 19 != M) ret += add;

    //E, S, M을 1씩 뺐으므로 ret에 1을 더한 값을 출력한다
    printf("%d\n", ret + 1);

    return 0;
}