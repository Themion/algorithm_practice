#include <cstdio>

//어느 숫자가 사이클에 포함되어 있는지 검사
bool cont[100];

int main()
{
	//place: 사이클의 다음 수를 계산
    //ret: 출력할 사이클의 수를 저장한다
	int place, ret = 1;

	//사이클의 첫 수를 입력받아 cont에 저장
	scanf("%d", &place);
	cont[place] = true;

	//사이클에 포함된 수를 발견할 때까지 무한반복
	while (1)
	{
		//사이클에 포함될 수를 생성
		place = (((place / 10) + (place % 10)) % 10) + (place % 10) * 10;

		//place가 사이클에 이미 포함되어 있다면 break
		if (cont[place] == true) break;
		//그렇지 않다면 place를 사이클에 포함시킨 뒤 ret에 값을 1 더한다
		else {cont[place] = true; ret++;}
	}

	//사이클의 크기는 ret과 같으므로 ret을 출력한다
	printf("%d\n", ret);

    return 0;
}