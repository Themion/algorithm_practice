#include <cstdio>
#include <vector>

using namespace std;

//각 주문을 저장할 클래스
class order { public: long long time = 0, size = 0; };

//pack[i][j]: (i == 0: 파란색, 1: 빨간색) 포장지로 포장한 j번째 상품이 포장을 시작한 시간
long long pack[2][100001];

//gift[i][j]: (i == 0: 파란색, 1: 빨간색) 포장지로 포장한 j번째 주문
order gift[2][1001];

int main()
{
	//입력에 사용할 버퍼
	char buf;
    //N: 주문의 수, int_buf: 입력에 사용할 버퍼
	//cnt[i]: (i == 0: 파란색, 1: 빨간색) 포장지로 포장한 손님의 수
	int N, int_buf[2], idx[2] = { 1, 1 };
	//cnt: 상품의 수를 카운팅할 때 사용할 변수
	long long cnt;
	//출력에 사용할 bool타입 변수
	vector<bool> ret;

	//파란색 포장지와 빨간색 포장지로 포장하는 시간, 손님의 수를 각각 입력받는다
	scanf("%lld %lld %d\n", &pack[0][0], &pack[1][0], &N);
	//각 손님에 대해 주문 정보를 입력받는다
	for (int i = 1; i <= N; i++)
	{
		scanf("%d ", &int_buf[0]);
		scanf("%c ", &buf);
		scanf("%d%*c", &int_buf[1]);
		//N만으로는 파란색 포장지와 빨간색 포장지를 구분할 수 없다
		//포장지의 색이 파란색이라면 cnt[0]을, 빨간색이라면 cnt[1]을 1씩 증가
		gift[buf == 'R'][idx[buf == 'R']].time = int_buf[0];
		gift[buf == 'R'][idx[buf == 'R']++].size = int_buf[1];
	}

	//idx를 1로 초기화한 뒤
	cnt = 1;

	//파란색 포장지로 포장한 주문에 대해
	for (int i = 1; i < idx[0]; i++)
	{
		//해당 주문을 받았을 때 그 이전 주문이 끝나지 않았다면 주문을 받은 시각을 갱신
		if (gift[0][i].time < gift[0][i - 1].time)
			gift[0][i].time = gift[0][i - 1].time;

		//그 주문의 모든 상품에 대해
		for (int j = 0; j < gift[0][i].size; j++)
		{
			//해당 상품을 포장을 시작한 시각을 pack[0]에 저장한 다음
			//포장을 시작한 시각에 포장하는 시간을 더한다
			pack[0][cnt++] = gift[0][i].time;
			gift[0][i].time += pack[0][0];
		}
	}
	//파란색 포장지로 주문한 모든 상품의 수를 사용하지 않은 공간인 pack[0][0]에 저장
	pack[0][0] = cnt - 1;

	//idx를 1로 초기화한 뒤
	cnt = 1;

	//빨간색 포장지로 포장한 주문에 대해
	for (int i = 1; i < idx[1]; i++)
	{
		//해당 주문을 받았을 때 그 이전 주문이 끝나지 않았다면 주문을 받은 시각을 갱신
		if (gift[1][i].time < gift[1][i - 1].time)
		    gift[1][i].time = gift[1][i - 1].time;

		//그 주문의 모든 상품에 대해
		for (int j = 0; j < gift[1][i].size; j++)
		{
			//해당 상품을 포장을 시작한 시각을 pack[1]에 저장한 다음
			//포장을 시작한 시각에 포장하는 시간을 더한다
			pack[1][cnt++] = gift[1][i].time;
			gift[1][i].time += pack[1][0];
		}
	}
	//빨간색 포장지로 주문한 모든 상품의 수를 사용하지 않은 공간인 pack[1][0]에 저장
	pack[1][0] = cnt - 1;

	//손님의 수는 이제 의미가 없으므로 인덱싱에 재사용한다
	idx[0] = 1; idx[1] = 1;

	//파란색 상품과 빨간색 상품을 모두 비교할 수 있을 때
	while ((idx[0] <= pack[0][0]) && (idx[1] <= pack[1][0]))
	{
		//어느 빨간색 상품이 파란색 상품보다 먼저 포장되었다면
		if (pack[0][idx[0]] > pack[1][idx[1]])
		{
			//ret에 이를 표시한 뒤 다음 빨간색 상품에 대해 같은 작업을 실행한다
			ret.push_back(true);
			idx[1] += 1;
		}
		//반대의 경우도 똑같이 실행
		else
		{
			ret.push_back(false);
			idx[0] += 1;
		}
	}

	//파란색과 빨간색 중 어느 한 상품을 모두 비교했다면 ret의 뒤에 나머지 상품을 모두 표시한다
	if (idx[0] > pack[0][0]) while (idx[1]++ <= pack[1][0]) ret.push_back(true);
	else                     while (idx[0]++ <= pack[0][0]) ret.push_back(false);

	//파란색 상품과 빨간색 상품의 수, 각 상품이 포장된 순서를 출력한다
	printf("%lld\n", pack[0][0]);
	for (long long i = 0; i < ret.size(); i++) if (!ret[i]) printf("%lld ", i + 1);
	printf("\n%lld\n", pack[1][0]);
	for (long long i = 0; i < ret.size(); i++) if (ret[i]) printf("%lld ", i + 1);
	printf("\n");

    return 0;
}