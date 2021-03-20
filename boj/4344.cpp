#include <cstdio>

int main()
{
	//cases : 테스트 케이스의 수
	//size : 각 테스트 케이스에서 점수의 개수
	//score : 각 테스트 케이스에서 점수를 저장할 컨테이너
	int cases, size, score[1000]{ 0, };

	//mean : 각 테스트 케이스에서의 평균
	//num : 각 테스트 케이스에서 평균을 넘는 학생의 퍼센티지
	double mean, num;

	scanf("%d", &cases);

	for (int t = 0; t < cases; t++)
	{
		//mean과 num은 매 테스트 케이스마다 초기화되어야 한다
		mean = 0; num = 0;

		scanf("%d", &size);

		//점수를 입력받는대로 mean에 더해준다
		for (int i = 0; i < size; i++)
		{
			scanf("%d", &score[i]);
			mean += score[i];
		}

		//평균을 구한 뒤 이 평균을 넘는 학생의 수를 num에 저장
		mean /= size;
		for (int i = 0; i < size; i++) if (score[i] > mean) num += 1;

		//num을 이용해 퍼센티지를 게산
		num = (double)(num * 100 / size);
		//구한 퍼센티지를 출력
		printf("%.3f%%\n", num);
	}

    return 0;
}