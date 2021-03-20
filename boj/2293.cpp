#include <cstdio>

const int N_MAX = 100;
const int K_MAX = 10000;

//cases[i % 2][j]: 1번째 동전부터 (i - 1)번째 동전까지 이용해서
//                 j원을 만들 수 있는 경우의 수
//arr[i]: i번째 동전의 가치
int cases[2][K_MAX + 1], arr[N_MAX + 1];

int main()
{
    //n, k: 문제에서 제시하는 정보, buf: 입력에 사용할 버퍼
    //cnt: 가치가 k개 이하인 동전의 수
	int n, k, buf, cnt = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &buf);
		if (buf <= k) arr[cnt++] = buf;
	}

    //동전을 얼마나 쓰든 0원은 항상 만들 수 있다
	cases[0][0] = 1; cases[1][0] = 1;

	//첫번째 동전부터 n번째 동전까지 중 어느 한 동전을 a라고 하자
	//첫번째 동전부터 a - 1번째 동전까지 써서 0 ~ (k - a)원을 만든 경우
	//여기에 a를 하나 더 추가해 a ~ k원을 만들 수 있다
	//0 ~ (a - 1)원의 경우 기존에 구한 경우의 수를 그대로 이용하면 된다
	for (int a = 0; a < cnt; a++)
	{
		//arr[a] 동전을 쓰지 않고 i + arr[a]원을 만든 경우는 
        //  arr[0]부터 arr[a]까지 사용해서 i + arr[a]원을 만든 경우이므로
        //  cases[a % 2][i + arr[a]]이다
		//arr[a] 동전을 반드시 쓰고 i + arr[a]원을 만든 경우는 
		//  arr[0]부터 arr[a]까지 사용해서 i원을 만들고 
		//  거기에 arr[a]짜리 동전을 하나 더 넣은 경우이므로
		//  cases[(a + 1) % 2][i]와 같다
		for (int i = 0; i + arr[a] <= k; i++) 
			cases[(a + 1) % 2][i + arr[a]] = 
				cases[a % 2][i + arr[a]] + cases[(a + 1) % 2][i];
		for (int j = 0; j <= k; j++) cases[a % 2][j] = cases[(a + 1) % 2][j];
	}

	printf("%d\n", cases[cnt % 2][k]);

	return 0;
}