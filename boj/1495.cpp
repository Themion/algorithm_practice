#include <cstdio>

//vol[i][j]: i번째 곡을 연주한 직후 볼륨이 j인 경우가 있다면 true, 아니라면 false
bool vol[101][1001];
//c_vol[i]: i번째 곡을 연주한 직후 바꿀 수 있는 볼륨의 크기
short c_vol[100];

int main()
{
    //n: 연주할 곡의 수, s: 초기 볼륨, m: 최대 볼륨
    //ret: 출력에 사용할 변수
	int n, s, m, ret = -1;

    //n, s, m과 c_vol을 주어진 순서대로 입력받는다
	scanf("%d %d %d", &n, &s, &m);
	for (int i = 0; i < n; i++) scanf("%hd", &c_vol[i]);

    //0번째 곡을 연주한 직후, 즉 공연 직전 볼륨을 s로 정한다
	vol[0][s] = true;

    //i번째 곡을 연주한 직후 볼륨이 j일 가능성이 있다면
	for (int i = 0; i < n; i++) for (int j = 0; j <= m; j++) if (vol[i][j])
	{   
        //j +- c_vol[i]이 0 이상 m 이하라면 해당 볼륨으로 연주할 가능성이 있음을 표시한다
		if (j + c_vol[i] <= m) vol[i + 1][j + c_vol[i]] = true;
		if (j - c_vol[i] >= 0) vol[i + 1][j - c_vol[i]] = true;
	}

    //n번째 곡을 연주한 직후 가능한 최대 볼륨을 ret에 저장한 다음 이를 출력한다
    //만일 가능한 볼륨이 존재하지 않다면 ret의 초기값인 -1을 출력한다
	for (int i = 0; i <= m; i++) if (vol[n][i]) ret = i;
	printf("%d\n", ret);

	return 0;
}