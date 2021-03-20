#include <algorithm>
#include <cstdio>

//난쟁이들의 키
int height[9];

int main()
{
	//sum: 키의 합. 올바른 난쟁이의 키의 합이 100이므로
	//잘못된 난쟁이의 키의 합은 height의 합 - 100일 것이다
	//lp, rp : 난쟁이를 찾을 때 쓸 인덱스
	int sum = -100, lp = 0, rp = 8;

	//난쟁이의 키를 입력받아 sum에 더한다
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &height[i]);
		sum += height[i];
	}

	//난쟁이들의 키를 정렬한다
	std::sort(height, height + 9);

	//height[lp] + height[rp] == sum이라면 lp번째 난쟁이와 rp번째 난쟁이는 잘못된 난쟁이이다
	while (height[lp] + height[rp] != sum)
	{
		if      (height[lp] + height[rp] < sum) lp += 1;
		else if (height[lp] + height[rp] > sum) rp -= 1;
	}
	//올바른 난쟁이들의 키를 출력한다
	for (int i = 0; i < 9; i++) if ((i != lp) && (i != rp)) printf("%d\n", height[i]);

    return 0;
}