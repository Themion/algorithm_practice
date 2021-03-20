#include <cstdio>

int main()
{
    //input : 입력받은 점수를 저장할 공간
	//rng: 입력받을 점수의 수, max: 최대 점수값
	int input, rng, max = 0;
	//답을 출력할 때 쓸 변수
	double ret = 0;

	scanf("%d", &rng);

	//각 점수를 입력받은 뒤 ret에 더하고 가장 큰 점수를 max에 저장
	for (int i = 0; i < rng; i++) 
    {
        scanf("%d", &input);
        ret += input;
        if(max < input) max = input;
    }
	
	//ret에 100을 곱한 뒤 (max * rng)만큼 나누어 새로운 평균을 출력한다
	ret *= 100;
	printf("%f\n", ret / (max * rng));

    return 0;
}