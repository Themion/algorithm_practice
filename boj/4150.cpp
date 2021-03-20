#include <cstdio>

//최대 피보나치 수의 자리수는 1000을 넘지 않는다
int const size = 1000;
//피보나치 수를 3개의 1차원 배열에 한 자리씩 나누어 저장한다
short arr[3][size];

//두 배열 a, b에 담긴 수를 더해 배열 ab에 한 자리씩 나누어 저장한다
void fib(short a[], short b[], short ab[])
{
    //각 자리를 더한 결과가 10을 넘을 때 쓸 공간
	int add = 0;

    //a, b의 각 자리에 대해
	for (int i = 0; i <= size; i++)
	{
        //a, b의 각 자리를 더한 값을 ab에 더한다
        //이전 결과가 10을 넘은 경우 10의 자리 이상 역시 ab에 더한다
		ab[i] = a[i] + b[i] + add;
        //add를 사용했건 사용하지 않았건 add를 0으로 초기화한다
		add = 0;

        //a와 b의 각 자리를 더한 결과가 10 이상이라면
		if (ab[i] >= 10)
		{
            //ab[i]를 10으로 나눈 결과를 add에 저장한뒤
			add = ab[i] / 10;
            //ab[i]를 한 자리 수로 만든다
			ab[i] %= 10;
		}
	}
}

int main()
{
    //n: n번째 피보나치 수를 구할 때 쓸 변수
    //cnt: n번째 피보나치 수의 자리수
	int n, cnt = size - 1;
	scanf("%d", &n);

    //1번째 피보나치 수는 1임이 자명하다
	arr[1][0] = 1;

    //2번째 피보나치 수부터 차례로 구한다
	for (int i = 2; i <= n; i++)
		fib(arr[(i - 2) % 3], arr[(i - 1) % 3], arr[i % 3]);

    //피보나치 수의 자리수는 배열에서 0이 마지막으로 등장한 위치의 인덱스와 같다
	while (arr[n % 3][cnt] == 0) cnt--;
    //만일 n == 0일 경우 cnt는 음수가 되므로 이를 수정한다
    if(cnt < 0) cnt = 0;

    //피보나치 수의 각 자리를 차례로 출력한 뒤 개행문자를 출력한다
	for (int i = cnt; i >= 0; i--) printf("%d", arr[n % 3][i]);
	printf("\n");

	return 0;
}