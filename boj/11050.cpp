#include <cstdio>

int main()
{
	//n, k : 입력받을 두 수
	//ret : 이항 계수를 저장할 공간
	int n, k, ret = 1;
	scanf("%d %d", &n, &k);

	//빠른 계산을 위해 k를 수정한다
	if (n - k < k) k = n - k;

	//k번만큼 분자 부분, 즉 n * (n - 1) * ... * (n - k + 1)을 곱해준다
	for (int i = 0; i < k; i++) ret *= n--;
	//k번만큼 분모 부분, 즉 1 * 2 * ... * k를 곱해준다
	for (int i = 1; i <= k; i++) ret /= i;

	printf("%d\n", ret);
    
    return 0;
}