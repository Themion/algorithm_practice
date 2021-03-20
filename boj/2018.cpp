#include <cmath>
#include <cstdio>

//cont[i+4000]: i가 나온 횟수
//most[i][j]: (i==0: 첫번째, 1: 두번째) 최빈값의 (j==0: 등장 횟수, 1:값)
int cont[8001], most[2][2];

int main()
{
	//N: 배열의 크기, input: 입력에 사용할 버퍼
	//min, max: 최솟값/최댓값, mid: 중간값
	int N, input, min = 4001, max = -4001, mid;
	//sum: 각 값의 합. N으로 나누면 산술평균이 됨
	long double sum = 0;

	//배열의 크기를 입력받는다
	scanf("%d", &N);

	//배열의 각 항에 대해
	for (int i = 0; i < N; i++)
	{
		//배열을 입력받아 cont에 등장했음을 표시한다
		scanf("%d", &input);
		cont[input + 4000]++;

		//배열의 합에 해당 값을 더한다
		sum += input;

		//최솟값과 최댓값을 갱신한다
		if (input < min) min = input;
		if (input > max) max = input;
    }

    //수가 단 한 종류만 등장한 경우 예외가 발생한다
    //예외처리를 위해 mid에 이미 등장했던 아무 값이나 저장한다
    mid = input;

    //sum을 N으로 나눠 평균으로 만든 뒤, 중앙값을 구하기 위해 N을 2로 나눈다
	sum /= N; N /= 2;

	//4000부터 -4000 사이의 모든 값에 대해
	for (int i = 4000; i >= -4000; i--)
	{
		//최빈값과 두번째 최빈값을 갱신한다
		if (cont[i + 4000] >= most[0][0])
		{
			most[1][0] = most[0][0];
			most[1][1] = most[0][1];

			most[0][0] = cont[i + 4000];
			most[0][1] = i;
		}

		//N에 i가 나온 횟수만큼 뺀다
		//N이 처음으로 음수가 되게 만든 i값이 중앙값
		if (N >= 0)
		{
			N -= cont[i + 4000];
			if (N < 0) mid = i;
		}
	}

	//첫번째 최빈값과 두번째 최빈값의 등장 횟수가 같다면 두번째 최빈값을 사용한다
	if (most[0][0] == most[1][0]) most[0][1] = most[1][1];

    //산술평균, 중앙값, 최빈값, 범위를 각각 출력한다
    printf("%lld\n", (long long)floor(sum + 0.5));
    printf("%d\n", mid);
    printf("%d\n", most[0][1]);
	printf("%d\n", max - min);

    return 0;
}