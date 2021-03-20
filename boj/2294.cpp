#include <cstdio>

const int K_MAX = 10000;

//arr[i]: 주어진 동전 종류 중 i가 있다면 true, 아니라면 false
bool arr[K_MAX + 1];
//num[i % 2][j]: i개의 동전으로 j원을 만들 때의 동전 수
short num[K_MAX + 1];

//num[i + a]와 num[i] + 1 중 어느 쪽이 적합한가 테스트
void cmp(int i, int a)
{
    //num[i]가 0이거나 arr[a]가 0이라면 num[i + a]를 num[a] + 1로 대체할 수 없다
    if      (!num[i] || !arr[a])      return;
    //num[i + a]가 0이라면 i + a가 등장한 적 없으므로 num[i + a]는 num[a] + 1이다
	else if (!num[i + a])             num[i + a] = num[i] + 1;
    //그 이외의 경우는 둘을 비교해 더 작은 쪽이 적합하다
	else if (num[i + a] > num[i] + 1) num[i + a] = num[i] + 1;
}

int main()
{
    //n, k: 동전 종류의 수와 목표 금액
    //buf: 입력에 사용할 버퍼, min: 루프 횟수를 제한할 때 사용할 변수
	int n, k, buf, min = 0x3f3f3f3f;

    //동전 종류의 수와 목표 금액, 각 동전의 금액을 입력받는다
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &buf);
		if (buf <= k) arr[buf] = true;
        //금액이 가장 작은 동전의 금액을 min에 저장한다
        if(min > buf) min = buf;
	}

    //각 동전의 금액은 동전 하나만으로 해결 가능하다
	for (int i = 1; i <= k; i++) if (arr[i]) num[i] = 1;

    //최악의 경우 금액이 가장 작은 동전만으로 금액 k를 채워야 한다
    for (int t = 0; (!num[k]) && (t <= k / min); t++)
        //모든 가능한 종류의 동전에 대해
        for (int a = 1; a <= K_MAX; a++) if (arr[a])
            //금액 i + a를 낸 적 없거나 더 적은 동전으로 낼 수 있다면
            //기존의 num[i + a]를 num[i] + 1로 대체한다
            for (int i = 1; i + a <= k; i++) cmp(i, a);

    //반복문을 빠져나왔을 때 num[k]가 0이라면 주어진 동전만으로는 금액 k를 달성할 수 없다
    if (!num[k]) num[k] = -1;
    //최소 동전의 수 혹은 -1을 출력한다
	printf("%hd\n", num[k]);

	return 0;
}